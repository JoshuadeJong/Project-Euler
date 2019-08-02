#include <stdio.h>
#include <math.h>

int factorcount(int long n){
    int count = 0;

    for(long int i = 1; i <= ceil(sqrt(n)); i++){
        if(0 == n%i){
            count += 2;
        }
    }

    return count + 1;
}

int main() {

    int MAX = 500;
    long int index = 0;
    long int sum = 0;

    do{
        index = index + 1;
        sum = sum + index;
    } while(MAX > factorcount(sum));

    printf("number = %d\n", sum);
    return sum;
}