//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUMBER_LENGTH 32

typedef struct {
    char *binary;
    char *octal;
    char *decimal;
} Number;

void print_number(Number *number) {
    printf("Binary: %s\n", number->binary);
    printf("Octal: %s\n", number->octal);
    printf("Decimal: %s\n", number->decimal);
}

int main() {
    char line[MAX_LINE_LENGTH];
    char *endptr;
    int decimal = 0;
    Number number;

    // Prompt user to enter a decimal number
    printf("Enter a decimal number: ");

    // Read input from user
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Convert input to decimal
    decimal = strtol(line, &endptr, 10);

    // Check for errors
    if (endptr == line) {
        printf("Invalid input.\n");
        return 1;
    }

    // Convert decimal to binary
    char *binary = malloc(MAX_NUMBER_LENGTH * sizeof(char));
    sprintf(binary, "%b", decimal);

    // Convert binary to octal
    char *octal = malloc(MAX_NUMBER_LENGTH * sizeof(char));
    sprintf(octal, "%o", decimal);

    // Set number fields
    number.binary = binary;
    number.octal = octal;
    number.decimal = malloc(MAX_NUMBER_LENGTH * sizeof(char));
    sprintf(number.decimal, "%d", decimal);

    // Print result
    printf("Decimal: %d\n", decimal);
    print_number(&number);

    return 0;
}