//Falcon-180B DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ARGS 10

// Function to print error message and exit program with error code
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to check if a string is a valid integer
int is_int(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

// Function to convert a string to an integer
int str_to_int(char *str) {
    return atoi(str);
}

// Function to perform division and handle errors
int divide(int a, int b) {
    if (b == 0) {
        error("Division by zero is not allowed!");
    }
    return a / b;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        error("Insufficient arguments!");
    }

    int num1 = str_to_int(argv[1]);
    int num2 = str_to_int(argv[2]);
    char op = argv[3][0];

    switch (op) {
        case '+':
            printf("Result: %d\n", num1 + num2);
            break;
        case '-':
            printf("Result: %d\n", num1 - num2);
            break;
        case '*':
            printf("Result: %d\n", num1 * num2);
            break;
        case '/':
            printf("Result: %d\n", divide(num1, num2));
            break;
        default:
            error("Invalid operator!");
    }

    return 0;
}