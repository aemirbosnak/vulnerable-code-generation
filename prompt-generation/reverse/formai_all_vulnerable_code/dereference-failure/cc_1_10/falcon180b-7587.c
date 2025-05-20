//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 256
#define MAX_WORD_LENGTH 16
#define MAX_SENTIMENTS 6
#define POSITIVE_SENTIMENT 1
#define NEGATIVE_SENTIMENT -1
#define NEUTRAL_SENTIMENT 0

typedef struct {
    char *word;
    int sentiment;
} WordSentiment;

typedef struct {
    WordSentiment *words;
    int numWords;
    int totalSentiment;
} SentenceSentiment;

SentenceSentiment analyzeSentiment(char *sentence) {
    SentenceSentiment result = {0};
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        WordSentiment ws = {word, NEUTRAL_SENTIMENT};
        result.words = realloc(result.words, sizeof(WordSentiment) * ++result.numWords);
        memcpy(&result.words[result.numWords - 1], &ws, sizeof(WordSentiment));
        word = strtok(NULL, " ");
    }
    return result;
}

void printSentiment(SentenceSentiment sentence) {
    printf("Sentiment: ");
    if (sentence.totalSentiment > 0) {
        printf("positive\n");
    } else if (sentence.totalSentiment < 0) {
        printf("negative\n");
    } else {
        printf("neutral\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    char sentence[MAX_SENTENCE_LENGTH] = {0};
    strncpy(sentence, argv[1], MAX_SENTENCE_LENGTH - 1);

    SentenceSentiment ss = analyzeSentiment(sentence);
    printSentiment(ss);

    return 0;
}