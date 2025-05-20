//FormAI DATASET v1.0 Category: Modern Encryption ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MSG_LEN 256
#define MAX_KEY_LEN 16

char* encrypt_message(char* message, char* key);
char* decrypt_message(char* encrypted_message, char* key);
char* generate_key(int key_len);
int paranoia_check();

int main() {
    char message[MAX_MSG_LEN];
    char encrypted_message[MAX_MSG_LEN];
    char* key;
    int key_len;

    // Prompt user for message and key length
    printf("Enter the message to encrypt (max %d characters):\n", MAX_MSG_LEN);
    fgets(message, MAX_MSG_LEN, stdin);
    printf("Enter the desired key length (max %d characters):\n", MAX_KEY_LEN);
    scanf("%d", &key_len);

    // Generate encryption key
    key = generate_key(key_len);

    // Encrypt the message and print the encrypted message
    strcpy(encrypted_message, encrypt_message(message, key));
    printf("\nEncrypted message:\n%s", encrypted_message);

    // Decrypt the encrypted message and print the decrypted message
    printf("\n\nEnter the key to decrypt the message:\n");
    scanf("%s", key);
    printf("\nDecrypted message:\n%s", decrypt_message(encrypted_message, key));

    return 0;
}

/**
 * Encrypts a message using a provided key
 */
char* encrypt_message(char* message, char* key) {
    char* encrypted_message = malloc(strlen(message) * sizeof(char));
    int key_index = 0;

    for (int i = 0; i < strlen(message); i++) {
        // Use paranoia check to ensure randomization
        paranoia_check();

        // Apply XOR algorithm with key and current character
        encrypted_message[i] = message[i] ^ key[key_index];
        
        // Increment key index and loop back to the start of the key if necessary
        key_index = (key_index + 1) % strlen(key);
    }

    return encrypted_message;
}

/**
 * Decrypts an encrypted message using a provided key
 */
char* decrypt_message(char* encrypted_message, char* key) {
    char* decrypted_message = malloc(strlen(encrypted_message) * sizeof(char));
    int key_index = 0;

    for (int i = 0; i < strlen(encrypted_message); i++) {
        // Use paranoia check to ensure randomization
        paranoia_check();

        // Apply XOR algorithm with key and current character
        decrypted_message[i] = encrypted_message[i] ^ key[key_index];
        
        // Increment key index and loop back to the start of the key if necessary
        key_index = (key_index + 1) % strlen(key);
    }

    return decrypted_message;
}

/**
 * Generates a random encryption key of a specified length
 */
char* generate_key(int key_len) {
    char* key = malloc(key_len * sizeof(char));

    for (int i = 0; i < key_len; i++) {
        // Use paranoia check to ensure randomization
        paranoia_check();

        // Generate a random ASCII character
        key[i] = (char)(rand() % 128);
    }

    return key;
}

/**
 * Performs a paranoia check by sleeping for a random number of microseconds between 1 and 1000
 */
int paranoia_check() {
    int sleep_time = rand() % 1000 + 1;
    struct timespec sleep_timespec = {0, sleep_time * 1000};

    // Sleep for the specified amount of time
    nanosleep(&sleep_timespec, NULL);

    return 0;
}