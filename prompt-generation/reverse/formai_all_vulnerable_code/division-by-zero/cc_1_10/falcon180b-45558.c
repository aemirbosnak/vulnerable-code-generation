//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_DATA_SIZE 1024

void generate_key(char *key, int key_size) {
    int i;
    for (i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

void encrypt(char *data, char *key, int key_size) {
    int i, j;
    for (i = 0, j = 0; i < strlen(data); i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = 'a' + ((data[i] - 'a' + key[j]) % 26);
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = 'A' + ((data[i] - 'A' + key[j]) % 26);
        }
        j = (j + 1) % key_size;
    }
}

void decrypt(char *data, char *key, int key_size) {
    int i, j;
    for (i = 0, j = 0; i < strlen(data); i++) {
        if (data[i] >= 'a' && data[i] <= 'z') {
            data[i] = 'a' + (((data[i] - 'a' - key[j]) % 26) + 26) % 26;
        } else if (data[i] >= 'A' && data[i] <= 'Z') {
            data[i] = 'A' + (((data[i] - 'A' - key[j]) % 26) + 26) % 26;
        }
        j = (j + 1) % key_size;
    }
}

int main() {
    char data[MAX_DATA_SIZE];
    char key[MAX_KEY_SIZE];

    printf("Enter data to encrypt: ");
    fgets(data, MAX_DATA_SIZE, stdin);

    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    generate_key(key, strlen(key));

    encrypt(data, key, strlen(key));

    printf("Encrypted data: %s\n", data);

    printf("Enter decryption key: ");
    fgets(key, MAX_KEY_SIZE, stdin);

    decrypt(data, key, strlen(key));

    printf("Decrypted data: %s\n", data);

    return 0;
}