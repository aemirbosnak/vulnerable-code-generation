//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: optimized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 2048

typedef struct SentimentAnalysis {
    char* sentence;
    int sentiment;
    int subjectivity;
    int objectivity;
} SentimentAnalysis;

SentimentAnalysis* analyzeSentiment(char* sentence) {
    SentimentAnalysis* sa = malloc(sizeof(SentimentAnalysis));
    sa->sentence = strdup(sentence);

    sa->sentiment = analyzeSentimentScore(sentence);
    sa->subjectivity = analyzeSubjectivityScore(sentence);
    sa->objectivity = analyzeObjectivityScore(sentence);

    return sa;
}

int analyzeSentimentScore(char* sentence) {
    int score = 0;
    int length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        char character = sentence[i];
        if (isupper(character)) {
            character = tolower(character);
        }
        switch (character) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                score++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                score++;
                break;
            default:
                break;
        }
    }
    return score;
}

int analyzeSubjectivityScore(char* sentence) {
    int score = 0;
    int length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        char character = sentence[i];
        if (isupper(character)) {
            character = tolower(character);
        }
        switch (character) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                score++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                score++;
                break;
            default:
                break;
        }
    }
    return score;
}

int analyzeObjectivityScore(char* sentence) {
    int score = 0;
    int length = strlen(sentence);
    for (int i = 0; i < length; i++) {
        char character = sentence[i];
        if (isupper(character)) {
            character = tolower(character);
        }
        switch (character) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                score++;
                break;
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                score++;
                break;
            default:
                break;
        }
    }
    return score;
}

int main() {
    char* sentence = "I am very happy today.";
    SentimentAnalysis* sa = analyzeSentiment(sentence);

    printf("Sentiment: %d\n", sa->sentiment);
    printf("Subjectivity: %d\n", sa->subjectivity);
    printf("Objectivity: %d\n", sa->objectivity);

    free(sa);

    return 0;
}