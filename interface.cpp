#include <iostream>
using namespace std;

// Interfaces or abstract classes are classes that describe the behaviors of a C++ class without
// implementing the actual functionality of that class. Simplified, it's a class that will give 
// the general description of a class. Don't confuse abstraction with an abstract class. 
// Absraction is when you add class functions to control class members and properties which helps with controlling data.

// usually interface/abstract classes are meant to be a base class for others to inherit
class Shape {
    
    public:
        // pure virtual function providing interface framework.
        // having one virtual function will make this class an interface/abstract class.
        virtual int getArea() = 0;

        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }
        
    protected:
        int width;
        int height;

};

// Derived class. This will also be known as the concrete class since we're deriving this class to instantiate
// objects. Failure to implement/override the pure virtual functions will result in compilation error.
class Rectangle: public Shape {
    public:
        int getArea() {
            return (width * height);
        }
};

class Triangle: public Shape {
    public: 
        int getArea() {
            return (width * height) / 2;
        }
};

int main(void) {
    Rectangle Rect;
    Triangle Tri;

    Rect.setWidth(5);
    Rect.setHeight(9);

    // Print the area of the object.
   cout << "Total Rectangle area: " << Rect.getArea() << endl;

   Tri.setWidth(5);
   Tri.setHeight(7);
   
   // Print the area of the object.
   cout << "Total Triangle area: " << Tri.getArea() << endl; 
}