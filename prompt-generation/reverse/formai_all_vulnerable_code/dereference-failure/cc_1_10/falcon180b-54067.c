//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int main() {
    char input[MAX_LENGTH];
    char unit[MAX_LENGTH];
    int value;
    int validInput = 0;

    printf("Welcome to the Temperature Converter!\n");
    printf("Please enter a temperature value followed by its unit (e.g. 25C, 77F): ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove trailing newline character
    input[strcspn(input, "\n")] = '\0';

    // Convert input to uppercase
    for (int i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Extract temperature value
    value = atoi(input);

    // Extract temperature unit
    char *token = strtok(input, " ");
    strcpy(unit, token);

    // Check if input is valid
    if (value >= -273 && value <= 1000 && strcmp(unit, "C") == 0 || strcmp(unit, "F") == 0) {
        validInput = 1;
    } else {
        printf("Invalid input. Please enter a temperature value between -273 and 1000 followed by its unit (C or F).\n");
        return 1;
    }

    // Convert Celsius to Fahrenheit
    if (strcmp(unit, "C") == 0) {
        double fahrenheit = (value * 9/5) + 32;
        printf("%dC is equal to %.2lfF.\n", value, fahrenheit);
    }
    // Convert Fahrenheit to Celsius
    else if (strcmp(unit, "F") == 0) {
        double celsius = (value - 32) * 5/9;
        printf("%dF is equal to %.2lfC.\n", value, celsius);
    }

    return 0;
}