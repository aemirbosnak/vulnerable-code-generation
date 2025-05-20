//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ABC "XQWERRPSSDDFGGAAZZZ"
#define ALPHABET_SIZE 26

void alien_encode(char *input, char *output, int len) {
    int i, index;
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            index = input[i] - 'A';
            output[i] = ALIEN_ABC[index < 0 ? index + ALPHABET_SIZE : index];
        } else {
            output[i] = input[i];
        }
    }
    output[len] = '\0';
}

void alien_decode(char *input, char *output, int len) {
    int i, index;
    for (i = 0; i < len; i++) {
        if (isalpha(input[i])) {
            index = input[i] - 'X';
            output[i] = 'A' + (index < 0 ? index + ALPHABET_SIZE : index);
        } else {
            output[i] = input[i];
        }
    }
    output[len] = '\0';
}

int main(int argc, char **argv) {
    char input[100], output[100];
    int len;

    if (argc != 3) {
        printf("Usage: %s <alien-encoded-string> <decoded-string>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]);
    alien_decode(argv[1], input, len);
    alien_encode(input, argv[2], len);

    printf("Input: %s\n", argv[1]);
    printf("Output: %s\n", argv[2]);
    printf("Decoded: %s\n", input);

    return 0;
}