//GEMINI-pro DATASET v1.0 Category: Spam Detection System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LEN 100

// Array of spam words
const char *spamWords[] = {
    "free", "money", "win", "click", "offer", "guarantee", "amazing", "urgent", "limited time", "act now"
};

// Array of stop words
const char *stopWords[] = {
    "a", "an", "the", "and", "or", "but", "for", "to", "of", "in"
};

// Function to check if a word is a spam word
int isSpamWord(const char *word) {
    for (int i = 0; i < sizeof(spamWords) / sizeof(spamWords[0]); i++) {
        if (strcmp(word, spamWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if a word is a stop word
int isStopWord(const char *word) {
    for (int i = 0; i < sizeof(stopWords) / sizeof(stopWords[0]); i++) {
        if (strcmp(word, stopWords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to remove punctuation from a string
void removePunctuation(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (ispunct(str[i])) {
            str[i] = ' ';
        }
    }
}

// Function to tokenize a string into words
char **tokenize(const char *str, int *numTokens) {
    char **tokens = malloc(MAX_WORDS * sizeof(char *));
    char *token = strtok(str, " ");
    int i = 0;
    while (token != NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, " ");
    }
    *numTokens = i;
    return tokens;
}

// Function to classify a message as spam or not
int classifyMessage(const char *message) {
    // Convert message to lowercase
    char *msg = strdup(message);
    for (int i = 0; msg[i] != '\0'; i++) {
        msg[i] = tolower(msg[i]);
    }

    // Remove punctuation from message
    removePunctuation(msg);

    // Tokenize message
    int numTokens;
    char **tokens = tokenize(msg, &numTokens);

    // Count number of spam words in message
    int numSpamWords = 0;
    for (int i = 0; i < numTokens; i++) {
        if (isSpamWord(tokens[i]) && !isStopWord(tokens[i])) {
            numSpamWords++;
        }
    }

    // Free allocated memory
    free(tokens);
    free(msg);

    // Return classification
    if (numSpamWords > 0) {
        return 1;  // Spam
    } else {
        return 0;  // Not spam
    }
}

int main() {
    // Get the message from the user
    char message[MAX_LEN];
    printf("Enter a message: ");
    fgets(message, MAX_LEN, stdin);

    // Classify the message
    int classification = classifyMessage(message);

    // Print the classification
    if (classification == 1) {
        printf("The message is spam.\n");
    } else {
        printf("The message is not spam.\n");
    }

    return 0;
}