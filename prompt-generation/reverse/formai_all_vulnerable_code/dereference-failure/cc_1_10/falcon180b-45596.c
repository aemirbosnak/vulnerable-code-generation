//Falcon-180B DATASET v1.0 Category: Binary Converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int main(int argc, char *argv[]) {
    char input_str[MAX_SIZE];
    int binary_num[MAX_SIZE];
    int i, j, k, size;

    // Check if user entered a string
    if (argc < 2) {
        printf("Please enter a string.\n");
        return 1;
    }

    // Get the input string from user
    strcpy(input_str, argv[1]);

    // Remove any leading/trailing spaces
    input_str[strcspn(input_str, " ")] = '\0';

    // Convert the input string to uppercase
    for (i = 0; i < strlen(input_str); i++) {
        input_str[i] = toupper(input_str[i]);
    }

    // Check if the input string contains only alphabetic characters
    for (i = 0; i < strlen(input_str); i++) {
        if (!isalpha(input_str[i])) {
            printf("Input string must contain only alphabetic characters.\n");
            return 1;
        }
    }

    // Convert the input string to binary
    size = strlen(input_str);
    for (i = 0; i < size; i++) {
        binary_num[i] = input_str[i] - 'A' + 1;
    }

    // Print the binary representation of the input string
    printf("Binary representation of the input string is:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < 8; j++) {
            if (binary_num[i] & (1 << j)) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
    }

    return 0;
}