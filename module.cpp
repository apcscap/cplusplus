#include <iostream>

extern int _counter; // this _counter var will refer to the global var declared in hello.cpp

void write_extern(void) { // here we initialize the write_extern func declared in hello.cpp
    std::cout << "Count is " << _counter << std::endl;
}