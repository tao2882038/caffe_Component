#ifndef CAFFE_H_
#define CAFFE_H_

#include <boost/thread.hpp>

class Caffe {
 public:
  ~Caffe();

  // Thread local context for Caffe. Moved to common.cpp instead of
  // including boost/thread.hpp to avoid a boost/NVCC issues (#1009, #1010)
  // on OSX. Also fails on Linux with CUDA 7.0.18.
  static Caffe& Get();

  enum Brew { CPU, GPU };

  // Returns the mode: running on CPU or GPU.
  inline static Brew mode() { return Get().mode_; }
  
  inline static void set_mode(Brew mode) { Get().mode_ = mode; }
 
  
  inline static int solver_count() { return Get().solver_count_; }
  inline static void set_solver_count(int val) { Get().solver_count_ = val; }
  inline static int solver_rank() { return Get().solver_rank_; }
  inline static void set_solver_rank(int val) { Get().solver_rank_ = val; }
  inline static bool multiprocess() { return Get().multiprocess_; }
  inline static void set_multiprocess(bool val) { Get().multiprocess_ = val; }
  inline static bool root_solver() { return Get().solver_rank_ == 0; }

 protected:
  Brew mode_;

  // Parallel training
  int solver_count_;
  int solver_rank_;
  bool multiprocess_;

 private:
  // The private constructor to avoid duplicate instantiation.
  Caffe();


};



#endif