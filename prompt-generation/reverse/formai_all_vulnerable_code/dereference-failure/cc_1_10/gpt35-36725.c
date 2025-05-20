//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a character is a punctuation mark
int is_punct(char c) {
    if (c == '.' || c == ',' || c == ';' || c == ':' || c == '-' || c == '?' || c == '!' || c == '\"' || c == '\'' || c == '(' || c == ')') {
        return 1;
    }
    else {
        return 0;
    }
}

// Recursive function to perform sentiment analysis
int analyze_sentiment(char *text, int score) {
    int len = strlen(text);
    if (len == 0) {
        return score;
    }
    else if (text[0] == ' ') {
        return analyze_sentiment(text + 1, score);
    }
    else if (is_punct(text[0])) {
        return analyze_sentiment(text + 1, score);
    }
    else {
        // Extract the first word from the text
        char *word = (char*) malloc(sizeof(char) * (len + 1));
        int i = 0;
        while (!is_punct(text[i]) && text[i] != ' ' && i < len) {
            word[i] = text[i];
            i++;
        }
        word[i] = '\0';

        // Assign a score to the word based on a simple lookup table
        int word_score = 0;
        if (strcmp(word, "good") == 0) {
            word_score = 1;
        }
        else if (strcmp(word, "bad") == 0) {
            word_score = -1;
        }

        // Update the overall score and recursively analyze the remaining text
        score += word_score;
        return analyze_sentiment(text + i, score);
    }
}

int main() {
    char text[1000];
    printf("Enter some text:");
    fgets(text, sizeof(text), stdin);
    int score = analyze_sentiment(text, 0);
    printf("Sentiment score: %d", score);
    return 0;
}