#ifndef __ACTION_H__
#define __ACTION_H__

#include <boost/function.hpp>

namespace test_signal {

 namespace ActionEnum {
    enum Enum {
      NONE = 0,  // Take no special action.
      STOP = 1,  // Stop training. snapshot_after_train controls whether a
                 // snapshot is created.
      SNAPSHOT = 2  // Take a snapshot, and keep training.
    };
  }

typedef boost::function<ActionEnum::Enum()> ActionCallback;

class Action {
 public:
  explicit Action();
  void SetActionFunction(ActionCallback func);
  ActionEnum::Enum GetRequestedAction();

 protected:
  ActionCallback action_request_function_;
  

};

}

#endif