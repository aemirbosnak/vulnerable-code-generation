//Gemma-7B DATASET v1.0 Category: Word Count Tool ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *words;

void initializeWords() {
    words = malloc(MAX_WORDS * sizeof(Word));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i].word = NULL;
        words[i].frequency = 0;
    }
}

void addWord(char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word == NULL) {
            words[i].word = strdup(word);
            words[i].frequency = 1;
            return;
        } else if (strcmp(words[i].word, word) == 0) {
            words[i].frequency++;
            return;
        }
    }

    // If no space, allocate more memory
    initializeWords();
    addWord(word);
}

int main() {
    initializeWords();

    addWord("apple");
    addWord("banana");
    addWord("orange");
    addWord("grapefruit");
    addWord("apricot");
    addWord("peach");
    addWord("mango");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }

    return 0;
}