//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 256

// Define the maximum number of words in a sentence
#define MAX_WORDS_IN_SENTENCE 1024

// Define the number of sentiment classes
#define NUM_SENTIMENT_CLASSES 3

// Define the sentiment classes
char *sentiment_classes[] = {"positive", "neutral", "negative"};

// Define the sentiment scores for each word
float sentiment_scores[] = {
    1.0,  // "good"
    0.5,  // "bad"
    0.0,  // "neutral"
    -0.5, // "terrible"
    -1.0  // "awful"
};

// Define the number of sentiment scores
#define NUM_SENTIMENT_SCORES (sizeof(sentiment_scores) / sizeof(float))

// Define the function to get the sentiment score of a word
float get_sentiment_score(char *word) {
    // Convert the word to lowercase
    char *lowercase_word = strdup(word);
    for (int i = 0; lowercase_word[i]; i++) {
        lowercase_word[i] = tolower(lowercase_word[i]);
    }

    // Find the sentiment score for the word
    float sentiment_score = 0.0;
    for (int i = 0; i < NUM_SENTIMENT_SCORES; i++) {
        if (strcmp(lowercase_word, sentiment_classes[i]) == 0) {
            sentiment_score = sentiment_scores[i];
            break;
        }
    }

    // Free the memory allocated for the lowercase word
    free(lowercase_word);

    // Return the sentiment score
    return sentiment_score;
}

// Define the function to get the sentiment of a sentence
int get_sentiment(char *sentence) {
    // Split the sentence into words
    char *words[MAX_WORDS_IN_SENTENCE];
    int num_words = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[num_words++] = word;
        word = strtok(NULL, " ");
    }

    // Calculate the sentiment score for each word
    float sentiment_scores[num_words];
    for (int i = 0; i < num_words; i++) {
        sentiment_scores[i] = get_sentiment_score(words[i]);
    }

    // Calculate the average sentiment score
    float average_sentiment_score = 0.0;
    for (int i = 0; i < num_words; i++) {
        average_sentiment_score += sentiment_scores[i];
    }
    average_sentiment_score /= num_words;

    // Determine the sentiment of the sentence
    int sentiment;
    if (average_sentiment_score > 0.0) {
        sentiment = 0; // positive
    } else if (average_sentiment_score < 0.0) {
        sentiment = 2; // negative
    } else {
        sentiment = 1; // neutral
    }

    // Return the sentiment
    return sentiment;
}

int main() {
    // Get the sentence from the user
    char sentence[1024];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the newline character from the sentence
    sentence[strcspn(sentence, "\n")] = 0;

    // Get the sentiment of the sentence
    int sentiment = get_sentiment(sentence);

    // Print the sentiment of the sentence
    printf("The sentiment of the sentence is: %s\n", sentiment_classes[sentiment]);

    return 0;
}