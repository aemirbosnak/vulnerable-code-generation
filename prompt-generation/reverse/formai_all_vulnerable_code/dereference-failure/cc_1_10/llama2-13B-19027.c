//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_LENGTH 1024

// Function prototypes
int checkInput(const char *input);
int performCalculation(int num1, int num2);
int printResult(int result);

// Global variables
bool isError = false;
char errorMessage[MAX_LENGTH];

int main() {
    int num1, num2;

    // Get input from user
    printf("Enter two numbers: ");
    if (scanf("%d%d", &num1, &num2) != 2) {
        isError = true;
        strcpy(errorMessage, "Error: Unable to scan input");
    }

    // Check if input is valid
    if (checkInput(num1) || checkInput(num2)) {
        isError = true;
        strcpy(errorMessage, "Error: Invalid input");
    }

    // Perform calculation
    int result = performCalculation(num1, num2);

    // Check if calculation failed
    if (result == -1) {
        isError = true;
        strcpy(errorMessage, "Error: Calculation failed");
    }

    // Print result
    if (!isError) {
        printResult(result);
    } else {
        printf("Error: %s\n", errorMessage);
    }

    return 0;
}

// Function to check input
int checkInput(const char *input) {
    int length = strlen(input);

    if (length < 1 || length > MAX_LENGTH) {
        return true;
    }

    for (int i = 0; i < length; i++) {
        if (!isdigit(input[i])) {
            return true;
        }
    }

    return false;
}

// Function to perform calculation
int performCalculation(int num1, int num2) {
    int result = num1 + num2;

    if (result < 0) {
        result = -1;
    }

    return result;
}

// Function to print result
int printResult(int result) {
    if (result < 0) {
        printf("Error: Result is negative\n");
    } else {
        printf("Result: %d\n", result);
    }

    return 0;
}