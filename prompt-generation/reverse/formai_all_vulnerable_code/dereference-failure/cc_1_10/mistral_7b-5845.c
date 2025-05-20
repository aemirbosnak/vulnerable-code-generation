//MISTRAL-7B DATASET v1.0 Category: Modern Encryption ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_COUNT 5
#define KEY_LENGTH 5

void encrypt_rail_fence(char *plaintext, char *key, char *ciphertext) {
    int key_index = 0, line = 0, len = strlen(plaintext), i;
    for (i = 0; i < len; i++) {
        ciphertext[i] = plaintext[i];
    }

    for (i = 0; i < len; i++) {
        if (line == 0) {
            if (key_index >= KEY_LENGTH) key_index = 0;
            if (plaintext[i] == key[key_index] || isspace(plaintext[i])) {
                continue;
            }
        }

        while (ciphertext[(line + i) % len] != '\0') line++;

        ciphertext[line + i] = plaintext[i];

        if (line == LINE_COUNT - 1 && i < len - 1) {
            line--;
            key_index++;
        }
    }
}

void print_array(char *arr, int size) {
    int i;
    for (i = 0; i < size; i++) printf("%c ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    char plaintext[100], key[KEY_LENGTH], ciphertext[100];

    if (argc != 3) {
        printf("Usage: %s <plaintext> <key>\n", argv[0]);
        return 1;
    }

    strcpy(plaintext, argv[1]);
    strcpy(key, argv[2]);

    for (int i = 0; i < strlen(key); i++) key[i] = toupper(key[i]);

    encrypt_rail_fence(plaintext, key, ciphertext);
    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: ");
    print_array(ciphertext, strlen(ciphertext));

    return 0;
}