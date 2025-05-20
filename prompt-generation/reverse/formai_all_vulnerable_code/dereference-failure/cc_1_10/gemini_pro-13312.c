//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 1024

// Structure to store the sentiment analysis results
typedef struct {
    int positive;
    int negative;
    int neutral;
} SentimentAnalysisResult;

// Function to perform sentiment analysis on a sentence
SentimentAnalysisResult sentiment_analysis(char *sentence) {
    SentimentAnalysisResult result = {0, 0, 0};

    // Convert the sentence to lowercase
    for (int i = 0; i < strlen(sentence); i++) {
        sentence[i] = tolower(sentence[i]);
    }

    // Split the sentence into words
    char *words[MAX_SENTENCE_LENGTH];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Check each word for positive, negative, or neutral sentiment
    for (int i = 0; i < num_words; i++) {
        if (strcmp(words[i], "good") == 0 || strcmp(words[i], "great") == 0 || strcmp(words[i], "excellent") == 0) {
            result.positive++;
        } else if (strcmp(words[i], "bad") == 0 || strcmp(words[i], "terrible") == 0 || strcmp(words[i], "awful") == 0) {
            result.negative++;
        } else {
            result.neutral++;
        }
    }

    return result;
}

// Function to print the sentiment analysis results
void print_sentiment_analysis_results(SentimentAnalysisResult result) {
    printf("Positive: %d\n", result.positive);
    printf("Negative: %d\n", result.negative);
    printf("Neutral: %d\n", result.neutral);
}

// Function to get a sentence from the user
char *get_sentence() {
    char *sentence = (char *)malloc(MAX_SENTENCE_LENGTH * sizeof(char));
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    return sentence;
}

// Main function
int main() {
    char *sentence = get_sentence();
    SentimentAnalysisResult result = sentiment_analysis(sentence);
    print_sentiment_analysis_results(result);
    return 0;
}