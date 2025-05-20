//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 255

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **createWordList() {
    Word **words = malloc(MAX_WORDS * sizeof(Word));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
    }
    return words;
}

void addWordToWordList(Word **words, char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i] == NULL) {
            words[i] = malloc(MAX_WORD_LENGTH * sizeof(char));
            strcpy(words[i], word);
            words[i]->frequency = 1;
            return;
        } else if (strcmp(words[i], word) == 0) {
            words[i]->frequency++;
            return;
        }
    }
    // Word not found, so add it to the end
    Word *newWord = malloc(MAX_WORD_LENGTH * sizeof(char));
    strcpy(newWord, word);
    newWord->frequency = 1;
    words[MAX_WORDS - 1] = newWord;
}

int main() {
    Word **words = createWordList();
    char *text = "This text has many words. Some words are repeated. The most common word is the word 'the'.";

    // Add words to the word list
    addWordToWordList(words, "the");
    addWordToWordList(words, "words");
    addWordToWordList(words, "has");
    addWordToWordList(words, "many");
    addWordToWordList(words, "some");

    // Print word frequencies
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i] != NULL) {
            printf("%s: %d\n", words[i]->word, words[i]->frequency);
        }
    }

    return 0;
}