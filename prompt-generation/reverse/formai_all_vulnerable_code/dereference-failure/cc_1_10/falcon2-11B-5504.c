//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to encrypt a string using a simple Caesar cipher
char* encrypt(char* str, int shift) {
    int len = strlen(str);
    char* encrypted = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        int index = (str[i] - 'a' + shift) % 26;
        if (index < 0) index += 26;
        encrypted[i] = (char)(index + 'a');
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Function to decrypt a string using a simple Caesar cipher
char* decrypt(char* str, int shift) {
    int len = strlen(str);
    char* decrypted = (char*)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        int index = (str[i] - 'a' - shift) % 26;
        if (index < 0) index += 26;
        decrypted[i] = (char)(index + 'a');
    }
    decrypted[len] = '\0';
    return decrypted;
}

int main() {
    // Prompt the user for input
    printf("Enter a string to encrypt: ");
    char* str = (char*)malloc(sizeof(char) * 100);
    fgets(str, sizeof(str), stdin);

    // Encrypt the string
    printf("Encrypted string: %s\n", encrypt(str, 5));

    // Prompt the user for input
    printf("Enter a string to decrypt: ");
    char* str2 = (char*)malloc(sizeof(char) * 100);
    fgets(str2, sizeof(str2), stdin);

    // Decrypt the string
    printf("Decrypted string: %s\n", decrypt(str2, 5));

    free(str);
    free(str2);
    return 0;
}