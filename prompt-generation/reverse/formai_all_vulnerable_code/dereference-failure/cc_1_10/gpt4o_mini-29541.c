//GPT-4o-mini DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 20
#define HEX_LENGTH 8

// Function prototypes
void getInput(char *input);
int validateInput(const char *input);
void convertToHex(int decimal, char *hex);
void displayResult(const char *hex);
void toUpperCase(char *string);

int main() {
    char input[MAX_INPUT_LENGTH];
    int decimalNumber;
    char hexValue[HEX_LENGTH];

    // Step 1: Get user input
    getInput(input);

    // Step 2: Validate input
    if (!validateInput(input)) {
        printf("Invalid input! Please enter a valid integer.\n");
        return 1;
    }

    // Step 3: Convert input to integer
    decimalNumber = atoi(input);

    // Step 4: Convert decimal to hexadecimal
    convertToHex(decimalNumber, hexValue);

    // Step 5: Display the result
    displayResult(hexValue);

    return 0;
}

void getInput(char *input) {
    printf("Enter an integer to convert to hexadecimal: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    // Remove newline character
    input[strcspn(input, "\n")] = '\0';
}

int validateInput(const char *input) {
    // Check if input is a valid integer
    char *endptr;
    strtol(input, &endptr, 10);
    return (*endptr == '\0'); // No extra characters should be present
}

void convertToHex(int decimal, char *hex) {
    snprintf(hex, HEX_LENGTH, "%X", decimal);
    toUpperCase(hex);
}

void displayResult(const char *hex) {
    printf("The hexadecimal representation is: %s\n", hex);
}

void toUpperCase(char *string) {
    for (int i = 0; string[i]; i++) {
        if (string[i] >= 'a' && string[i] <= 'f') {
            string[i] -= 32; // Convert to uppercase
        }
    }
}