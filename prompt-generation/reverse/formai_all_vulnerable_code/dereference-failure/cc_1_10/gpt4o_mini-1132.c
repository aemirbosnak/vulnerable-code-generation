//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define SENTIMENT_WORDS 10

// Struct to hold sentiment words and their corresponding scores
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score; // Positive score (+1) or Negative score (-1)
} Sentiment;

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to load sentiment words into an array
void loadSentimentWords(Sentiment *sentiments, int *count) {
    const char *words[SENTIMENT_WORDS][2] = {
        {"happy", 1},
        {"joy", 1},
        {"excited", 1},
        {"sad", -1},
        {"angry", -1},
        {"hate", -1},
        {"love", 1},
        {"disappointed", -1},
        {"great", 1},
        {"terrible", -1}
    };

    for (int i = 0; i < SENTIMENT_WORDS; i++) {
        strcpy(sentiments[i].word, words[i][0]);
        sentiments[i].score = atoi(words[i][1]);
    }
    *count = SENTIMENT_WORDS;
}

// Function to analyze sentiment of a given line of text
int analyzeSentiment(char *line, Sentiment *sentiments, int count) {
    int sentimentScore = 0;
    char *token = strtok(line, " ,.!?;:\n");

    while (token) {
        toLowerCase(token);
        for (int i = 0; i < count; i++) {
            if (strcmp(token, sentiments[i].word) == 0) {
                sentimentScore += sentiments[i].score;
                break;
            }
        }
        token = strtok(NULL, " ,.!?;:\n");
    }
    
    return sentimentScore;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    Sentiment sentiments[SENTIMENT_WORDS];
    int sentimentCount;
    loadSentimentWords(sentiments, &sentimentCount);

    char line[MAX_LINE_LENGTH];
    int totalScore = 0, lineCount = 0;

    while (fgets(line, sizeof(line), file)) {
        int score = analyzeSentiment(line, sentiments, sentimentCount);
        totalScore += score;
        lineCount++;
        printf("Sentiment score for line %d: %d\n", lineCount, score);
    }

    fclose(file);

    if (lineCount > 0) {
        float averageScore = (float)totalScore / lineCount;
        printf("Total sentiment score: %d\n", totalScore);
        printf("Average sentiment score: %.2f\n", averageScore);
        
        if (averageScore > 0) {
            printf("Overall sentiment: Positive\n");
        } else if (averageScore < 0) {
            printf("Overall sentiment: Negative\n");
        } else {
            printf("Overall sentiment: Neutral\n");
        }
    } else {
        printf("No lines to analyze.\n");
    }

    return EXIT_SUCCESS;
}