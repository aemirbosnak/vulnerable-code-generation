//Gemma-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_READ_LENGTH 100

typedef struct Read {
    char* sequence;
    int length;
    struct Read* next;
} Read;

Read* createRead(int length) {
    Read* read = malloc(sizeof(Read));
    read->sequence = malloc(length * sizeof(char));
    read->length = length;
    read->next = NULL;
    return read;
}

void insertRead(Read* head, int length) {
    Read* read = createRead(length);
    if (head) {
        read->next = head;
    }
    head = read;
}

int main() {
    // Create a random number generator
    srand(time(NULL));

    // Create a read list
    Read* head = NULL;

    // Simulate reads
    for (int i = 0; i < 10; i++) {
        int length = rand() % MAX_READ_LENGTH + 1;
        insertRead(head, length);
    }

    // Print reads
    for (Read* read = head; read; read = read->next) {
        printf("Read length: %d\n", read->length);
        printf("Sequence: %s\n", read->sequence);
        printf("\n");
    }

    return 0;
}