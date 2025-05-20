//FormAI DATASET v1.0 Category: Text Summarizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100
#define MAX_SUMMARY_LENGTH 50
#define DELIMITERS " \t\r\n"

char* summarize(char* input) {
    char* token;
    char* summary = (char*) malloc(MAX_SUMMARY_LENGTH * sizeof(char));
    int summary_length = 0;
    int token_count = 0;
    int word_count = 0;

    token = strtok(input, DELIMITERS);
    while(token != NULL && word_count < MAX_SUMMARY_LENGTH) {
        if(token_count == 0) {
            strcat(summary, token);
            summary_length += strlen(token);
            word_count++;
        }
        else {
            strcat(summary, " ");
            strcat(summary, token);
            summary_length += 1 + strlen(token);
            word_count++;
        }

        token_count++;
        token = strtok(NULL, DELIMITERS);
    }

    if(token_count > word_count) {
        strcat(summary, "...");
        summary_length += 3;
    }

    if(summary_length > MAX_SUMMARY_LENGTH) {
        summary[MAX_SUMMARY_LENGTH - 3] = '.';
        summary[MAX_SUMMARY_LENGTH - 2] = '.';
        summary[MAX_SUMMARY_LENGTH - 1] = '.';
    }

    return summary;
}

int main() {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    char* summary;
    char* input = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));

    fp = fopen("input.txt", "r");
    if(fp == NULL) {
        printf("File not found.\n");
        return 1;
    }

    while(fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        strcat(input, line);
    }

    summary = summarize(input);
    printf("%s\n", summary);

    free(summary);
    free(input);

    return 0;
}