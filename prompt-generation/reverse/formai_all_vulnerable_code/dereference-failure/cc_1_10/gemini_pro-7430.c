//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_FIB_NUM 46

// Function to calculate the nth Fibonacci number
unsigned long long int fibonacci(unsigned int n) {
    unsigned long long int fib[MAX_FIB_NUM];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

// Function to generate a random Fibonacci number
unsigned int random_fibonacci() {
    unsigned int fib_num = rand() % MAX_FIB_NUM;
    return fibonacci(fib_num);
}

// Function to convert a Fibonacci number to a binary string
char *fibonacci_to_binary(unsigned long long int fib_num) {
    char *binary_str = malloc(sizeof(char) * MAX_FIB_NUM);
    int i = 0;
    while (fib_num > 0) {
        binary_str[i] = (fib_num % 2) + '0';
        fib_num /= 2;
        i++;
    }
    binary_str[i] = '\0';
    return binary_str;
}

// Function to visualize the binary representation of a Fibonacci number
void visualize_fibonacci(char *binary_str) {
    int len = strlen(binary_str);
    int num_rows = (int)ceil(len / 8.0);
    for (int i = 0; i < num_rows; i++) {
        for (int j = i * 8; j < (i + 1) * 8 && j < len; j++) {
            printf("%c", binary_str[j]);
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random Fibonacci number
    unsigned int fib_num = random_fibonacci();

    // Convert the Fibonacci number to a binary string
    char *binary_str = fibonacci_to_binary(fib_num);

    // Visualize the binary representation of the Fibonacci number
    visualize_fibonacci(binary_str);

    // Free the allocated memory
    free(binary_str);

    return 0;
}