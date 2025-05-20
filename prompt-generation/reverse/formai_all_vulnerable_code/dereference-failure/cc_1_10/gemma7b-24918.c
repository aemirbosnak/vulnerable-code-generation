//Gemma-7B DATASET v1.0 Category: Text Summarizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct TextChunk {
    char *text;
    int length;
    struct TextChunk *next;
} TextChunk;

TextChunk *createTextChunk(int length, char *text) {
    TextChunk *newChunk = malloc(sizeof(TextChunk));
    newChunk->text = malloc(length * sizeof(char));
    newChunk->length = length;
    newChunk->next = NULL;
    memcpy(newChunk->text, text, length);
    return newChunk;
}

int main() {
    TextChunk *head = NULL;
    char text[] = "This is a long text that will be divided into chunks. It has many words and sentences.";

    // Divide the text into chunks
    int chunkSize = 256;
    char *currentText = text;
    while (currentText) {
        int length = 0;
        char *chunkText = NULL;
        while (length < chunkSize && currentText) {
            char nextChar = *currentText;
            currentText++;
            length++;
            chunkText = realloc(chunkText, length * sizeof(char));
            chunkText[length - 1] = nextChar;
        }
        TextChunk *newChunk = createTextChunk(length, chunkText);
        if (head == NULL) {
            head = newChunk;
        } else {
            newChunk->next = head;
            head = newChunk;
        }
    }

    // Print the chunks
    TextChunk *currentChunk = head;
    while (currentChunk) {
        printf("%s", currentChunk->text);
        printf("\n");
        currentChunk = currentChunk->next;
    }

    return 0;
}