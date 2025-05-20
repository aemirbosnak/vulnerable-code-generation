//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_LENGTH 10000
#define MAX_SENTENCE_LENGTH 200
#define MAX_SUMMARY_LENGTH 500

void summarize(char *input, char *summary) {
    // initialize variables
    char sentences[MAX_INPUT_LENGTH][MAX_SENTENCE_LENGTH];
    int num_sentences = 0;
    int sentence_scores[MAX_INPUT_LENGTH];
    int total_score = 0;

    // loop through input and split into sentences
    char *token = strtok(input, ".");
    while (token != NULL) {
        strcpy(sentences[num_sentences], token);
        num_sentences++;
        token = strtok(NULL, ".");
    }

    // loop through sentences and calculate scores
    for (int i = 0; i < num_sentences; i++) {
        int sentence_score = 0;

        // calculate length score
        int length = strlen(sentences[i]);
        if (length < 10) {
            sentence_score += 2;
        } else if (length < 20) {
            sentence_score += 1;
        }

        // calculate word score
        char *word_token = strtok(sentences[i], " ");
        while (word_token != NULL) {
            // ignore small words like "a" or "the"
            if (strlen(word_token) > 2) {
                sentence_score++;
            }
            word_token = strtok(NULL, " ");
        }

        // store sentence score
        sentence_scores[i] = sentence_score;
        total_score += sentence_score;
    }

    // calculate average score and threshold for summary
    int average_score = total_score / num_sentences;
    int summary_threshold = average_score + 1;

    // loop through sentences again and add high-scoring ones to summary
    int summary_length = 0;
    for (int i = 0; i < num_sentences; i++) {
        if (sentence_scores[i] >= summary_threshold) {
            strcat(summary, sentences[i]);
            strcat(summary, ".");
            summary_length += strlen(sentences[i]);
            if (summary_length >= MAX_SUMMARY_LENGTH) break;
        }
    }
}

int main() {
    char input[MAX_INPUT_LENGTH];
    char summary[MAX_SUMMARY_LENGTH] = "";

    // read input from user
    printf("Please input text to be summarized:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0;

    // summarize input
    summarize(input, summary);

    // print summary
    printf("\nText summary:\n%s\n", summary);

    return 0;
}