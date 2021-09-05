// Encapsulation: AKA data encapsulation is a way of hiding access to variables so only data abstraction can retrieve the variables.
// private, protected and public are the keywords for Encapsulation.
// again private means that those members can only be accessed by the class the variables were defined in. No access given to derived classes.
// derived classes can see the protected members.

#include <iostream>
using namespace std;

class Adder {
    public: 
        // constructor
        Adder(int i=0) {
            total = i;
        }

        // interface to outside world
        void addNum(int number) {
            total += number;
        }

        // interface to outside world
        int getTotal() {
            return total;
        }

    private:
        // hidden data from outside world
        int total;
};

int main() {
    Adder a;

    a.addNum(10);
    a.addNum(20);
    a.addNum(30);

    cout << "Total " << a.getTotal() << endl;
    return 0;
}