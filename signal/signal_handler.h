#ifndef __SIGNAL_HANDLER_H__
#define __SIGNAL_HANDLER_H__

#include "action.h"


namespace test_signal {

class SignalHandler {
 public:
  // Contructor. Specify what action to take when a signal is received.
  SignalHandler(ActionEnum::Enum SIGINT_action,
                ActionEnum::Enum SIGHUP_action);
  ~SignalHandler();
  ActionCallback GetActionFunction();
 private:
  ActionEnum::Enum CheckForSignals();
  ActionEnum::Enum SIGINT_action_;
  ActionEnum::Enum SIGHUP_action_;
};

}  // namespace caffe

#endif  // INCLUDE_CAFFE_UTIL_SIGNAL_HANDLER_H_
