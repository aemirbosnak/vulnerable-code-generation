//FormAI DATASET v1.0 Category: Text Summarizer ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SENTENCES 100
#define MAX_SENTENCE_LENGTH 1000

void get_input(char** text_input) {
    char temp[MAX_SENTENCE_LENGTH];
    int i = 0;
    *text_input = malloc(MAX_SENTENCES * MAX_SENTENCE_LENGTH);

    while (fgets(temp, MAX_SENTENCE_LENGTH, stdin) != NULL) {
        strcat(*text_input, temp);
        if (strlen(*text_input) >= MAX_SENTENCES * MAX_SENTENCE_LENGTH - 1) {
            break;
        }
    }
}

void sentence_tokenize(char* text_input, char** sentence_list, int* num_sentences) {
    char* temp;
    temp = strtok(text_input, ".!?\n");
    int i = 0;

    while (temp != NULL) {
        sentence_list[i] = malloc(strlen(temp) + 2);
        strcpy(sentence_list[i], temp);
        strcat(sentence_list[i], ".");
        i++;
        temp = strtok(NULL, ".!?\n");
    }
    *num_sentences = i;
}

int sentence_similarity(char* sentence1, char* sentence2) {
    int num_common = 0;
    char* word;
    char temp1[MAX_SENTENCE_LENGTH];
    char temp2[MAX_SENTENCE_LENGTH];
    strcpy(temp1, sentence1);
    strcpy(temp2, sentence2);
    word = strtok(temp1, " ,.\n");
    while (word != NULL) {
        if (strstr(temp2, word)) {
            num_common++;
        }
        word = strtok(NULL, " ,.\n");
    }
    if (num_common > 0) {
        return 1;
    } else {
        return 0;
    }
}

void summarize_text(char* text_input, int num_sentences_to_keep) {
    int num_sentences = 0;
    int i, j, k;

    char* sentence_list[MAX_SENTENCES];
    sentence_tokenize(text_input, sentence_list, &num_sentences);

    int similarity_matrix[MAX_SENTENCES][MAX_SENTENCES];

    for (i = 0; i < num_sentences; i++) {
        for (j = 0; j < num_sentences; j++) {
            similarity_matrix[i][j] = sentence_similarity(sentence_list[i], sentence_list[j]);
        }
    }

    int sentence_scores[MAX_SENTENCES];
    for (i = 0; i < num_sentences; i++) {
        sentence_scores[i] = 0;
        for (j = 0; j < num_sentences; j++) {
            if (similarity_matrix[i][j] == 1) {
                sentence_scores[i]++;
            }
        }
    }

    int summary_sentences[num_sentences_to_keep];
    for (i = 0; i < num_sentences_to_keep; i++) {
        int max_score = 0;
        int max_score_index = 0;
        for (j = 0; j < num_sentences; j++) {
            if (sentence_scores[j] > max_score) {
                max_score = sentence_scores[j];
                max_score_index = j;
            }
        }
        summary_sentences[i] = max_score_index;
        sentence_scores[max_score_index] = -1;
    }

    for (i = 0; i < num_sentences_to_keep; i++) {
        printf("%s ", sentence_list[summary_sentences[i]]);
    }

    for (i = 0; i < num_sentences; i++) {
        free(sentence_list[i]);
    }
}

int main() {
    char* text_input;
    printf("Enter the text to summarize: \n");
    get_input(&text_input);
    printf("Enter the number of sentences to include in the summary: ");
    int num_sentences_to_keep = 0;
    scanf("%d", &num_sentences_to_keep);
    printf("Summary: \n");
    summarize_text(text_input, num_sentences_to_keep);
    free(text_input);
    return 0;
}