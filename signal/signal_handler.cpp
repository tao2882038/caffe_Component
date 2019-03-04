#include <boost/bind.hpp>
#include<iostream>

#include <signal.h>
#include <csignal>

#include "signal_handler.h"

namespace test_signal {

  static volatile sig_atomic_t got_sigint = false;
  static volatile sig_atomic_t got_sighup = false;
  static bool already_hooked_up = false;

  void handle_signal(int signal) {
    switch (signal) {
    case SIGHUP:
      std::cout << "signal:SIGHUP"<<std::endl;
      got_sighup = true;
      break;
    case SIGINT:
      got_sigint = true;
      std::cout << "signal:SIGINT"<<std::endl;
      break;
    }
  }

  void HookupHandler() {
    if (already_hooked_up) {
      std::cout << "Tried to hookup signal handlers more than once.";
    }
    already_hooked_up = true;

    struct sigaction sa;
    // Setup the handler
    sa.sa_handler = &handle_signal;
    // Restart the system call, if at all possible
    sa.sa_flags = SA_RESTART;
    // Block every signal during the handler
    sigfillset(&sa.sa_mask);
    // Intercept SIGHUP and SIGINT
    if (sigaction(SIGHUP, &sa, NULL) == -1) {
      std::cout << "Cannot install SIGHUP handler.";
    }
    if (sigaction(SIGINT, &sa, NULL) == -1) {
      std::cout << "Cannot install SIGINT handler.";
    }
  }

  // Set the signal handlers to the default.
  void UnhookHandler() {
    if (already_hooked_up) {
      struct sigaction sa;
      // Setup the sighub handler
      sa.sa_handler = SIG_DFL;
      // Restart the system call, if at all possible
      sa.sa_flags = SA_RESTART;
      // Block every signal during the handler
      sigfillset(&sa.sa_mask);
      // Intercept SIGHUP and SIGINT
      if (sigaction(SIGHUP, &sa, NULL) == -1) {
        std::cout << "Cannot uninstall SIGHUP handler.";
      }
      if (sigaction(SIGINT, &sa, NULL) == -1) {
        std::cout << "Cannot uninstall SIGINT handler.";
      }

      already_hooked_up = false;
    }
  }

SignalHandler::SignalHandler(ActionEnum::Enum SIGINT_action,
                             ActionEnum::Enum SIGHUP_action):
  SIGINT_action_(SIGINT_action),
  SIGHUP_action_(SIGHUP_action) {
  HookupHandler();
}

SignalHandler::~SignalHandler() {
  UnhookHandler();
}

ActionEnum::Enum SignalHandler::CheckForSignals() {
  if (got_sighup) {
    got_sighup = false;
    return SIGHUP_action_;
  }
  if (got_sigint) {
    got_sigint = false;
    return SIGINT_action_;
  }
  return ActionEnum::NONE;
}

ActionCallback SignalHandler::GetActionFunction() {
  return boost::bind(&SignalHandler::CheckForSignals, this);
}

}  // namespace 
