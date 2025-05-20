//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_SIZE 256
#define MAX_FILE_SIZE 1024*1024*10 // 10 MB

// Function to encrypt/decrypt the file using the key
void encrypt_decrypt(char *key, int key_size, FILE *input_file, FILE *output_file) {
    char buffer[1024];
    int i;

    // Read the input file in chunks
    while (fread(buffer, sizeof(char), sizeof(buffer), input_file) > 0) {
        for (i = 0; i < key_size; i++) {
            // Encrypt/decrypt the buffer using the key
            if (isalpha(buffer[i])) {
                if (isupper(buffer[i])) {
                    buffer[i] = (buffer[i] + key[i % key_size] - 65) % 26 + 65;
                } else {
                    buffer[i] = (buffer[i] + key[i % key_size] - 97) % 26 + 97;
                }
            } else {
                buffer[i] = buffer[i];
            }
        }
        // Write the encrypted/decrypted buffer to the output file
        fwrite(buffer, sizeof(char), sizeof(buffer), output_file);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage: %s -e|-d input_file key output_file\n", argv[0]);
        return 1;
    }

    char *input_file = argv[2];
    char *output_file = argv[4];
    char *key = argv[3];
    int key_size = strlen(key);

    FILE *input = fopen(input_file, "rb");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    FILE *output = fopen(output_file, "wb");
    if (output == NULL) {
        printf("Error: Could not create output file.\n");
        fclose(input);
        return 1;
    }

    if (strcmp(argv[1], "-e") == 0) {
        encrypt_decrypt(key, key_size, input, output);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[1], "-d") == 0) {
        encrypt_decrypt(key, key_size, input, output);
        printf("File decrypted successfully.\n");
    } else {
        printf("Invalid operation.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    fclose(input);
    fclose(output);
    return 0;
}