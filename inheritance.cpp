#include <iostream>
using namespace std;

class Shape {
    public:
        void setWidth(int w) {
            width = w;
        }
        void setHeight(int h) {
            height = h;
        }
    protected: // protected means that the base class, Shape, and its derived classes, Rectangle, can access these variables
        int width;
        int height;

};

class PaintCost {
    public:
        int getCost(int area) {
            return area * 70;
        } 
};

// derived class
class Rectangle: public Shape, public PaintCost { // the access-specifier is private by default. usually do public 
                                // public all access types stay the same as the base class.
                                // protected inheritance will cause all public and protected member types to be protected 
                                // thus only the derived class will have access
                                // private inheritance will make everything private.
                                // a derived class can also inherit from multiple base classes.
    public:
        int getArea() {
            return (width * height);
        }
};

int main(void) {
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(10);

    cout << "The area of the rectangle is : " << Rect.getArea() << endl;

    cout << "The cost to cover with paint is : " << Rect.getCost(Rect.getArea()) << endl;
} 