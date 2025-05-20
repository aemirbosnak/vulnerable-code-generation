//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY 25
#define MAX_PLAIN_TEXT 100
#define MAX_CIPHER_TEXT 100

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void encode(char *cipherText, const char *plainText, int key) {
    int i;
    for (i = 0; plainText[i]; i++) {
        if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = (char)(((plainText[i] - 'A' + key) % 26) + 'A');
        } else if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = (char)(((plainText[i] - 'a' + key) % 26) + 'a');
        } else {
            cipherText[i] = plainText[i];
        }
    }
    cipherText[i] = '\0';
}

int main(int argc, char **argv) {
    char plainText[MAX_PLAIN_TEXT];
    char keyStr[MAX_KEY + 1];
    char cipherText[MAX_CIPHER_TEXT];
    int key;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <plaintext> <key>\n", argv[0]);
        exit(1);
    }

    strcpy(plainText, argv[1]);
    strcpy(keyStr, argv[2]);

    key = atoi(keyStr);
    if (key < 0 || key > MAX_KEY) {
        fprintf(stderr, "Invalid key.\n");
        exit(1);
    }

    encode(cipherText, plainText, key);
    printf("Ciphertext: %s\n", cipherText);

    return 0;
}