//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LEN 1000

char *generateKey(int len);
char *encrypt(char *key, char *msg);
char *decrypt(char *key, char *encrypted);

int main(void) {
    char message[MAX_LEN] = "Secret Message";
    char *key = generateKey(strlen(message));
    char *encrypted = encrypt(key, message);
    char *decrypted = decrypt(key, encrypted);

    printf("Original message: %s\n", message);
    printf("Key: %s\n", key);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    free(key);
    free(encrypted);
    free(decrypted);

    return 0;
}

char *generateKey(int len) {
    char *key = malloc((len + 1) * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 256;
    }
    key[len] = '\0';
    return key;
}

char *encrypt(char *key, char *msg) {
    int len = strlen(msg);
    char *encrypted = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        encrypted[i] = msg[i] ^ key[i];
    }
    encrypted[len] = '\0';
    return encrypted;
}

char *decrypt(char *key, char *encrypted) {
    int len = strlen(encrypted);
    char *decrypted = malloc((len + 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        decrypted[i] = encrypted[i] ^ key[i];
    }
    decrypted[len] = '\0';
    return decrypted;
}