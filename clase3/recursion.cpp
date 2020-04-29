#include <iostream>
using namespace std;

//multiply
int mult_iter(int a, int b);
int mult_rec(int a, int b);

//palindrome
bool is_palindrome(string str);

//fib
int fibonacci(int a);
int fib_memo(int a);

//factorial
int facto(int a);

//towersOfHanoi
void move_towers(int disks, string source_tower, string dest_tower, string aux_tower);

//binary search
bool binary_search(int start, int end, int arr[], int x);

int main(int argc, char** argv) {
    if (argc > 1)
        cout << argv[1] << endl;

    cout << mult_iter(3, 4) << endl;
    cout << mult_rec(3, 4) << endl;
    cout << is_palindrome("holh") << endl;
    cout << fib_memo(40) << endl;
    cout << facto(4) << endl;
    move_towers(2, "S", "D", "AUX");

    int arr[] = {1, 2, 4, 7, 10, 11};
    int x = 10;
    cout << x << " founded: " << binary_search(0, 5, arr, x) << endl; 

    return 0;
}

bool binary_search(int start, int end, int arr[], int x) {
    if (start > end) {
        return false;
    }
    int mid = start + (end - start) / 2; //divide by 2
    if (arr[mid] == x) {
        return true;
    }
    if (arr[mid] > x) {
        return binary_search(start, mid-1, arr, x);
    }
    if (arr[mid] < x) {
        return binary_search(mid+1, end, arr, x);
    }
}

void print_move(int disk, string source, string dest) {
    cout << "Moving disk " << disk << " from " << source << " to " << dest << endl;
}

void move_towers(int disks, string source_tower, string dest_tower, string aux_tower) {
    if (disks == 1) {
        print_move(1, source_tower, dest_tower);
        return;
    }
    move_towers(disks-1, source_tower, aux_tower, dest_tower);
    print_move(disks, source_tower, dest_tower);
    move_towers(disks-1, aux_tower, dest_tower, source_tower);
}

int facto(int a) {
    if (a == 1 || a == 0) {
        return 1;
    }
    return facto(a-1) * a;
}

int fib_memo_aux(int a, int memo[]) {
    if (a == 0 || a == 1) {
        return 1;
    }
    if (memo[a] == 0) {
        memo[a] = fib_memo_aux(a-1, memo) + fib_memo_aux(a-2, memo);
    }
    return memo[a];
}

int fib_memo(int a) {
    int memo[a+1];
    for (int i = 0; i < a+1; i++) {
        memo[i] = 0;
    }
    return fib_memo_aux(a, memo);
}

int fibonacci(int a) {
    if (a == 0 || a == 1) {
        return 1;
    }
    return fibonacci(a-1) + fibonacci(a-2);
}

bool is_palindrome(string str) {
    if (str.size() == 0 || str.size() == 1) {
        return true;
    }
    if (str[0] == str[str.size()-1]) {
        return is_palindrome(str.substr(1, str.size()-2));
    }
    return false;
}

int mult_iter(int a, int b) {
    int res = 0;
    for (int i = 0; i < a; i++) {
        res += b;
    }
    return res;
}

int mult_rec(int a, int b) {
    if (a == 1) {
        return b;
    }
    return b + mult_rec(a-1, b);
}