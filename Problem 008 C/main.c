#include <stdio.h>

#define ADJLEN 13

int main() {

    // Open File and Read
    FILE *file = fopen("D:\\Dropbox\\Code Projects\\Project Euler\\Problem 008 C\\number.txt", "r");

    if (file == NULL){
        printf("File could not be opened.\n");
        return 1;
    }

    int list[1000];
    int number;
    int length = 0;

    while(( number = fgetc(file)) != EOF){
        number = number - '0';

        if( number >= 0 && number <= 9){
            list[length] = number;
            length++;
        }
    }

    fclose(file);

    // Find greatest product

    int noPro = 1;      // There is no running product
    long long int maxPro = 0; // The max product

    for(int start = 0; start < length - ADJLEN - 1; ){

        long long int product;

        if(1 == noPro){
            noPro = 0; // False
            product = 1; // Restart sum

            for(int i = 0; i < ADJLEN; i++){
                product = product*list[start + i];

                if(0 == list[start + i]){
                    noPro = 1; // True
                    start = start + i + 1;
                    break;
                }
            }
        }

        if(0 == noPro){

            // Check Product against max
            if( maxPro < product){
                maxPro = product;
            }

            // Remove first element from product
            product = product/list[start];

            // Check the next element
            if(0 == list[start + ADJLEN]){
                noPro = 1;
                start = start + ADJLEN + 1;
            } else {
                product = product*list[start + ADJLEN];
                start++;
            }
        }
    }

    printf("%lli\n", maxPro);

    return 0;
}