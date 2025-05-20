//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: realistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define KEY_SIZE 256
#define MAX_STRING_SIZE 1024

void encrypt(char *plaintext, char *key, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (islower(plaintext[i])) {
                plaintext[i] = (((plaintext[i] + shift - 'a') % KEY_SIZE) + 'a');
            } else {
                plaintext[i] = (((plaintext[i] + shift - 'A') % KEY_SIZE) + 'A');
            }
        }
    }

    for (i = 0; i < strlen(key); i++) {
        if (!isalpha(key[i])) {
            printf("Error: Key contains non-alphabetic characters.\n");
            exit(1);
        }
    }

    for (i = 0; i < strlen(plaintext); i++) {
        int j;
        char temp = plaintext[i];
        for (j = 0; j < strlen(key); j++) {
            if (plaintext[i] == key[j]) {
                key[j] = temp;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <plaintext> <key> <shift>\n", argv[0]);
        return 1;
    }

    char plaintext[MAX_STRING_SIZE];
    strcpy(plaintext, argv[1]);

    char key[MAX_STRING_SIZE];
    strcpy(key, argv[2]);

    int shift = atoi(argv[3]);

    encrypt(plaintext, key, shift);

    printf("Encrypted text: %s\n", plaintext);

    return 0;
}