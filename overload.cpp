#include <iostream>

using namespace std;

class printData {
    // C++ classes have function or operator overloading which is when functions have the same name as another but different arguments.
    // These functions, although with same name, can do different things. The compiler determines the correct function to use by 
    // matching the arguments in a process called overload resolution.
    public:
        void print(int i) {
            cout << "Printing int: " << i << endl;
        }
        void print(double f) {
            cout << "Printing double: " << f << endl;
        }
        void print(string s) {
            cout << "Printing string: " << s << endl;
        }
};

int main(void) {
    printData pd;
 
    // Call print to print integer
    pd.print(5);
    
    // Call print to print float
    pd.print(500.263);
    
    // Call print to print character
    pd.print("Hello C++");

    return 0;
};