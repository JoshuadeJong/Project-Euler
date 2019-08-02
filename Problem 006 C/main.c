#include <stdio.h>

int sumSquare(int n);
int sumInteger(int n);


int main() {
/*  Question
    The sum of the squares of the first ten natural numbers is,
            12 + 22 + ... + 102 = 385
    The square of the sum of the first ten natural numbers is,
            (1 + 2 + ... + 10)2 = 552 = 3025
    Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
    Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
    int n = 100;

    int output = sumInteger(n)*sumInteger(n) - sumSquare(n);

    return output;
}

int sumSquare(int n){
    return (n*(n + 1)*(2*n + 1))/6;
}

int sumInteger(int n){
    return (n*(n+1))/2;
}