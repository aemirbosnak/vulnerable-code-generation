//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the sentiment scores for each word
const int SENTIMENT_SCORES[] = {
    // Positive words
    [0] = 1,  // "good"
    [1] = 2,  // "great"
    [2] = 3,  // "excellent"
    [3] = 4,  // "amazing"
    [4] = 5,  // "superb"

    // Negative words
    [5] = -1, // "bad"
    [6] = -2, // "terrible"
    [7] = -3, // "horrible"
    [8] = -4, // "awful"
    [9] = -5, // "dreadful"
};

// Get the sentiment score for a given word
int get_sentiment_score(char* word) {
    for (int i = 0; i < sizeof(SENTIMENT_SCORES) / sizeof(int); i++) {
        if (strcmp(word, SENTIMENT_SCORES[i]) == 0) {
            return SENTIMENT_SCORES[i];
        }
    }

    // Word not found in the sentiment dictionary
    return 0;
}

// Analyze the sentiment of a given sentence
int analyze_sentiment(char* sentence) {
    // Tokenize the sentence into words
    char* tokens[100];
    int num_tokens = 0;
    char* token = strtok(sentence, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    int sentiment_score = 0;
    for (int i = 0; i < num_tokens; i++) {
        sentiment_score += get_sentiment_score(tokens[i]);
    }

    return sentiment_score;
}

// Print the sentiment analysis result
void print_sentiment_analysis_result(int sentiment_score) {
    if (sentiment_score > 0) {
        printf("Positive sentiment\n");
    } else if (sentiment_score < 0) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }
}

// Main function
int main() {
    // Get the sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    fgets(sentence, 100, stdin);

    // Analyze the sentiment of the sentence
    int sentiment_score = analyze_sentiment(sentence);

    // Print the sentiment analysis result
    print_sentiment_analysis_result(sentiment_score);

    return 0;
}