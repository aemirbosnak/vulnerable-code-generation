//Falcon2-11B DATASET v1.0 Category: Encryption ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt a string using Caesar cipher
char* encrypt(char* str, int shift) {
    int len = strlen(str);
    char* encrypted = (char*)malloc(sizeof(char) * (len + 1));
    if (encrypted == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        encrypted[i] = (char)((str[i] + shift - 'a') % 26 + 'a');
    }
    encrypted[len] = '\0';
    return encrypted;
}

// Function to decrypt a string using Caesar cipher
char* decrypt(char* str, int shift) {
    int len = strlen(str);
    char* decrypted = (char*)malloc(sizeof(char) * (len + 1));
    if (decrypted == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    for (int i = 0; i < len; i++) {
        decrypted[i] = (char)((str[i] - shift - 'a') % 26 + 'a');
    }
    decrypted[len] = '\0';
    return decrypted;
}

int main() {
    char* message = "Hello, world!";
    char* encrypted = encrypt(message, 3);
    if (encrypted!= NULL) {
        printf("Encrypted message: %s\n", encrypted);
        free(encrypted);
    }

    char* decrypted = decrypt(encrypted, 3);
    if (decrypted!= NULL) {
        printf("Decrypted message: %s\n", decrypted);
        free(decrypted);
    }

    return 0;
}