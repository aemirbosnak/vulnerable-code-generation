//Falcon2-11B DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a random string
void generateRandomString(char* str, int length) {
    for (int i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
}

// Function to encrypt a string using a Caesar cipher
void encryptCaesar(char* str, int shift) {
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c += shift;
            if (c > 'z') {
                c -= 26;
            }
            str[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c += shift;
            if (c > 'Z') {
                c -= 26;
            }
            str[i] = c;
        }
    }
}

// Function to decrypt a string using a Caesar cipher
void decryptCaesar(char* str, int shift) {
    for (int i = 0; i < strlen(str); i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c -= shift;
            if (c < 'a') {
                c += 26;
            }
            str[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c -= shift;
            if (c < 'A') {
                c += 26;
            }
            str[i] = c;
        }
    }
}

int main() {
    char str[100];
    char key[5];

    // Generate a random string
    generateRandomString(str, 10);
    printf("Original string: %s\n", str);

    // Prompt the user for a key
    printf("Enter a key (1-26): ");
    scanf("%s", key);

    // Encrypt the string using the Caesar cipher
    encryptCaesar(str, atoi(key));
    printf("Encrypted string: %s\n", str);

    // Decrypt the string using the Caesar cipher
    decryptCaesar(str, atoi(key));
    printf("Decrypted string: %s\n", str);

    return 0;
}