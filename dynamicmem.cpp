#include <iostream>

using namespace std;

// the stack - variables declared in a function will be stored in the stack for functions to use
// the heap - free memory that will be dynamically allocated when programs run

int main(void) {
    double* pvalue = NULL; // Pointer initialized with null

    if(!(pvalue = new double)) { // dynamically allocate memory to the pointer and then check if the pointer is still null
        cout << "Error: out of memory." << endl;
        exit(1);
    }

    pvalue = new double; // Request memory for the variable for any datatype. (in this case double since that's the pointer's data type)

    double* qvalue = NULL;
    qvalue = new double;

    *qvalue = 2969.56; // store value at allocated address
    cout << "Value of pvalue: " << *qvalue << endl;

    delete qvalue; // free up memory

    return 0;
}