//Falcon2-11B DATASET v1.0 Category: Sentiment analysis tool ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

// Function to calculate sentiment score of a given text
int calculateSentimentScore(char* text) {
    // Split the text into individual words
    char* words[MAX_WORDS];
    int numWords = splitTextIntoWords(text, words, MAX_WORDS);
    
    // Initialize sentiment score and positive/negative count
    int sentimentScore = 0;
    int positiveCount = 0;
    int negativeCount = 0;
    
    // Iterate over each word
    for (int i = 0; i < numWords; i++) {
        char* word = words[i];
        
        // Check if the word is positive or negative
        if (isPositiveWord(word)) {
            positiveCount++;
        } else if (isNegativeWord(word)) {
            negativeCount++;
        }
        
        // Calculate sentiment score based on word count
        if (positiveCount > negativeCount) {
            sentimentScore += (positiveCount - negativeCount);
        } else if (negativeCount > positiveCount) {
            sentimentScore += (negativeCount - positiveCount);
        }
    }
    
    // Return sentiment score
    return sentimentScore;
}

// Function to split the text into individual words
int splitTextIntoWords(char* text, char* words[], int maxWords) {
    int numWords = 0;
    
    // Split the text using space as delimiter
    char* tokens[MAX_WORD_LENGTH];
    int numTokens = splitStringIntoTokens(text, tokens, MAX_WORD_LENGTH);
    
    // Store the words in the array
    for (int i = 0; i < numTokens; i++) {
        strcpy(words[numWords], tokens[i]);
        numWords++;
        if (numWords == maxWords) {
            break;
        }
    }
    
    // Free the memory allocated for tokens array
    free(tokens);
    
    // Return number of words
    return numWords;
}

// Function to split a string into tokens
int splitStringIntoTokens(char* text, char* tokens[], int maxTokens) {
    int numTokens = 0;
    char* token = strtok(text, " ");
    
    // Split the string using space as delimiter
    while (token!= NULL) {
        strcpy(tokens[numTokens], token);
        numTokens++;
        token = strtok(NULL, " ");
    }
    
    // Return number of tokens
    return numTokens;
}

// Function to check if a word is positive
int isPositiveWord(char* word) {
    // Check if the word is a positive word
    if (strcmp(word, "good") == 0 || strcmp(word, "great") == 0 || strcmp(word, "awesome") == 0 || strcmp(word, "excellent") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to check if a word is negative
int isNegativeWord(char* word) {
    // Check if the word is a negative word
    if (strcmp(word, "bad") == 0 || strcmp(word, "horrible") == 0 || strcmp(word, "awful") == 0 || strcmp(word, "terrible") == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main() {
    char* text = "I had a wonderful day today. The weather was great and the food was delicious.";
    
    int sentimentScore = calculateSentimentScore(text);
    
    printf("Sentiment score: %d\n", sentimentScore);
    
    return 0;
}