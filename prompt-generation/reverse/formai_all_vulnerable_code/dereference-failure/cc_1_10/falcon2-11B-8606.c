//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Function to perform sentiment analysis
int sentimentAnalysis(char* text) {
    // Initialize sentiment score
    int sentiment = 0;

    // Split text into words
    char* words[100];
    char* token = strtok(text, " ");
    int count = 0;
    while (token!= NULL) {
        words[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    // Check sentiment of each word
    for (int i = 0; i < count; i++) {
        if (isalpha(words[i][0]) && words[i][strlen(words[i])-1] == '.') {
            int sentimentValue = getSentimentValue(words[i]);
            sentiment += sentimentValue;
        }
    }

    // Return the sentiment score
    return sentiment;
}

// Function to get sentiment value of a word
int getSentimentValue(char* word) {
    int sentimentValue = 0;

    // Check sentiment of the word
    if (strcmp(word, "happy") == 0) {
        sentimentValue = 1;
    } else if (strcmp(word, "sad") == 0) {
        sentimentValue = -1;
    } else if (strcmp(word, "angry") == 0) {
        sentimentValue = -1;
    } else if (strcmp(word, "disgusted") == 0) {
        sentimentValue = -1;
    } else if (strcmp(word, "fearful") == 0) {
        sentimentValue = -1;
    } else if (strcmp(word, "surprised") == 0) {
        sentimentValue = 1;
    } else {
        sentimentValue = 0;
    }

    return sentimentValue;
}

// Main function
int main() {
    // Input text
    char* text = "I am feeling very happy today.";

    // Perform sentiment analysis
    int sentimentScore = sentimentAnalysis(text);

    // Output sentiment score
    printf("Sentiment score: %d\n", sentimentScore);

    return 0;
}