#include <fstream>
#include <iostream>

using namespace std;

// ofstream - object for writing to files and creating them
// ifstream - object for reading files
// fstream can do both ofstream and ifstream

int main(void) {

    char data[100];

    // ios::<flag> are commands for how the file should be read
    // app - all output will be appended to the end
    // ate - move read and write control to the end of the file
    // in - regular open file for reading
    // out - open a file for writing
    // trunc - if a file exists then remove all of the contents

    ofstream outfile;
    outfile.open("file.txt", ios::out | ios::trunc); // the | symbol will combine the two actions. open the file for writing and remove contents of old file if exists.

    cout << "Writing to a file" << endl;
    cout << "Enter your name: ";
    cin >> data;

    // write inputted data to the file
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();

    // again write the inputted data to the file
    outfile << data << endl;

    // close the outfile file
    outfile.close();

    // open a file in read mode
    ifstream infile;
    infile.open("file.txt", ios::in);

    cout << "Reading info from file." << endl;
    infile >> data; // read one line at a time. starts from the beginning of the file

    // write that data to the screen.
    cout << data << endl;

    // again write that data to the screen.
    infile >> data; // every '>>' will move the cursor to the next line to read
    cout << data << endl;

    // position to the nth byte of fileObject (assumes ios::beg)
    infile.seekg( 1 ); // moves the pointer to the address where the first byte is located in the file
    infile >> data;
    cout << data << endl;

    // position n bytes forward in fileObject
    infile.seekg( 0, ios::cur );

    // position n bytes back from end of fileObject
    infile.seekg( 1, ios::end );

    // position at end of fileObject
    infile.seekg( 0, ios::end );

    infile.close();

    // fstream afile;
    // afile.open("afile.txt", ios::out | ios::in);

    return 0;
}


