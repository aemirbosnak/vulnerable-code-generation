//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void encrypt(char* message, char* key) {
    int key_length = strlen(key);
    int message_length = strlen(message);

    char encrypted[message_length];
    for (int i = 0; i < message_length; i++) {
        char letter = message[i];
        int index = (letter - 'A') + (key_length * (i % key_length));
        if (index > 25)
            index -= 26;
        encrypted[i] = (char)(index + 'A');
    }

    printf("Encrypted message: %s\n", encrypted);
}

void decrypt(char* encrypted_message, char* key) {
    int key_length = strlen(key);
    int encrypted_message_length = strlen(encrypted_message);

    char decrypted[encrypted_message_length];
    for (int i = 0; i < encrypted_message_length; i++) {
        char letter = encrypted_message[i];
        int index = (letter - 'A') - (key_length * (i % key_length));
        if (index < 0)
            index += 26;
        decrypted[i] = (char)(index + 'A');
    }

    printf("Decrypted message: %s\n", decrypted);
}

int main() {
    char message[100];
    char key[100];

    printf("Enter a message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter a key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(message, key);
    decrypt(message, key);

    return 0;
}