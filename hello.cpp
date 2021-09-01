#include <iostream>
#include <ctime> // for the time
#include <cstdlib> // probably to get the rand lib
#include <iomanip> // 

using namespace std;
using std::setw; // use std::setw so that setw func is available when we std::cout

int num; // extern keyword says that variable will be 

void func(void); // declare func and declare param type
static int counter = 10; // Global var

int _counter;
extern void write_extern(); // use extern for reference of a global var or func. can only be used for init
                            // can also be written as void write_extern(void) but module.cpp write_extern will have 'extern' keyword

int max(int num1, int num2); // declare a function and param names and types
void swap_pointer(int *num1, int *num2); // declare a func with pointer var
void swap_reference(int &num1, int &num2);

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

    _counter = 5; // set global _counter var to five. will be accessible to module 
    write_extern(); // write_extern declared as a global var in hello.cpp but initialized as void method in module.cpp

    /*
    A = 0011 1100
    B = 0000 1101
    -----------------
    A&B = 0000 1100 '&' operator will copy bit '1' if exist in both. result: 12 (0000 1100)
    A|B = 0011 1101 '|' operator will copy bit '1' if exist in either. result: 61 (0011 1101)
    A^B = 0011 0001 '^' XOR operator will copy bit '1' if exist in one but not other. result: 49 (0011 0001)
    ~A  = 1100 0011 '~' Ones Complement operator will flip bit. result -61 (1100 0011)
    A << 2 = 1111 0000 '<<' left shift operator will shift all bits to the left as specified (plus carried over to other end). result: 240 (1111 0000)
    A >> 2 = 0000 1111 '>>' right shift operator will shift all bits to the right as specified (plus carried over to other end). result: 15 (0000 1111)
    */

    for (int a = 10; a < 20; a = a + 1) { // put it here so i know how to do a for loop :)
        cout << "value of a: " << a << endl;
    }

    int flip = 1;
    
    char grade = 'A'; // love it, want it, need it
    switch(grade) { // example of a switch in c++
        case 'A' :
         cout << "Excellent!" << endl; 
         break; // put break to finish statement. this is optional
      case 'B' :
      case 'C' :
         cout << "Well done" << endl;
         break;
      case 'D' :
         cout << "You passed" << endl;
         break;
      case 'F' :
         cout << "Better try again" << endl;
         break;
      default :
         cout << "Invalid grade" << endl;
    }
    cout << "Your grade is : " << grade << endl;

    bool reward;
    reward = grade == 'A' ? true : false; 
    cout << "I am getting rewarded : " << to_string(reward) << endl;

    int a = 100;
    int b = 200;
    int res;

    res = max(a, b);
    cout << "Max value is : " << res << endl;

    swap_pointer(&a, &b); // how to pass in var for a func with pointers 

    cout << "After swap, value of a :" << a << endl; // a = 200
    cout << "After swap, value of b :" << b << endl; // b = 100 there was a swap in pointers

    a = 100; // reset a and b
    b = 200;

    swap_reference(a, b); // pass in var with function that has reference type for param

    cout << "After swap, value of a :" << a << endl; // a = 200
    cout << "After swap, value of b :" << b << endl; // b = 100 there was a swap by changing the reference

    // number definitions:
    short s;
    int _i;
    long l;
    float f;
    double d;

    // number assignments:
    s = 10;
    _i = 1000; // max : 32767 (*2 if unsigned)
    l = 1000000;
    f = 230.47;
    d = 20949.374;

    // there are also the math/trig funcs

    // set seed of rand func
    srand( (unsigned) time(NULL) ); // type casting

    int randNum = rand(); // generate a rand number by calling function
    cout << "Random number : " << randNum << endl;

    double balance[5] = {1000.0, 2.0, 3.5, 17.0, 50.0}; // specifying the array size between [] is not required.
    cout << "Balance at index 4 (last value) : " << balance[4] << endl;

    return 0;
}

void func( void ) {
    static int i = 5; // this is the local static variable. rather than the variable be destroyed, it is maintained in memory.
    i++;
    std::cout << "i is " << i;
    std::cout << " and count is " << counter << std::endl;
}

int max(int num1, int num2=20) { // can also add default value for func param
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}

void swap_pointer(int *num1, int *num2) { // the '*' will pass the var pointer thus the setters will change the value the pointer in the var points to.
    int temp;

    temp = *num1; /* save the value at address x */
    *num1 = *num2; /* put num2 into num1*/
    *num2= temp; /* put num1 into num2 */

    return;
}

void swap_reference(int &num1, int &num2) { // the '&' will copy the reference of the vars that are passed in when the func is called. essentially imagine the original vars replacing the param names
    int temp;

    temp = num1; 
    num1 = num2;
    num2 = temp;

    return;
}