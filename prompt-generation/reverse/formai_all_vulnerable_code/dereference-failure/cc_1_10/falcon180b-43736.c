//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCE_LENGTH 1024
#define MAX_WORD_LENGTH 64

// Function to remove punctuation from a string
void remove_punctuation(char* str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i]) &&!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to tokenize a sentence into words
int tokenize_sentence(char* sentence, char** tokens) {
    int num_tokens = 0;
    char* token = strtok(sentence, " ");
    while (token!= NULL) {
        tokens[num_tokens] = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(tokens[num_tokens], token);
        num_tokens++;
        token = strtok(NULL, " ");
    }
    return num_tokens;
}

// Function to calculate the sentiment score of a sentence
float calculate_sentiment_score(char** tokens, int num_tokens) {
    float score = 0.0;
    int i;
    for (i = 0; i < num_tokens; i++) {
        char* word = tokens[i];
        if (strcmp(word, "happy") == 0) {
            score += 1.0;
        } else if (strcmp(word, "sad") == 0) {
            score -= 1.0;
        }
    }
    return score;
}

int main() {
    char input_sentence[MAX_SENTENCE_LENGTH];
    printf("Enter a sentence: ");
    fgets(input_sentence, MAX_SENTENCE_LENGTH, stdin);

    // Remove punctuation and convert to lowercase
    remove_punctuation(input_sentence);

    // Tokenize the sentence into words
    char* tokens[MAX_WORD_LENGTH];
    int num_tokens = tokenize_sentence(input_sentence, tokens);

    // Calculate the sentiment score of the sentence
    float sentiment_score = calculate_sentiment_score(tokens, num_tokens);

    // Print the result
    if (sentiment_score > 0.0) {
        printf("The sentence is positive.\n");
    } else if (sentiment_score < 0.0) {
        printf("The sentence is negative.\n");
    } else {
        printf("The sentence is neutral.\n");
    }

    return 0;
}