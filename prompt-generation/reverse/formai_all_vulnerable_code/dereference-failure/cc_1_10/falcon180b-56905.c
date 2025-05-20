//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void generate_key(char *key) {
    for(int i=0; i<KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *message, char *key, char *ciphertext) {
    int message_len = strlen(message);
    int key_len = strlen(key);

    for(int i=0; i<message_len; i++) {
        if(message[i] >= 'a' && message[i] <= 'z') {
            int j = (int)message[i] - 97;
            int k = (int)key[i % key_len] - 97;
            int sum = j + k;
            if(sum > 25) {
                sum -= 26;
            }
            ciphertext[i] = sum + 97;
        } else {
            ciphertext[i] = message[i];
        }
    }
}

void decrypt(char *ciphertext, char *key, char *message) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);

    for(int i=0; i<ciphertext_len; i++) {
        if(ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            int j = (int)ciphertext[i] - 97;
            int k = (int)key[i % key_len] - 97;
            int sum = j - k;
            if(sum < 0) {
                sum += 26;
            }
            message[i] = sum + 97;
        } else {
            message[i] = ciphertext[i];
        }
    }
}

int main() {
    char message[100] = "secret message";
    char key[KEY_SIZE] = "";
    generate_key(key);
    char ciphertext[100] = "";
    encrypt(message, key, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);
    char decrypted_message[100] = "";
    decrypt(ciphertext, key, decrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);
    return 0;
}