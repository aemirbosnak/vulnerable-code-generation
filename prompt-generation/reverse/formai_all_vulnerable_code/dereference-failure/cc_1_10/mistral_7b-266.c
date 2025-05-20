//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define KEY 3

void encrypt(char *str, int key) {
    int i, len;

    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i]))
                str[i] = ((int)str[i] + key - 65) % 26 + 65;
            else
                str[i] = ((int)str[i] + key) % 26;
        }
    }
}

void decrypt(char *str, int key) {
    int i, len;

    len = strlen(str);

    for (i = 0; i < len; i++) {
        if (isalpha(str[i])) {
            if (isupper(str[i]))
                str[i] = ((int)str[i] - key + 26) % 26 + 65;
            else
                str[i] = ((int)str[i] - key) % 26;
        }
    }
}

int main(int argc, char **argv) {
    char *plaintext, *ciphertext, *decrypted_text;
    int key, len;

    if (argc != 3) {
        printf("Usage: %s <key> <plaintext>\n", argv[0]);
        return -1;
    }

    key = atoi(argv[1]);
    plaintext = argv[2];

    ciphertext = (char *)malloc(strlen(plaintext) * sizeof(char));
    decrypted_text = (char *)malloc(strlen(plaintext) * sizeof(char));

    strcpy(ciphertext, plaintext);
    encrypt(ciphertext, key);

    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key);
    strcpy(decrypted_text, ciphertext);

    printf("Decrypted Text: %s\n", decrypted_text);

    free(ciphertext);
    free(decrypted_text);

    return 0;
}