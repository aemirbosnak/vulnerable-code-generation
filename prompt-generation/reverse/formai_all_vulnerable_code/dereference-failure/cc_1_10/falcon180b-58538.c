//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LENGTH 16
#define MAX_PLAIN_TEXT_LENGTH 100

void generate_key(char *key) {
    for (int i = 0; i < MAX_KEY_LENGTH; i++) {
        char c = rand() % 26 + 'A';
        key[i] = c;
    }
    key[MAX_KEY_LENGTH] = '\0';
}

void encrypt(char *key, char *plain_text) {
    for (int i = 0; i < strlen(plain_text); i++) {
        char c = plain_text[i];
        if (isalpha(c)) {
            c = (c - 'A' + (rand() % 26)) % 26 + 'A';
        }
        printf("%c", c);
    }
}

void decrypt(char *key, char *cipher_text) {
    for (int i = 0; i < strlen(cipher_text); i++) {
        char c = cipher_text[i];
        if (isalpha(c)) {
            c = (c - 'A' - (rand() % 26)) % 26 + 'A';
        }
        printf("%c", c);
    }
}

int main() {
    srand(time(NULL));

    char key[MAX_KEY_LENGTH];
    generate_key(key);

    char plain_text[MAX_PLAIN_TEXT_LENGTH];
    printf("Enter plain text: ");
    scanf("%s", plain_text);

    encrypt(key, plain_text);
    printf("\nEncrypted text: ");

    char cipher_text[MAX_PLAIN_TEXT_LENGTH];
    for (int i = 0; i < strlen(plain_text); i++) {
        cipher_text[i] = plain_text[i];
    }
    cipher_text[strlen(plain_text)] = '\0';

    decrypt(key, cipher_text);
    printf("\nDecrypted text: ");

    return 0;
}