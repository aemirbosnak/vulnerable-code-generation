//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextSummarizer {
    char** buffer;
    int capacity;
    int used;
    int currentPos;
    char* summary;
    int summarySize;
} TextSummarizer;

TextSummarizer* textSummarizer_init(int capacity) {
    TextSummarizer* summarizer = malloc(sizeof(TextSummarizer));
    summarizer->buffer = NULL;
    summarizer->capacity = capacity;
    summarizer->used = 0;
    summarizer->currentPos = 0;
    summarizer->summary = NULL;
    summarizer->summarySize = 0;

    return summarizer;
}

void textSummarizer_add(TextSummarizer* summarizer, char* text) {
    int textLen = strlen(text);
    if (summarizer->used + textLen >= summarizer->capacity) {
        summarizer->buffer = realloc(summarizer->buffer, (summarizer->capacity * 2) * sizeof(char*));
        summarizer->capacity *= 2;
    }

    summarizer->buffer[summarizer->currentPos] = malloc(textLen + 1);
    strcpy(summarizer->buffer[summarizer->currentPos], text);
    summarizer->currentPos++;
    summarizer->used += textLen + 1;
}

void textSummarizer_summarize(TextSummarizer* summarizer) {
    char* summary = malloc(summarizer->summarySize);
    int i = 0;
    for (i = 0; i < summarizer->used; i++) {
        char* text = summarizer->buffer[i];
        int textLen = strlen(text);
        summary = realloc(summary, summarizer->summarySize + textLen + 1);
        strcat(summary, text);
        summarizer->summarySize += textLen + 1;
    }

    free(summarizer->summary);
    summarizer->summary = summary;
}

int main() {
    TextSummarizer* summarizer = textSummarizer_init(MAX_BUFFER_SIZE);
    textSummarizer_add(summarizer, "This is a sample text.");
    textSummarizer_add(summarizer, "It is a long text.");
    textSummarizer_add(summarizer, "It has many words.");

    textSummarizer_summarize(summarizer);

    printf("%s\n", summarizer->summary);

    free(summarizer);

    return 0;
}