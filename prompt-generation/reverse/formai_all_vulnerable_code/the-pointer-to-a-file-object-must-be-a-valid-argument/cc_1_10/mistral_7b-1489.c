//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: grateful
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_LENGTH 50

typedef struct {
    char word[MAX_LENGTH];
    int score;
} Word;

Word words[MAX_WORDS];
int num_words = 0;

void init_scores() {
    FILE *file = fopen("sentiment.txt", "r");
    char line[MAX_LENGTH];
    char *token;
    int i = 0;

    while (fgets(line, MAX_LENGTH, file) != NULL) {
        token = strtok(line, " \t\n");
        while (token != NULL) {
            strcpy(words[i].word, token);
            sscanf(strtok(NULL, ":"), "%d", &words[i].score);
            i++;
            num_words++;
        }
    }

    fclose(file);
}

int main() {
    char input[1000];
    int total_score = 0;
    int num_words_in_text = 0;

    init_scores();

    printf("Enter text for sentiment analysis: ");
    fgets(input, 1000, stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " .,!?:;()");

    while (token != NULL) {
        int i;

        for (i = 0; i < num_words; i++) {
            if (strcmp(token, words[i].word) == 0) {
                total_score += words[i].score;
                num_words_in_text++;
                break;
            }
        }

        if (i == num_words) {
            // Unknown word, assume neutral score
            total_score += 0;
        }

        token = strtok(NULL, " .,!?:;()");
    }

    float avg_score = (float) total_score / num_words_in_text;

    if (avg_score > 0) {
        printf("Positive sentiment.\n");
    } else if (avg_score < 0) {
        printf("Negative sentiment.\n");
    } else {
        printf("Neutral sentiment.\n");
    }

    printf("Total score: %d\n", total_score);
    printf("Average score: %.2f\n", avg_score);

    return 0;
}