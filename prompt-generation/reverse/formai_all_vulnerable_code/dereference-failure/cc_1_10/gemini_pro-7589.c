//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char *message;
    int message_len;
} EncryptedMessage;

EncryptedMessage *encrypt_message(char *message, int key) {
    EncryptedMessage *encrypted_message = malloc(sizeof(EncryptedMessage));
    encrypted_message->key = key;
    encrypted_message->message_len = strlen(message);
    encrypted_message->message = malloc(encrypted_message->message_len + 1);
    strcpy(encrypted_message->message, message);

    for (int i = 0; i < encrypted_message->message_len; i++) {
        encrypted_message->message[i] ^= key;
    }

    return encrypted_message;
}

char *decrypt_message(EncryptedMessage *encrypted_message) {
    char *decrypted_message = malloc(encrypted_message->message_len + 1);
    strcpy(decrypted_message, encrypted_message->message);

    for (int i = 0; i < encrypted_message->message_len; i++) {
        decrypted_message[i] ^= encrypted_message->key;
    }

    return decrypted_message;
}

int main() {
    char *message = "Hello, world!";
    int key = 42;

    EncryptedMessage *encrypted_message = encrypt_message(message, key);

    printf("Encrypted message: %s\n", encrypted_message->message);

    char *decrypted_message = decrypt_message(encrypted_message);

    printf("Decrypted message: %s\n", decrypted_message);

    free(encrypted_message->message);
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}