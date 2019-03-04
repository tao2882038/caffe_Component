#include "caffe/common_thread.hpp"

namespace caffe{


void CommonThread::InternalThreadEntry(){
    Caffe_.reset(&Caffe::Get());
    try {
    while (!must_stop()) {
      value_++;
    }
  } catch (boost::thread_interrupted&) {
    // Interrupted exception is expected on shutdown
  }
    
}























} // namespace caffe