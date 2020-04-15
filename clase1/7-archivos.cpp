#include <iostream>
#include <fstream>
using namespace std;

int main() {
    //writing file
    ofstream file1 ("example.txt");
    if (file1.is_open()) {
        file1 << "ola ke ase\nke creisi\n";
        file1.close();
    }
    //reading file line by line
    ifstream file2 ("example.txt");
    string line;
    if (file2.is_open()){
        while(getline(file2, line)) {
            cout << line << endl;
        }
        file2.close();

    }
    //reading file string by string
    fstream file3 ("example.txt", ios::in);
    string str;
    if (file3.is_open()) {
        while(file3 >> str) {
            cout << str << " ";
        }
    }
    cout << endl;
    //reading file char by char
    fstream file4 ("example.txt", ios::in);
    char ch;
    if (file4.is_open()) {
        while (file4 >> noskipws >> ch) {
            cout << ch << " ";
        }
        file4.close();
    }
    cout << endl;
    return 0;
}