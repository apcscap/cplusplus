#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// templates are blueprints for classes and functions. 
// (alsmost confused it with classes. classes are blueprints for object instances)

// creating a template of a function 
template <typename T> // create a typename which is a placeholder for the datatype that we're accepting and returning
inline T const& Max(T const& a, T const& b) { // returning a reference of typename T (remember it's just a placeholder). also taking parameters of typename T as placeholders (also references).
    return a < b ? a:b; // implementing the actual body of a function
}

/* Can also be written in one line:
template <typename T> T const& Max(T const& a, T const& b) { 
    return a < b ? a:b;
}
*/

template <typename CT>
class Stack {
    private:
        vector<CT> elems; // create a vector list of elements that will contain our CT datatype
    public:
        // in public we're declaring our public functions, their parameters and return types

        void push(CT const&); // push an element onto the elements array
        void pop(); // pop an element which will remove the top element
        CT top() const; // returns the top element of typename CT

        bool empty() const { // a function that returns a bool if the elems array is empty or not
            return elems.empty();
        }
};

template <class CT> // here we're implementing the classes outside of the class template
void Stack<CT>::push(CT const& elem) { // properly define params
    // append copy (reference/alias) of passed element
    elems.push_back(elem);
}

template <class CT> 
void Stack<CT>::pop() { // we're specifying that we're initializing the function from the 'Stack<CT>' class template
    if(elems.empty()) {
        throw out_of_range("Stack<>::pop(); empty stack");
    }
    elems.pop_back(); // remove the last element
}

template <class CT>
CT Stack<CT>::top() const {
    if(elems.empty()) {
        throw out_of_range("Stack<>::pop(); empty stack");
    }
    return elems.back(); // returns copy of the last element
}



int main(void) {
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << endl; 

    double f1 = 13.5; 
    double f2 = 20.7; 
    cout << "Max(f1, f2): " << Max(f1, f2) << endl; 

    string s1 = "Hello"; 
    string s2 = "World"; 
    cout << "Max(s1, s2): " << Max(s1, s2) << endl; 
    
    try {
        Stack<int> intStack;  // stack of ints 
        Stack<string> stringStack;    // stack of strings 

        // manipulate int stack 
        intStack.push(7); 
        cout << intStack.top() <<endl; 

        // manipulate string stack 
        stringStack.push("hello"); 
        cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    } catch (exception const& ex) { 
        cerr << "Exception: " << ex.what() <<endl; 
        return -1;
    } 

    return 0;
}