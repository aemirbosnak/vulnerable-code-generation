//Falcon-180B DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 100 // Maximum length of encryption key
#define MAX_MESSAGE_LENGTH 1000 // Maximum length of message to be encrypted

typedef struct {
    char key[MAX_KEY_LENGTH]; // Encryption key
    int key_length; // Length of encryption key
} EncryptionContext;

void generate_key(EncryptionContext *context) {
    char key[MAX_KEY_LENGTH] = {0};
    int key_length = 0;
    
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    
    // Remove trailing newline character
    key[strcspn(key, "\n")] = '\0';
    
    // Convert all characters to uppercase
    for (int i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }
    
    context->key_length = strlen(key);
    strncpy(context->key, key, context->key_length);
}

void encrypt_message(EncryptionContext *context, char *message) {
    int message_length = strlen(message);
    
    // Check if message is too long
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Message is too long.\n");
        exit(1);
    }
    
    char encrypted_message[MAX_MESSAGE_LENGTH] = {0};
    int encrypted_message_length = 0;
    
    // Encrypt message using Caesar cipher
    for (int i = 0; i < message_length; i++) {
        char c = message[i];
        if (isalpha(c)) {
            char k = context->key[i % context->key_length];
            if (isupper(c)) {
                encrypted_message[encrypted_message_length++] = (c - 'A' + k - 'A') % 26 + 'A';
            } else {
                encrypted_message[encrypted_message_length++] = (c - 'a' + k - 'a') % 26 + 'a';
            }
        } else {
            encrypted_message[encrypted_message_length++] = c;
        }
    }
    
    printf("Encrypted message: %s\n", encrypted_message);
}

int main() {
    EncryptionContext context;
    generate_key(&context);
    
    char message[MAX_MESSAGE_LENGTH] = {0};
    printf("Enter message to be encrypted: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    
    // Remove trailing newline character
    message[strcspn(message, "\n")] = '\0';
    
    encrypt_message(&context, message);
    
    return 0;
}