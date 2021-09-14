// two types of threading. process-based multi tasking - allow two or more programs to run concurrently.
// then there's thread-multitasking which allows two peices of code to execute in the same program.

// c++ uses the operating system to perform threading
// the library to write threading code is POSIX or pthread
#include <iostream>
#include <pthread.h>
#include <cstdlib>

using namespace std;

#define NUM_THREADS 5

void *PrintHello(void *threadid) {
    long tid;
    tid = (long)threadid;
    cout << "Hello World! Thread ID, " << tid << endl;
    pthread_exit(NULL);
}

int main () {
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;
    
    for( i = 0; i < NUM_THREADS; i++ ) {
        cout << "main() : creating thread, " << i << endl;
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);
        
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}