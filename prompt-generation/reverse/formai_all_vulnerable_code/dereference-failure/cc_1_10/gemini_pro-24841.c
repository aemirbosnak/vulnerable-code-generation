//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encrypt a file using a simple substitution cipher.
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    // Open the input and output files.
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        printf("Error opening output file: %s\n", argv[2]);
        return 1;
    }

    // Read the input file into a buffer.
    fseek(input, 0, SEEK_END);
    long input_size = ftell(input);
    rewind(input);
    char *input_buffer = malloc(input_size);
    if (input_buffer == NULL) {
        printf("Error allocating memory for input buffer.\n");
        return 1;
    }
    fread(input_buffer, input_size, 1, input);

    // Create a substitution cipher.
    char substitution_table[256];
    for (int i = 0; i < 256; i++) {
        substitution_table[i] = i;
    }
    for (int i = 0; i < 256; i++) {
        int j = rand() % 256;
        char temp = substitution_table[i];
        substitution_table[i] = substitution_table[j];
        substitution_table[j] = temp;
    }

    // Encrypt the input buffer using the substitution cipher.
    for (int i = 0; i < input_size; i++) {
        input_buffer[i] = substitution_table[input_buffer[i]];
    }

    // Write the encrypted buffer to the output file.
    fwrite(input_buffer, input_size, 1, output);

    // Free the input buffer.
    free(input_buffer);

    // Close the input and output files.
    fclose(input);
    fclose(output);

    return 0;
}