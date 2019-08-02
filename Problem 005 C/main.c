#include <stdio.h>
#include <stdlib.h>

// Defines
#define MIN 1
#define MAX 10
#define DELTA 1
#define LENGTH (MAX - MIN)/DELTA


// General
void swap(int *n, int *m);

// Math Functions
int gcd(int n, int m);
int lcm(int n, int m);

// List functions
int * list();

int main() {

    /*  Question
        2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
        What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/

    int *numList = list();

    int i;
    for(i = 1; i < LENGTH; i++){
        *(numList + i) = lcm(*(numList + i), *(numList + i - 1));
    }

    printf("The smallest positive number that evenly divides all the "
           "numbers from %d to %d by %d is %d.\n", MIN, MAX, DELTA, *(numList + i - 1));

    return *(numList + i - 1);
}

// General
void swap(int *n, int *m){
    int temp = *n;
    *n = *m;
    *m = temp;
}

// Math Functions
int gcd(int n, int m) {

    do{
        while(m >= n){
            m -= n;
        }

        swap( &n, &m);
    }while(n > 0);

    return m;
}

int lcm(int n, int m) {
    return (n*m)/(gcd(n,m));
}

// List Functions
int * list(){

    static int numList[LENGTH];
    numList[0] = MIN;

    for(int i = 1; i <= LENGTH; i++){
        numList[i] = numList[i-1] + DELTA;
    }

    return numList;
}