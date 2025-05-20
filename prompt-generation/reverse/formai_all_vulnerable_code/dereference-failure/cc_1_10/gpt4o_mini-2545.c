//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum size constants
#define MAX_TEXT_SIZE 1024
#define MAX_WORD_SIZE 20
#define MAX_WORDS 200

// Function prototypes
void analyzeSentiment(const char *text, int *positiveCount, int *negativeCount);
void displayResult(int positiveCount, int negativeCount);

int main() {
    char inputText[MAX_TEXT_SIZE];
    int positiveCount = 0, negativeCount = 0;

    // Predefined positive and negative words
    const char *positiveWords[] = {
        "good", "happy", "joy", "love", "excellent", "great", "wonderful", "fantastic", "amazing"
    };
    const char *negativeWords[] = {
        "bad", "sad", "hate", "terrible", "awful", "poor", "horrible", "disaster", "worst"
    };

    // Get text input from the user
    printf("Enter your text for sentiment analysis:\n");
    if (fgets(inputText, MAX_TEXT_SIZE, stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    // Remove newline character if present
    inputText[strcspn(inputText, "\n")] = 0;

    // Analyze the sentiment of the input text
    analyzeSentiment(inputText, &positiveCount, &negativeCount);
    displayResult(positiveCount, negativeCount);

    return EXIT_SUCCESS;
}

void analyzeSentiment(const char *text, int *positiveCount, int *negativeCount) {
    // Define positive and negative words
    const char *positiveWords[] = {
        "good", "happy", "joy", "love", "excellent", "great", "wonderful", "fantastic", "amazing"
    };
    const char *negativeWords[] = {
        "bad", "sad", "hate", "terrible", "awful", "poor", "horrible", "disaster", "worst"
    };

    // Count of positive and negative words
    size_t positiveWordsCount = sizeof(positiveWords) / sizeof(positiveWords[0]);
    size_t negativeWordsCount = sizeof(negativeWords) / sizeof(negativeWords[0]);

    // Tokenize input text
    char *token = strtok(strdup(text), " ");
    while (token != NULL) {
        for (size_t i = 0; i < positiveWordsCount; i++) {
            if (strcasecmp(token, positiveWords[i]) == 0) {
                (*positiveCount)++;
                break;
            }
        }
        for (size_t j = 0; j < negativeWordsCount; j++) {
            if (strcasecmp(token, negativeWords[j]) == 0) {
                (*negativeCount)++;
                break;
            }
        }
        token = strtok(NULL, " ");
    }
}

void displayResult(int positiveCount, int negativeCount) {
    printf("\nSentiment Analysis Result:\n");
    printf("Positive words count: %d\n", positiveCount);
    printf("Negative words count: %d\n", negativeCount);

    if (positiveCount > negativeCount) {
        printf("Overall Sentiment: Positive\n");
    } else if (negativeCount > positiveCount) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}