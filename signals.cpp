#include <iostream>
#include <csignal>
#include <unistd.h>

using namespace std;

// signals are the interupts a program receives from the operating system.
// things like CTRL + C and such. list of interupts here https://www.tutorialspoint.com/cplusplus/cpp_signal_handling.htm

void signalHandler(int signum) {
    cout << "Interrupt signal ("<< signum << ") received. \n";

    // cleanup and close program stuff here
    // terminate program
    exit(signum);
}

int main(void) {
    // register signal SIGINT which is a preprocessor macro and signal handler which is a pointer to a function
    // SIGINT must have been defined in the csignal lib and signalHander is a pointer to a function
    signal(SIGINT, signalHandler); 

    // while(1) {
    //     cout << "Going to sleep..." << endl;
    //     sleep(1);
    // }

    int i=0;
    while(++i) {
      cout << "Going to sleep...." << endl;
      if( i == 3 ) {
         raise(SIGINT); // use raise to intentionally raise a signal interrupt
      }
      sleep(1);
   }

    return 0;
}