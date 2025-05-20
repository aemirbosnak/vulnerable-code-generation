//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: Linus Torvalds
/* Linus Torvalds style Sentiment analysis tool */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_WORD_SIZE 50

/* Function prototypes */
void calculate_sentiment(char *input_str);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("Error: No input string provided.\n");
        return 0;
    }

    char *input_str = argv[1];

    calculate_sentiment(input_str);

    return 0;
}

void calculate_sentiment(char *input_str) {
    char words[MAX_INPUT_SIZE][MAX_WORD_SIZE], temp[MAX_WORD_SIZE];
    int frequency[MAX_INPUT_SIZE], total_words = 0, i = 0, j = 0;
    char ch;

    /* Remove punctuation from input string */
    for (int i = 0; i < strlen(input_str); i++) {
        ch = input_str[i];
        if (ispunct(ch)) {
            input_str[i] = ' ';
        }
    }

    /* Tokenize the input string */
    char *token = strtok(input_str, " ");
    while (token != NULL) {
        strcpy(words[i], token);
        frequency[i] = 1;
        total_words++;
        i++;

        token = strtok(NULL, " ");
    }

    /* Calculate the frequency of each word */
    for (int i = 0; i < total_words - 1; i++) {
        strcpy(temp, words[i]);
        for (int j = i + 1; j < total_words; j++) {
            if (strcmp(temp, words[j]) == 0) {
                frequency[i]++;
                frequency[j] = -1;
            }
        }
    }

    /* Print the sentiment analysis */
    printf("Sentiment analysis:\n");
    printf("-------------------\n");

    for (int i = 0; i < total_words; i++) {
        if (frequency[i] != -1) {
            printf("%s\t%d\n", words[i], frequency[i]);
        }
    }
}