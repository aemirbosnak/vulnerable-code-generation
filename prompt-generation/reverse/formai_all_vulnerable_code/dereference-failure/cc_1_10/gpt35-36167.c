//FormAI DATASET v1.0 Category: modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

char* encrypt(char* message) {
    int len = strlen(message);
    char* encrypted = malloc(sizeof(char) * len + 1);
    int keyLen = strlen(KEY);
    int i, j;

    for(i = 0, j = 0; i < len; ++i, ++j) {
        if(j == keyLen)
            j = 0;
        encrypted[i] = message[i] ^ KEY[j];
    }

    encrypted[i] = '\0';
    return encrypted;
}

char* decrypt(char* encrypted) {
    int len = strlen(encrypted);
    char* decrypted = malloc(sizeof(char) * len + 1);
    int keyLen = strlen(KEY);
    int i, j;

    for(i = 0, j = 0; i < len; ++i, ++j) {
        if(j == keyLen)
            j = 0;
        decrypted[i] = encrypted[i] ^ KEY[j];
    }

    decrypted[i] = '\0';
    return decrypted;
}

int main() {
    char message[] = "Encrypt me!";
    printf("Original message: %s\n", message);

    char* encrypted = encrypt(message);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}