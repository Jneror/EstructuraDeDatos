#include <iostream>
#include <cstdio>
using namespace std;

//if else

int main() {
    cout << "Insert a number: ";
    int num;
    cin >> num;
    //check parity
    if (num % 2 == 0) {
        cout << num << " is even\n";
    }
    else {
        cout << num << " is odd\n";
    }
    //check sign
    if (num > 0) {
        printf("%d is positive\n", num);
    }
    else if (num < 0) {
        printf("%d is negative\n", num);
    }
    else {
        printf("zero\n");
    }
    return 0;
}