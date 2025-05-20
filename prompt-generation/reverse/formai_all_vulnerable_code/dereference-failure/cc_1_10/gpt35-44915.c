//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

// Function to remove punctuation marks from a given string
void remove_punctuation(char *string) {
    int len = strlen(string);
    for (int i = 0; i < len; i++) {
        if (string[i] == ',' || string[i] == '.' || string[i] == '?' || string[i] == '!') {
            for (int j = i; j < len - 1; j++) {
                string[j] = string[j + 1];
            }
            len--;
            i--;
        }
    }
}

// Function to calculate the sentiment score of a given sentence
int calculate_sentiment_score(char *sentence, char **positive_words, char **negative_words, int num_positive_words, int num_negative_words) {
    int score = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        for (int i = 0; i < num_positive_words; i++) {
            if (strcmp(token, positive_words[i]) == 0) {
                score++;
            }
        }
        for (int i = 0; i < num_negative_words; i++) {
            if (strcmp(token, negative_words[i]) == 0) {
                score--;
            }
        }
        token = strtok(NULL, " ");
    }
    return score;
}

int main() {
    char input_string[MAX_LEN];
    printf("Enter a sentence: ");
    fgets(input_string, MAX_LEN, stdin);

    // Remove punctuation marks from the input string
    remove_punctuation(input_string);

    // Load the positive and negative words from files
    FILE *positive_file = fopen("positive_words.txt", "r");
    FILE *negative_file = fopen("negative_words.txt", "r");
    char **positive_words = malloc(sizeof(char*) * MAX_LEN);
    char **negative_words = malloc(sizeof(char*) * MAX_LEN);
    char line[MAX_LEN];
    int num_positive_words = 0, num_negative_words = 0;
    while (fgets(line, MAX_LEN, positive_file) != NULL) {
        positive_words[num_positive_words] = malloc(sizeof(char) * MAX_LEN);
        strcpy(positive_words[num_positive_words], line);
        num_positive_words++;
    }
    while (fgets(line, MAX_LEN, negative_file) != NULL) {
        negative_words[num_negative_words] = malloc(sizeof(char) * MAX_LEN);
        strcpy(negative_words[num_negative_words], line);
        num_negative_words++;
    }

    // Calculate the sentiment score of the input sentence
    int score = calculate_sentiment_score(input_string, positive_words, negative_words, num_positive_words, num_negative_words);

    // Print the sentiment score
    if (score > 0) {
        printf("The input sentence has a positive sentiment.\n");
    } else if (score < 0) {
        printf("The input sentence has a negative sentiment.\n");
    } else {
        printf("The input sentence has a neutral sentiment.\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < num_positive_words; i++) {
        free(positive_words[i]);
    }
    for (int i = 0; i < num_negative_words; i++) {
        free(negative_words[i]);
    }
    free(positive_words);
    free(negative_words);
    fclose(positive_file);
    fclose(negative_file);

    return 0;
}