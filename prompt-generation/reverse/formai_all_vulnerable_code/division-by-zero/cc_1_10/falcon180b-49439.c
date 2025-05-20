//Falcon-180B DATASET v1.0 Category: Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LENGTH 256
#define MAX_DATA_LENGTH 1000

int main() {
    char key[MAX_KEY_LENGTH];
    char data[MAX_DATA_LENGTH];
    char encrypted[MAX_DATA_LENGTH];
    char decrypted[MAX_DATA_LENGTH];

    // Get key from user
    printf("Enter encryption key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key[strcspn(key, "\n")] = '\0';

    // Get data to encrypt from user
    printf("Enter data to encrypt: ");
    fgets(data, MAX_DATA_LENGTH, stdin);
    data[strcspn(data, "\n")] = '\0';

    // Encrypt data
    int i, j, k = 0;
    for (i = 0; data[i]!= '\0'; i++) {
        if (isalpha(data[i])) {
            encrypted[k++] = (data[i] + key[i % strlen(key)]) % 26 + 'a';
        } else {
            encrypted[k++] = data[i];
        }
    }
    encrypted[k] = '\0';

    // Decrypt data
    for (i = 0, j = strlen(encrypted) - 1; i < j; i++, j--) {
        if (isalpha(encrypted[i])) {
            decrypted[i] = (encrypted[i] - key[j % strlen(key)]) % 26 + 'a';
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

    // Print encrypted and decrypted data
    printf("Encrypted data: %s\n", encrypted);
    printf("Decrypted data: %s\n", decrypted);

    return 0;
}