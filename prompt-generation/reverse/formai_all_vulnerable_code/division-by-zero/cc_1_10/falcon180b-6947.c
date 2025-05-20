//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main() {
    char plaintext[100];
    char key[100];
    char ciphertext[200];
    int i, j, k, n, len;
    bool is_key_valid = false;

    // Get plaintext from user
    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);
    len = strlen(plaintext);

    // Get key from user
    printf("Enter key: ");
    fgets(key, 100, stdin);
    n = strlen(key);

    // Validate key
    for (i = 0; i < n; i++) {
        if (!isalpha(key[i])) {
            printf("Invalid key! Key should only contain alphabets.\n");
            return 0;
        }
    }

    // Perform encryption
    is_key_valid = true;
    for (i = 0, j = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                ciphertext[j++] = ((int) plaintext[i] + (int) key[i % n] - 65) % 26 + 65;
            } else {
                ciphertext[j++] = ((int) plaintext[i] + (int) key[i % n] - 97) % 26 + 97;
            }
        } else {
            ciphertext[j++] = plaintext[i];
        }
    }

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}