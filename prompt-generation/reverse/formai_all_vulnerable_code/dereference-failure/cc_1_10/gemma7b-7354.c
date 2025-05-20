//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **createWordList(int size) {
    Word **words = malloc(size * sizeof(Word *));
    for (int i = 0; i < size; i++) {
        words[i] = malloc(sizeof(Word));
        words[i]->word = malloc(20 * sizeof(char));
        words[i]->frequency = 0;
    }
    return words;
}

void addWordToWordList(Word **words, char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i]->word, word) == 0) {
            words[i]->frequency++;
            return;
        }
    }
    words[MAX_WORDS - 1]->word = strdup(word);
    words[MAX_WORDS - 1]->frequency = 1;
}

int main() {
    Word **words = createWordList(100);
    addWordToWordList(words, "hello");
    addWordToWordList(words, "world");
    addWordToWordList(words, "spam");
    addWordToWordList(words, "eggs");
    addWordToWordList(words, "ham");

    int spamCount = 0;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i]->word, "spam") == 0) {
            spamCount++;
        }
    }

    printf("The number of occurrences of the word 'spam' is: %d", spamCount);

    return 0;
}