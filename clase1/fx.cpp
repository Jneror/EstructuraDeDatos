#include <iostream>
#include "fx.hpp"
using namespace std;

int min_of_array(int arr[], int n) {
    if (n == 0) {
        cout << "Arreglo vacío\n";
        return 0;
    }
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}