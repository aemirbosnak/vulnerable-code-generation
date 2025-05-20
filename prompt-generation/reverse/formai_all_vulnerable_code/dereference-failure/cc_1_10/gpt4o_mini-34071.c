//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt text using a simple Caesar cipher
void encrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        // Encrypt uppercase letters
        if (isupper(text[i])) {
            text[i] = (text[i] + shift - 'A') % 26 + 'A';
        } 
        // Encrypt lowercase letters
        else if (islower(text[i])) {
            text[i] = (text[i] + shift - 'a') % 26 + 'a';
        }
        // Ignore non-alphabetical characters
    }
}

// Function to decrypt text using a simple Caesar cipher
void decrypt(char *text, int shift) {
    int i;
    for (i = 0; text[i] != '\0'; ++i) {
        // Decrypt uppercase letters
        if (isupper(text[i])) {
            text[i] = (text[i] - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(text[i])) {
            text[i] = (text[i] - shift - 'a' + 26) % 26 + 'a';
        }
        // Ignore non-alphabetical characters
    }
}

// Function to read text from a file
char *readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = malloc(length + 1);
    if (content) {
        fread(content, 1, length, file);
        content[length] = '\0'; // Null-terminate the string
    }

    fclose(file);
    return content;
}

// Function to write text to a file
void writeToFile(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    
    fprintf(file, "%s", text);
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <encrypt/decrypt> <shift> <filename>\n", argv[0]);
        return 1;
    }

    char *operation = argv[1];
    int shift = atoi(argv[2]);
    const char *filename = argv[3];

    // Read the content of the file
    char *content = readFromFile(filename);
    if (!content) {
        return 1;
    }

    // Determine if encrypting or decrypting
    if (strcmp(operation, "encrypt") == 0) {
        encrypt(content, shift);
        writeToFile("encrypted.txt", content);
        printf("Encryption complete. Encrypted text saved to 'encrypted.txt'.\n");
    } else if (strcmp(operation, "decrypt") == 0) {
        decrypt(content, shift);
        writeToFile("decrypted.txt", content);
        printf("Decryption complete. Decrypted text saved to 'decrypted.txt'.\n");
    } else {
        printf("Invalid operation. Use 'encrypt' or 'decrypt'.\n");
        free(content);
        return 1;
    }

    free(content);
    return 0;
}