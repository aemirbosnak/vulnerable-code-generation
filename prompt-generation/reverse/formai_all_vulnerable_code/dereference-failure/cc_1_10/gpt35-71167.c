//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A function to convert the input string to lowercase.
char* toLowerCase(char* input) {
    char* result = malloc(sizeof(char) * strlen(input));
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            result[i] = input[i] + 32;
        } else {
            result[i] = input[i];
        }
    }
    return result;
}

// A function to determine if a word is positive, negative, or neutral.
char* sentimentAnalysis(char* word) {
    char* positive[] = {"good", "great", "excellent"};
    char* negative[] = {"bad", "terrible", "horrible"};
    int positiveCount = 3, negativeCount = 3;

    // Convert word to lowercase for easier comparison.
    char* wordLowercase = toLowerCase(word);

    // Check if the word is in the positive list.
    for (int i = 0; i < positiveCount; i++) {
        if (strcmp(wordLowercase, positive[i]) == 0) {
            return "positive";
        }
    }

    // Check if the word is in the negative list.
    for (int i = 0; i < negativeCount; i++) {
        if (strcmp(wordLowercase, negative[i]) == 0) {
            return "negative";
        }
    }

    // If the word is not positive or negative, then it must be neutral.
    return "neutral";
}

int main() {
    char input[1000], *word;
    printf("Enter a sentence to analyze: ");
    fgets(input, sizeof(input), stdin);

    // Tokenize the input into words.
    word = strtok(input, " \n");

    while (word != NULL) {
        printf("%s: %s\n", word, sentimentAnalysis(word));
        word = strtok(NULL, " \n");
    }

    return 0;
}