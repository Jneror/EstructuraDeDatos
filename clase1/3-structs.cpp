#include <iostream>
using namespace std;

struct person {
    string name;
    int age;
};

int main() {
    person pedrito;
    pedrito.name = "Pedro";
    pedrito.age = 19;
    cout << pedrito.name << endl;
    cout << pedrito.age << endl;
    person user;
    cout << "Insert your name: ";
    cin >> user.name;
    cout << "Insert your age: ";
    cin >> user.age;
    return 0;
}