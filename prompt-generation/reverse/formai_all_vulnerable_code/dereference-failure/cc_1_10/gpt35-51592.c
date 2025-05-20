//FormAI DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt_message(char* message, int key);
char* decrypt_message(char* message, int key);

int main() {
    printf("Welcome to the Encrypt-O-Matic 3000!\n");
    printf("Please enter the message you want to encrypt: ");

    char message[1000];
    fgets(message, sizeof(message), stdin);

    printf("Please enter the encryption key: ");

    int key;
    scanf("%d", &key);

    char* encrypted_message = encrypt_message(message, key);

    printf("Your encrypted message is: %s\n", encrypted_message);

    char* decrypted_message = decrypt_message(encrypted_message, key);

    printf("Your decrypted message is: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}

char* encrypt_message(char* message, int key) {
    int length = strlen(message);

    char* encrypted_message = (char*) malloc(length * sizeof(char));

    for(int i = 0; i < length; i++) {
        encrypted_message[i] = (char) (message[i] + key);
    }

    return encrypted_message;
}

char* decrypt_message(char* message, int key) {
    int length = strlen(message);

    char* decrypted_message = (char*) malloc(length * sizeof(char));

    for(int i = 0; i < length; i++) {
        decrypted_message[i] = (char) (message[i] - key);
    }

    return decrypted_message;
}