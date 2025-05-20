//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define KEY_SIZE 256

// Function to create a simple key for encryption/decryption
void create_key(unsigned char *key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        key[i] = (unsigned char)(rand() % 256);
    }
}

// Function to encrypt data
void encrypt(FILE *input, FILE *output, unsigned char *key, size_t key_length) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length]; // XOR encryption
        }
        fwrite(buffer, 1, bytes_read, output);
    }
}

// Function to decrypt data
void decrypt(FILE *input, FILE *output, unsigned char *key, size_t key_length) {
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key[i % key_length]; // XOR decryption
        }
        fwrite(buffer, 1, bytes_read, output);
    }
}

// Function to get the user's choice
void get_choice(char *choice, size_t size) {
    printf("Choose action:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Your choice: ");
    fgets(choice, size, stdin);
}

// Function to get key from user
void get_key(unsigned char *key, size_t size) {
    printf("Enter a key (max %zu characters): ", size - 1);
    fgets((char *)key, size, stdin);
    key[strcspn((char *)key, "\n")] = 0; // Remove newline character
}

// Main function
int main() {
    char choice[2];
    char input_file[256], output_file[256];
    unsigned char key[KEY_SIZE];

    srand((unsigned int)time(NULL));

    get_choice(choice, sizeof(choice));

    if (choice[0] != '1' && choice[0] != '2') {
        fprintf(stderr, "Invalid choice!\n");
        return 1;
    }

    // Get the input file name
    printf("Enter input filename: ");
    fgets(input_file, sizeof(input_file), stdin);
    input_file[strcspn(input_file, "\n")] = 0; // Remove newline character

    // Get the output file name
    printf("Enter output filename: ");
    fgets(output_file, sizeof(output_file), stdin);
    output_file[strcspn(output_file, "\n")] = 0; // Remove newline character

    // Get the key from the user
    get_key(key, sizeof(key));

    FILE *input = fopen(input_file, "rb");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (!output) {
        fclose(input);
        perror("Error opening output file");
        return 1;
    }

    if (choice[0] == '1') {
        encrypt(input, output, key, strlen((char *)key));
        printf("File encrypted successfully: %s\n", output_file);
    } else {
        decrypt(input, output, key, strlen((char *)key));
        printf("File decrypted successfully: %s\n", output_file);
    }

    fclose(input);
    fclose(output);

    return 0;
}