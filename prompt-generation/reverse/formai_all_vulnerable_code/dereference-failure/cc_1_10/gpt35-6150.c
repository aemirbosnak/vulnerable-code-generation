//FormAI DATASET v1.0 Category: Modern Encryption ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256

unsigned char* encrypt(char* message, unsigned char* key);
void print_hex(unsigned char* data, size_t size);

int main(void) {
    char message[] = "Hello, World!";
    unsigned char key[KEY_SIZE];
    unsigned char* encrypted_message;

    // Generate random key
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256;
    }

    printf("Original Message: %s\n", message);
    printf("Key: ");
    print_hex(key, KEY_SIZE);

    // Encrypt message
    encrypted_message = encrypt(message, key);

    printf("Encrypted Message: ");
    print_hex(encrypted_message, strlen(message));

    free(encrypted_message);

    return 0;
}

unsigned char* encrypt(char* message, unsigned char* key) {
    size_t message_length = strlen(message);
    size_t key_length = KEY_SIZE;
    unsigned char* encrypted_message = (unsigned char*)malloc(message_length + 1);

    for (int i = 0; i < message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i % key_length];
    }

    encrypted_message[message_length] = '\0';

    return encrypted_message;
}

void print_hex(unsigned char* data, size_t size) {
    for (int i = 0; i < size; i++) {
        printf("%02x", data[i]);
    }

    printf("\n");
}