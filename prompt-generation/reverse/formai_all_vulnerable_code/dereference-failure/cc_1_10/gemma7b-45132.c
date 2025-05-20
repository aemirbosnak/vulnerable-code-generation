//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 10
#define MAX_LENGTH 20

typedef struct AlienWord {
    char **words;
    int capacity;
    int used;
} AlienWord;

AlienWord *createAlienWord(int capacity) {
    AlienWord *aw = malloc(sizeof(AlienWord));
    aw->words = malloc(sizeof(char *) * capacity);
    aw->capacity = capacity;
    aw->used = 0;
    return aw;
}

void addAlienWord(AlienWord *aw, char *word) {
    aw->words[aw->used++] = strdup(word);
    if (aw->used == aw->capacity) {
        aw->words = realloc(aw->words, sizeof(char *) * (aw->capacity * 2));
        aw->capacity *= 2;
    }
}

char *translateAlien(AlienWord *aw, char *alien) {
    char *translated = malloc(MAX_LENGTH);
    int i = 0;
    for (i = 0; alien[i] != '\0'; i++) {
        char alienWord[MAX_WORDS];
        int j = 0;
        for (j = 0; aw->words[j] != NULL && alienWord[j] != '\0'; j++) {
            if (strcmp(alienWord, alien) == 0) {
                sprintf(translated, "%s ", aw->words[j]);
                break;
            }
            strcpy(alienWord, aw->words[j]);
            j++;
        }
        if (alienWord[0] == '\0') {
            strcpy(translated, "UNKNOWN ");
        }
    }
    translated[MAX_LENGTH - 1] = '\0';
    return translated;
}

int main() {
    AlienWord *aw = createAlienWord(MAX_WORDS);
    addAlienWord(aw, "Zoar'k");
    addAlienWord(aw, "Bar'nak");
    addAlienWord(aw, "Blorg'nak");

    char *alien = "Blorg'nak zork'ka";
    char *translated = translateAlien(aw, alien);

    printf("%s", translated);

    return 0;
}