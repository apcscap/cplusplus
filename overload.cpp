#include <iostream>

using namespace std;

class printData {
    // C++ classes have function or operator overloading which is when functions have the same name as another but different arguments.
    // These functions, although with same name, can do different things. The compiler determines the correct function to use by 
    // matching the arguments in a process called overload resolution.
    public:
        void print(int i) {
            cout << "Printing int: " << i << endl;
        }
        void print(double f) {
            cout << "Printing double: " << f << endl;
        }
        void print(string s) {
            cout << "Printing string: " << s << endl;
        }
};

class Box {
    public:
        double getVolume(void) {
            return length * breadth * height;
        }
        void setLength( double len ) {
            length = len;
        }
        void setBreadth( double bre ) {
            breadth = bre;
        }
        void setHeight( double hei) {
            height = hei;
        }
        Box operator+(const Box& b) {   // the overloaded operator function doesn't have to be a class member.
                                        // it can be a non-class function but there will need to be two box parameters
                                        // in this case the operator is taking a REFERENCE of the box object being added
            Box box;
            box.length = this->length + b.length; // seems here that to refer to self or the current (this) box object we use a pointer
            box.breadth = this->breadth + b.breadth;
            box.height = this->height + b.height;
            
            return box;
        }

    private:
        double length;
        double breadth;
        double height;
};

int main(void) {
    printData pd;
 
    // Call print to print integer
    pd.print(5);
    
    // Call print to print float
    pd.print(500.263);
    
    // Call print to print character
    pd.print("Hello C++");

    Box Box1;
    Box Box2;
    Box Box3;
    double volume = 0.0;

    // box 1 specification
    Box1.setLength(6.0); 
    Box1.setBreadth(7.0); 
    Box1.setHeight(5.0);
    
    // box 2 specification
    Box2.setLength(12.0); 
    Box2.setBreadth(13.0); 
    Box2.setHeight(10.0);

    // volume of box 1
    volume = Box1.getVolume();
    cout << "Volume of Box1 : " << volume <<endl;

    // volume of box 2
    volume = Box2.getVolume();
    cout << "Volume of Box2 : " << volume <<endl;

    // Add two objects together
    Box3 = Box1 + Box2;

    // volume of Box3
    // volume of box 2
    volume = Box3.getVolume();
    cout << "Volume of Box3 : " << volume <<endl;

    return 0;
};