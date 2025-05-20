//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define a struct to store the sentiment of a word
typedef struct {
    char *word;
    int sentiment;
} WordSentiment;

// Create an array of WordSentiment structs to store the sentiment of each word
WordSentiment wordSentiments[] = {
    { "amazing", 5 },
    { "great", 4 },
    { "good", 3 },
    { "ok", 2 },
    { "bad", 1 },
    { "terrible", 0 }
};

// Get the sentiment of a word
int getWordSentiment(char *word) {
    // Convert the word to lowercase
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }

    // Search for the word in the array of WordSentiment structs
    for (int i = 0; i < sizeof(wordSentiments) / sizeof(WordSentiment); i++) {
        if (strcmp(word, wordSentiments[i].word) == 0) {
            return wordSentiments[i].sentiment;
        }
    }

    // If the word is not found, return 0
    return 0;
}

// Get the sentiment of a sentence
int getSentenceSentiment(char *sentence) {
    // Tokenize the sentence into words
    char *words[100];
    int numWords = 0;
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        words[numWords++] = word;
        word = strtok(NULL, " ");
    }

    // Get the sentiment of each word
    int wordSentiments[numWords];
    for (int i = 0; i < numWords; i++) {
        wordSentiments[i] = getWordSentiment(words[i]);
    }

    // Calculate the average sentiment of the sentence
    int totalSentiment = 0;
    for (int i = 0; i < numWords; i++) {
        totalSentiment += wordSentiments[i];
    }
    int averageSentiment = totalSentiment / numWords;

    // Return the average sentiment
    return averageSentiment;
}

// Print the sentiment of a sentence
void printSentenceSentiment(char *sentence) {
    int sentiment = getSentenceSentiment(sentence);

    switch (sentiment) {
        case 0:
            printf("The sentence is terrible.\n");
            break;
        case 1:
            printf("The sentence is bad.\n");
            break;
        case 2:
            printf("The sentence is ok.\n");
            break;
        case 3:
            printf("The sentence is good.\n");
            break;
        case 4:
            printf("The sentence is great.\n");
            break;
        case 5:
            printf("The sentence is amazing.\n");
            break;
    }
}

// Main function
int main() {
    // Get the input sentence from the user
    char sentence[100];
    printf("Enter a sentence: ");
    gets(sentence);

    // Print the sentiment of the sentence
    printSentenceSentiment(sentence);

    return 0;
}