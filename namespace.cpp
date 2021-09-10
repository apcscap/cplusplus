#include <iostream>

using namespace std;

// good and bad practice for namespace https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice?rq=1
// namespace defines a scope for your variables so functions, classes, vars with the same name don't confuse the compiler
// NOTE: the rule of scopes apply and which methods and classes have access to the namespace

// writing namespace structs can declare a new namespace or add to an already existing one
// this allows for multiple files to contribute to the same namspace

// first namespace
namespace first_space {
    void func() {
        cout << "namespace first_space" << endl;
    }
}

namespace second_space {
    void func() {
        cout << "namespace second_space" << endl;
    }
}

namespace x {
    void func() {
        cout << "Inside space x" << endl;
    }
    namespace y {
        void funct() {
            cout << "Inside space y" << endl;
        }
    }
}

using namespace first_space; // this tells the compiler that we're using these funtions 
using std::cout; // doesn't have to be a whole namespace but a single function in a namespace
using namespace x::y; // how to access func in nested namespace

int main(void) {
    // Calls the function located inside first_space. Access func with '::'
    first_space::func();

    // Calls the funnction located inside second_space.
    second_space::func();

    func(); // will use the func from first_space since we told compiler we're using this

    cout << "Hello World!" << std::endl;

    funct();

    return 0;
}