//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char symbol;
    int size;
} HappySymbol;

HappySymbol happy_symbols[] = {
    {'(', 3},
    {'D', 2},
    {')', 3},
    {'P', 2},
    {'<3', 3},
    {'~', 1},
    {'o', 1},
    {'O', 1},
    {'>', 1},
    {'-', 1},
    {'_', 1},
    {'*', 1},
    {'!', 1},
};

void print_happy_face(HappySymbol symbol) {
    int i;
    for (i = 0; i < symbol.size; i++) {
        putchar(symbol.symbol);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    int text_length = strlen(argv[1]);
    int i;
    for (i = 0; i < text_length; i++) {
        int j;
        for (j = 0; j < sizeof(happy_symbols) / sizeof(HappySymbol); j++) {
            if (tolower(argv[1][i]) == happy_symbols[j].symbol) {
                print_happy_face(happy_symbols[j]);
                break;
            }
        }
        if (j == (sizeof(happy_symbols) / sizeof(HappySymbol))) {
            putchar(argv[1][i]);
        }
    }
    putchar('\n');

    return 0;
}