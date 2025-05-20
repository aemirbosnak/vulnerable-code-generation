//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
#define KEY_MOD 26

// Function to generate a key based on a mathematical operation
int generate_key(int seed) {
    return (seed * 7) % KEY_MOD; // Simple mathematical operation
}

// Function to encrypt the character using the generated key
char encrypt_char(char c, int key) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' + key) % KEY_MOD + 'a'; // Encrypt lowercase
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' + key) % KEY_MOD + 'A'; // Encrypt uppercase
    }
    return c; // Return unchanged
}

// Function to decrypt the character using the generated key
char decrypt_char(char c, int key) {
    if (c >= 'a' && c <= 'z') {
        return (c - 'a' - key + KEY_MOD) % KEY_MOD + 'a'; // Decrypt lowercase
    } else if (c >= 'A' && c <= 'Z') {
        return (c - 'A' - key + KEY_MOD) % KEY_MOD + 'A'; // Decrypt uppercase
    }
    return c; // Return unchanged
}

// Function to encrypt a text file
void encrypt_file(const char *input_file, const char *output_file, int key) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    char buffer[BUFFER_SIZE];
    
    if (!fin || !fout) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }
    
    while (fgets(buffer, BUFFER_SIZE, fin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = encrypt_char(buffer[i], key);
        }
        fputs(buffer, fout);
    }
    
    fclose(fin);
    fclose(fout);
}

// Function to decrypt a text file
void decrypt_file(const char *input_file, const char *output_file, int key) {
    FILE *fin = fopen(input_file, "r");
    FILE *fout = fopen(output_file, "w");
    char buffer[BUFFER_SIZE];
    
    if (!fin || !fout) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }
    
    while (fgets(buffer, BUFFER_SIZE, fin)) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            buffer[i] = decrypt_char(buffer[i], key);
        }
        fputs(buffer, fout);
    }
    
    fclose(fin);
    fclose(fout);
}

// Main function to handle user input
int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <encrypt/decrypt> <input_file> <output_file> <seed>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int seed = atoi(argv[4]);
    int key = generate_key(seed);
    
    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2], argv[3], key);
        printf("File encrypted successfully with key %d.\n", key);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2], argv[3], key);
        printf("File decrypted successfully with key %d.\n", key);
    } else {
        fprintf(stderr, "Invalid operation: use 'encrypt' or 'decrypt'.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}