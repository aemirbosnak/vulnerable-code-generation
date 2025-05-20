//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextSummary {
    char **buffer;
    int size;
    int capacity;
} TextSummary;

TextSummary *createTextSummary(int capacity) {
    TextSummary *summary = malloc(sizeof(TextSummary));
    summary->buffer = malloc(sizeof(char *) * capacity);
    summary->size = 0;
    summary->capacity = capacity;
    return summary;
}

void addTextToSummary(TextSummary *summary, char *text) {
    if (summary->size >= summary->capacity) {
        summary->buffer = realloc(summary->buffer, sizeof(char *) * summary->capacity * 2);
        summary->capacity *= 2;
    }

    summary->buffer[summary->size++] = text;
}

void printTextSummary(TextSummary *summary) {
    for (int i = 0; i < summary->size; i++) {
        printf("%s\n", summary->buffer[i]);
    }
}

int main() {
    TextSummary *summary = createTextSummary(MAX_BUFFER_SIZE);

    char *text1 = "This is the first text to be added to the summary.";
    addTextToSummary(summary, text1);

    char *text2 = "This is the second text to be added to the summary.";
    addTextToSummary(summary, text2);

    printTextSummary(summary);

    free(summary->buffer);
    free(summary);

    return 0;
}