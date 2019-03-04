#include<iostream>
#include "action.h"
#include "signal_handler.h"

using namespace test_signal;
// using test_signal::Action;
// using test_signal::SignalHandler;

int main(int argc, char** argv) {
    SignalHandler signal_handler(
        ActionEnum::SNAPSHOT,
        ActionEnum::STOP);
    Action action;

    action.SetActionFunction(signal_handler.GetActionFunction());

    int i = 0;
    while(1){
        //std::cout<<i<<std::endl;
        i++;
        if(action.GetRequestedAction() == ActionEnum::STOP){
            std::cout<<"STOP"<<std::endl;
            break;
        }
        if(action.GetRequestedAction() == ActionEnum::SNAPSHOT){
            std::cout<<"SNAPSHOT"<<std::endl;
            break;
        }
    }
    return 1;


}