//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HEAP_SIZE 100
#define MAX_ROMANCE 50

typedef struct RomanticHeap {
    char *word;
    int frequency;
    struct RomanticHeap *next;
} RomanticHeap;

RomanticHeap *createRomanticHeap(void) {
    RomanticHeap *heap = (RomanticHeap *) malloc(sizeof(RomanticHeap));
    heap->word = NULL;
    heap->frequency = 0;
    heap->next = NULL;
    return heap;
}

void addRomanticWord(RomanticHeap *heap, char *word) {
    RomanticHeap *newHeap = (RomanticHeap *) malloc(sizeof(RomanticHeap));
    newHeap->word = word;
    newHeap->frequency = 1;
    newHeap->next = heap;
    heap = newHeap;
}

void printRomanticHeap(RomanticHeap *heap) {
    while (heap != NULL) {
        printf("%s (%d)\n", heap->word, heap->frequency);
        heap = heap->next;
    }
}

int main(void) {
    RomanticHeap *heap = createRomanticHeap();

    // Add some romantic words
    addRomanticWord(heap, "love");
    addRomanticWord(heap, "kiss");
    addRomanticWord(heap, "hug");
    addRomanticWord(heap, "cuddle");
    addRomanticWord(heap, "romance");

    // Print the romantic heap
    printRomanticHeap(heap);

    // Free the memory
    free(heap);

    return 0;
}