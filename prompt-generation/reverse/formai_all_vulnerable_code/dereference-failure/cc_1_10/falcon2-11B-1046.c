//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LEN 100
#define MAX_WORD_LEN 20

typedef struct {
    char* word;
    int sentiment;
} Sentiment;

Sentiment analyzeSentence(char* sentence) {
    Sentiment result;
    char* words[MAX_SENTENCE_LEN];
    int wordCount = 0;

    // Split sentence into words
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        words[wordCount] = token;
        wordCount++;
        token = strtok(NULL, " ");
    }
    words[wordCount] = NULL;

    // Analyze sentiment of each word
    result.word = (char*) malloc(MAX_WORD_LEN * sizeof(char));
    result.sentiment = 0;
    for (int i = 0; i < wordCount; i++) {
        char* word = words[i];
        int sentimentValue = 0;
        if (strcmp(word, "happy") == 0) {
            sentimentValue = 1;
        } else if (strcmp(word, "sad") == 0) {
            sentimentValue = -1;
        } else if (strcmp(word, "angry") == 0) {
            sentimentValue = -2;
        } else if (strcmp(word, "excited") == 0) {
            sentimentValue = 2;
        } else {
            sentimentValue = 0;
        }
        strcpy(result.word, word);
        result.sentiment += sentimentValue;
    }

    // Return the analyzed sentiment
    return result;
}

int main() {
    char* sentence = "I am feeling happy today";
    Sentiment sentiment = analyzeSentence(sentence);
    printf("Sentiment analysis: %s (%d)\n", sentiment.word, sentiment.sentiment);
    free(sentiment.word);
    return 0;
}