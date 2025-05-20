//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20
#define MAX_SENTENCE_LENGTH 100
#define MAX_SENTENCES 10

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

typedef struct {
    Word words[MAX_WORDS];
    int numWords;
} Sentence;

void generateRandomSentence(Sentence *sentence) {
    srand(time(NULL));
    int numWords = rand() % (MAX_SENTENCE_LENGTH / 2) + 1;
    for (int i = 0; i < numWords; i++) {
        char word[MAX_WORD_LENGTH];
        int length = rand() % MAX_WORD_LENGTH + 1;
        for (int j = 0; j < length; j++) {
            word[j] = rand() % 26 + 'a';
        }
        word[length] = '\0';
        int found = 0;
        for (int k = 0; k < sentence->numWords; k++) {
            if (strcmp(sentence->words[k].word, word) == 0) {
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(sentence->words[sentence->numWords].word, word);
            sentence->words[sentence->numWords].count = 1;
            sentence->numWords++;
        }
    }
}

void printSentence(Sentence *sentence) {
    for (int i = 0; i < sentence->numWords; i++) {
        for (int j = 0; j < sentence->words[i].count; j++) {
            printf("%s ", sentence->words[i].word);
        }
    }
    printf("\n");
}

int main() {
    Sentence sentence;
    generateRandomSentence(&sentence);
    printSentence(&sentence);
    return 0;
}