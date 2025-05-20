//FormAI DATASET v1.0 Category: Sentiment analysis tool ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// function to tokenize input string into separate words
char** tokenize(char* str, int* count) {
    char* tok;
    char** tokens = malloc(sizeof(char*) * 100);
    int i = 0;
    tok = strtok(str, " ");
    while (tok != NULL) {
        tokens[i++] = tok;
        tok = strtok(NULL, " ");
    }
    *count = i;
    return tokens;
}

// function to check if input word is positive
int is_positive(char* word) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("positive_words.txt", "r");
    if (fp == NULL) {
        printf("Positive words file not found!\n");
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0; // remove trailing newline character
        if (strcmp(line, word) == 0) {
            fclose(fp);
            if (line) free(line);
            return TRUE;
        }
    }
    fclose(fp);
    if (line) free(line);
    return FALSE;
}

// function to check if input word is negative
int is_negative(char* word) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    fp = fopen("negative_words.txt", "r");
    if (fp == NULL) {
        printf("Negative words file not found!\n");
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, fp)) != -1) {
        line[strcspn(line, "\n")] = 0; // remove trailing newline character
        if (strcmp(line, word) == 0) {
            fclose(fp);
            if (line) free(line);
            return TRUE;
        }
    }
    fclose(fp);
    if (line) free(line);
    return FALSE;
}

int main() {
    char input[1000];
    printf("Enter a sentence: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // remove trailing newline character
    int word_count;
    char** tokens = tokenize(input, &word_count);
    int positive_count = 0;
    int negative_count = 0;
    for (int i = 0; i < word_count; i++) {
        if (is_positive(tokens[i])) {
            positive_count++;
        }
        else if (is_negative(tokens[i])) {
            negative_count++;
        }
    }
    printf("Positive words count: %d\n", positive_count);
    printf("Negative words count: %d\n", negative_count);
    if (positive_count > negative_count) {
        printf("Overall sentiment: Positive\n");
    }
    else if (negative_count > positive_count) {
        printf("Overall sentiment: Negative\n");
    }
    else {
        printf("Overall sentiment: Neutral\n");
    }
    free(tokens);
    return 0;
}