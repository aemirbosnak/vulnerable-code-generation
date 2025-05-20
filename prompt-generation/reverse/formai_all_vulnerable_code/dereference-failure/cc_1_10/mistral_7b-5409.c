//MISTRAL-7B DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define KEY_LENGTH 25
#define ALPHABET_SIZE 26

char *key, *plaintext, *ciphertext;

void generate_key() {
    int i, rand_num;
    key = (char*)malloc(KEY_LENGTH * sizeof(char));

    for(i = 0; i < KEY_LENGTH; i++) {
        do {
            rand_num = rand() % ALPHABET_SIZE;
            key[i] = (char)('A' + rand_num);
        } while(strchr(key, (char)('A' + rand_num)) != NULL && i < KEY_LENGTH - 1);
    }

    key[KEY_LENGTH] = '\0';
}

int vigenere_encrypt(char plaintext_char, char key_char) {
    int plaintext_ascii = (int)plaintext_char;
    int key_ascii = (int)key_char;
    int shifted_ascii;

    if(isalpha(plaintext_char) && isalpha(key_char)) {
        shifted_ascii = ((plaintext_ascii - 'A' + key_ascii - 'A') % ALPHABET_SIZE) + 'A';
        return (char)shifted_ascii;
    } else {
        return plaintext_char;
    }
}

void encrypt(char *input) {
    int i, j;
    char key_char;

    ciphertext = (char*)calloc(strlen(input) + strlen(key) + 1, sizeof(char));

    for(i = 0; input[i] != '\0'; i++) {
        key_char = key[(i % KEY_LENGTH)];
        ciphertext[i] = vigenere_encrypt(input[i], key_char);
    }

    for(j = 0; key[j] != '\0'; j++) {
        ciphertext[i + j] = key[j];
        i++;
    }

    ciphertext[strlen(input) + strlen(key)] = '\0';
}

int main() {
    srand(time(NULL));
    int i;

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    generate_key();

    printf("Random key: %s\n", key);

    encrypt(plaintext);

    printf("Ciphertext: %s\n", ciphertext);

    free(key);
    free(plaintext);
    free(ciphertext);

    return 0;
}