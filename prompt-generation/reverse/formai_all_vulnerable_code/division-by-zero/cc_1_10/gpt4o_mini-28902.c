//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void encrypt(const char *input_file, const char *output_file, const char *key);
void decrypt(const char *input_file, const char *output_file, const char *key);
void process_file(const char *input_file, const char *output_file, const char *key, int mode);
char *read_file(const char *filename, size_t *length);
void write_file(const char *filename, const char *data, size_t length);

#define ENCRYPT_MODE 1
#define DECRYPT_MODE 0

int main() {
    char input_file[256];
    char output_file[256];
    char key[128];
    int mode;

    printf("File Encryptor/Decryptor\n");
    printf("=========================\n");

    printf("Enter input file name: ");
    scanf("%255s", input_file);
    
    printf("Enter output file name: ");
    scanf("%255s", output_file);
    
    printf("Enter encryption key (max 127 chars): ");
    scanf("%127s", key);

    printf("Choose mode (1: Encrypt, 0: Decrypt): ");
    scanf("%d", &mode);

    if (mode == ENCRYPT_MODE) {
        encrypt(input_file, output_file, key);
        printf("File encrypted successfully!\n");
    } else if (mode == DECRYPT_MODE) {
        decrypt(input_file, output_file, key);
        printf("File decrypted successfully!\n");
    } else {
        printf("Invalid mode selected!\n");
    }

    return 0;
}

// Function to encrypt a file
void encrypt(const char *input_file, const char *output_file, const char *key) {
    process_file(input_file, output_file, key, ENCRYPT_MODE);
}

// Function to decrypt a file
void decrypt(const char *input_file, const char *output_file, const char *key) {
    process_file(input_file, output_file, key, DECRYPT_MODE);
}

// Generic function to process file
void process_file(const char *input_file, const char *output_file, const char *key, int mode) {
    size_t input_length;
    char *data = read_file(input_file, &input_length);
    if (!data) {
        fprintf(stderr, "Failed to read input file.\n");
        exit(EXIT_FAILURE);
    }

    size_t key_length = strlen(key);
    for (size_t i = 0; i < input_length; i++) {
        data[i] ^= key[i % key_length]; // XOR operation
    }

    write_file(output_file, data, input_length);
    free(data); // Free allocated memory
}

// Function to read file contents
char *read_file(const char *filename, size_t *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *data = malloc(*length);
    if (!data) {
        fclose(file);
        perror("Failed to allocate memory");
        return NULL;
    }

    fread(data, 1, *length, file);
    fclose(file);
    return data;
}

// Function to write data to a file
void write_file(const char *filename, const char *data, size_t length) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    fwrite(data, 1, length, file);
    fclose(file);
}