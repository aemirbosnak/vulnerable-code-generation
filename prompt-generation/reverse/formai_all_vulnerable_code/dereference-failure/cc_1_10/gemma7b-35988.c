//Gemma-7B DATASET v1.0 Category: Alien Language Translator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

typedef struct AlienWord {
    char **words;
    int capacity;
    int size;
} AlienWord;

AlienWord *alienWord_create(int capacity) {
    AlienWord *aw = malloc(sizeof(AlienWord));
    aw->words = malloc(sizeof(char *) * capacity);
    aw->capacity = capacity;
    aw->size = 0;
    return aw;
}

void alienWord_add(AlienWord *aw, char *word) {
    if (aw->size == aw->capacity) {
        aw->words = realloc(aw->words, sizeof(char *) * aw->capacity * 2);
        aw->capacity *= 2;
    }
    aw->words[aw->size++] = strdup(word);
}

int alienWord_search(AlienWord *aw, char *word) {
    for (int i = 0; i < aw->size; i++) {
        if (strcmp(aw->words[i], word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    AlienWord *aw = alienWord_create(MAX_WORDS);
    alienWord_add(aw, "Blorg");
    alienWord_add(aw, "Zork");
    alienWord_add(aw, "Nargle");

    int index = alienWord_search(aw, "Zork");
    if (index != -1) {
        printf("Word index: %d\n", index);
    } else {
        printf("Word not found.\n");
    }

    return 0;
}