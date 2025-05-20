//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define SHIFT 3

void encrypt(const char *input, char *output, int shift) {
    while (*input) {
        // Encrypt alphabetic characters
        if (*input >= 'a' && *input <= 'z') {
            *output = ((*input - 'a' + shift) % 26) + 'a';
        } else if (*input >= 'A' && *input <= 'Z') {
            *output = ((*input - 'A' + shift) % 26) + 'A';
        } else {
            *output = *input; // Non-alphabetic characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

void decrypt(const char *input, char *output, int shift) {
    while (*input) {
        // Decrypt alphabetic characters
        if (*input >= 'a' && *input <= 'z') {
            *output = ((*input - 'a' - shift + 26) % 26) + 'a'; // Added +26 to handle negative values
        } else if (*input >= 'A' && *input <= 'Z') {
            *output = ((*input - 'A' - shift + 26) % 26) + 'A';
        } else {
            *output = *input; // Non-alphabetic characters remain unchanged
        }
        input++;
        output++;
    }
    *output = '\0'; // Null-terminate the output string
}

void usage(const char *prog_name) {
    printf("Usage: %s <encrypt|decrypt> <input_file> <output_file>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    char mode[10];
    strncpy(mode, argv[1], sizeof(mode));
    mode[sizeof(mode) - 1] = '\0'; // Ensure null-termination

    FILE *input_file = fopen(argv[2], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[3], "w");
    if (!output_file) {
        fclose(input_file);
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    char buffer[MAX_BUFFER];
    char processed[MAX_BUFFER];

    if (strcmp(mode, "encrypt") == 0) {
        while (fgets(buffer, sizeof(buffer), input_file)) {
            encrypt(buffer, processed, SHIFT);
            fputs(processed, output_file);
        }
        printf("Encryption completed successfully.\n");
    } else if (strcmp(mode, "decrypt") == 0) {
        while (fgets(buffer, sizeof(buffer), input_file)) {
            decrypt(buffer, processed, SHIFT);
            fputs(processed, output_file);
        }
        printf("Decryption completed successfully.\n");
    } else {
        usage(argv[0]);
    }

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}