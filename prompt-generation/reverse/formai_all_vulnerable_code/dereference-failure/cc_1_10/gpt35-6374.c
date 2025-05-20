//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_SIZE 1000

/* The encryption function */
char *encrypt(char *plaintext, int key) {
    int i;
    char *ciphertext = malloc(strlen(plaintext) + 1);

    for (i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i])) {
                /* Shift the character by the key value */
                ciphertext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            } else {
                /* Shift the character by the key value */
                ciphertext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';
    return ciphertext;
}

/* The decryption function */
char *decrypt(char *ciphertext, int key) {
    int i;
    char *plaintext = malloc(strlen(ciphertext) + 1);

    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            if (isupper(ciphertext[i])) {
                /* Shift the character by the key value */
                plaintext[i] = ((ciphertext[i] - 'A' - key + 26) % 26) + 'A';
            } else {
                /* Shift the character by the key value */
                plaintext[i] = ((ciphertext[i] - 'a' - key + 26) % 26) + 'a';
            }
        } else {
            plaintext[i] = ciphertext[i];
        }
    }

    plaintext[i] = '\0';
    return plaintext;
}

int main() {
    int key;
    char plaintext[MAX_SIZE];
    char *ciphertext, *decrypted;

    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_SIZE, stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    /* Remove the newline character */
    plaintext[strcspn(plaintext, "\n")] = '\0';

    /* Encrypt the plaintext */
    ciphertext = encrypt(plaintext, key);

    printf("The encrypted message is: %s\n", ciphertext);

    /* Decrypt the ciphertext */
    decrypted = decrypt(ciphertext, key);

    printf("The decrypted message is: %s\n", decrypted);

    free(ciphertext);
    free(decrypted);

    return 0;
}