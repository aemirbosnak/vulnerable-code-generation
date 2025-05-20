//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_DATA_LENGTH 1024

typedef struct {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
    char encrypted[MAX_DATA_LENGTH];
} Encryption;

Encryption* createEncryption() {
    Encryption* encryption = (Encryption*)malloc(sizeof(Encryption));
    strcpy(encryption->key, "default_key");
    strcpy(encryption->data, "");
    strcpy(encryption->encrypted, "");
    return encryption;
}

void destroyEncryption(Encryption* encryption) {
    free(encryption);
}

void generateRandomKey(Encryption* encryption) {
    srand(time(NULL));
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        encryption->key[i] = rand() % 26 + 'a';
    }
    encryption->key[MAX_KEY_LENGTH - 1] = '\0';
}

void encryptData(Encryption* encryption) {
    int keyIndex = 0;
    for (int i = 0; i < strlen(encryption->data); i++) {
        encryption->encrypted[i] = encryption->data[i] ^ encryption->key[keyIndex];
        keyIndex = (keyIndex + 1) % MAX_KEY_LENGTH;
    }
    encryption->encrypted[strlen(encryption->data)] = '\0';
}

void decryptData(Encryption* encryption) {
    int keyIndex = 0;
    for (int i = 0; i < strlen(encryption->encrypted); i++) {
        encryption->data[i] = encryption->encrypted[i] ^ encryption->key[keyIndex];
        keyIndex = (keyIndex + 1) % MAX_KEY_LENGTH;
    }
    encryption->data[strlen(encryption->encrypted)] = '\0';
}

int main() {
    Encryption* encryption = createEncryption();
    generateRandomKey(encryption);
    printf("Key: %s\n", encryption->key);
    printf("Data: ");
    scanf("%s", encryption->data);
    encryptData(encryption);
    printf("Encrypted Data: %s\n", encryption->encrypted);
    decryptData(encryption);
    printf("Decrypted Data: %s\n", encryption->data);
    destroyEncryption(encryption);
    return 0;
}