//Gemma-7B DATASET v1.0 Category: Spell checking ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct SpellChecker {
    char **dictionary;
    int size;
    int maxSize;
} SpellChecker;

SpellChecker *createSpellChecker(int size, int maxSize) {
    SpellChecker *spellChecker = malloc(sizeof(SpellChecker));
    spellChecker->dictionary = malloc(sizeof(char *) * size);
    spellChecker->size = size;
    spellChecker->maxSize = maxSize;

    return spellChecker;
}

void addWordToSpellChecker(SpellChecker *spellChecker, char *word) {
    if (spellChecker->size >= spellChecker->maxSize) {
        return;
    }

    spellChecker->dictionary[spellChecker->size++] = strdup(word);
}

int main() {
    SpellChecker *spellChecker = createSpellChecker(1000, 10000);
    addWordToSpellChecker(spellChecker, "Hello");
    addWordToSpellChecker(spellChecker, "World");
    addWordToSpellChecker(spellChecker, "Paranoid");

    char *wordToSearch = "Paranoid";

    if (wordToSearch) {
        if (spellChecker && spellChecker->size) {
            for (int i = 0; i < spellChecker->size; i++) {
                if (strcmp(wordToSearch, spellChecker->dictionary[i]) == 0) {
                    printf("Word found: %s\n", wordToSearch);
                    break;
                }
            }
        } else {
            printf("No words found.\n");
        }
    } else {
        printf("Error: No word to search.\n");
    }

    return 0;
}