//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: rigorous
#include <stdio.h>
#include <string.h>

// Function to encrypt a given string using a given shift value
void encrypt(char* str, int shift) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c += shift;
            if (c > 'z') {
                c -= 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            c += shift;
            if (c > 'Z') {
                c -= 26;
            }
        }
        str[i] = c;
    }
    printf("Encrypted string: %s\n", str);
}

// Function to decrypt a given string using a given shift value
void decrypt(char* str, int shift) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c -= shift;
            if (c < 'a') {
                c += 26;
            }
        } else if (c >= 'A' && c <= 'Z') {
            c -= shift;
            if (c < 'A') {
                c += 26;
            }
        }
        str[i] = c;
    }
    printf("Decrypted string: %s\n", str);
}

int main() {
    char plaintext[100];
    printf("Enter the plaintext string: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Convert the input string to lowercase for consistency
    char* lowercase_plaintext = strdup(plaintext);
    for (int i = 0; lowercase_plaintext[i]; i++) {
        lowercase_plaintext[i] = tolower(lowercase_plaintext[i]);
    }

    int shift;
    printf("Enter the shift value: ");
    scanf("%d", &shift);

    // Encrypt the plaintext
    encrypt(lowercase_plaintext, shift);

    // Decrypt the encrypted string
    decrypt(lowercase_plaintext, shift);

    free(lowercase_plaintext);
    return 0;
}