#include <iostream>
#include <ctime> // for the time
#include <cstdlib> // probably to get the rand lib
#include <iomanip> // 

using namespace std;
using std::setw; // use std::setw so that setw func is available when we std::cout

int num; // extern keyword says that variable will be 

const int MAX = 3;

void func(void); // declare func and declare param type
static int counter = 10; // Global var

int _counter;
extern void write_extern(); // use extern for reference of a global var or func. can only be used for init
                            // can also be written as void write_extern(void) but module.cpp write_extern will have 'extern' keyword

int max(int num1, int num2); // declare a function and param names and types
void swap_pointer(int *num1, int *num2); // declare a func with pointer var
void swap_reference(int &num1, int &num2);

double getAverage(double arr[], int size); // declare a func that take array as param.

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

    int n[10];

    for(int i=0; i<10;i++) {
        n[i] = i + 100;
    }
    cout << "Element" << setw(13) << "Value" << endl;

    for(int j=0; j<10; j++) {
        cout << setw(7) << j << setw(13) << n[j] << endl;
    }

    int matrix[8][8]; // two-dimensional arrays still work

    // an array with 5 elements.
    double bal[5] = {1000.0, 2.0, 3.4, 17.0, 50.0};
    double *p; // create a double var and indicate that it will be a pointer

    p = bal; // have the pointer point to the location of the balance array
    
    // output each array element's value 
    cout << "Array values using pointer " << endl;
    
    for ( int i = 0; i < 5; i++ ) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;   // *(p + i) will get the address the pointer is pointing and add a byte (+i) for incrementing. 
                                    // the pointer expression will point to the location of element in the array and retrieve the value.   
    }

    cout << "Array values using balance as address " << endl;
    
    for ( int i = 0; i < 5; i++ ) {
        cout << "*(balance + " << i << ") : ";
        cout << *(balance + i) << endl;     // *(balance + i) will get the address of the array and like the pointer method point to 
                                            // value inside of the array by accessing the address next to the first element in the array
                                            // by incrementing one byte at a time.
    }
    double avg = getAverage(bal, 5);
    cout << "Average of balance : " << avg << endl;

    // how to return an array with pointers
    // https://www.tutorialspoint.com/cplusplus/cpp_return_arrays_from_functions.htm

    char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // C-style string from the c language
    char greeting2[] = "Hello";

    cout << "Greeting message : " << greeting << endl; 

    /* Functions with strings stored in a char array
        strcpy(s1, s2) -> copies s2 into string 1
        strcat(s1, s2) -> s1 + s2
        strlen(s1) -> gets length of string
        strcomp(s1, s2) -> returns 0 if the strings are equal. <0 if s1<s2. >0 if s1>s2
        strchr(s1, ch) -> returns pointer to first occurence of char ch in string s1
        strstr(s1, s2) -> returns first occurance of s2 in s1 
    */

    // well there's also a string class that does all of the above ^
    string str1 = "Hello";
    string str2 = "World";
    string str3;

    // copy str1 into str3
    str3 = str1;
    cout << "str3 : " << str3 << endl;

    // concatenates str1 and str2
    str3 = str1 + str2;
    cout << "str1 + str2 : " << str3 << endl;

    // total length of str3 after concatenation
    int len = str3.size();
    cout << "str3.size() :  " << len << endl;

    int  var1;
    char var2[10];

    cout << "Address of var1 variable: ";
    cout << &var1 << endl; // the & sign will allow access to the address of the variable

    cout << "Address of var2 variable: ";
    cout << &var2 << endl;

    // a pointer in c++ and in many other languages is a variable whose value is the address of another variable.
    int *ip; // pointer denoted by '*' to a variable that stores integers. pattern is same for other variable types

    int nump = 20;

    ip = &nump; // store the address of the nump variable in ip

    cout << "Value of nump variable : " << nump << endl;

    cout << "Address stored in ip variable : " << ip << endl;

    cout << "Value of *ip variable : " << *ip << endl; // access the value of address stored in the ip variable.

    int *pointer = NULL; // will set the address value of the pointer to 0. in if statement conditions will be true if there's a 
                        // val in the pointer

    int  var[MAX] = {10, 100, 200};
    int  *ptr;

    // let us have array address in pointer.
    ptr = var;
    
    // poinnter arithmetic: ++, --, +, - . It's pretty intuitive. Cap figure it out.
    for (int i = 0; i < MAX; i++) {
        cout << "Address of var[" << i << "] = ";
        cout << ptr << endl; // print the address of the variable 

        cout << "Value of var[" << i << "] = ";
        cout << *ptr << endl; // prints the value of the variable stored at the address in the pointer

        // point to the next location
        ptr++; // adds a byte to access the adjacent address and gets the next value in the array 
    }
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

double getAverage(double arr[], int size) { // won't need size if we already know the size of the array. Ex: arr[10]. Can also take array as a pointer such as '*arr'
    int i, sum = 0;       
    double avg;          

    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }
    avg = double(sum) / size;

    return avg;
}