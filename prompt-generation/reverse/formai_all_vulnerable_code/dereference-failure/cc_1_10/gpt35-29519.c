//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the message
char* encrypt(char* message, int key)
{
    char* encrypted_message = (char*)malloc((strlen(message) + 1) * sizeof(char));

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            encrypted_message[i] = (((message[i] - 'a') + key) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            encrypted_message[i] = (((message[i] - 'A') + key) % 26) + 'A';
        }
        else {
            encrypted_message[i] = message[i];
        }
    }
    encrypted_message[strlen(message)] = '\0';

    return encrypted_message;
}

// Function to decrypt the message
char* decrypt(char* message, int key)
{
    char* decrypted_message = (char*)malloc((strlen(message) + 1) * sizeof(char));

    for (int i = 0; i < strlen(message); i++) {
        if (message[i] >= 'a' && message[i] <= 'z') {
            decrypted_message[i] = (((message[i] - 'a') - key + 26) % 26) + 'a';
        }
        else if (message[i] >= 'A' && message[i] <= 'Z') {
            decrypted_message[i] = (((message[i] - 'A') - key + 26) % 26) + 'A';
        }
        else {
            decrypted_message[i] = message[i];
        }
    }
    decrypted_message[strlen(message)] = '\0';

    return decrypted_message;
}

int main()
{
    char message[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);
    message[strlen(message) - 1] = '\0';

    printf("Enter key: ");
    scanf("%d", &key);

    char* encrypted = encrypt(message, key);
    printf("Encrypted message: %s\n", encrypted);

    char* decrypted = decrypt(encrypted, key);
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}