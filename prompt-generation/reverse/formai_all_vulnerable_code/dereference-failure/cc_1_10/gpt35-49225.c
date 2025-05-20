//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Sentiment analysis function
int analyze_sentiment(char *text) {
    int sentiment_score = 0;
    int num_words = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        num_words++;
        if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "excellent") == 0) {
            sentiment_score += 2;
        } else if (strcmp(word, "bad") == 0 || strcmp(word, "terrible") == 0 || strcmp(word, "poor") == 0) {
            sentiment_score -= 2;
        } else if (strcmp(word, "like") == 0 || strcmp(word, "love") == 0) {
            sentiment_score++;
        } else if (strcmp(word, "hate") == 0 || strcmp(word, "dislike") == 0) {
            sentiment_score--;
        }
        word = strtok(NULL, " ");
    }

    // Calculate sentiment ratio
    float sentiment_ratio = (float) sentiment_score / num_words;
    if (sentiment_ratio >= 0.5) {
        printf("Positive sentiment detected!\n");
        return 1;
    } else if (sentiment_ratio <= -0.5) {
        printf("Negative sentiment detected.\n");
        return -1;
    } else {
        printf("Neutral sentiment detected.\n");
        return 0;
    }
}

// Main function
int main() {
    // Test sentiment analysis with sample text
    char *text = "I had a great time at the amusement park yesterday. The rides were thrilling and the food was delicious!";
    analyze_sentiment(text);

    text = "I was really disappointed with the movie I watched over the weekend. The plot was confusing and the acting was poor.";
    analyze_sentiment(text);

    text = "I don't really care for sushi, but my friend convinced me to try it and it wasn't that bad.";
    analyze_sentiment(text);

    return 0;
}