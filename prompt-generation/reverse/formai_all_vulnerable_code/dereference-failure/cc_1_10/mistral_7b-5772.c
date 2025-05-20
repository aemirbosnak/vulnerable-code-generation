//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 26

char alien_alphabet[ALIEN_ALPHABET_SIZE] = {'&', '*', '+', '.', '>', '?', '@', '#', '%', '^', '&', '|', '!', '(', ')', '_', '-', '=', '+', '[', ']', '{', '}'};

int alien_to_human(char alien) {
    int i;
    for (i = 0; i < ALIEN_ALPHABET_SIZE; i++)
        if (alien == alien_alphabet[i])
            return i;
    return -1;
}

int human_to_alien(char human) {
    if (isalpha(human))
        return alien_to_human(toupper(human)) ^ 0x20;
    return human;
}

void translate(char *input, char *output) {
    int i, j;
    for (i = 0; input[i] != '\0'; i++) {
        if (isalpha(input[i])) {
            output[i] = alien_alphabet[human_to_alien(input[i])];
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    char *input = argv[1];
    char *output = malloc(strlen(input) + 1);

    translate(input, output);

    printf("Input: %s\n", input);
    printf("Output: %s\n", output);

    free(output);
    return 0;
}