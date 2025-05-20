//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT 1000
#define POSITIVE_WORDS 10
#define NEGATIVE_WORDS 10

// Arrays to hold positive and negative words
const char *positive_words[POSITIVE_WORDS] = {
    "happy", "joy", "love", "fantastic", "great", 
    "amazing", "positive", "awesome", "wonderful", 
    "excited"
};

const char *negative_words[NEGATIVE_WORDS] = {
    "sad", "hate", "bad", "terrible", "awful", 
    "horrible", "negative", "angry", "disappointing", 
    "frustrated"
};

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for(int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Function to analyze sentiment from input string
void analyze_sentiment(const char *input) {
    int positive_count = 0;
    int negative_count = 0;

    char *token = strtok(strdup(input), " ");
    
    while(token != NULL) {
        to_lowercase(token); // Convert token to lowercase

        // Check for positive words
        for(int i = 0; i < POSITIVE_WORDS; i++) {
            if(strcmp(token, positive_words[i]) == 0) {
                positive_count++;
                break;
            }
        }

        // Check for negative words
        for(int i = 0; i < NEGATIVE_WORDS; i++) {
            if(strcmp(token, negative_words[i]) == 0) {
                negative_count++;
                break;
            }
        }

        token = strtok(NULL, " ");
    }

    // Determine overall sentiment
    if(positive_count > negative_count) {
        printf("Sentiment Analysis Result: Positive sentiment detected (%d positive words, %d negative words).\n", positive_count, negative_count);
    } else if(negative_count > positive_count) {
        printf("Sentiment Analysis Result: Negative sentiment detected (%d positive words, %d negative words).\n", positive_count, negative_count);
    } else {
        printf("Sentiment Analysis Result: Neutral sentiment detected (%d positive words, %d negative words).\n", positive_count, negative_count);
    }
}

int main() {
    char input[MAX_INPUT];

    printf("Welcome to the Creative C Sentiment Analysis Tool!\n");
    printf("Please enter a sentence to analyze its sentiment:\n");
    
    // Read user input
    fgets(input, sizeof(input), stdin);
    
    // Remove new line character from input
    input[strcspn(input, "\n")] = 0;

    // Perform sentiment analysis
    analyze_sentiment(input);

    return 0;
}