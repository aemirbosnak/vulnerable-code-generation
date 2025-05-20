//Falcon-180B DATASET v1.0 Category: Sentiment analysis tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

// Function to tokenize the input string into words
void tokenize(char *input, char **words) {
    int i, j, k = 0;
    char *token;

    for (i = 0; input[i]!= '\0'; i++) {
        if (isspace(input[i])) {
            input[i] = '\0';
        }
    }

    token = strtok(input, " ");
    while (token!= NULL) {
        if (k >= MAX_WORDS) {
            break;
        }
        words[k] = malloc(MAX_WORD_LENGTH * sizeof(char));
        strcpy(words[k], token);
        k++;
        token = strtok(NULL, " ");
    }
}

// Function to calculate the sentiment score of the input text
float calculate_sentiment_score(char **words) {
    int i;
    float score = 0.0;

    for (i = 0; i < MAX_WORDS && words[i]!= NULL; i++) {
        if (strcmp(words[i], "happy") == 0) {
            score += 1.0;
        } else if (strcmp(words[i], "sad") == 0) {
            score -= 1.0;
        }
    }

    return score;
}

// Function to print the sentiment analysis result
void print_result(float score) {
    if (score > 0.0) {
        printf("The sentiment of the input text is positive.\n");
    } else if (score < 0.0) {
        printf("The sentiment of the input text is negative.\n");
    } else {
        printf("The sentiment of the input text is neutral.\n");
    }
}

int main() {
    char input[1000];
    char **words;
    float score;
    time_t start_time, end_time;

    printf("Enter the input text: ");
    fgets(input, sizeof(input), stdin);

    words = malloc(MAX_WORDS * sizeof(char*));
    tokenize(input, words);

    start_time = clock();
    score = calculate_sentiment_score(words);
    end_time = clock();

    printf("The sentiment analysis took %ld seconds.\n", end_time - start_time);
    print_result(score);

    return 0;
}