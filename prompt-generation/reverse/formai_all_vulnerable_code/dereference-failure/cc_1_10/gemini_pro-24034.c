//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

int main(int argc, char *argv[]) {
    // Check if there are enough arguments.
    if (argc < 4) {
        printf("Usage: %s encrypt|decrypt key input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the operation (encrypt or decrypt).
    int operation = (strcmp(argv[1], "encrypt") == 0) ? ENCRYPT : DECRYPT;

    // Get the key.
    char *key = argv[2];

    // Get the input and output file names.
    char *input_file = argv[3];
    char *output_file = argv[4];

    // Open the input file.
    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening the input file: %s\n", input_file);
        return EXIT_FAILURE;
    }

    // Open the output file.
    FILE *output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening the output file: %s\n", output_file);
        return EXIT_FAILURE;
    }

    // Get the length of the key.
    int key_len = strlen(key);

    // Read the input file character by character.
    int c;
    while ((c = fgetc(input)) != EOF) {
        // Encrypt or decrypt the character.
        if (operation == ENCRYPT) {
            c ^= key[c % key_len];
        } else {
            c ^= key[c % key_len];
        }

        // Write the encrypted or decrypted character to the output file.
        fputc(c, output);
    }

    // Close the input and output files.
    fclose(input);
    fclose(output);

    // Operation success!
    printf("Operation successful! The output is in the file %s\n", output_file);
    return EXIT_SUCCESS;
}