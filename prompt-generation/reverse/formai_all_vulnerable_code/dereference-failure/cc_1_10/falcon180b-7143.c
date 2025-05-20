//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_NUM_LENGTH 32
#define MAX_ERROR_LENGTH 100

typedef struct {
    char *binary;
    char *hex;
    char *octal;
    char *error;
} ConversionResult;

ConversionResult convert(char *input) {
    ConversionResult result = {0};
    char *endptr = 0;
    long int decimal = strtol(input, &endptr, 10);
    if (endptr == input) {
        strcpy(result.error, "Invalid input");
        return result;
    }
    char binary[MAX_NUM_LENGTH];
    char hex[MAX_NUM_LENGTH];
    char octal[MAX_NUM_LENGTH];
    sprintf(binary, "%032b", decimal);
    sprintf(hex, "%08X", decimal);
    sprintf(octal, "%lo", decimal);
    strcpy(result.binary, binary);
    strcpy(result.hex, hex);
    strcpy(result.octal, octal);
    return result;
}

void print_result(ConversionResult result) {
    printf("Binary: %s\n", result.binary);
    printf("Hexadecimal: %s\n", result.hex);
    printf("Octal: %s\n", result.octal);
    if (result.error[0]!= '\0') {
        printf("Error: %s\n", result.error);
    }
}

int main() {
    char input[MAX_LINE_LENGTH];
    printf("Enter a number to convert: ");
    fgets(input, MAX_LINE_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';
    ConversionResult result = convert(input);
    print_result(result);
    return 0;
}