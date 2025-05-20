//Falcon2-11B DATASET v1.0 Category: Modern Encryption ; Style: careful
#include <stdio.h>
#include <string.h>

// Encrypts a string using the Caesar cipher
char* encrypt(const char* str, int shift) {
    char* result = (char*)malloc(strlen(str) * sizeof(char));

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c += shift;
        } else if (c >= 'A' && c <= 'Z') {
            c += shift - 26;
        }
        result[i] = c;
    }

    result[strlen(str)] = '\0'; // null-terminate the string

    return result;
}

// Decrypts a string using the Caesar cipher
char* decrypt(const char* str, int shift) {
    char* result = (char*)malloc(strlen(str) * sizeof(char));

    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c -= shift;
        } else if (c >= 'A' && c <= 'Z') {
            c -= shift - 26;
        }
        result[i] = c;
    }

    result[strlen(str)] = '\0'; // null-terminate the string

    return result;
}

int main() {
    char* str = "Hello, World!";
    int shift = 2;

    // Encrypt the string
    char* encrypted = encrypt(str, shift);
    printf("Encrypted string: %s\n", encrypted);

    // Decrypt the encrypted string
    char* decrypted = decrypt(encrypted, shift);
    printf("Decrypted string: %s\n", decrypted);

    // Free the allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}