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

#include "caffe/common.hpp"
#include "caffe/common_thread.hpp"

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

const char* g_cublasGetErrorString(int a){
  cublasStatus_t error = (cublasStatus_t)a;
  return cublasGetErrorString(error);
}

const char* g_curandGetErrorString(int a){
  curandStatus_t error = (curandStatus_t)a;
  return curandGetErrorString(error);
}

// Selecting mode.
const char* g_mode(){
  Caffe::Brew mode = Caffe::mode();
  if(mode == Caffe::CPU)
    return "CPU";
  if(mode == Caffe::GPU)
    return "GPU";
} 
void set_mode_cpu() { Caffe::set_mode(Caffe::CPU); }
void set_mode_gpu() { Caffe::set_mode(Caffe::GPU); }
void set_random_seed(unsigned int seed) { Caffe::set_random_seed(seed); }



BOOST_PYTHON_MODULE(_common) {

  bp::def("GlobalInit", &GlobalInit);
  bp::def("cublasGetErrorString", &g_cublasGetErrorString);
  bp::def("curandGetErrorString", &g_curandGetErrorString);

  bp::def("mode", &g_mode);
  bp::def("set_mode_cpu", &set_mode_cpu);
  bp::def("set_mode_gpu", &set_mode_gpu);
  bp::def("set_random_seed", &set_random_seed);
  bp::def("set_device", &Caffe::SetDevice);
  bp::def("solver_count", &Caffe::solver_count);
  bp::def("set_solver_count", &Caffe::set_solver_count);
  bp::def("solver_rank", &Caffe::solver_rank);
  bp::def("set_solver_rank", &Caffe::set_solver_rank);
  bp::def("multiprocess", &Caffe::multiprocess);
  bp::def("set_multiprocess", &Caffe::set_multiprocess);
  bp::def("pid", &Caffe::pid);


    
  bp::class_<CommonThread, boost::noncopyable >("CommonThread",bp::init<>())
    .def("value", &CommonThread::get_value)
    .def("mode", &CommonThread::mode)
    .def("set_mode_cpu", &CommonThread::set_mode_cpu)
    .def("set_mode_gpu", &CommonThread::set_mode_gpu)
    .def("tid", &CommonThread::tid)

    


    .def("Caffe", &CommonThread::get_Caffe);
  BP_REGISTER_SHARED_PTR_TO_PYTHON(Caffe);

  bp::class_<Caffe, boost::noncopyable >("Caffe",bp::no_init);
    



  bp::class_<vector<int> >("vector<int>")
    .def(bp::vector_indexing_suite<vector<int> >());

  import_array1();
}

}  // namespace caffe
