//MISTRAL-7B DATASET v1.0 Category: Cat Language Translator ; Style: satisfied
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char symbol;
    int value;
} Token;

void meow() {
    printf("Miaow~\n");
}

void purr() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("Rrrumble, purr, purr...\n");
    }
}

void translate(char *input) {
    Token tokens[256];
    int tokenIndex = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == 'M') {
            tokens[tokenIndex].symbol = 'M';
            tokens[tokenIndex].value = meow;
            tokenIndex++;
        } else if (input[i] == 'P') {
            tokens[tokenIndex].symbol = 'P';
            tokens[tokenIndex].value = purr;
            tokenIndex++;
        } else {
            tokens[tokenIndex].symbol = input[i];
            tokens[tokenIndex].value = input[i];
            tokenIndex++;
        }
    }

    for (int i = 0; tokens[i].symbol != '\0'; i++) {
        if (tokens[i].symbol != ' ') {
            putchar(tokens[i].symbol);
            if (tokens[i].value != tokens[i].symbol) {
                ((void (*)())(tokens[i].value))();
            }
        }
    }

    putchar('\n');
}

int main() {
    char input[100];

    printf("Welcome to the C Cat Language Translator! Enter your CAT code below:\n");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0'; // remove newline character

    translate(input);

    return 0;
}