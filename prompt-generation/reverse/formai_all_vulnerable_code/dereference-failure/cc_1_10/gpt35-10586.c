//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum number of characters in the input text
#define MAX_INPUT_SIZE 1024

// define the maximum number of words in the positive and negative word lists
#define MAX_WORD_SIZE 50
#define MAX_WORD_COUNT 10

// define the paths to the positive and negative word lists
#define POSITIVE_WORDS_FILE "positive_words.txt"
#define NEGATIVE_WORDS_FILE "negative_words.txt"

// function to check if a word is in the positive or negative word lists
int is_word_in_list(char *word, char **list, int list_length) {
    for (int i = 0; i < list_length; i++) {
        if (strcmp(word, list[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// function to calculate the sentiment score of the input text
float calculate_sentiment_score(char *input_text) {
    // read in the positive word list
    FILE *positive_file = fopen(POSITIVE_WORDS_FILE, "r");
    if (!positive_file) {
        printf("Error: Could not open %s\n", POSITIVE_WORDS_FILE);
        exit(1);
    }
    char **positive_words = (char**) malloc(MAX_WORD_COUNT * sizeof(char*));
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        positive_words[i] = (char*) malloc(MAX_WORD_SIZE * sizeof(char));
        if (!fgets(positive_words[i], MAX_WORD_SIZE, positive_file)) {
            break;
        }
        positive_words[i][strlen(positive_words[i])-1] = '\0'; // remove newline character
    }
    fclose(positive_file);

    // read in the negative word list
    FILE *negative_file = fopen(NEGATIVE_WORDS_FILE, "r");
    if (!negative_file) {
        printf("Error: Could not open %s\n", NEGATIVE_WORDS_FILE);
        exit(1);
    }
    char **negative_words = (char**) malloc(MAX_WORD_COUNT * sizeof(char*));
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        negative_words[i] = (char*) malloc(MAX_WORD_SIZE * sizeof(char));
        if (!fgets(negative_words[i], MAX_WORD_SIZE, negative_file)) {
            break;
        }
        negative_words[i][strlen(negative_words[i])-1] = '\0'; // remove newline character
    }
    fclose(negative_file);

    // tokenize the input text by spaces and punctuation
    char *token = strtok(input_text, " .,;:-?!'");
    int positive_count = 0;
    int negative_count = 0;
    while (token != NULL) {
        if (is_word_in_list(token, positive_words, MAX_WORD_COUNT)) {
            positive_count++;
        }
        if (is_word_in_list(token, negative_words, MAX_WORD_COUNT)) {
            negative_count++;
        }
        token = strtok(NULL, " .,;:-?!'");
    }

    // calculate the sentiment score based on the number of positive and negative words
    float sentiment_score = (float) (positive_count - negative_count) / (float) (positive_count + negative_count);
    
    // free memory
    for (int i = 0; i < MAX_WORD_COUNT; i++) {
        free(positive_words[i]);
        free(negative_words[i]);
    }
    free(positive_words);
    free(negative_words);

    return sentiment_score;
}

// main function to get input from the user and calculate the sentiment score
int main() {
    char input_text[MAX_INPUT_SIZE];
    printf("Enter a sentence or phrase to analyze:\n");
    fgets(input_text, MAX_INPUT_SIZE, stdin);
    float sentiment = calculate_sentiment_score(input_text);
    printf("Sentiment score: %.2f\n", sentiment);
    return 0;
}