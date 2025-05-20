//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **words;

void generateWords() {
    words = (Word **)malloc(MAX_WORDS * sizeof(Word));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = (Word *)malloc(sizeof(Word));
        words[i]->word = (char *)malloc(20 * sizeof(char));
        words[i]->frequency = 0;
    }
}

void addWord(char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i]->word, word) == 0) {
            words[i]->frequency++;
            return;
        }
    }

    generateWords();
    words[MAX_WORDS - 1]->word = word;
    words[MAX_WORDS - 1]->frequency = 1;
}

int main() {
    char text[] = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    addWord("quick");
    addWord("brown");
    addWord("fox");
    addWord("jumps");
    addWord("lazy");
    addWord("over");
    addWord("the");

    printf("The words in the text are:");
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i]->frequency) {
            printf(" %s (%d)", words[i]->word, words[i]->frequency);
        }
    }

    return 0;
}