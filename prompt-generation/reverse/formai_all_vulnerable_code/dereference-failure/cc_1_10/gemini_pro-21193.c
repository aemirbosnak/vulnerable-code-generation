//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the maximum length of a sentence
#define MAX_SENTENCE_LENGTH 255

// Define the number of words in the sentiment dictionary
#define NUM_WORDS_IN_DICTIONARY 200

// Define the sentiment dictionary
const char *sentiment_dictionary[NUM_WORDS_IN_DICTIONARY] = {
    "good", "great", "excellent", "amazing", "fantastic",
    "bad", "terrible", "awful", "horrible", "disgusting",
    "happy", "joyful", "excited", "delighted", "thrilled",
    "sad", "depressed", "angry", "frustrated", "disappointed"
};

// Define the sentiment scores
const int sentiment_scores[NUM_WORDS_IN_DICTIONARY] = {
    1, 1, 1, 1, 1,
    -1, -1, -1, -1, -1,
    1, 1, 1, 1, 1,
    -1, -1, -1, -1, -1
};

// Parse the sentence and count the number of positive and negative words
int analyze_sentiment(const char *sentence) {
    // Convert the sentence to lowercase
    char *lower_sentence = strdup(sentence);
    for (char *p = lower_sentence; *p; p++) {
        *p = tolower(*p);
    }

    // Tokenize the sentence
    char *tokens[MAX_SENTENCE_LENGTH];
    int num_tokens = 0;
    char *token = strtok(lower_sentence, " ");
    while (token != NULL) {
        tokens[num_tokens++] = token;
        token = strtok(NULL, " ");
    }

    // Count the number of positive and negative words
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < num_tokens; i++) {
        for (int j = 0; j < NUM_WORDS_IN_DICTIONARY; j++) {
            if (strcmp(tokens[i], sentiment_dictionary[j]) == 0) {
                if (sentiment_scores[j] > 0) {
                    positive_count++;
                } else {
                    negative_count++;
                }
            }
        }
    }

    // Return the sentiment score
    return positive_count - negative_count;
}

// Print the sentiment analysis results
void print_results(const char *sentence, int sentiment_score) {
    if (sentiment_score > 0) {
        printf("The sentence '%s' is positive.\n", sentence);
    } else if (sentiment_score < 0) {
        printf("The sentence '%s' is negative.\n", sentence);
    } else {
        printf("The sentence '%s' is neutral.\n", sentence);
    }
}

// Get the user input
char *get_user_input() {
    char *sentence = malloc(MAX_SENTENCE_LENGTH);
    printf("Enter a sentence: ");
    fgets(sentence, MAX_SENTENCE_LENGTH, stdin);
    return sentence;
}

// Main function
int main() {
    // Get the user input
    char *sentence = get_user_input();

    // Analyze the sentiment of the sentence
    int sentiment_score = analyze_sentiment(sentence);

    // Print the sentiment analysis results
    print_results(sentence, sentiment_score);

    // Free the allocated memory
    free(sentence);

    return 0;
}