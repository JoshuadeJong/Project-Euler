#include <stdio.h>

int main() {

    int MAX_N = 21;
    int MAX_M = 21;
    unsigned long long int table[MAX_M][MAX_N];

    for(int i = 0; i < MAX_M || i < MAX_N; i++){
        if(i < MAX_M){
            table[i][0] = 1;
        }

        if(i < MAX_N){
            table[0][i] = 1;
        }
    }

    for(int i = 1; i < MAX_M; i++){
        for(int j = 1; j < MAX_N; j++){
            table[i][j] = table[i-1][j] + table[i][j-1];
        }
    }

    // PRINT
    /*
    for(int i = 0; i < MAX_M; i++){
        for(int j = 0; j < MAX_N; j++){
            printf("  %lu", table[i][j]);
        }
        printf("\n");
    }
    */

    printf("%llu\n", table[MAX_M-1][MAX_N-1]);

    return 1;
}