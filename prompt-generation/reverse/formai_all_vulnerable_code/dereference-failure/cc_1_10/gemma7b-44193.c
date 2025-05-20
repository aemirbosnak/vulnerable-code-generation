//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word **createWordList(int size) {
    Word **words = malloc(size * sizeof(Word));
    for (int i = 0; i < size; i++) {
        words[i] = malloc(sizeof(Word));
        words[i]->word = malloc(MAX_WORDS * sizeof(char));
        words[i]->frequency = 0;
    }
    return words;
}

void addWord(Word **words, char *word) {
    for (int i = 0; i < MAX_WORDS; i++) {
        if (strcmp(words[i]->word, word) == 0) {
            words[i]->frequency++;
            return;
        }
    }

    Word *newWord = malloc(sizeof(Word));
    newWord->word = malloc(MAX_WORDS * sizeof(char));
    newWord->frequency = 1;
    strcpy(newWord->word, word);
    words = realloc(words, (MAX_WORDS + 1) * sizeof(Word));
    words[MAX_WORDS] = newWord;
}

int main() {
    char *text = "This is a sample text with many words. The words are repeated several times. Some words are unique, while others are not.";
    Word **words = createWordList(100);
    addWord(words, "the");
    addWord(words, "is");
    addWord(words, "a");
    addWord(words, "sample");
    addWord(words, "text");
    addWord(words, "with");
    addWord(words, "many");
    addWord(words, "words");
    addWord(words, "are");
    addWord(words, "repeated");
    addWord(words, "several");
    addWord(words, "times");
    addWord(words, "some");
    addWord(words, "words");
    addWord(words, "are");
    addWord(words, "unique");
    addWord(words, "while");
    addWord(words, "others");
    addWord(words, "are");
    addWord(words, "not");

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i] != NULL) {
            printf("%s: %d\n", words[i]->word, words[i]->frequency);
        }
    }

    return 0;
}