#include <iostream>
using namespace std;

int main() {
    //arreglo de 10 celdas
    int arr[5];
    //indexar
    arr[0] = 1;
    //llamar valor en arreglo
    arr[1] = arr[0] + 1;
    //pedir valores al usuario
    for(int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    cout << "a o k" << endl;
    return 0;
}