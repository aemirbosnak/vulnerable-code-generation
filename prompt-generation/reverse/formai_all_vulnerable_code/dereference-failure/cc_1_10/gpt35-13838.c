//FormAI DATASET v1.0 Category: Text Summarizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SENTENCES 1000
#define MAX_SENTENCE_LENGTH 200

// Function to calculate the intersection of words between two sentences
int intersection(char *sentence1, char *sentence2) {
    int count = 0;
    char words[MAX_SENTENCE_LENGTH][MAX_SENTENCE_LENGTH];
    char *token;
    token = strtok(sentence1, " ");
    while (token != NULL) {
        strcpy(words[count], token);
        count++;
        token = strtok(NULL, " ");
    }
    token = strtok(sentence2, " ");
    while (token != NULL) {
        for (int i = 0; i < count; i++) {
            if (strcmp(token, words[i]) == 0) {
                return 1;
            }
        }
        token = strtok(NULL, " ");
    }
    return 0;
}

// Function to rank the sentences based on their importance
void rank_sentences(char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH], int *rankings, int num_sentences) {
    for (int i = 0; i < num_sentences; i++) {
        int rank = 0;
        for (int j = 0; j < num_sentences; j++) {
            if (i != j && intersection(sentences[i], sentences[j])) {
                rank++;
            }
        }
        rankings[i] = rank;
    }
}

// Function to print the summary
void print_summary(char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH], int num_sentences, int *rankings) {
    int summary_length = num_sentences / 3;
    if (summary_length == 0) {
        summary_length = 1;
    }
    printf("\nSummary:\n");
    for (int i = 0; i < summary_length; i++) {
        int max_rank = 0;
        int max_index = 0;
        for (int j = 0; j < num_sentences; j++) {
            if (rankings[j] > max_rank) {
                max_rank = rankings[j];
                max_index = j;
            }
        }
        printf("%s\n", sentences[max_index]);
        rankings[max_index] = -1;
    }
}

int main() {
    // Get input text
    char input_text[MAX_SENTENCES * MAX_SENTENCE_LENGTH];
    printf("Enter the text:\n");
    fgets(input_text, sizeof(input_text), stdin);
    
    // Split text into sentences
    char sentences[MAX_SENTENCES][MAX_SENTENCE_LENGTH];
    char *token;
    int sentence_count = 0;
    token = strtok(input_text, ".!?"); 
    while (token != NULL) {
        strcpy(sentences[sentence_count], token);
        sentence_count++;
        token = strtok(NULL, ".!?");
    }

    // Rank sentences
    int rankings[sentence_count];
    rank_sentences(sentences, rankings, sentence_count);

    // Print summary
    print_summary(sentences, sentence_count, rankings);

    return 0;
}