#include <boost/thread.hpp>

#include "Caffe.hpp"


void increment()
{
    Caffe::Brew mode = Caffe::CPU;
    Caffe::set_mode(mode);
}

void increment2()
{
    Caffe::Brew mode = Caffe::GPU;
    Caffe::set_mode(mode);
}

void show(){
    if(Caffe::mode() == Caffe::CPU)
        std::cout << "threadid: "<<boost::this_thread::get_id()<<" mode:CPU"<<std::endl;
    if(Caffe::mode() == Caffe::GPU)
        std::cout << "threadid: "<<boost::this_thread::get_id()<<" mode:GPU"<<std::endl;
}


void thread_proc(int i)
{
    if(i%2)
        increment();
    else
        increment2();
    show();
}
 
int main(int argc, char* argv[])
{
    boost::thread_group threads;
    for (int i=0; i<5; ++i)
        threads.create_thread(boost::bind(&thread_proc,i));
    threads.join_all();
}
