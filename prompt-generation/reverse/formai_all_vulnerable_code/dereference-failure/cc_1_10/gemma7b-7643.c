//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 255

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

typedef struct Sentence {
    char *sentence;
    Word *words;
} Sentence;

Sentence *createSentence(char *sentence) {
    Sentence *newSentence = malloc(sizeof(Sentence));
    newSentence->sentence = strdup(sentence);
    newSentence->words = NULL;
    return newSentence;
}

void addWordToSentence(Sentence *sentence, char *word) {
    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->next = NULL;

    if (sentence->words == NULL) {
        sentence->words = newWord;
    } else {
        sentence->words->next = newWord;
    }
}

int isSpam(Sentence *sentence) {
    char *keywords[] = {"free", "lottery", "miracle", "prize", "offer"};
    int i = 0;

    for (i = 0; i < MAX_WORDS; i++) {
        if (strstr(sentence->sentence, keywords[i]) != NULL) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char *sentence = "You have won a lottery! Free prize! Click here to claim your prize.";
    Sentence *sentenceObj = createSentence(sentence);

    if (isSpam(sentenceObj) == 1) {
        printf("This sentence is spam.");
    } else {
        printf("This sentence is not spam.");
    }

    return 0;
}