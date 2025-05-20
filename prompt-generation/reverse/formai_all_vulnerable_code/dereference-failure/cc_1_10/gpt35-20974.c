//FormAI DATASET v1.0 Category: File Encyptor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/* Function declarations */
int encrypt_file(char* input_file, char* output_file, char* key);
int decrypt_file(char* input_file, char* output_file, char* key);

/* Main function */
int main(int argc, char* argv[]) {
    char* input_file = argv[2];
    char* output_file = argv[3];
    char* key = argv[4];
    char* option = argv[1];
    
    if (strcmp(option, "-e") == 0) {
        if (encrypt_file(input_file, output_file, key) == 0) {
            printf("Encryption successful.\n");
        }
        else {
            printf("Encryption failed.\n");
        }
    } 
    else if (strcmp(option, "-d") == 0) {
        if (decrypt_file(input_file, output_file, key) == 0) {
            printf("Decryption successful.\n");
        }
        else {
            printf("Decryption failed.\n");
        }
    }
    else {
        printf("Invalid option. Use -e to encrypt and -d to decrypt.\n");
    }

    return 0;
}

/* Encryption function */
int encrypt_file(char* input_file, char* output_file, char* key) {
    FILE* input_ptr = fopen(input_file, "rb");
    FILE* output_ptr = fopen(output_file, "wb");

    if (input_ptr == NULL || output_ptr == NULL) {
        return 1;
    }

    fseek(input_ptr, 0, SEEK_END);
    long file_size = ftell(input_ptr);
    fseek(input_ptr, 0, SEEK_SET);

    char* buffer = (char*) malloc(sizeof(char) * BUFFER_SIZE);
    int key_length = strlen(key);

    for (long i = 0; i < file_size; i += BUFFER_SIZE) {
        long bytes_to_read = (BUFFER_SIZE < file_size - i) ? BUFFER_SIZE : file_size - i;
        size_t bytes_read = fread(buffer, sizeof(char), bytes_to_read, input_ptr);

        for (size_t j = 0; j < bytes_read; j++) {
            buffer[j] ^= key[j % key_length];
        }
        
        fwrite(buffer, sizeof(char), bytes_read, output_ptr);
    }

    free(buffer);
    fclose(input_ptr);
    fclose(output_ptr);
    return 0;
}

/* Decryption function */
int decrypt_file(char* input_file, char* output_file, char* key) {
    return encrypt_file(input_file, output_file, key);
}