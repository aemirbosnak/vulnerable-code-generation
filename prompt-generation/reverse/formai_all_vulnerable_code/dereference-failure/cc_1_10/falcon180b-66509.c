//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct {
    char* name;
    int value;
} binary_digits[] = {
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"A", 10},
    {"B", 11},
    {"C", 12},
    {"D", 13},
    {"E", 14},
    {"F", 15}
};

int main() {
    char* input_string;
    int input_length, i, j;
    char* output_string = malloc(1024); // Allocate 1KB for output string
    if (output_string == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for output string.\n");
        exit(1);
    }
    memset(output_string, 0, 1024); // Initialize output string with zeros

    printf("Enter a binary number: ");
    fgets(input_string, 1024, stdin);
    input_length = strlen(input_string);

    // Remove leading/trailing whitespace
    for (i = 0; i < input_length; i++) {
        if (isspace(input_string[i])) {
            input_string[i] = '\0';
            input_length--;
        }
    }

    // Convert binary to decimal
    for (i = input_length - 1, j = 0; i >= 0; i--, j++) {
        int digit_value = 0;
        for (int k = 0; k < 16; k++) {
            if (tolower(input_string[i]) == binary_digits[k].name[0]) {
                digit_value = binary_digits[k].value;
                break;
            }
        }
        sprintf(&output_string[j], "%d", digit_value);
    }

    printf("Decimal equivalent: %s\n", output_string);

    free(output_string);
    return 0;
}