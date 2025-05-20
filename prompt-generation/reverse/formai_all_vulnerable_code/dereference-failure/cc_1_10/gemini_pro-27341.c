//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_LEN 100

typedef struct {
    char *word;
    int sentiment;
} Word;

int compareWords(const void *a, const void *b) {
    return strcmp(((Word *)a)->word, ((Word *)b)->word);
}

int main() {
    // Load the sentiment lexicon
    FILE *lexicon = fopen("sentiment-lexicon.txt", "r");
    if (lexicon == NULL) {
        perror("Error opening sentiment lexicon");
        return EXIT_FAILURE;
    }

    // Create an array to store the words and their sentiments
    Word words[MAX_WORDS];
    int numWords = 0;

    // Read the words and sentiments from the lexicon
    char line[MAX_LEN];
    while (fgets(line, MAX_LEN, lexicon) != NULL) {
        char *word = strtok(line, "\t");
        char *sentiment = strtok(NULL, "\n");

        words[numWords].word = strdup(word);
        words[numWords].sentiment = atoi(sentiment);

        numWords++;
    }

    fclose(lexicon);

    // Sort the words alphabetically
    qsort(words, numWords, sizeof(Word), compareWords);

    // Get the input text
    char text[MAX_LEN];
    printf("Enter the text to analyze: ");
    fgets(text, MAX_LEN, stdin);

    // Tokenize the text
    char *tokens[MAX_WORDS];
    int numTokens = 0;

    char *token = strtok(text, " ");
    while (token != NULL) {
        tokens[numTokens] = strdup(token);

        numTokens++;

        token = strtok(NULL, " ");
    }

    // Calculate the sentiment of the text
    int sentiment = 0;
    for (int i = 0; i < numTokens; i++) {
        // Find the word in the lexicon
        int index = bsearch(tokens[i], words, numWords, sizeof(Word), compareWords);

        // If the word is in the lexicon, add its sentiment to the total sentiment
        if (index != -1) {
            sentiment += words[index].sentiment;
        }
    }

    // Print the sentiment of the text
    if (sentiment > 0) {
        printf("The text is positive.\n");
    } else if (sentiment < 0) {
        printf("The text is negative.\n");
    } else {
        printf("The text is neutral.\n");
    }

    // Free the memory allocated for the words and tokens
    for (int i = 0; i < numWords; i++) {
        free(words[i].word);
    }
    for (int i = 0; i < numTokens; i++) {
        free(tokens[i]);
    }

    return EXIT_SUCCESS;
}