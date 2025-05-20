//FormAI DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <stdlib.h>

/* Generate random key for encryption */
int* generate_key(int length) {
    int* key = (int*) malloc(length * sizeof(int));
    for(int i = 0; i < length; i++) {
        key[i] = rand() % 26; // limit key values to 26 (1 letter in the alphabet)
    }
    return key;
}

/* Encrypt a message using a given key */
char* encrypt_message(char* message, int* key, int key_len) {
    int message_len = strlen(message);
    char* encrypted_message = (char*) malloc(message_len * sizeof(char));

    for(int i = 0; i < message_len; i++) {
        char letter = message[i];
        int key_index = i % key_len; // loop through the key if message is longer than key
        int key_value = key[key_index];
        char encrypted_letter = letter + key_value;
        if(encrypted_letter > 'z') { // handle overflow by wrapping around to 'a'
            encrypted_letter = encrypted_letter - 'z' + 'a' - 1;
        }
        encrypted_message[i] = encrypted_letter;
    }
    encrypted_message[message_len] = '\0'; // add null terminator
    return encrypted_message;
}

int main() {
    char* message = "this is a secret message";
    int key_length = 7;

    // generate key
    int* key = generate_key(key_length);

    // display key
    printf("Key: ");
    for(int i = 0; i < key_length; i++) {
        printf("%d ", key[i]);
    }
    printf("\n");

    // encrypt message
    char* encrypted_message = encrypt_message(message, key, key_length);

    // display encrypted message
    printf("Encrypted message: %s\n", encrypted_message);

    // free allocated memory
    free(key);
    free(encrypted_message);

    return 0;
}