//GEMINI-pro DATASET v1.0 Category: Sentiment analysis tool ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Helper function to tokenize the input sentence
char **tokenize(char *sentence) {
    char **tokens = malloc(sizeof(char *) * 100);
    int token_count = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        tokens[token_count] = token;
        token_count++;
        token = strtok(NULL, " ");
    }
    tokens[token_count] = NULL;
    return tokens;
}

// Helper function to calculate the sentiment score of a word
int get_sentiment_score(char *word) {
    // Open the sentiment lexicon file
    FILE *lexicon = fopen("sentiment-lexicon.txt", "r");
    if (lexicon == NULL) {
        printf("Error: Unable to open sentiment lexicon file.\n");
        exit(1);
    }

    // Read the lexicon and store the words and their sentiment scores in a hash table
    char line[1024];
    char *word_entry;
    int score;
    while (fgets(line, sizeof(line), lexicon) != NULL) {
        word_entry = strtok(line, "\t");
        if (strcmp(word_entry, word) == 0) {
            score = atoi(strtok(NULL, "\t"));
            break;
        }
    }

    // Close the lexicon file
    fclose(lexicon);

    // Return the sentiment score if the word is found in the lexicon, otherwise return 0
    return score;
}

// Main function to perform sentiment analysis on the input sentence
int main() {
    // Get the input sentence from the user
    char sentence[1024];
    printf("Enter the sentence you want to analyze: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize the sentence into individual words
    char **tokens = tokenize(sentence);

    // Calculate the sentiment score of each word and sum them up
    int sentiment_score = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        sentiment_score += get_sentiment_score(tokens[i]);
    }

    // Print the sentiment score
    printf("The sentiment score of the sentence is: %d\n", sentiment_score);

    // Free the memory allocated for the tokens
    free(tokens);

    return 0;
}