//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LEN 1024
#define MAX_WORD_LEN 32
#define NUM_SENTIMENTS 6

typedef struct {
    char *word;
    int count;
} WordCount;

typedef struct {
    char *sentiment;
    int value;
} Sentiment;

Sentiment sentiments[NUM_SENTIMENTS] = {
    {"happy", 1},
    {"sad", -1},
    {"angry", -1},
    {"excited", 1},
    {"bored", -1},
    {"confused", 0}
};

char *tokenize(char *sentence) {
    char *token = strtok(sentence, ",.!?;:");
    while (token!= NULL) {
        printf("%s ", token);
        token = strtok(NULL, ",.!?;:");
    }
    printf("\n");
}

void analyze_sentiment(char *sentence) {
    int i, j, k, len;
    char word[MAX_WORD_LEN];
    WordCount word_counts[MAX_SENTENCE_LEN];
    memset(word_counts, 0, sizeof(word_counts));

    tokenize(sentence);

    for (i = 0; i < MAX_SENTENCE_LEN; i++) {
        if (i >= MAX_WORD_LEN) {
            break;
        }
        strncpy(word, sentence + i, MAX_WORD_LEN);
        len = strlen(word);
        for (j = 0; j < len; j++) {
            word[j] = tolower(word[j]);
        }
        for (k = 0; k < NUM_SENTIMENTS; k++) {
            if (strstr(word, sentiments[k].sentiment)) {
                word_counts[i].count++;
                word_counts[i].word = strdup(sentiments[k].sentiment);
                break;
            }
        }
        if (k == NUM_SENTIMENTS) {
            word_counts[i].word = strdup(word);
        }
    }

    printf("Overall Sentiment: ");
    for (i = 0; i < NUM_SENTIMENTS; i++) {
        if (word_counts[i].count > 0) {
            printf("%s ", word_counts[i].word);
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sentence>\n", argv[0]);
        return 1;
    }

    analyze_sentiment(argv[1]);

    return 0;
}