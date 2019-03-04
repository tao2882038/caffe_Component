#ifndef CAFFE_COMMON_THREAD_HPP_
#define CAFFE_COMMON_THREAD_HPP_

#include <boost/thread.hpp>
#include "caffe/internal_thread.hpp"
#include <boost/shared_ptr.hpp>

namespace caffe {

using boost::shared_ptr;

class CommonThread: public InternalThread{
 public:
  explicit CommonThread(){
      value_ = 0;
      StartInternalThread();
      ThreadId_ = ThreadId();  
  }
  ~CommonThread(){
      this->StopInternalThread();
  }
  const char* mode(){
    Caffe::Brew mode = Caffe_->mode();
    if(mode == Caffe::CPU)
        return "CPU";
    if(mode == Caffe::GPU)
        return "GPU";
  }
  void set_mode_cpu() { Caffe_->set_mode(Caffe::CPU); }
  void set_mode_gpu() { Caffe_->set_mode(Caffe::GPU); }
  std::string tid(){ return ThreadId_;}
  int get_value(){return value_;}
  shared_ptr<Caffe> get_Caffe(){return Caffe_;}
protected:
  void InternalThreadEntry();

private:
  int value_;
  shared_ptr<Caffe> Caffe_;
  std::string ThreadId_;

  
};



















}  // namespace caffe

#endif  // CAFFE_COMMON_THRAED_HPP_