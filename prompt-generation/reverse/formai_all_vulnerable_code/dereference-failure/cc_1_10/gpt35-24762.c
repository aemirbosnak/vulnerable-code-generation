//FormAI DATASET v1.0 Category: Text Summarizer ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUMMARY_SIZE 1000
#define MAX_TEXT_SIZE 10000

char* remove_punctuations(char* text) {
    int len = strlen(text);

    char* result = (char*) malloc(len * sizeof(char));
    int i, j = 0;

    for (i = 0; i < len; i++) {
        if (isalpha(text[i]) || isspace(text[i])) {
            result[j++] = text[i];
        }
    }

    result[j] = '\0';

    return result;
}

void summarize(char* text) {
    char* summary = (char*) malloc(MAX_SUMMARY_SIZE * sizeof(char));
    int summary_index = 0;

    char* token = strtok(text, " ");
    while (token != NULL) {
        int token_len = strlen(token);
        if (summary_index + token_len > MAX_SUMMARY_SIZE) {
            break;
        }

        strncpy(summary + summary_index, token, token_len);
        summary_index += token_len;
        strncpy(summary + summary_index, " ", 1);
        summary_index += 1;

        token = strtok(NULL, " ");
    }

    printf("SUMMARY:\n%s\n", summary);
}

int main() {
    char text[MAX_TEXT_SIZE];
    printf("Enter text to summarize:\n");
    fgets(text, MAX_TEXT_SIZE, stdin);

    char* cleaned_text = remove_punctuations(text);
    summarize(cleaned_text);

    free(cleaned_text);

    return 0;
}