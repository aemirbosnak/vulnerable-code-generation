//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

typedef struct TextChunk {
    char *buffer;
    int size;
    struct TextChunk *next;
} TextChunk;

TextChunk *createTextChunk(int size) {
    TextChunk *chunk = malloc(sizeof(TextChunk));
    chunk->buffer = malloc(size);
    chunk->size = size;
    chunk->next = NULL;
    return chunk;
}

void addTextChunk(TextChunk *head, char *text, int textSize) {
    TextChunk *newChunk = createTextChunk(textSize);
    memcpy(newChunk->buffer, text, textSize);
    newChunk->size = textSize;
    if (head) {
        head->next = newChunk;
    } else {
        head = newChunk;
    }
}

void summarizeText(TextChunk *head) {
    int totalSize = 0;
    TextChunk *current = head;
    while (current) {
        totalSize += current->size;
        current = current->next;
    }

    char *summary = malloc(totalSize);
    current = head;
    int i = 0;
    while (current) {
        memcpy(summary + i, current->buffer, current->size);
        i += current->size;
        current = current->next;
    }

    printf("%s", summary);
    free(summary);
}

int main() {
    TextChunk *head = NULL;
    char text[] = "This is a sample text that will be summarized.";
    addTextChunk(head, text, strlen(text));

    char text2[] = "This is another sample text that will be appended to the first text.";
    addTextChunk(head, text2, strlen(text2));

    summarizeText(head);

    return 0;
}