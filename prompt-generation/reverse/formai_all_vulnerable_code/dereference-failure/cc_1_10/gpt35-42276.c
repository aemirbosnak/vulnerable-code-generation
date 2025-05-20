//FormAI DATASET v1.0 Category: File Encyptor ; Style: Linus Torvalds
/*
* C file encryptor example program
* Inspired by Linus Torvalds
*
* Usage: ./encryptor <input_file> <output_file> <encryption_key>
*
* This program takes an input file and encrypts its contents using a simple Caesar cipher
* with the provided encryption key. The encrypted data is written to the output file.
*
* (c) 2021 [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform the Caesar cipher encryption
void encrypt(char *data, int key) {
    int i;
    char c;

    for (i = 0; i < strlen(data); i++) {
        c = data[i];

        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + key) % 26 + 'a';
        }
        else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + key) % 26 + 'A';
        }

        data[i] = c;
    }
}

int main(int argc, char *argv[]) {
    // Check that the correct number of arguments have been provided
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <encryption_key>\n", argv[0]);
        return 1;
    }

    // Open the input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("Could not open input file: %s\n", argv[1]);
        return 1;
    }

    // Open the output file for writing
    FILE *output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("Could not create output file: %s\n", argv[2]);
        fclose(input);
        return 1;
    }

    // Parse the encryption key
    int key = atoi(argv[3]);

    // Read the input file one character at a time
    char c;
    char data[256];
    int counter = 0;

    while ((c = fgetc(input)) != EOF) {
        data[counter++] = c;
    }

    // Close the input file
    fclose(input);

    // Encrypt the data
    encrypt(data, key);

    // Write the encrypted data to the output file
    fwrite(data, sizeof(char), counter, output);

    // Close the output file
    fclose(output);

    printf("File encrypted successfully!\n");

    return 0;
}