#include <stdio.h>

int pow(int x){

    return x*x;
}


int main() {

    int MAX = 1000;

    for(int a = 1; a < MAX; a++){
        for(int b = a; b < MAX; b++){
            for(int c = b; c < MAX; c++){
                if(MAX == a + b + c && pow(c) == pow(a)+pow(b)){
                    printf("a = %d\n b = %d\n c = %d\n", a, b, c);
                    printf("a*b*c = %d\n", a*b*c);
                    return 1;
                }
            }
        }
    }

    printf("Couldn't be found.\n");
    return 0;
}