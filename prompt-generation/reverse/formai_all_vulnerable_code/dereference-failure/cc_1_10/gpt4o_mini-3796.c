//GPT-4o-mini DATASET v1.0 Category: Sentiment analysis tool ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_WORD_LENGTH 50
#define MAX_WORDS 200
#define POSITIVE_WORDS 10
#define NEGATIVE_WORDS 10

// Predefined lists of positive and negative words
const char *positiveWords[POSITIVE_WORDS] = {
    "happy", "good", "excellent", "fantastic", "great",
    "love", "enjoy", "positive", "wonderful", "amazing"
};

const char *negativeWords[NEGATIVE_WORDS] = {
    "sad", "bad", "terrible", "horrible", "awful",
    "hate", "angry", "negative", "worst", "disappointing"
};

// Function to check if a word is in a given list
int isWordInList(const char *word, const char **wordList, int listSize) {
    for (int i = 0; i < listSize; i++) {
        if (strcmp(word, wordList[i]) == 0) {
            return 1; // Word found
        }
    }
    return 0; // Word not found
}

// Function to analyze sentiment of the input text
void analyzeSentiment(const char *input) {
    char words[MAX_WORDS][MAX_WORD_LENGTH];
    int wordCount = 0;
    int positiveCount = 0;
    int negativeCount = 0;

    // Tokenizing input text into words
    char *token = strtok(strdup(input), " ");
    while (token != NULL && wordCount < MAX_WORDS) {
        strncpy(words[wordCount], token, MAX_WORD_LENGTH - 1);
        words[wordCount][MAX_WORD_LENGTH - 1] = '\0'; // Ensure null termination
        wordCount++;
        token = strtok(NULL, " ");
    }

    // Analyzing words for sentiment
    for (int i = 0; i < wordCount; i++) {
        if (isWordInList(words[i], positiveWords, POSITIVE_WORDS)) {
            positiveCount++;
        } else if (isWordInList(words[i], negativeWords, NEGATIVE_WORDS)) {
            negativeCount++;
        }
    }

    // Calculating sentiment score
    int sentimentScore = positiveCount - negativeCount;

    // Outputting results
    printf("Total Words: %d\n", wordCount);
    printf("Positive Words: %d\n", positiveCount);
    printf("Negative Words: %d\n", negativeCount);
    printf("Sentiment Score: %d\n", sentimentScore);

    if (sentimentScore > 0) {
        printf("Overall Sentiment: Positive\n");
    } else if (sentimentScore < 0) {
        printf("Overall Sentiment: Negative\n");
    } else {
        printf("Overall Sentiment: Neutral\n");
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter your text for sentiment analysis (max %d characters):\n", MAX_INPUT_LENGTH);
    
    // Read input text
    if (fgets(input, sizeof(input), stdin) != NULL) {
        // Remove newline character from input
        input[strcspn(input, "\n")] = '\0';

        // Analyze sentiment
        analyzeSentiment(input);
    } else {
        fprintf(stderr, "Error reading input.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}