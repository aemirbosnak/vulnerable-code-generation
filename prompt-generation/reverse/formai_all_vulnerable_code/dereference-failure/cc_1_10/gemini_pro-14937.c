//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Key for encryption and decryption
char key[] = "my_secret_key";

// Encrypt a file using XOR encryption
int encrypt_file(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input || !output) {
        printf("Error opening files!\n");
        return -1;
    }

    // Read the input file in chunks
    int chunk_size = 1024;
    char chunk[chunk_size];
    while (!feof(input)) {
        int bytes_read = fread(chunk, 1, chunk_size, input);
        if (bytes_read <= 0) {
            break;
        }

        // Encrypt the chunk
        for (int i = 0; i < bytes_read; i++) {
            chunk[i] ^= key[i % strlen(key)];
        }

        // Write the encrypted chunk to the output file
        fwrite(chunk, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}

// Decrypt a file using XOR encryption
int decrypt_file(char *input_file, char *output_file) {
    FILE *input = fopen(input_file, "rb");
    FILE *output = fopen(output_file, "wb");

    if (!input || !output) {
        printf("Error opening files!\n");
        return -1;
    }

    // Read the input file in chunks
    int chunk_size = 1024;
    char chunk[chunk_size];
    while (!feof(input)) {
        int bytes_read = fread(chunk, 1, chunk_size, input);
        if (bytes_read <= 0) {
            break;
        }

        // Decrypt the chunk
        for (int i = 0; i < bytes_read; i++) {
            chunk[i] ^= key[i % strlen(key)];
        }

        // Write the decrypted chunk to the output file
        fwrite(chunk, 1, bytes_read, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}

int main() {
    char input_file[] = "input.txt";
    char encrypted_file[] = "encrypted.dat";
    char decrypted_file[] = "decrypted.txt";

    // Encrypt the file
    if (encrypt_file(input_file, encrypted_file) != 0) {
        printf("Error encrypting file!\n");
        return -1;
    }

    // Decrypt the file
    if (decrypt_file(encrypted_file, decrypted_file) != 0) {
        printf("Error decrypting file!\n");
        return -1;
    }

    printf("File encrypted and decrypted successfully!\n");
    return 0;
}