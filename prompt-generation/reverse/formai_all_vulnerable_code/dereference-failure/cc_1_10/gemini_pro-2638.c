//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct AlienLang {
    char glyph;
    char eng;
} AlienLang;

AlienLang alienLangs[] = {
    {'*', 'a'},
    {'!', 'b'},
    {'?', 'c'},
    {'#', 'd'},
    {'%', 'e'},
    {'^', 'f'},
    {'&', 'g'},
    {'(', 'h'},
    {')', 'i'},
    {'_', 'j'}, {'=', 'k'}, {'-', 'l'}, {'\\', 'm'}, {'/', 'n'},
    {'1', 'o'}, {'2', 'p'}, {'3', 'q'}, {'4', 'r'}, {'5', 's'},
    {'6', 't'}, {'7', 'u'}, {'8', 'v'}, {'9', 'w'}, {'0', 'x'},
    {'a', 'y'}, {'b', 'z'}, {'c', ' '}
};

char *translateAlienToEng(char *alienText) {
    int i, len = strlen(alienText);
    char *engText = malloc(len + 1);
    for (i = 0; i < len; i++) {
        engText[i] = alienLangs[i].eng;
    }
    engText[len] = '\0';
    return engText;
}

char *translateEngToAlien(char *engText) {
    int i, len = strlen(engText);
    char *alienText = malloc(len + 1);
    for (i = 0; i < len; i++) {
        alienText[i] = alienLangs[i].glyph;
    }
    alienText[len] = '\0';
    return alienText;
}

int main() {
    char choice;
    char text[100];

    printf("Alien Language Translator\n");
    printf("------------------------\n");
    printf("1. Translate Alien to English\n");
    printf("2. Translate English to Alien\n");
    printf("Enter your choice (1 or 2): ");
    scanf(" %c", &choice);

    printf("Enter the text: ");
    scanf(" %s", text);

    if (choice == '1') {
        printf("English translation: %s\n", translateAlienToEng(text));
    } else if (choice == '2') {
        printf("Alien translation: %s\n", translateEngToAlien(text));
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}