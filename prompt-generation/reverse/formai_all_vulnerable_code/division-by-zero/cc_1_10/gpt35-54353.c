//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void encrypt(char data[], char key[]) {
    int i, j;
    int dataLen = strlen(data);
    int keyLen = strlen(key);

    // Generating random number
    srand(time(NULL));
    int randomNum = rand() % keyLen;

    for (i = 0, j = 0; i < dataLen; ++i, ++j) {
        if (j == randomNum) {
            j = 0; // Resetting j
        }
        data[i] = data[i] ^ key[j];
    }
}

void decrypt(char data[], char key[]) {
    int i, j;
    int dataLen = strlen(data);
    int keyLen = strlen(key);

    // Generating random number
    srand(time(NULL));
    int randomNum = rand() % keyLen;

    for (i = 0, j = 0; i < dataLen; ++i, ++j) {
        if (j == randomNum) {
            j = 0; // Resetting j
        }
        data[i] = data[i] ^ key[j];
    }
}

int main() {
    char data[100], key[100];

    printf("Enter data to be encrypted: ");
    scanf("%s", data);

    printf("Enter key: ");
    scanf("%s", key);

    encrypt(data, key);
    printf("Encrypted data: %s\n", data);

    decrypt(data, key);
    printf("Original data: %s\n", data);

    return 0;
}