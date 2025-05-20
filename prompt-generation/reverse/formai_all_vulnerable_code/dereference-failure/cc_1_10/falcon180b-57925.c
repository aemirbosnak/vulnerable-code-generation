//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 100
#define MAX_WORD_LENGTH 20
#define NUM_SENTIMENTS 3

typedef struct sentiment_score {
    char* sentiment;
    int score;
} SentimentScore;

SentimentScore* initialize_sentiments() {
    SentimentScore* sentiments = (SentimentScore*)malloc(sizeof(SentimentScore) * NUM_SENTIMENTS);
    if (sentiments == NULL) {
        printf("Error: Failed to allocate memory for sentiments.\n");
        exit(1);
    }

    sentiments[0].sentiment = "Positive";
    sentiments[0].score = 0;

    sentiments[1].sentiment = "Negative";
    sentiments[1].score = 0;

    sentiments[2].sentiment = "Neutral";
    sentiments[2].score = 0;

    return sentiments;
}

void free_sentiments(SentimentScore* sentiments) {
    free(sentiments);
}

void analyze_sentence(char* sentence, SentimentScore* sentiments) {
    int i, j, k;
    char word[MAX_WORD_LENGTH];
    bool in_word = false;

    for (i = 0; i < strlen(sentence); i++) {
        if (isalnum(sentence[i])) {
            in_word = true;
        } else if (in_word) {
            word[k] = '\0';
            for (j = 0; j < NUM_SENTIMENTS; j++) {
                if (strcmp(word, sentiments[j].sentiment) == 0) {
                    sentiments[j].score++;
                    break;
                }
            }
            k = 0;
            in_word = false;
        }
    }
}

void print_sentiments(SentimentScore* sentiments) {
    int i;

    for (i = 0; i < NUM_SENTIMENTS; i++) {
        printf("%s: %d\n", sentiments[i].sentiment, sentiments[i].score);
    }
}

int main() {
    FILE* input_file;
    char sentence[MAX_SENTENCE_LENGTH];
    SentimentScore* sentiments = initialize_sentiments();

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Failed to open input file.\n");
        exit(1);
    }

    while (fgets(sentence, MAX_SENTENCE_LENGTH, input_file)!= NULL) {
        analyze_sentence(sentence, sentiments);
    }

    fclose(input_file);
    print_sentiments(sentiments);
    free_sentiments(sentiments);

    return 0;
}