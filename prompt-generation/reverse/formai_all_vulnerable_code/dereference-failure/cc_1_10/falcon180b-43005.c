//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 10000

// Function to remove all spaces from the input string
void remove_spaces(char *input) {
    int i, j;
    for (i = 0, j = 0; i < strlen(input); i++) {
        if (!isspace(input[i])) {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

// Function to compress the input string using run-length encoding
void run_length_encoding(char *input) {
    int i, j, count = 1;
    for (i = 0; i < strlen(input); i++) {
        if (i + 1 < strlen(input) && input[i] == input[i + 1]) {
            count++;
        } else {
            input[j++] = input[i];
            input[j++] = '%';
            input[j++] = count + '0';
            count = 1;
        }
    }
    input[j++] = input[i - 1];
    input[j++] = '%';
    input[j++] = count + '0';
    input[j] = '\0';
}

// Function to decompress the compressed input string
void decompress(char *input) {
    int i, j, count = 0;
    for (i = 0; i < strlen(input); i++) {
        if (input[i] == '%') {
            count = input[i + 1] - '0';
            i += 2;
            while (count-- > 0) {
                input[j++] = input[i];
                i++;
            }
        } else {
            input[j++] = input[i];
        }
    }
    input[j] = '\0';
}

int main() {
    char input[MAX_INPUT_SIZE];
    printf("Enter the input string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    remove_spaces(input);
    run_length_encoding(input);
    printf("Compressed string: %s\n", input);
    decompress(input);
    printf("Decompressed string: %s\n", input);
    return 0;
}