//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_SENTIMENT_SCORE 10

typedef struct sentiment_dict {
    char word[50];
    int score;
} sentiment_dict;

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *token;
    int sentiment_score = 0;
    int word_count = 0;
    int i;
    
    // Load sentiment dictionary
    sentiment_dict dict[MAX_SENTIMENT_SCORE];
    fp = fopen("sentiment_dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error opening sentiment dictionary file");
        return 1;
    }
    i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL && i < MAX_SENTIMENT_SCORE) {
        token = strtok(line, " ");
        strncpy(dict[i].word, token, sizeof(dict[i].word));
        token = strtok(NULL, " ");
        dict[i].score = strtol(token, NULL, 10);
        i++;
    }
    fclose(fp);
    
    // Get user input
    printf("Enter a sentence to analyze sentiment: ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    
    // Tokenize input and analyze sentiment
    token = strtok(line, " ");
    while (token != NULL) {
        word_count++;
        for (i = 0; i < MAX_SENTIMENT_SCORE; i++) {
            if (strcmp(dict[i].word, token) == 0) {
                sentiment_score += dict[i].score;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    if (word_count == 0) {
        printf("No words to analyze");
        return 1;
    }
    
    // Output sentiment analysis result
    double avg_sentiment_score = (double) sentiment_score / word_count;
    printf("Sentiment score: %.2f\n", avg_sentiment_score);
    
    return 0;
}