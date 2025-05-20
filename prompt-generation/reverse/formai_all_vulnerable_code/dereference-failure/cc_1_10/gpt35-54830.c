//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int scorePos = 0;
int scoreNeg = 0;

int main() {
    /* Sample text to be analyzed */
    char* text = "I absolutely love this restaurant! The food is amazing and the service is top-notch.";

    /* Positive and negative words to compare against */
    char* positiveWords[] = {"love", "amazing", "top-notch"};
    char* negativeWords[] = {"hate", "terrible", "awful"};

    /* Tokenize the input text */
    const char delim[2] = " ";
    char* token = strtok(text, delim);

    while (token != NULL) {
        /* Check for positive words */
        for (int i = 0; i < sizeof(positiveWords) / sizeof(char*); i++) {
            if (strcmp(positiveWords[i], token) == 0) {
                scorePos++;
            }
        }

        /* Check for negative words */
        for (int i = 0; i < sizeof(negativeWords) / sizeof(char*); i++) {
            if (strcmp(negativeWords[i], token) == 0) {
                scoreNeg++;
            }
        }

        token = strtok(NULL, delim);
    }

    /* Calculate sentiment score */
    int sentimentScore = scorePos - scoreNeg;

    /* Determine sentiment of text */
    if (sentimentScore > 0) {
        printf("The text is positive with a sentiment score of %d", sentimentScore);
    } else if (sentimentScore < 0) {
        printf("The text is negative with a sentiment score of %d", sentimentScore);
    } else {
        printf("The text is neutral with a sentiment score of %d", sentimentScore);
    }

    return 0;
}