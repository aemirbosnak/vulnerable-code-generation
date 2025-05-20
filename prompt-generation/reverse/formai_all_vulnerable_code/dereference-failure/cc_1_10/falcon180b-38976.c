//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char* word;
    int length;
} Word;

void generateRandomWords(Word* words, int numWords) {
    srand(time(NULL));

    for (int i = 0; i < numWords; i++) {
        char* word = (char*)malloc(MAX_WORD_LENGTH*sizeof(char));
        int length = rand() % MAX_WORD_LENGTH + 1;

        for (int j = 0; j < length; j++) {
            char c = rand() % 26 + 'a';
            word[j] = c;
        }

        words[i].word = word;
        words[i].length = length;
    }
}

void generateRandomTheory(Word* words, int numWords) {
    srand(time(NULL));

    char* theory = (char*)malloc(MAX_WORD_LENGTH*sizeof(char));
    int theoryLength = rand() % MAX_WORD_LENGTH + 1;

    for (int i = 0; i < theoryLength; i++) {
        char c = rand() % 26 + 'a';
        theory[i] = c;
    }

    printf("Random Conspiracy Theory: %s\n", theory);

    for (int i = 0; i < numWords; i++) {
        printf("Involved entity: %s\n", words[i].word);
    }
}

int main() {
    Word words[MAX_WORDS];
    int numWords = rand() % MAX_WORDS + 1;

    generateRandomWords(words, numWords);
    generateRandomTheory(words, numWords);

    return 0;
}