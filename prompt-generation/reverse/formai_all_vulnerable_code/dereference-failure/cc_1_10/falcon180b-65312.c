//Falcon-180B DATASET v1.0 Category: Error handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Function to check if a string is an integer
bool is_integer(const char *str) {
    for (int i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Function to read a line from standard input
char *read_line() {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        exit(1);
    }
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Error: Input too long\n");
        exit(1);
    }
    return line;
}

// Function to convert a string to an integer
int string_to_int(const char *str) {
    int num = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        num = num * 10 + str[i] - '0';
    }
    return num;
}

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    char *input_line = NULL;
    int num = 0;

    // Read a line of input
    input_line = read_line();

    // Convert the input to an integer
    if (!is_integer(input_line)) {
        fprintf(stderr, "Error: Invalid input\n");
        exit(1);
    }
    num = string_to_int(input_line);

    // Calculate the factorial
    int result = factorial(num);

    // Print the result
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}