#include <iostream>
#include <cstdio>
using namespace std;

//loops

int main() {
    int arr[] = {1, 2, 4, 8, 6, 7, 9, 21};
    int n = 8;
    //check factors of 3
    cout << "Multiples of 3:";
    int cont = 0;
    while (cont < n) {
        if (arr[cont] % 3 == 0) {
            printf(" %d", arr[cont]);
        }
        cont++;
    }
    cout << endl;
    //check multiple of 7
    cout << "Multiples of 7:";
    for (int i = 0; i < n; i++) {
        if (arr[i] % 7 == 0) {
            printf(" %d", arr[i]);
        }
    }
    cout << endl;
    //check even numbers
    cout << "Even numbers:";
    for (int num: arr) {
        if (num % 2 == 0) {
            printf(" %d", num);
        }
    }
    cout << endl;
    return 0;
}