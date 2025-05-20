//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16 // Size of the encryption key

// Function to encrypt the input file using the given key
void encrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[1024]; // Buffer to hold input data
    char output_buffer[1024]; // Buffer to hold output data
    int key_index = 0; // Index to keep track of the key position

    while (fread(input_buffer, 1, 1024, input_file) > 0) {
        for (int i = 0; i < 1024; i++) {
            output_buffer[i] = input_buffer[i] ^ key[key_index]; // XOR encryption
            key_index = (key_index + 1) % KEY_SIZE; // Increment key index and wrap around if necessary
        }

        fwrite(output_buffer, 1, 1024, output_file); // Write encrypted data to output file
    }
}

// Function to decrypt the input file using the given key
void decrypt_file(FILE *input_file, FILE *output_file, char *key) {
    char input_buffer[1024]; // Buffer to hold input data
    char output_buffer[1024]; // Buffer to hold output data
    int key_index = 0; // Index to keep track of the key position

    while (fread(input_buffer, 1, 1024, input_file) > 0) {
        for (int i = 0; i < 1024; i++) {
            output_buffer[i] = input_buffer[i] ^ key[key_index]; // XOR decryption
            key_index = (key_index + 1) % KEY_SIZE; // Increment key index and wrap around if necessary
        }

        fwrite(output_buffer, 1, 1024, output_file); // Write decrypted data to output file
    }
}

int main() {
    char input_file_name[100];
    char output_file_name[100];
    char key[KEY_SIZE];

    // Get input file name from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);

    // Get output file name from user
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Get encryption key from user
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input and output files
    FILE *input_file = fopen(input_file_name, "rb");
    FILE *output_file = fopen(output_file_name, "wb");

    if (input_file == NULL || output_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Encrypt input file
    encrypt_file(input_file, output_file, key);

    // Close files
    fclose(input_file);
    fclose(output_file);

    printf("File encrypted successfully\n");

    return 0;
}