//FormAI DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000000
#define SUMMARIZE_SIZE 10

char* read_text_file(char* filename) {
    FILE* fp;
    char* buffer;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("File not found");
        exit(EXIT_FAILURE);
    }

    buffer = (char*) malloc(sizeof(char) * MAX_SIZE);
    if (buffer == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    fread(buffer, MAX_SIZE, 1, fp);
    fclose(fp);

    return buffer;
}

char** split_text_to_sentences(char* text, int* num_sentences) {
    int i, j, k;
    char** sentences;

    sentences = (char**) malloc(sizeof(char*) * MAX_SIZE);
    if (sentences == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    i = 0;
    *num_sentences = 0;

    while (text[i] != '\0') {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences[*num_sentences] = (char*) malloc(sizeof(char) * MAX_SIZE);
            if (sentences[*num_sentences] == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
            for (j = k; j <= i; j++) {
                sentences[*num_sentences][j - k] = text[j];
            }
            sentences[*num_sentences][j - k] = '\0';
            (*num_sentences)++;
            k = i + 1;
        }
        i++;
    }

    return sentences;
}

char* trim_whitespace(char* str) {
    int i, j;
    char* trimmed_str;

    trimmed_str = (char*) malloc(sizeof(char) * MAX_SIZE);
    if (trimmed_str == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    i = 0;
    j = strlen(str) - 1;

    while (isspace(str[i])) {
        i++;
    }
    while (isspace(str[j])) {
        j--;
    }

    for (int k = i; k <= j; k++) {
        trimmed_str[k - i] = str[k];
    }
    trimmed_str[j - i + 1] = '\0';

    return trimmed_str;
}

void summarize_text(char* filename) {
    char* text = read_text_file(filename);
    int num_sentences;
    char** sentences = split_text_to_sentences(text, &num_sentences);
    char** trimmed_sentences = (char**) malloc(sizeof(char*) * num_sentences);
    int* sentence_lengths = (int*) malloc(sizeof(int) * num_sentences);

    for (int i = 0; i < num_sentences; i++) {
        trimmed_sentences[i] = trim_whitespace(sentences[i]);
        sentence_lengths[i] = strlen(trimmed_sentences[i]);
    }

    for (int i = 0; i < SUMMARIZE_SIZE; i++) {
        int max_index = 0;
        int max_length = 0;
        for (int j = 0; j < num_sentences; j++) {
            if (sentence_lengths[j] > max_length) {
                max_index = j;
                max_length = sentence_lengths[j];
            }
        }
        printf("%s\n", sentences[max_index]);
        sentence_lengths[max_index] = 0;
    }

    free(text);
    for (int i = 0; i < num_sentences; i++) {
        free(sentences[i]);
        free(trimmed_sentences[i]);
    }
    free(sentences);
    free(trimmed_sentences);
    free(sentence_lengths);
}

int main() {
    summarize_text("example.txt");
    return 0;
}