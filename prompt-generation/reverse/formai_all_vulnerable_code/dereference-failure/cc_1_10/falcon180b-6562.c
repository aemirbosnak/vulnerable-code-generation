//Falcon-180B DATASET v1.0 Category: User Input Sanitizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <limits.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_NUMBER_LENGTH 20
#define MAX_STRING_LENGTH 100

// Function to sanitize user input
void sanitize_input(char* input) {
    int i = 0, j = 0;
    char buffer[MAX_INPUT_LENGTH];

    // Remove leading/trailing spaces
    while (isspace(input[i])) {
        i++;
    }
    while (isspace(input[strlen(input) - 1])) {
        input[strlen(input) - 1] = '\0';
    }

    // Copy input to buffer
    strcpy(buffer, input);

    // Remove non-alphanumeric characters
    while (buffer[i]) {
        if (isalnum(buffer[i])) {
            input[j++] = tolower(buffer[i]);
        }
        i++;
    }
    input[j] = '\0';
}

int main() {
    char input[MAX_INPUT_LENGTH];
    int number;
    double decimal;
    char string[MAX_STRING_LENGTH];

    // Example usage of sanitize_input function
    printf("Enter a string: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    sanitize_input(input);
    printf("Sanitized string: %s\n", input);

    // Example usage of input validation
    printf("Enter a number: ");
    if (scanf("%d", &number)!= 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("You entered %d\n", number);

    // Example usage of decimal input validation
    printf("Enter a decimal number: ");
    if (scanf("%lf", &decimal)!= 1) {
        printf("Invalid input\n");
        return 1;
    }
    printf("You entered %.2lf\n", decimal);

    // Example usage of string input validation
    printf("Enter a string: ");
    if (fgets(string, MAX_STRING_LENGTH, stdin) == NULL) {
        printf("Invalid input\n");
        return 1;
    }
    printf("You entered %s\n", string);

    return 0;
}