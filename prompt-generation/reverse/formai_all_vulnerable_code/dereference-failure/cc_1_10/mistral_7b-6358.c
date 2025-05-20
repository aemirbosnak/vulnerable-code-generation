//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define WORD_LENGTH 50
#define BUFFER_SIZE 1024

typedef struct {
    char word[WORD_LENGTH];
    int sentiment_score;
} Word;

Word dictionary[MAX_WORDS];
int num_words = 0;

void load_dictionary() {
    FILE *fp;
    char line[BUFFER_SIZE];
    char *token;

    fp = fopen("sentiment_dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    while (fgets(line, BUFFER_SIZE, fp)) {
        token = strtok(line, " \t\n\r");
        strcpy(dictionary[num_words].word, token);
        num_words++;

        token = strtok(NULL, " \t\n\r");
        dictionary[num_words - 1].sentiment_score = atoi(token);
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int total_score = 0;
    char *token;
    int word_index;

    token = strtok(text, " .,?!:;-_");
    while (token != NULL) {
        for (word_index = 0; word_index < num_words; word_index++) {
            if (strcasecmp(token, dictionary[word_index].word) == 0) {
                total_score += dictionary[word_index].sentiment_score;
                break;
            }
        }

        if (word_index == num_words) {
            // Unknown word, assume neutral sentiment
            total_score += 0;
        }

        token = strtok(NULL, " .,?!:;-_");
    }

    return total_score;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    load_dictionary();

    int sentiment_score = analyze_sentiment(argv[1]);

    printf("Sentiment score: %d\n", sentiment_score);

    if (sentiment_score > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment_score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}