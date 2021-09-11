#include <iostream>
#include <string>

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
    
    return 0;
}