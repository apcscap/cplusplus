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

    char* cvalue = NULL; // Pointer initialized with null
    cvalue = new char[20]; // Request memory for char of 20 characters

    delete [] cvalue; // Delete array pointed to by cvalue

    double** xyvalue = NULL; // Pointer initalized for a two dimensional array
    xyvalue = new double*[4]; // Allocate memory for a 1x4 array
    

    delete [] xyvalue; // Deleting a 2 dimensional array uses same syntax as one dimensional

    return 0;
}