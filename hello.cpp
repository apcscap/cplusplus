#include <iostream>
using namespace std;

// main() program begins execution here
int main() {
    cout << "Hello World" << endl; // print func

    cout << "Size of char : " << sizeof(char) << endl; // sizeof gives size of var type in bytes
    cout << "Size of int : " << sizeof(int) << endl; // endl inserts a '\n' after every line
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

    

    return 0;
}