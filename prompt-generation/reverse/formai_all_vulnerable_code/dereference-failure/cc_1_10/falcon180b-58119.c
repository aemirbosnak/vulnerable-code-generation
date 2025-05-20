//Falcon-180B DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

// Function to print a message and exit the program
void error(char* msg) {
    printf("Error: %s\n", msg);
    exit(1);
}

// Function to read an integer from standard input
int read_int() {
    int x;
    if (scanf("%d", &x)!= 1) {
        error("Invalid input");
    }
    return x;
}

// Function to read a string from standard input
char* read_string() {
    char* s = malloc(100);
    if (fgets(s, 100, stdin) == NULL) {
        error("Failed to read input");
    }
    return s;
}

// Function to reverse a string
char* reverse_string(char* s) {
    int i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n;
    char* s;

    // Read the input integer
    n = read_int();

    // Read the input string
    s = read_string();

    // Reverse the input string
    s = reverse_string(s);

    // Calculate the factorial of the input integer
    int f = factorial(n);

    // Print the reversed string and factorial
    printf("The reversed string is: %s\n", s);
    printf("The factorial of %d is: %d\n", n, f);

    return 0;
}