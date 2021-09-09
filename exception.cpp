#include <iostream>

using namespace std;

// Exceptions useful because it can transfer control of a block of code to another.
// Thus your code has extra protection.

double division(int a, int b) {
    if (b==0) {
        throw "Division by zero condition!";    // throwing an error of type char* will cause the catch handler to run it's code
                                                // in other words it will throw a pointer to the char
                                                // list of exceptions https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
    }
    return a/b;
}

int main(void) {
    int x = 50;
    int y = 0;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    } catch (const char* msg) { // we're writing an exception in which the err thrown will be a char*
        cout << msg << endl;
    }

    return 0;
}