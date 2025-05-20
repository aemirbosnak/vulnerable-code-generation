//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 16
#define MAX_TEXT_LEN 1024

void generate_key(char *key) {
    int i;
    for (i = 0; i < MAX_KEY_LEN; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[MAX_KEY_LEN] = '\0';
}

void encrypt(char *text, char *key) {
    int i, j;
    char encrypted_text[MAX_TEXT_LEN];
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            encrypted_text[j] = ((text[i] + key[i % MAX_KEY_LEN] - 'a' + 26) % 26) + 'a';
            j++;
        } else {
            encrypted_text[j] = text[i];
            j++;
        }
    }
    encrypted_text[j] = '\0';
    strcpy(text, encrypted_text);
}

void decrypt(char *text, char *key) {
    int i, j;
    char decrypted_text[MAX_TEXT_LEN];
    for (i = 0, j = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            decrypted_text[j] = ((text[i] - key[i % MAX_KEY_LEN] - 'a' + 26) % 26) + 'a';
            j++;
        } else {
            decrypted_text[j] = text[i];
            j++;
        }
    }
    decrypted_text[j] = '\0';
    strcpy(text, decrypted_text);
}

int main() {
    char text[MAX_TEXT_LEN];
    char key[MAX_KEY_LEN];
    printf("Enter the plain text: ");
    fgets(text, MAX_TEXT_LEN, stdin);
    printf("Enter the encryption key: ");
    fgets(key, MAX_KEY_LEN, stdin);
    generate_key(key);
    encrypt(text, key);
    printf("Encrypted text: %s\n", text);
    decrypt(text, key);
    printf("Decrypted text: %s\n", text);
    return 0;
}