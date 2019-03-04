#include <Python.h>  // NOLINT(build/include_alpha)


// Produce deprecation warnings (needs to come before arrayobject.h inclusion).
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include <boost/make_shared.hpp>
#include <boost/python.hpp>
#include <boost/python/raw_function.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <numpy/arrayobject.h>

// these need to be included after boost on OS X
#include <string>  // NOLINT(build/include_order)
#include <vector>  // NOLINT(build/include_order)
#include <fstream>  // NOLINT

#include "caffe/blob.hpp"
#include "caffe/common.hpp"

// Temporary solution for numpy < 1.7 versions: old macro, no promises.
// You're strongly advised to upgrade to >= 1.7.
#ifndef NPY_ARRAY_C_CONTIGUOUS
#define NPY_ARRAY_C_CONTIGUOUS NPY_C_CONTIGUOUS
#define PyArray_SetBaseObject(arr, x) (PyArray_BASE(arr) = (x))
#endif

/* Fix to avoid registration warnings in pycaffe (#3960) */
#define BP_REGISTER_SHARED_PTR_TO_PYTHON(PTR) do { \
  const boost::python::type_info info = \
    boost::python::type_id<shared_ptr<PTR > >(); \
  const boost::python::converter::registration* reg = \
    boost::python::converter::registry::query(info); \
  if (reg == NULL) { \
    bp::register_ptr_to_python<shared_ptr<PTR > >(); \
  } else if ((*reg).m_to_python == NULL) { \
    bp::register_ptr_to_python<shared_ptr<PTR > >(); \
  } \
} while (0)

namespace bp = boost::python;

namespace caffe {

// For Python, for now, we'll just always use float as the type.
typedef float Dtype;
const int NPY_DTYPE = NPY_FLOAT32;

void InitLog() {
  ::google::InitGoogleLogging("");
  ::google::InstallFailureSignalHandler();
}

bp::object Blob_Reshape(bp::tuple args, bp::dict kwargs) {
  if (bp::len(kwargs) > 0) {
    throw std::runtime_error("Blob.reshape takes no kwargs");
  }
  Blob<Dtype>* self = bp::extract<Blob<Dtype>*>(args[0]);
  vector<int> shape(bp::len(args) - 1);
  for (int i = 1; i < bp::len(args); ++i) {
    shape[i - 1] = bp::extract<int>(args[i]);
  }
  self->Reshape(shape);
  // We need to explicitly return None to use bp::raw_function.
  return bp::object();
}

struct NdarrayConverterGenerator {
  template <typename T> struct apply;
};

template <>
struct NdarrayConverterGenerator::apply<Dtype*> {
  struct type {
    PyObject* operator() (Dtype* data) const {
      // Just store the data pointer, and add the shape information in postcall.
      return PyArray_SimpleNewFromData(0, NULL, NPY_DTYPE, data);
    }
    const PyTypeObject* get_pytype() {
      return &PyArray_Type;
    }
  };
};

struct NdarrayCallPolicies : public bp::default_call_policies {
  typedef NdarrayConverterGenerator result_converter;
  PyObject* postcall(PyObject* pyargs, PyObject* result) {
    bp::object pyblob = bp::extract<bp::tuple>(pyargs)()[0];
    shared_ptr<Blob<Dtype> > blob =
      bp::extract<shared_ptr<Blob<Dtype> > >(pyblob);
    // Free the temporary pointer-holding array, and construct a new one with
    // the shape information from the blob.
    void* data = PyArray_DATA(reinterpret_cast<PyArrayObject*>(result));
    Py_DECREF(result);
    const int num_axes = blob->num_axes();
    vector<npy_intp> dims(blob->shape().begin(), blob->shape().end());
    PyObject *arr_obj = PyArray_SimpleNewFromData(num_axes, dims.data(),
                                                  NPY_FLOAT32, data);
    // SetBaseObject steals a ref, so we need to INCREF.
    Py_INCREF(pyblob.ptr());
    PyArray_SetBaseObject(reinterpret_cast<PyArrayObject*>(arr_obj),
        pyblob.ptr());
    return arr_obj;
  }
};

std::string mode() {
  if(Caffe::mode() == Caffe::TEST)
    return "TEST";
  if(Caffe::mode() == Caffe::CPU)
    return "CPU";
  if(Caffe::mode() == Caffe::GPU)
    return "GPU";

} 

BOOST_PYTHON_MODULE(_blob) {
  
  bp::def("init_log", &InitLog);
  bp::def("mode", &mode);

  bp::class_<Blob<Dtype>, shared_ptr<Blob<Dtype> >, boost::noncopyable>(
    "Blob", bp::init<>())
    .add_property("shape",
        bp::make_function(
            static_cast<const vector<int>& (Blob<Dtype>::*)() const>(
                &Blob<Dtype>::shape),
            bp::return_value_policy<bp::copy_const_reference>()))
    .def("reshape",           bp::raw_function(&Blob_Reshape))
    .def("reshape_like", &Blob<Dtype>::ReshapeLike)
    .def("check_error", &Blob<Dtype>::check_error)
    .add_property("shape_string",      &Blob<Dtype>::shape_string)
    .add_property("num",      &Blob<Dtype>::num)
    .add_property("channels", &Blob<Dtype>::channels)
    .add_property("height",   &Blob<Dtype>::height)
    .add_property("width",    &Blob<Dtype>::width)
    .add_property("count",    static_cast<int (Blob<Dtype>::*)() const>(
        &Blob<Dtype>::count))
    
#ifndef CPU_ONLY
    .add_property("_gpu_data_ptr",
        reinterpret_cast<uintptr_t (Blob<Dtype>::*)()>(
          &Blob<Dtype>::mutable_gpu_data))
    .add_property("_gpu_diff_ptr",
        reinterpret_cast<uintptr_t (Blob<Dtype>::*)()>(
          &Blob<Dtype>::mutable_gpu_diff))
#endif
    .add_property("data_ptr",
        reinterpret_cast<uintptr_t (Blob<Dtype>::*)()>(
          &Blob<Dtype>::mutable_cpu_data))
    .add_property("data",     bp::make_function(&Blob<Dtype>::mutable_cpu_data,
          NdarrayCallPolicies()))
    .add_property("diff",     bp::make_function(&Blob<Dtype>::mutable_cpu_diff,
          NdarrayCallPolicies()));
  BP_REGISTER_SHARED_PTR_TO_PYTHON(Blob<Dtype>);

  bp::class_<vector<int> >("vector<int>")
    .def(bp::vector_indexing_suite<vector<int> >());

  import_array1();
}

}  // namespace caffe
