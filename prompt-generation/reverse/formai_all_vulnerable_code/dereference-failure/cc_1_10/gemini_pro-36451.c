//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the encryption key
#define KEY 123

// Encrypt a character using the XOR operator
char encrypt(char c) {
    return c ^ KEY;
}

// Decrypt a character using the XOR operator
char decrypt(char c) {
    return c ^ KEY;
}

// Encrypt a string using the XOR operator
char* encrypt_string(char* str) {
    char* encrypted_str = (char*)malloc(strlen(str) + 1);
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        encrypted_str[i] = encrypt(str[i]);
    }

    encrypted_str[i] = '\0';

    return encrypted_str;
}

// Decrypt a string using the XOR operator
char* decrypt_string(char* str) {
    char* decrypted_str = (char*)malloc(strlen(str) + 1);
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        decrypted_str[i] = decrypt(str[i]);
    }

    decrypted_str[i] = '\0';

    return decrypted_str;
}

// Print the usage message
void print_usage() {
    printf("Usage: c_file_encryptor [option] filename\n");
    printf("Options:\n");
    printf("  -e  Encrypt the file\n");
    printf("  -d  Decrypt the file\n");
}

// Main function
int main(int argc, char* argv[]) {
    // Check the number of arguments
    if (argc < 3) {
        print_usage();
        return 1;
    }

    // Get the option and the filename
    char option = argv[1][1];
    char* filename = argv[2];

    // Open the file
    FILE* file = fopen(filename, "r+");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Encrypt or decrypt the file
    if (option == 'e') {
        // Encrypt the file
        char* encrypted_str = encrypt_string(filename);
        fwrite(encrypted_str, strlen(encrypted_str), 1, file);
    } else if (option == 'd') {
        // Decrypt the file
        char* decrypted_str = decrypt_string(filename);
        fwrite(decrypted_str, strlen(decrypted_str), 1, file);
    } else {
        // Invalid option
        print_usage();
        return 1;
    }

    // Close the file
    fclose(file);

    return 0;
}