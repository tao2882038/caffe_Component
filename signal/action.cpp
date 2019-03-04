#include "action.h"

namespace test_signal {

Action::Action(){}

void Action::SetActionFunction(ActionCallback func) {
  action_request_function_ = func;
}

ActionEnum::Enum Action::GetRequestedAction() {
  if (action_request_function_) {
    // If the external request function has been set, call it.
    return action_request_function_();
  }
  return ActionEnum::NONE;
}

}