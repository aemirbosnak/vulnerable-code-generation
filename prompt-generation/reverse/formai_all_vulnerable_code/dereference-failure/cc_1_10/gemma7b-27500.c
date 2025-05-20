//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORDS 1000
#define MAX_SENTENCE_LENGTH 512

typedef struct Word {
    char *word;
    int frequency;
} Word;

typedef struct Sentence {
    char *sentence;
    int wordCount;
    Word **words;
} Sentence;

Sentence **createSentence(char *sentence) {
    Sentence **sentencePtr = malloc(sizeof(Sentence));
    *sentencePtr = malloc(sizeof(Sentence));

    (*sentencePtr)->sentence = strdup(sentence);
    (*sentencePtr)->wordCount = 0;
    (*sentencePtr)->words = NULL;

    return sentencePtr;
}

void addWordToSentence(Sentence *sentence, char *word) {
    Word **words = malloc(sizeof(Word *) * (sentence->wordCount + 1));
    sentence->words = words;

    Word *newWord = malloc(sizeof(Word));
    newWord->word = strdup(word);
    newWord->frequency = 0;

    words[sentence->wordCount] = newWord;
    sentence->wordCount++;
}

int calculateSpamScore(Sentence *sentence) {
    int score = 0;

    for (int i = 0; i < sentence->wordCount; i++) {
        Word *word = sentence->words[i];

        if (word->frequency > 5) {
            score++;
        }

        if (strcmp(word->word, "free") == 0) {
            score++;
        }

        if (strcmp(word->word, "lottery") == 0) {
            score++;
        }
    }

    return score;
}

int main() {
    char *sentence = "This is a spam email with lots of free offers and a lottery drawing.";

    Sentence *sentenceObj = createSentence(sentence);

    addWordToSentence(sentenceObj, "free");
    addWordToSentence(sentenceObj, "lottery");
    addWordToSentence(sentenceObj, "spam");

    int spamScore = calculateSpamScore(sentenceObj);

    printf("Spam score: %d", spamScore);

    return 0;
}