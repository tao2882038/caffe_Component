#include "Caffe.hpp"

static boost::thread_specific_ptr<Caffe> thread_instance_;

Caffe& Caffe::Get() {
  if (!thread_instance_.get()) {
    thread_instance_.reset(new Caffe());
  }
  return *(thread_instance_.get());
}

Caffe::Caffe()
    : mode_(Caffe::CPU),
    solver_count_(1), solver_rank_(0), multiprocess_(false) {
}

Caffe::~Caffe() {
}