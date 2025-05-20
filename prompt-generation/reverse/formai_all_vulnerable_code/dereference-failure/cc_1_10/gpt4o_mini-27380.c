//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_WORDS 50
#define MAX_WORD_LENGTH 20

// A simple structure to hold sentiment words
typedef struct {
    char word[MAX_WORD_LENGTH];
    int score; // Positive or negative score 
} SentimentWord;

// Function prototypes
void loadSentimentWords(SentimentWord *sentimentWords, int *count);
void analyzeSentiment(const char *line, SentimentWord *sentimentWords, int count);
int findSentimentScore(const char *word, SentimentWord *sentimentWords, int count);

// Main function
int main() {
    FILE *file;
    char *filename = "input.txt";
    char line[256];
    int sentimentCount = 0;
    SentimentWord sentimentWords[MAX_WORDS];

    // Load sentiment words
    loadSentimentWords(sentimentWords, &sentimentCount);

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return 1;
    }

    // Read each line and analyze sentiment
    while (fgets(line, sizeof(line), file)) {
        analyzeSentiment(line, sentimentWords, sentimentCount);
    }

    // Close the file
    fclose(file);
    return 0;
}

// Load sentiment words and their scores from a predefined source
void loadSentimentWords(SentimentWord *sentimentWords, int *count) {
    // Define some basic sentiment words for demonstration
    const char *words[][2] = {
        {"happy", 1},
        {"joy", 1},
        {"love", 2},
        {"sad", -1},
        {"hate", -2},
        {"anger", -1},
        {"excited", 1},
        {"confused", -1},
        {"good", 1},
        {"bad", -1}
    };

    *count = sizeof(words) / sizeof(words[0]);
    for (int i = 0; i < *count; i++) {
        strcpy(sentimentWords[i].word, words[i][0]);
        sentimentWords[i].score = atoi(words[i][1]);
    }
}

// Analyze a line of text and print sentiment score
void analyzeSentiment(const char *line, SentimentWord *sentimentWords, int count) {
    char *token;
    int totalScore = 0;

    // Tokenize the line into words
    char *lineCopy = strdup(line);
    token = strtok(lineCopy, " \n");
    while (token != NULL) {
        totalScore += findSentimentScore(token, sentimentWords, count);
        token = strtok(NULL, " \n");
    }

    // Print the result
    if (totalScore > 0) {
        printf("Sentiment score for line: %s (Positive)\n", line);
    } else if (totalScore < 0) {
        printf("Sentiment score for line: %s (Negative)\n", line);
    } else {
        printf("Sentiment score for line: %s (Neutral)\n", line);
    }

    free(lineCopy);
}

// Find the sentiment score of a given word
int findSentimentScore(const char *word, SentimentWord *sentimentWords, int count) {
    for (int i = 0; i < count; i++) {
        if (strcmp(word, sentimentWords[i].word) == 0) {
            return sentimentWords[i].score;
        }
    }
    return 0; // Word not found in sentiment list
}