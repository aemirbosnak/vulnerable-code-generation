//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 256

int main() {
    char message[1000];
    char key[SIZE];
    char encrypted[1000];
    char decrypted[1000];
    int i, j, k, n;

    // Get the message from the user
    printf("Enter the message to encrypt: ");
    fgets(message, 1000, stdin);

    // Get the encryption key from the user
    printf("Enter the encryption key: ");
    fgets(key, SIZE, stdin);

    // Convert the key to uppercase
    for (i = 0; i < strlen(key); i++) {
        key[i] = toupper(key[i]);
    }

    // Encrypt the message using the key
    for (i = 0, j = 0; message[i]!= '\0'; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                encrypted[j++] = 'A' + ((message[i] - 'A' + key[i % strlen(key)] - 'A') % 26);
            } else {
                encrypted[j++] = 'a' + ((message[i] - 'a' + key[i % strlen(key)] - 'a') % 26);
            }
        } else {
            encrypted[j++] = message[i];
        }
    }
    encrypted[j] = '\0';

    // Print the encrypted message
    printf("Encrypted message: %s\n", encrypted);

    // Decrypt the message using the key
    for (i = 0, j = 0; encrypted[i]!= '\0'; i++) {
        if (isalpha(encrypted[i])) {
            if (isupper(encrypted[i])) {
                decrypted[j++] = 'A' + ((encrypted[i] - 'A' - key[i % strlen(key)] + 26) % 26);
            } else {
                decrypted[j++] = 'a' + ((encrypted[i] - 'a' - key[i % strlen(key)] + 26) % 26);
            }
        } else {
            decrypted[j++] = encrypted[i];
        }
    }
    decrypted[j] = '\0';

    // Print the decrypted message
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}