//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 100
#define NUM_SENTIMENTS 3

typedef struct {
    char* word;
    int score;
} SentimentWord;

SentimentWord positiveWords[] = {{"happy", 1}, {"love", 1}, {"joy", 1}, {"excited", 1}, {"amazing", 1}, {"great", 1}};
SentimentWord negativeWords[] = {{"hate", -1}, {"sad", -1}, {"angry", -1}, {"disappointed", -1}, {"upset", -1}, {"terrible", -1}};
SentimentWord neutralWords[] = {{"the", 0}, {"and", 0}, {"a", 0}, {"an", 0}, {"in", 0}, {"of", 0}};

void loadSentimentWords(SentimentWord words[], int numWords) {
    for (int i = 0; i < numWords; i++) {
        words[i].word = malloc(strlen(words[i].word) + 1);
        strcpy(words[i].word, words[i].word);
    }
}

int isPositive(char* word) {
    for (int i = 0; i < sizeof(positiveWords)/sizeof(positiveWords[0]); i++) {
        if (strcmp(word, positiveWords[i].word) == 0) {
            return 1;
        }
    }
    return 0;
}

int isNegative(char* word) {
    for (int i = 0; i < sizeof(negativeWords)/sizeof(negativeWords[0]); i++) {
        if (strcmp(word, negativeWords[i].word) == 0) {
            return -1;
        }
    }
    return 0;
}

int isNeutral(char* word) {
    for (int i = 0; i < sizeof(neutralWords)/sizeof(neutralWords[0]); i++) {
        if (strcmp(word, neutralWords[i].word) == 0) {
            return 0;
        }
    }
    return 0;
}

void analyzeSentiment(char* sentence) {
    int totalScore = 0;
    int numWords = 0;
    char* word = strtok(sentence, " ");
    while (word!= NULL) {
        numWords++;
        if (isPositive(word)) {
            totalScore += 1;
        } else if (isNegative(word)) {
            totalScore -= 1;
        }
        word = strtok(NULL, " ");
    }
    if (numWords == 0) {
        printf("No sentiment detected.\n");
    } else if (totalScore > 0) {
        printf("Positive sentiment detected.\n");
    } else if (totalScore < 0) {
        printf("Negative sentiment detected.\n");
    } else {
        printf("Neutral sentiment detected.\n");
    }
}

int main() {
    loadSentimentWords(positiveWords, sizeof(positiveWords)/sizeof(positiveWords[0]));
    loadSentimentWords(negativeWords, sizeof(negativeWords)/sizeof(negativeWords[0]));
    loadSentimentWords(neutralWords, sizeof(neutralWords)/sizeof(neutralWords[0]));

    char sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    analyzeSentiment(sentence);

    return 0;
}