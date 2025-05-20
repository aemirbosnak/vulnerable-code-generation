//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_WORDS 10000
#define VOCAB_SIZE 2000
#define NUM_FEATURES 10

typedef struct {
    char word[50];
    float score;
} Word;

Word words[MAX_WORDS];
int num_words = 0;
float weights[NUM_FEATURES];
float thresholds[NUM_FEATURES];

void load_data() {
    FILE *fp = fopen("sentiment.csv", "r");
    char line[1000];
    char *token = NULL;
    int row = 0;

    while (fgets(line, sizeof(line), fp) != NULL) {
        token = strtok(line, ",");
        if (token != NULL) {
            strcpy(words[row].word, token);
            token = strtok(NULL, ",");
            if (token != NULL)
                words[row].score = atof(token);
            row++;
        }
        if (row >= MAX_WORDS)
            break;
    }

    fclose(fp);
}

void preprocess(char *text, char *processed_text) {
    int i = 0;
    for (; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            processed_text[i] = tolower(text[i]);
            continue;
        }

        if (text[i] == '\'') {
            i++;
            if (isalpha(text[i])) {
                processed_text[i - 1] = 'a';
                processed_text[i] = text[i];
                i++;
                continue;
            }
        }

        processed_text[i] = text[i];
    }

    processed_text[i] = '\0';
}

int get_word_index(char *word) {
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i].word, word) == 0)
            return i;
    }

    return -1;
}

void analyze_sentiment(char *text) {
    char processed_text[100];
    int word_index = 0;
    float sentiment_score = 0.0;

    preprocess(text, processed_text);

    for (int i = 0; i < strlen(processed_text); i++) {
        word_index = get_word_index(&processed_text[i]);
        if (word_index >= 0) {
            sentiment_score += words[word_index].score * weights[word_index];
        }
    }

    for (int i = 0; i < NUM_FEATURES; i++) {
        if (sentiment_score < thresholds[i]) {
            printf("Negative sentiment\n");
            return;
        }
    }

    printf("Positive sentiment\n");
}

int main(int argc, char *argv[]) {
    load_data();

    srand(time(NULL));

    for (int i = 0; i < NUM_FEATURES; i++) {
        weights[i] = (float) rand() / RAND_MAX;
        thresholds[i] = weights[i] * 0.9;
    }

    char text[100];
    printf("Enter text to analyze: ");
    scanf("%s", text);

    analyze_sentiment(text);

    return 0;
}