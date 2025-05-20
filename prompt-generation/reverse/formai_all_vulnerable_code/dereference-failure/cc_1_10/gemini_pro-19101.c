//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the substitution alphabet
const char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
const char encrypted[] = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA0987654321";

// Encrypt a single character
char encryptChar(char c) {
    int index = strchr(alphabet, c) - alphabet;
    if (index >= 0) {
        return encrypted[index];
    } else {
        return c;
    }
}

// Encrypt a string
char* encryptString(char* str) {
    int len = strlen(str);
    char* encrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        encrypted[i] = encryptChar(str[i]);
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Decrypt a single character
char decryptChar(char c) {
    int index = strchr(encrypted, c) - encrypted;
    if (index >= 0) {
        return alphabet[index];
    } else {
        return c;
    }
}

// Decrypt a string
char* decryptString(char* str) {
    int len = strlen(str);
    char* decrypted = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        decrypted[i] = decryptChar(str[i]);
    }
    decrypted[len] = '\0';
    return decrypted;
}

// Print the usage information
void printUsage() {
    printf("Usage: ./encryption [-e|-d] <string>\n");
    printf("Options:\n");
    printf("  -e  Encrypt the string\n");
    printf("  -d  Decrypt the string\n");
}

// Main function
int main(int argc, char** argv) {
    // Check the number of arguments
    if (argc != 3) {
        printUsage();
        return 1;
    }

    // Get the option and the string
    char* option = argv[1];
    char* str = argv[2];

    // Encrypt or decrypt the string depending on the option
    char* result;
    if (strcmp(option, "-e") == 0) {
        result = encryptString(str);
    } else if (strcmp(option, "-d") == 0) {
        result = decryptString(str);
    } else {
        printUsage();
        return 1;
    }

    // Print the result
    printf("%s\n", result);

    // Free the allocated memory
    free(result);

    return 0;
}