//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ALIEN_ALPHABET_SIZE 26

typedef struct {
    char symbol;
    int index;
} AlienSymbol;

AlienSymbol alienAlphabet[ALIEN_ALPHABET_SIZE];

void initializeAlienAlphabet() {
    int i;
    for (i = 0; i < ALIEN_ALPHABET_SIZE; i++) {
        alienAlphabet[i].symbol = 'A' + i;
        alienAlphabet[i].index = i;
    }
}

void translate(char *earthText, char *alienText) {
    int i, j;
    for (i = 0; earthText[i] != '\0'; i++) {
        if (isalpha(earthText[i])) {
            for (j = 0; j < ALIEN_ALPHABET_SIZE; j++) {
                if (tolower(earthText[i]) == alienAlphabet[j].symbol) {
                    alienText[i] = alienAlphabet[(j + 3) % ALIEN_ALPHABET_SIZE].symbol;
                    break;
                }
            }
        } else {
            alienText[i] = earthText[i];
        }
    }
    alienText[i] = '\0';
}

int main(int argc, char *argv[]) {
    char earthText[100], alienText[100];

    if (argc < 3) {
        printf("Usage: %s <Earth text> <Alien text>\n", argv[0]);
        return 1;
    }

    strcpy(earthText, argv[1]);
    initializeAlienAlphabet();

    translate(earthText, alienText);

    printf("Earth text: %s\n", earthText);
    printf("Alien text: %s\n", alienText);

    return 0;
}