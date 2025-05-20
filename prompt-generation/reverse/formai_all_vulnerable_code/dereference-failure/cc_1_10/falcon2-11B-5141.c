//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: careful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the sentiment score dictionary
static const char *sentimentScores[] = {
    "positive", "negative", "neutral", "mixed"
};

// Function to determine the overall sentiment of a piece of text
int getSentiment(char *text) {
    // Tokenize the text into individual words
    char *words[100];
    int numWords = 0;
    char *token = strtok(text, " ");
    while (token!= NULL) {
        words[numWords] = token;
        numWords++;
        token = strtok(NULL, " ");
    }
    
    // Remove any stop words
    int i;
    for (i = 0; i < numWords; i++) {
        if (strstr(words[i], "a") || strstr(words[i], "the") || strstr(words[i], "and")) {
            words[i] = NULL;
        }
    }
    
    // Calculate the sentiment score for each word
    int sentimentScore = 0;
    int j;
    for (j = 0; j < numWords; j++) {
        int k;
        for (k = 0; k < 4; k++) {
            if (strcmp(words[j], sentimentScores[k]) == 0) {
                sentimentScore += k;
                break;
            }
        }
    }
    
    // Determine the overall sentiment of the text
    if (sentimentScore > 0) {
        return 1;
    } else if (sentimentScore < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    char text[100];
    printf("Enter a piece of text: ");
    fgets(text, sizeof(text), stdin);
    int sentiment = getSentiment(text);
    printf("The sentiment of the text is %d\n", sentiment);
    return 0;
}