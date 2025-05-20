//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

/*
  This program generates a fractal using modular arithmetic.
  The initial coefficients are randomly generated and the sequence
  is repeated multiple times to create a larger pattern.
  The final result is displayed in ASCII art.
*/

// modular arithmetic function
long long mod(long long a, long long b){
    long long m = a % b;
    if(m < 0){
        m += b;
    }
    return m;
}

// polynomial function
long long poly(long long n, long long a, long long b, long long c){
    return mod((a * n * n + b * n + c), 256);
}

// random number generator for initial coefficients
long long rand_coef(){
    return (rand() % 256);
}

// main function
int main(){
    srand(time(0)); // seed random number generator
    int size = 20; // size of the fractal
    int repeats = 3; // number of times to repeat the sequence
    long long a = rand_coef(); // random first coefficient
    long long b = rand_coef(); // random second coefficient
    long long c = rand_coef(); // random third coefficient
    int **fractal = (int **)malloc(size * sizeof(int *)); // allocate memory for fractal

    // loop to generate fractal
    for(int i=0; i<size; i++){
        fractal[i] = (int *)malloc(size * sizeof(int));
        for(int j=0; j<size; j++){
            long long sum = 0;
            long long n = i*size + j; // current index of sequence
            for(int k=0; k<repeats; k++){
                sum += poly(n, a, b, c);
                n = sum;
            }
            fractal[i][j] = mod(sum, 256);
        }
    }

    // loop to display fractal in ASCII art
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            char c = fractal[i][j];
            printf("%c", c); // ascii value to character conversion
        }
        printf("\n");
    }

    // free memory
    for(int i=0; i<size; i++){
        free(fractal[i]);
    }
    free(fractal);
    return 0;
}