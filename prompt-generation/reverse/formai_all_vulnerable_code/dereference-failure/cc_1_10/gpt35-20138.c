//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to generate a random key
char *generate_key(int key_len) {
    char *key = (char *)malloc(sizeof(char) * (key_len + 1));
    srand(time(NULL));
    for(int i = 0; i < key_len; i++) {
        key[i] = (char)(rand() % 256);
    }
    key[key_len] = '\0';
    return key;
}

// function to perform XOR encryption on input message with given key
void encrypt(char *message, char *key, int message_len) {
    for(int i = 0; i < message_len; i++) {
        message[i] ^= key[i % strlen(key)];
    }
}

// function to perform XOR decryption on input message with given key
void decrypt(char *message, char *key, int message_len) {
    for(int i = 0; i < message_len; i++) {
        message[i] ^= key[i % strlen(key)];
    }
}

// function to print the encrypted and decrypted messages
void print_messages(char *message, char *key, int message_len) {
    char *encrypted = (char *)malloc(sizeof(char) * (message_len + 1));
    char *decrypted = (char *)malloc(sizeof(char) * (message_len + 1));
    strcpy(encrypted, message);  // make a copy of the message
    strcpy(decrypted, message);  // make another copy of the message
    encrypt(encrypted, key, message_len);  // encrypt the message
    decrypt(decrypted, key, message_len);  // decrypt the message
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);
    free(encrypted);  // free the memory used by encrypted and decrypted messages
    free(decrypted);
}

int main() {
    char *message = "Hello, world!";  // message to be encrypted and decrypted
    int message_len = strlen(message);  // length of the message
    char *key = generate_key(message_len);  // generate a random key
    print_messages(message, key, message_len);  // print the messages
    free(key);  // free the memory used by the key
    return 0;
}