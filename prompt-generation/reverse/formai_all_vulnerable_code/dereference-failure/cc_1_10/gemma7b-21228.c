//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **words = NULL;

void addWord(char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 1;

    if (words == NULL) {
        words = malloc(sizeof(Word *) * MAX_WORDS);
    }

    words = realloc(words, sizeof(Word *) * (MAX_WORDS + 1));
    words[MAX_WORDS] = newWord;
}

void countWords() {
    int i = 0;
    for (i = 0; words[i] != NULL; i++) {
        words[i]->frequency++;
    }
}

void printWordFrequency() {
    int i = 0;
    for (i = 0; words[i] != NULL; i++) {
        printf("%s: %d\n", words[i]->word, words[i]->frequency);
    }
}

int main() {
    char *text = "This is a sample text with many words. The word 'is' appears twice, while 'sample' appears only once. Some words may not even be in the dictionary.";

    addWord(text);

    countWords();

    printWordFrequency();

    return 0;
}