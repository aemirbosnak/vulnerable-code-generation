//FormAI DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

void encrypt(char *message, int key) {
    char *encrypted = (char*)malloc(sizeof(char) * (strlen(message) + 1));
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            encrypted[i] = (((message[i] - 'a') + key) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            encrypted[i] = (((message[i] - 'A') + key) % 26) + 'A';
        }
        else {
            encrypted[i] = message[i];
        }
    }
    encrypted[i] = '\0';
    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char *message, int key) {
    char *decrypted = (char*)malloc(sizeof(char) * (strlen(message) + 1));
    int i;
    for(i = 0; message[i] != '\0'; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            decrypted[i] = (((message[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if(message[i] >= 'A' && message[i] <= 'Z') {
            decrypted[i] = (((message[i] - 'A') - key + 26) % 26) + 'A';
        }
        else {
            decrypted[i] = message[i];
        }
    }
    decrypted[i] = '\0';
    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[1000];
    int key;
    printf("Enter message to encrypt: ");
    fgets(message, 1000, stdin);
    printf("Enter key: ");
    scanf("%d", &key);
    printf("Original message: %s", message);
    encrypt(message, key);
    decrypt(message, key);
    return 0;
}