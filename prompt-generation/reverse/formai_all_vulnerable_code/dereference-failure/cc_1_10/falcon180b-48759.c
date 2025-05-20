//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16 // length of encryption key
#define BLOCK_SIZE 16 // length of data block

void encrypt(char *data, char *key) {
    int i, j, n = strlen(data);
    char buffer[n + 1];
    int k = strlen(key);
    int sum = 0;

    // copy data into buffer
    strcpy(buffer, data);

    // XOR each character with key
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < k; j++) {
            if (i < n && j < k) {
                sum ^= buffer[i] ^ key[j];
            } else if (j < k) {
                sum ^= key[j];
            }
        }
        buffer[i] = sum;
    }

    // copy encrypted data back into original buffer
    strcpy(data, buffer);
}

void decrypt(char *data, char *key) {
    int i, j, n = strlen(data);
    char buffer[n + 1];
    int k = strlen(key);
    int sum = 0;

    // copy data into buffer
    strcpy(buffer, data);

    // XOR each character with key
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = 0; j < k; j++) {
            if (i < n && j < k) {
                sum ^= buffer[i] ^ key[j];
            } else if (j < k) {
                sum ^= key[j];
            }
        }
        buffer[i] = sum;
    }

    // copy decrypted data back into original buffer
    strcpy(data, buffer);
}

int main() {
    char *data = "Hello, world!";
    char *key = "secretkey123";
    int choice, n = strlen(data);

    // ask user for choice of encryption or decryption
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);

    // encrypt or decrypt data
    if (choice == 1) {
        encrypt(data, key);
        printf("Encrypted data: %s\n", data);
    } else if (choice == 2) {
        decrypt(data, key);
        printf("Decrypted data: %s\n", data);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}