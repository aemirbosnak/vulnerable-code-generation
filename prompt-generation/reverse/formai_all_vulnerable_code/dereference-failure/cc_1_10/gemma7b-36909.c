//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextSummary {
    char **buffer;
    int size;
    int allocatedSize;
} TextSummary;

TextSummary* textSummary_create() {
    TextSummary* summary = malloc(sizeof(TextSummary));
    summary->buffer = NULL;
    summary->size = 0;
    summary->allocatedSize = 0;
    return summary;
}

void textSummary_destroy(TextSummary* summary) {
    free(summary->buffer);
    free(summary);
}

void textSummary_add(TextSummary* summary, char* text) {
    int textLength = strlen(text);
    if (summary->size + textLength >= summary->allocatedSize) {
        summary->allocatedSize = summary->size * 2;
        summary->buffer = realloc(summary->buffer, summary->allocatedSize * MAX_BUFFER_SIZE);
    }
    summary->buffer = realloc(summary->buffer, (summary->size + textLength) * MAX_BUFFER_SIZE);
    memcpy(summary->buffer + summary->size, text, textLength);
    summary->size += textLength;
}

char* textSummary_get(TextSummary* summary) {
    return summary->buffer;
}

int main() {
    TextSummary* summary = textSummary_create();
    char* text = "This is a sample text that will be summarized.";
    textSummary_add(summary, text);
    text = "This is another sample text that will be appended to the previous text.";
    textSummary_add(summary, text);
    text = textSummary_get(summary);
    printf("%s", text);
    textSummary_destroy(summary);
    return 0;
}