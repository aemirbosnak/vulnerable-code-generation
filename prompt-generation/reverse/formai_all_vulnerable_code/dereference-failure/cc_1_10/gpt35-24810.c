//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char message[100];
    printf("Enter a message to encrypt: ");
    fgets(message, 100, stdin);

    char key[10];
    printf("Enter a key for encryption: ");
    fgets(key, 10, stdin);

    // remove newline characters from input
    message[strcspn(message, "\n")] = '\0';
    key[strcspn(key, "\n")] = '\0';

    int message_len = strlen(message);
    int key_len = strlen(key);

    // calculate the length of the encrypted message
    int encrypted_len = message_len + key_len;

    // dynamically allocate memory for encrypted message
    char *encrypted = malloc(encrypted_len * sizeof(char));

    // encrypt the message
    int i, j;
    for (i = 0, j = 0; i < message_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        encrypted[i] = (message[i] + key[j]) % 128;
    }
    encrypted[i] = '\0';

    printf("Encrypted Message: %s\n", encrypted);

    // dynamically allocate memory for decrypted message
    char *decrypted = malloc(message_len * sizeof(char));

    // decrypt the message
    for (i = 0, j = 0; i < message_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        decrypted[i] = (encrypted[i] - key[j] + 128) % 128;
    }
    decrypted[i] = '\0';

    printf("Decrypted Message: %s\n", decrypted);

    // free dynamically allocated memory
    free(encrypted);
    free(decrypted);

    return 0;
}