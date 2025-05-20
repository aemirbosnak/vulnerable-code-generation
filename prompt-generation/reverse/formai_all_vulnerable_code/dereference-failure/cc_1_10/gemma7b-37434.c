//Gemma-7B DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int frequency;
} Word;

Word *words;

void incrementWord(char *word) {
    Word *wordPtr = NULL;
    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word == NULL || strcmp(words[i].word, word) == 0) {
            wordPtr = &words[i];
            break;
        }
    }

    if (wordPtr == NULL) {
        words = (Word *)realloc(words, (MAX_WORDS + 1) * sizeof(Word));
        wordPtr = &words[MAX_WORDS];
        words[MAX_WORDS].word = strdup(word);
        words[MAX_WORDS].frequency = 1;
    } else {
        wordPtr->frequency++;
    }
}

int main() {
    words = (Word *)malloc(MAX_WORDS * sizeof(Word));
    words[0].word = NULL;

    char *text = "The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog. The quick brown fox jumps over the lazy dog.";

    char *wordsArray[] = {"the", "quick", "brown", "fox", "jumps", "over", "lazy", "dog"};

    for (int i = 0; i < 8; i++) {
        incrementWord(wordsArray[i]);
    }

    for (int i = 0; i < MAX_WORDS; i++) {
        if (words[i].word) {
            printf("%s: %d\n", words[i].word, words[i].frequency);
        }
    }

    return 0;
}