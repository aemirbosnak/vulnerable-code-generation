//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define sentiment scores for words
int sentiment_scores[] = {
    // Positive words
    [0] = 1, [1] = 2, [2] = 3, [3] = 4, [4] = 5,
    // Negative words
    [5] = -1, [6] = -2, [7] = -3, [8] = -4, [9] = -5
};

char *positive_words[] = {
    "amazing", "awesome", "brilliant", "excellent", "great"
};
char *negative_words[] = {
    "awful", "bad", "terrible", "horrible", "worst"
};

// Calculate sentiment score for a given text
int calculate_sentiment(char *text) {
    int score = 0;
    char *token;

    // Tokenize the text
    token = strtok(text, " ");
    while (token != NULL) {
        // Check if the token is in the positive or negative list
        for (int i = 0; i < 5; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                score += sentiment_scores[i];
            } else if (strcmp(token, negative_words[i]) == 0) {
                score += sentiment_scores[i];
            }
        }

        // Get the next token
        token = strtok(NULL, " ");
    }

    return score;
}

// Display the sentiment analysis result
void display_sentiment(char *text, int score) {
    if (score > 0) {
        printf("The sentiment of the text '%s' is positive (%d).\n", text, score);
    } else if (score < 0) {
        printf("The sentiment of the text '%s' is negative (%d).\n", text, score);
    } else {
        printf("The sentiment of the text '%s' is neutral (0).\n", text);
    }
}

int main() {
    char *text = "This movie was absolutely amazing!";

    // Calculate the sentiment score
    int score = calculate_sentiment(text);

    // Display the result
    display_sentiment(text, score);

    return 0;
}