//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert decimal to binary
char* dec_to_bin(int dec) {
    char* bin = malloc(33 * sizeof(char)); // Allocate enough memory for 32-bit integer + null terminator
    sprintf(bin, "%032b", dec); // Convert decimal to binary and pad with leading zeros
    return bin;
}

// Function to convert binary to decimal
int bin_to_dec(char* bin) {
    return strtol(bin, NULL, 2);
}

// Function to print usage instructions
void usage() {
    printf("Usage:./program [decimal/binary] [input]\n");
    printf("Where [decimal/binary] is the desired conversion type and [input] is the number to convert.\n");
    printf("Example:./program binary 101010\n");
}

int main(int argc, char** argv) {
    if (argc!= 4) {
        usage();
        return 1;
    }

    char* input = argv[3];
    int len = strlen(input);

    // Check if input contains only digits
    for (int i = 0; i < len; i++) {
        if (!isdigit(input[i])) {
            printf("Invalid input. Please enter a decimal or binary number.\n");
            return 1;
        }
    }

    // Convert decimal to binary or binary to decimal
    char* result = NULL;
    if (strcmp(argv[1], "decimal") == 0) {
        result = dec_to_bin(atoi(input));
    } else if (strcmp(argv[1], "binary") == 0) {
        result = malloc(sizeof(char) * (len + 1));
        strcpy(result, input);
    } else {
        printf("Invalid conversion type. Please enter 'decimal' or 'binary'.\n");
        return 1;
    }

    // Print result
    printf("%s = %s\n", argv[1], result);

    free(result);
    return 0;
}