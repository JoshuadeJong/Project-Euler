#include <stdio.h>

unsigned long int main() {

    unsigned long int MAX = 1000000;
    unsigned long int max_num = 0;
    unsigned long int max_chain = 0;

    //unsigned long int store[MAX];

    for(unsigned int i = 1; i < MAX; i++){
        unsigned long int count = 0;
        unsigned long int n = i;

        while(1 != n){

            if( 0 == n%2){
                n = n/2;
            } else {
                n = 3*n + 1;
            }

            count++;

            // Check table
            /*
            if(n < i){
                count = count + store[n-1];
                n = 1;
            }
            */
        }

        // Update Table
        //store[i-1] = count;


        if(max_chain < count){
            max_num = i;
            max_chain = count;
        }
    }

    printf("max_num = %lu, max_chain = %lu\n", max_num, max_chain);

    return max_num;
}