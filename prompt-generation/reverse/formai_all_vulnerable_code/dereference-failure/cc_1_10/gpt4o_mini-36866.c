//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1024

void encrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' + shift) % 26 + 'a';
        }
        // Characters that are not letters stay the same
        else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void decrypt(char *input, int shift, char *output) {
    for (int i = 0; input[i] != '\0'; i++) {
        char c = input[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            output[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            output[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
        // Characters that are not letters stay the same
        else {
            output[i] = c;
        }
    }
    output[strlen(input)] = '\0'; // Null-terminate the output string
}

void usage() {
    printf("Usage: ./cryptography <encrypt/decrypt> <shift> <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        usage();
        return 1;
    }

    char *mode = argv[1];
    int shift = atoi(argv[2]);
    char *input_file_name = argv[3];
    char *output_file_name = argv[4];

    FILE *input_file = fopen(input_file_name, "r");
    if (!input_file) {
        perror("Error opening input file");
        return 1;
    }

    // Read the input file
    char input[MAX_LEN];
    fread(input, sizeof(char), MAX_LEN, input_file);
    fclose(input_file);

    char output[MAX_LEN];

    // Perform encryption or decryption based on the mode specified
    if (strcmp(mode, "encrypt") == 0) {
        encrypt(input, shift, output);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt(input, shift, output);
    } else {
        usage();
        return 1;
    }

    // Write the output to the specified file
    FILE *output_file = fopen(output_file_name, "w");
    if (!output_file) {
        perror("Error opening output file");
        return 1;
    }

    fwrite(output, sizeof(char), strlen(output), output_file);
    fclose(output_file);

    printf("Operation successful! Output written to %s\n", output_file_name);
    return 0;
}