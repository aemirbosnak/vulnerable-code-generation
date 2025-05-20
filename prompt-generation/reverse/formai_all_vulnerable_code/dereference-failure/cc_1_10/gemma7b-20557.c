//Gemma-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000

char **get_words(char *text) {
    char **words = NULL;
    int i = 0;
    int num_words = 0;

    // Tokenize the text into words
    char *token = strtok(text, " ");

    // Allocate memory for the words array
    words = malloc(MAX_WORDS * sizeof(char *));

    // Loop over the tokens and add them to the array
    while (token) {
        words[num_words++] = strdup(token);
        token = strtok(NULL, " ");
    }

    // Return the words array
    return words;
}

int sentiment_analysis(char **words) {
    int i = 0;
    int sentiment = 0;

    // Loop over the words and analyze their sentiment
    for (i = 0; words[i] != NULL; i++) {
        // Check if the word is positive or negative
        if (words[i][0] == 'p') {
            sentiment++;
        } else if (words[i][0] == 'n') {
            sentiment--;
        }
    }

    // Return the sentiment score
    return sentiment;
}

int main() {
    char *text = "I am happy today.";
    char **words = get_words(text);
    int sentiment = sentiment_analysis(words);

    // Print the sentiment score
    printf("The sentiment score is: %d\n", sentiment);

    // Free the memory allocated for the words array
    free(words);

    return 0;
}