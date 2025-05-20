//FormAI DATASET v1.0 Category: Modern Encryption ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

char* generate_key() {
    char* key = malloc(26 * sizeof(char));
    for(int i = 0; i < 26; i++) {
        key[i] = (char) (i + 65); // A - Z
    }
    // Shuffle the key
    srand(time(NULL));
    for(int i = 0; i < 26; i++) {
        int j = rand() % 26;
        char temp = key[i];
        key[i] = key[j];
        key[j] = temp;
    }
    return key;
}

char* encrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    char* encrypted_message = malloc((message_length + 1) * sizeof(char));
    memset(encrypted_message, 0, message_length + 1);
    for(int i = 0; i < message_length; i++) {
        if(message[i] < 65 || message[i] > 90) {
            encrypted_message[i] = message[i];
        } else {
            encrypted_message[i] = key[message[i] - 65];
        }
    }
    return encrypted_message;
}

char* decrypt_message(char* message, char* key) {
    int message_length = strlen(message);
    char* decrypted_message = malloc((message_length + 1) * sizeof(char));
    memset(decrypted_message, 0, message_length + 1);
    for(int i = 0; i < message_length; i++) {
        if(message[i] < 65 || message[i] > 90) {
            decrypted_message[i] = message[i];
        } else {
            for(int j = 0; j < 26; j++) {
                if(key[j] == message[i]) {
                    decrypted_message[i] = (char) (j + 65);
                    break;
                }
            }
        }
    }
    return decrypted_message;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter a message to encrypt (A-Z only): ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove the newline character
    char* key = generate_key();
    printf("\nGenerated Key: %s\n", key);
    char* encrypted_message = encrypt_message(input, key);
    printf("Encrypted Message: %s\n", encrypted_message);
    char* decrypted_message = decrypt_message(encrypted_message, key);
    printf("Decrypted Message: %s\n", decrypted_message);
    free(key);
    free(encrypted_message);
    free(decrypted_message);
    return 0;
}