#include <iostream>

using namespace std;

// preprocessors - directives that give instructions to the compiler to preprocess before compiler starts
// we know it's a preprocessor when we see '#'
// the #include preprocessor is for including header files into the source file (find libraries by name and put them into our session)

// #define will create a symbolic constants
#define PI 3.14951

int main() {
    cout << "Value of PI: " << PI << endl;

    return 0;
}



