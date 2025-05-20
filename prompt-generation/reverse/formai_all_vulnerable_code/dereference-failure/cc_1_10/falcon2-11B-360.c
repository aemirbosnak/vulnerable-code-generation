//Falcon2-11B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Public-Key Algorithm Implementation

typedef struct {
    int key_length;
    char* public_key;
    char* private_key;
} key_pair;

key_pair generate_key_pair() {
    key_pair kp;
    int key_length = 256;
    char* public_key = (char*)malloc(key_length * sizeof(char));
    char* private_key = (char*)malloc(key_length * sizeof(char));
    for (int i = 0; i < key_length; i++) {
        public_key[i] = 'a' + rand() % 26;
        private_key[i] = 'a' + rand() % 26;
    }
    kp.key_length = key_length;
    kp.public_key = public_key;
    kp.private_key = private_key;
    return kp;
}

char* encrypt(char* message, key_pair kp) {
    char* encrypted_message = (char*)malloc(strlen(message) * sizeof(char));
    for (int i = 0; i < strlen(message); i++) {
        int offset = (int)(kp.public_key[i] - 'a');
        encrypted_message[i] = message[offset];
    }
    return encrypted_message;
}

char* decrypt(char* encrypted_message, key_pair kp) {
    char* decrypted_message = (char*)malloc(strlen(encrypted_message) * sizeof(char));
    for (int i = 0; i < strlen(encrypted_message); i++) {
        int offset = (int)(kp.private_key[i] - 'a');
        decrypted_message[i] = encrypted_message[offset];
    }
    return decrypted_message;
}

int main() {
    key_pair kp = generate_key_pair();
    printf("Public Key: %s\n", kp.public_key);
    printf("Private Key: %s\n", kp.private_key);
    char* message = "Hello, World!";
    char* encrypted = encrypt(message, kp);
    printf("Encrypted: %s\n", encrypted);
    char* decrypted = decrypt(encrypted, kp);
    printf("Decrypted: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    free(kp.public_key);
    free(kp.private_key);
    return 0;
}