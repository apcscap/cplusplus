// two types of threading. process-based multi tasking - allow two or more programs to run concurrently.
// then there's thread-multitasking which allows two peices of code to execute in the same program.

// c++ uses the operating system to perform threading
// the library to write threading code is POSIX or pthread
#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) { // define a func that RETURNS a POINTER and TAKES a POINTER PARAM of void datatype
    long tid;
    tid = (long)threadid; // cast the param as a long datatype
    cout << "Hello World! Thread ID, " << tid << endl; // print it
    pthread_exit(NULL); // then end the executable thread 
}

int main () {
    pthread_t threads[NUM_THREADS]; // create an NUM_THREADS sized array of pthread obj
    int rc;
    int i; // counter
    
    for( i = 0; i < NUM_THREADS; i++ ) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);  // create a thread passing in reference to init. threads[i] obj
                                                                        // NULL for thread attributes
                                                                        // the pointer func/routine that will be executed once the process is finished
                                                                        // then the single argument which is passed in as a VOID POINTER 
        
        if (rc) { // check if we can create the thread
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL); // exit all threads
    
    return 0;
}