//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MIN_KEY_LENGTH 1
#define MAX_KEY_LENGTH 25

void encrypt(char *plaintext, int key) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            if (isupper(plaintext[i]))
                plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            else
                plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
        }
    }
}

int analyze_input(char *input) {
    int i, key_length = 1;
    for (i = 0; input[i] != '\0'; i++) {
        if (!isalnum(input[i])) {
            if (input[i] == ' ' || input[i] == '\t') {
                key_length++;
            } else {
                return -1;
            }
        }
    }

    if (key_length < MIN_KEY_LENGTH || key_length > MAX_KEY_LENGTH) {
        return -1;
    }

    return key_length;
}

int main(int argc, char **argv) {
    char plaintext[100];
    int key, key_length;

    if (argc != 3) {
        printf("Usage: %s <plaintext> <key>\n", argv[0]);
        return 1;
    }

    strcpy(plaintext, argv[1]);
    key = atoi(argv[2]);

    if (key < 1) {
        printf("Error: Invalid key\n");
        return 1;
    }

    key_length = analyze_input(plaintext);
    if (key_length == -1) {
        printf("Error: Invalid plaintext\n");
        return 1;
    }

    encrypt(plaintext, key % key_length);
    printf("Ciphertext: %s\n", plaintext);

    return 0;
}