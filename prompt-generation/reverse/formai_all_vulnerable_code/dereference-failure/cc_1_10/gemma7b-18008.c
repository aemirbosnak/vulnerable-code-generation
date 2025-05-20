//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000

typedef struct TextChunk {
    char *text;
    int size;
    struct TextChunk *next;
} TextChunk;

TextChunk *createTextChunk(int size) {
    TextChunk *chunk = malloc(sizeof(TextChunk));
    chunk->text = malloc(size * sizeof(char));
    chunk->size = size;
    chunk->next = NULL;

    return chunk;
}

void addTextChunk(TextChunk *head, char *text, int size) {
    TextChunk *newChunk = createTextChunk(size);
    newChunk->text = text;

    if (head) {
        head->next = newChunk;
    } else {
        head = newChunk;
    }

    head = newChunk;
}

void summarizeText(TextChunk *head) {
    int totalSize = 0;
    TextChunk *current = head;

    while (current) {
        totalSize += current->size;
        current = current->next;
    }

    char *summary = malloc(totalSize * sizeof(char));

    current = head;
    int i = 0;

    while (current) {
        memcpy(summary + i, current->text, current->size);
        i += current->size;
        current = current->next;
    }

    printf("%s", summary);
    free(summary);
}

int main() {
    TextChunk *head = NULL;

    // Add some text chunks
    addTextChunk(head, "This is the first text chunk.", 20);
    addTextChunk(head, "This is the second text chunk.", 10);
    addTextChunk(head, "This is the third text chunk.", 15);

    // Summarize the text
    summarizeText(head);

    return 0;
}