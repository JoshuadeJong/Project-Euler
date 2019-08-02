#include <stdio.h>
#include <math.h>

int isPrime(int test);

int main() {

    long long int sum = 2; // two is the only even prime number
    int max = 2000000;

    for(int n = 3; n < max; n = n + 2){

        if(1 == isPrime( n)){
            sum = sum + n;
        }
    }

    printf("The sum is %lli\n", sum);

    return 0;
}

int isPrime(int n){
    int calculateTo = (int) sqrt(n);

    for(int i=3; i<=calculateTo; i+=2){
        if(n%i==0)
            return 0;
    }

    return 1;
}
