#include <iostream>

using namespace std;

// preprocessors - directives that give instructions to the compiler to preprocess before compiler starts
// we know it's a preprocessor when we see '#'
// the #include preprocessor is for including header files into the source file (find libraries by name and put them into our session)

// #define will create a symbolic constants
// in the preprocessing the compiler will replace all symbols with the actual value
#define PI 3.14951

// can also use define to write mini functions
#define MIN(a, b) (a < b ? a : b)

// here we'll define a symbolic constant DEBUG
#define DEBUG

#define MKSTR(x) #x // the '#' before the x means that it will conver the x into a string

#define CONCAT(x, y) x ## y // the '##' is used to concatenate x and y

int main() {
    cout << "Value of PI: " << PI << endl;

    int x = 19;
    int y = 5; // must pass variables into MIN

    #ifdef DEBUG
        // note DEBUG must be declared before this if statement runs
        cerr << "Trace Inside main function" << endl;
    #endif

    #if 0
        // this part is commented and will not run
        cout << MKSTR(HELLO C++) << endl;
    #endif

    cout << "Min value is: " << MIN(x, y) << endl;

    cout << MKSTR(HELLO WORLD) << endl;
    int JOMAMMA = 100; // for the concatenation it will seek a variable rather a string
    cout << CONCAT(JO, MAMMA) << endl;

    cout << "Value of __LINE__ : " << __LINE__ << endl; // there are other preprocessing macros to use
    cout << "Value of __FILE__ : " << __FILE__ << endl;
    cout << "Value of __DATE__ : " << __DATE__ << endl;
    cout << "Value of __TIME__ : " << __TIME__ << endl;

    #ifdef DEBUG
        cerr << "Trace: Coming out of main function" << endl;
    #endif 

    return 0;
}



