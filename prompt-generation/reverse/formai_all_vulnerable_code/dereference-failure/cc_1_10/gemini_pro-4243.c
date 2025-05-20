//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int weight;
} sentiment_word;

sentiment_word dictionary[MAX_WORDS];
int dictionary_size = 0;

void load_dictionary() {
    FILE *fp = fopen("sentiment.txt", "r");
    if (fp == NULL) {
        perror("Error opening sentiment.txt");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)) {
        char *word = strtok(line, " ");
        int weight = atoi(strtok(NULL, " "));

        dictionary[dictionary_size].word = strdup(word);
        dictionary[dictionary_size].weight = weight;
        dictionary_size++;
    }

    fclose(fp);
}

int analyze_sentiment(char *text) {
    int score = 0;

    char *words[MAX_WORDS];
    int num_words = 0;

    char *token = strtok(text, " ");
    while (token != NULL) {
        words[num_words] = token;
        num_words++;

        token = strtok(NULL, " ");
    }

    for (int i = 0; i < num_words; i++) {
        for (int j = 0; j < dictionary_size; j++) {
            if (strcmp(words[i], dictionary[j].word) == 0) {
                score += dictionary[j].weight;
                break;
            }
        }
    }

    return score;
}

int main() {
    load_dictionary();

    char *text = "I love this movie!";
    int score = analyze_sentiment(text);

    printf("Sentiment score: %d\n", score);

    return 0;
}