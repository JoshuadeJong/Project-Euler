#include <stdio.h>

#define ADJLEN 4

int main() {

    ///// Open File and Read
    FILE *file = fopen("D:\\Dropbox\\Code Projects\\Project Euler\\Problem 011 C\\number.txt", "r");

    if (file == NULL){
        printf("File could not be opened.\n");
        return 1;
    }

    // Find Size
    int rowS;
    int colS;

    fscanf(file, "%d %*s %d", &rowS, &colS);

    // Find elements
    int list[rowS][colS];
    int number;
    int length = 0;

    while(( fscanf(file, "%d", &number) == 1)){
        list[length/rowS][length%colS] = number;
        length++;
    }

    fclose(file);

    ///// Search
    int max = 0;
    int product;

    for(int i = 0; i < rowS; i++){ // Starting Position Row
        for(int j = 0; j < colS; j++){ // Starting Position Column
            // Horizontal
            if( j < colS - ADJLEN){
                product = 1;

                for(int k = 0; k < ADJLEN; k++){
                    product = product*list[i][j+k];
                }

                if(max < product){
                    max = product;
                }
            }

            // Vertical
            if( i < rowS - ADJLEN) {
                product = 1;

                for (int k = 0; k < ADJLEN; k++) {
                    product = product * list[i + k][j];
                }

                if (max < product) {
                    max = product;
                }
            }

            // Diagonal
            if(i < rowS - ADJLEN && j < colS - ADJLEN){
                product = 1;

                for(int k = 0; k < ADJLEN; k++){
                    product = product*list[i+k][j+k];
                }

                if(max < product){
                    max = product;
                }
            }

            // Anti-Diagonal
            if( i > ADJLEN - 1 && j < colS - ADJLEN) {
                product = 1;

                for (int k = 0; k < ADJLEN; k++) {
                    product = product * list[i - k][j + k];
                }

                if (max < product) {
                    max = product;
                }
            }
        }
    }

    printf("Max is %d\n", max);

    return 0;
}