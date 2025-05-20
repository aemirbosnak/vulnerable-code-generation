//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the file
void encrypt_file(FILE *file, char *key) {
    char buffer[1024];
    int i, j, k;
    char encrypted_buffer[1024];

    // Read the file in chunks
    while (fgets(buffer, 1024, file)!= NULL) {
        // Encrypt each character in the buffer using the key
        for (i = 0; i < strlen(buffer); i++) {
            // Convert the character to uppercase
            buffer[i] = toupper(buffer[i]);

            // Encrypt the character using the key
            j = (int) buffer[i] + (int) key[i % strlen(key)];

            // Wrap around if the encrypted character is out of range
            if (j > 122) {
                j = 96 + (j % 26);
            }

            // Convert the encrypted character back to ASCII
            encrypted_buffer[i] = j;
        }

        // Write the encrypted buffer to the file
        fputs(encrypted_buffer, file);
    }
}

int main(int argc, char *argv[]) {
    FILE *file, *encrypted_file;
    char key[1024];

    // Check if the correct number of arguments are provided
    if (argc!= 4) {
        printf("Usage: %s input_file output_file key\n", argv[0]);
        return 1;
    }

    // Open the input file in read mode
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Read the key from the command line argument
    strcpy(key, argv[3]);

    // Open the output file in write mode
    encrypted_file = fopen(argv[2], "w");
    if (encrypted_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    // Encrypt the input file and write the encrypted data to the output file
    encrypt_file(file, key);

    // Close the input and output files
    fclose(file);
    fclose(encrypted_file);

    return 0;
}