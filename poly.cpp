#include <iostream>

using namespace std;

// NOTE: polymorphism means that the method calls in base and derived classes will vary depending on the type of class

class Shape {
    protected:
        int width, height;
    
    public:
        Shape(int a=0, int b=0) { // this is an init constructor for Shape
            width = a;
            height = b;
        }
        virtual int area() {    // without the virtual keyword, the area() method is fixed or binded in the compiler thus it won't change. It will instead run the base class method
                                // sometimes we may intialize a Shape class with a derived class since they will have the same defined methods and variables
                                // according to the rules of inheritance. When we initliaze Shape with a derived class, the derived class may have modified a function
                                // area() thus the compiler won't recognize it since the base area() method is fixed in memory. Terms for this are static resolution or 
                                // static linkage. NOTE: This virtual keyword will only work if Shape is a pointer to an address of a derived class.

            cout << "Parent class area : " << endl;
            return 0;
        }

        // pure virtual method
        virtual int permimeter() = 0;
};

class Rectangle: public Shape {
    public:
        Rectangle(int a=0, int b=0): Shape(a, b) { }    // pass the parameters a and b to the Shape constructor which was inherited from the Shape base class
                                                        // this will intialize the width and height members for us. The empty {} are for if we want to intialize anything else.

        int area() {
            cout << "Reactangle class area: " << (width * height) << endl;
            return (width * height);
        }

        int permimeter() {
            return 2 * (width + height);
        }
};

class Triangle: public Shape {
    public:
        Triangle(int a=0, int b=0): Shape(a, b) { }

        int area() {
            cout << "Triangle class area: " << (width * height) / 2 << endl;
            return (width * height / 2);
        }

        int permimeter() {
            return 0;
        }
};

int main() {
    Shape *shape;
    Rectangle rec(10, 7);
    Triangle tri(10, 5);

    shape = &rec;

    shape->area();

    shape = &tri;

    shape->area();
    
    return 0;
}