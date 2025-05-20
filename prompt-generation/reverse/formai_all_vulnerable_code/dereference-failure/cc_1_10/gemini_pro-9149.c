//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: Cyberpunk
// Cyberpunk File Encrypt0r by "N30n-T3ch"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>

// Custom cyberpunk-style error handling
#define ERROR_HANDLER(err) { \
    fprintf(stderr, "Error: %s\n", strerror(err)); \
    exit(EXIT_FAILURE); \
}

// Key Generation Function
char* keygen(int len) {
    srand(time(NULL));
    char* key = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[len] = '\0';
    return key;
}

// Encryption Function
char* encrypt(char* plaintext, char* key) {
    int key_len = strlen(key);
    char* ciphertext = malloc(strlen(plaintext) + 1);
    for (int i = 0; i < strlen(plaintext); i++) {
        int shifted_index = (plaintext[i] - 'a' + key[i % key_len] - 'a') % 26;
        ciphertext[i] = 'a' + shifted_index;
    }
    ciphertext[strlen(plaintext)] = '\0';
    return ciphertext;
}

// Decryption Function
char* decrypt(char* ciphertext, char* key) {
    int key_len = strlen(key);
    char* plaintext = malloc(strlen(ciphertext) + 1);
    for (int i = 0; i < strlen(ciphertext); i++) {
        int shifted_index = (ciphertext[i] - 'a' - key[i % key_len] + 'a') % 26;
        plaintext[i] = 'a' + shifted_index;
    }
    plaintext[strlen(ciphertext)] = '\0';
    return plaintext;
}

int main(int argc, char** argv) {
    // Check if filename arguments are provided
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input and output files
    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) ERROR_HANDLER(errno);
    FILE* output_file = fopen(argv[2], "wb");
    if (output_file == NULL) ERROR_HANDLER(errno);

    // Read input file into a buffer
    fseek(input_file, 0L, SEEK_END);
    long file_size = ftell(input_file);
    rewind(input_file);
    char* file_buffer = malloc(file_size);
    if (fread(file_buffer, 1, file_size, input_file) != file_size) ERROR_HANDLER(errno);

    // Generate encryption key
    char* key = keygen(16); // Key length of 16 characters

    // Encrypt the file buffer
    char* encrypted_buffer = encrypt(file_buffer, key);

    // Write encrypted buffer to output file
    if (fwrite(encrypted_buffer, 1, strlen(encrypted_buffer), output_file) != strlen(encrypted_buffer)) ERROR_HANDLER(errno);

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    // Cleanup
    free(file_buffer);
    free(encrypted_buffer);
    free(key);

    printf("File encrypted successfully. Key: %s\n", key);
    return EXIT_SUCCESS;
}