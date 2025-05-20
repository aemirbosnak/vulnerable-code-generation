//FormAI DATASET v1.0 Category: Modern Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "secretpassword"

char* encrypt(char* plaintext);
char* decrypt(char* ciphertext);

int main(void) {
    char message[1000];
    char* ciphertext;
    char* decrypted_message;

    printf("Please enter a message to encrypt: ");
    fgets(message, 1000, stdin);

    ciphertext = encrypt(message);
    printf("Encrypted message: \n%s\n", ciphertext);

    decrypted_message = decrypt(ciphertext);
    printf("Decrypted message: \n%s\n", decrypted_message);

    free(ciphertext);
    free(decrypted_message);

    return 0;
}

char* encrypt(char* plaintext) {
    char* ciphertext;
    int key_length = strlen(KEY);
    int message_length = strlen(plaintext);
    int i;

    ciphertext = (char*) malloc(message_length * sizeof(char));

    for (i = 0; i < message_length; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % key_length];
    }

    return ciphertext;
}

char* decrypt(char* ciphertext) {
    char* plaintext;
    int key_length = strlen(KEY);
    int message_length = strlen(ciphertext);
    int i;

    plaintext = (char*) malloc(message_length * sizeof(char));

    for (i = 0; i < message_length; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % key_length];
    }

    return plaintext;
}