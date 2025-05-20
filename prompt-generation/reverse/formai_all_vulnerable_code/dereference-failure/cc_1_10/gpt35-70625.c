//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 8
#define BUFFER_SIZE 1024

char *encrypt(char *);
char *decrypt(char *);

int main(int argc, char *argv[]) {
    char message[BUFFER_SIZE], *encrypted_message, *decrypted_message;

    printf("Enter the message to encrypt: ");
    fgets(message, BUFFER_SIZE, stdin);

    encrypted_message = encrypt(message);
    printf("Encrypted message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}

char *encrypt(char *plaintext) {
    char *ciphertext = malloc(BUFFER_SIZE * sizeof(char));
    char key[KEY_LENGTH];
    int i;

    for(i = 0; i < KEY_LENGTH; i++) {
        key[i] = rand() % 26 + 'a';
    }

    sprintf(ciphertext, "%s%s", key, plaintext);

    for(i = 0; i < strlen(plaintext); i++) {
        ciphertext[i + KEY_LENGTH] = ((plaintext[i] - 'a') + (key[i % KEY_LENGTH] - 'a')) % 26 + 'a';
    }

    ciphertext[strlen(plaintext) + KEY_LENGTH] = '\0';

    return ciphertext;
}

char *decrypt(char *ciphertext) {
    char *plaintext = malloc(BUFFER_SIZE * sizeof(char));
    char key[KEY_LENGTH];
    int i;

    strncpy(key, ciphertext, KEY_LENGTH);

    for(i = 0; i < strlen(ciphertext) - KEY_LENGTH; i++) {
        plaintext[i] = ((ciphertext[i + KEY_LENGTH] - 'a') - (key[i % KEY_LENGTH] - 'a') + 26) % 26 + 'a';
    }

    plaintext[strlen(ciphertext) - KEY_LENGTH] = '\0';

    return plaintext;
}