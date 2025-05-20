//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove punctuations from a string
void removePunctuations(char* str) {
    int i = 0;
    int j = 0;
    while (str[i]!= '\0') {
        if (!isalnum(str[i])) {
            i++;
        } else {
            str[j] = tolower(str[i]);
            j++;
            i++;
        }
    }
    str[j] = '\0';
}

// Function to tokenize a string
void tokenize(char* str, char** tokens) {
    int count = 0;
    char* token = strtok(str, " ");
    while (token!= NULL) {
        tokens[count] = token;
        count++;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the sentiment score of a sentence
int calculateSentimentScore(char** tokens) {
    int count = 0;
    int positiveCount = 0;
    int negativeCount = 0;
    while (tokens[count]!= NULL) {
        if (strcmp(tokens[count], "happy") == 0 || strcmp(tokens[count], "love") == 0 || strcmp(tokens[count], "like") == 0) {
            positiveCount++;
        } else if (strcmp(tokens[count], "sad") == 0 || strcmp(tokens[count], "hate") == 0 || strcmp(tokens[count], "dislike") == 0) {
            negativeCount++;
        }
        count++;
    }
    if (positiveCount > negativeCount) {
        return 1;
    } else if (positiveCount < negativeCount) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the sentiment analysis result
void printResult(int score) {
    if (score == 1) {
        printf("The sentence is positive.\n");
    } else if (score == -1) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }
}

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, 1000, stdin);

    // Remove punctuations
    removePunctuations(input);

    // Tokenize the sentence
    char* tokens[100];
    tokenize(input, tokens);

    // Calculate the sentiment score
    int score = calculateSentimentScore(tokens);

    // Print the result
    printResult(score);

    return 0;
}