//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_DATA_SIZE 1024

void generate_key(char *key, int size) {
    int i;
    for (i = 0; i < size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[size] = '\0';
}

void encrypt(char *data, char *key) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(data); i++) {
        if (isalpha(data[i])) {
            data[i] = (data[i] - 'a' + j) % 26 + 'a';
        } else {
            data[i] = data[i];
        }
        j = (j + 1) % strlen(key);
    }
}

void decrypt(char *data, char *key) {
    int i, j, k;
    for (i = 0, j = 0; i < strlen(data); i++) {
        if (isalpha(data[i])) {
            data[i] = (data[i] - 'a' - j + 26) % 26 + 'a';
        } else {
            data[i] = data[i];
        }
        j = (j + 1) % strlen(key);
    }
}

int main() {
    char key[MAX_KEY_SIZE];
    generate_key(key, strlen(key));
    printf("Key: %s\n", key);

    char data[MAX_DATA_SIZE];
    printf("Enter data to encrypt: ");
    fgets(data, MAX_DATA_SIZE, stdin);

    encrypt(data, key);
    printf("Encrypted data: %s\n", data);

    decrypt(data, key);
    printf("Decrypted data: %s\n", data);

    return 0;
}