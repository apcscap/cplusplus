#include <iostream>
using namespace std;

int num; // extern keyword says that variable will be 

void func(void); // declare func
static int counter = 10; // Global var

// main() program begins execution here
int main() {
    cout << "Hello World" << endl; // print func

    cout << "Size of char : " << sizeof(char) << endl; // sizeof gives size of data type in bytes
    cout << "Size of int : " << sizeof(int) << endl; // endl inserts a '\n' after every line
    cout << "Size of short int : " << sizeof(short int) << endl;
    cout << "Size of long int : " << sizeof(long int) << endl;
    cout << "Size of float : " << sizeof(float) << endl;
    cout << "Size of double : " << sizeof(double) << endl;
    cout << "Size of wchar_t : " << sizeof(wchar_t) << endl;

    typedef int feet; // can create a new type of variable with new name
    feet distance = 4;
    cout << "Distance : " << distance << endl;

    enum color { red, green=5, blue } c; // enumeration type allows us to switch values based on the type name init in the {}
    c = green;
    cout << "Enum c is : " << c << endl; // prints out 5
    c = blue;
    cout << "Enum c is : " << c << endl; // prints out 6 (default prints index of enum name in {_} but will print value higher than previous as well)

    num = 17;
    cout << "num is : " << num << endl;

    const feet LENGTH = 10; // create a constant var AKA literal
    cout << "length is : " << LENGTH << endl;

    // char, int, and double can have modifers signed, unsigned, long, short
    short int i;
    short unsigned int j;

    j = 50000;
    i = j;
    cout << i << " " << j << endl;

    auto int month; // auto is a storage type meaning only local scope
    register int miles = 100000000; // register for local var but max size equal to reg size usually one word
    while(counter--) {
        func();
    }

    return 0;
}

void func( void ) {
    static int i = 5; // this is the local static variable. rather than the variable be destroyed, it is maintained in memory.
    i++;
    std::cout << "i is " << i;
    std::cout << " and count is " << counter << std::endl;
}