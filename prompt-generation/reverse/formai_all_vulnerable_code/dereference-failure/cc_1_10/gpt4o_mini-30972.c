//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to load the sentiment words from a file
// It uses positive and negative words to analyze sentiment.
int loadSentimentWords(const char *filename, char ***words) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening sentiment words file");
        return -1;
    }

    char **tempWords = malloc(1000 * sizeof(char *));
    char buffer[100];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        // Remove newline characters
        buffer[strcspn(buffer, "\n")] = 0;
        tempWords[count] = strdup(buffer);
        count++;
    }

    fclose(file);
    tempWords[count] = NULL; // Null-terminate the array
    *words = tempWords;
    return count;
}

// Function to analyze the sentiment of the input text
void analyzeSentiment(const char *text, char **positiveWords, int posCount, char **negativeWords, int negCount) {
    int positiveScore = 0;
    int negativeScore = 0;
    char *token;
    char *textCopy = strdup(text);
    
    // Tokenize the input text
    token = strtok(textCopy, " ");
    while (token) {
        for (int i = 0; i < posCount; i++) {
            if (strcmp(token, positiveWords[i]) == 0) {
                positiveScore++;
                break;
            }
        }
        for (int j = 0; j < negCount; j++) {
            if (strcmp(token, negativeWords[j]) == 0) {
                negativeScore++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }

    // Print the sentiment analysis result
    printf("Sentiment Analysis Result:\n");
    printf("Positive Score: %d\n", positiveScore);
    printf("Negative Score: %d\n", negativeScore);
    
    // Determine overall sentiment
    if (positiveScore > negativeScore) {
        printf("Overall Sentiment: Positive\n");
    } else if (negativeScore > positiveScore) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }

    free(textCopy);
}

// Main function to execute the sentiment analysis
int main() {
    char **positiveWords;
    char **negativeWords;
    int positiveCount = loadSentimentWords("positive.txt", &positiveWords);
    int negativeCount = loadSentimentWords("negative.txt", &negativeWords);

    if (positiveCount < 0 || negativeCount < 0) {
        return 1;
    }

    char inputText[500];
    printf("Enter the text for sentiment analysis: ");
    fgets(inputText, sizeof(inputText), stdin);
    
    // Remove newline character from input
    inputText[strcspn(inputText, "\n")] = 0;

    analyzeSentiment(inputText, positiveWords, positiveCount, negativeWords, negativeCount);
    
    // Free allocated memory
    for (int i = 0; i < positiveCount; i++) {
        free(positiveWords[i]);
    }
    for (int j = 0; j < negativeCount; j++) {
        free(negativeWords[j]);
    }
    free(positiveWords);
    free(negativeWords);

    return 0;
}