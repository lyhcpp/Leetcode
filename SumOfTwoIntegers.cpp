//XOR for sum
#include <iostream>

using namespace std;

int getSum(int a, int b) {
    //a represents the carry
    //b represents the sum of two integers
    //if a=0, carry is 0 and the sum is b
    int temp;
    while (a != 0) {
        //temp saves the temporary sum
        temp = a ^ b;
        a = (a & b) << 1;
        b = temp;
    }
    return b;
}

int main() {
    int x = -4, y = -9;
    cout << getSum(x, y) << endl;
    return 0;
}