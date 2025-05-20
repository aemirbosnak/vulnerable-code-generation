//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to convert string to lowercase
char* toLowerCase(char* str) {
    int len = strlen(str);
    char* res = (char*)malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        res[i] = tolower(str[i]);
    }
    return res;
}

// Function to check if a word is positive, negative or neutral
int checkWord(char* word) {
    char posWords[][20] = {"good", "great", "excellent", "nice", "wonderful", "fantastic", "lovely"};
    char negWords[][20] = {"bad", "awful", "horrible", "terrible", "disgusting", "ugly", "poor"};
    int nPos = sizeof(posWords)/sizeof(posWords[0]);
    int nNeg = sizeof(negWords)/sizeof(negWords[0]);

    for (int i = 0; i < nPos; i++) {
        if (strcmp(word, posWords[i]) == 0) {
            return 1; // positive word
        }
    }
    for (int i = 0; i < nNeg; i++) {
        if (strcmp(word, negWords[i]) == 0) {
            return -1; // negative word
        }
    }
    return 0; // neutral word
}

// Function to get sentiment score of a sentence
int getSentimentScore(char* sentence) {
    char* lowerS = toLowerCase(sentence);
    char* token;
    int score = 0;
    token = strtok(lowerS, " .,!?");
    while (token != NULL) {
        if (checkWord(token) == 1) {
            score++;
        } else if (checkWord(token) == -1) {
            score--;
        }
        token = strtok(NULL, " .,!?");
    }
    free(lowerS);
    return score;
}

// Main program
int main() {
    char sent[1000];
    printf("Enter a sentence: ");
    fgets(sent, 1000, stdin);
    int score = getSentimentScore(sent);
    if (score > 0) {
        printf("Positive sentiment. Score: %d\n", score);
    } else if (score < 0) {
        printf("Negative sentiment. Score: %d\n", score);
    } else {
        printf("Neutral sentiment\n");
    }
    return 0;
}