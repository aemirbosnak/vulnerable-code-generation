//FormAI DATASET v1.0 Category: Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message using Caesar cipher
char* encrypt(char* message, int key) {
    char* result = (char*) malloc(sizeof(char) * (strlen(message) + 1));
    int i;
    for(i = 0; i < strlen(message); i++) {
        char c = message[i];
        if(c >= 'a' && c <= 'z') {
            c = (c + key - 'a') % 26 + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = (c + key - 'A') % 26 + 'A';
        }
        result[i] = c;
    }
    result[i] = '\0';

    return result;
}

// Function to decrypt the message using Caesar cipher
char* decrypt(char* message, int key) {
    char* result = (char*) malloc(sizeof(char) * (strlen(message) + 1));
    int i;
    for(i = 0; i < strlen(message); i++) {
        char c = message[i];
        if(c >= 'a' && c <= 'z') {
            c = (c - key - 'a' + 26) % 26 + 'a';
        } else if(c >= 'A' && c <= 'Z') {
            c = (c - key - 'A' + 26) % 26 + 'A';
        }
        result[i] = c;
    }
    result[i] = '\0';

    return result;
}

int main() {
    // Get the message to encrypt from the user
    char message[100];
    printf("Enter the message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    // Get the key from the user
    int key;
    printf("Enter the key (a number between 1 and 25): ");
    scanf("%d", &key);

    // Encrypt the message
    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message
    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    // Free the dynamically allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}