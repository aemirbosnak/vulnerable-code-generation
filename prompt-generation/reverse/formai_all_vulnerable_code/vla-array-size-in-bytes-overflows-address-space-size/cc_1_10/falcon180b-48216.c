//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_TERMS 10000
#define MAX_DIGITS 1000

// Function to print a number with a given number of digits
void print_number(int n, int digits) {
    char buffer[MAX_DIGITS];
    int i = digits - 1;
    while (n > 0 && i >= 0) {
        buffer[i] = n % 10 + '0';
        n /= 10;
        i--;
    }
    while (i >= 0) {
        buffer[i] = '0';
        i--;
    }
    printf("%s", buffer);
}

// Function to calculate the nth term of the Fibonacci sequence
int fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return a;
}

// Function to generate a random number with a given number of digits
int random_number(int digits) {
    int n = rand() % 10;
    while (n == 0 || n == 1) {
        n = rand() % 10;
    }
    int i = 1;
    while (i < digits) {
        n = (n * 10) + rand() % 10;
        i++;
    }
    return n;
}

// Function to generate a random Fibonacci sequence with a given number of terms
void generate_sequence(int terms) {
    int numbers[terms];
    for (int i = 0; i < terms; i++) {
        numbers[i] = fibonacci(random_number(random() % MAX_DIGITS + 1));
    }
    printf("Random Fibonacci sequence with %d terms:\n", terms);
    for (int i = 0; i < terms; i++) {
        print_number(numbers[i], MAX_DIGITS);
        printf("\n");
    }
}

int main() {
    int terms;
    printf("Enter the number of terms in the sequence: ");
    scanf("%d", &terms);
    if (terms > MAX_TERMS) {
        printf("Error: The number of terms must be less than or equal to %d.\n", MAX_TERMS);
        return 1;
    }
    generate_sequence(terms);
    return 0;
}