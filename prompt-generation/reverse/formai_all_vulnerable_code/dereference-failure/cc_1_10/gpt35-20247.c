//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* Sequence struct represents a single part of genome sequence */
typedef struct Sequence {
    char* data;
    int start; /* Start index in the genome */
    int length; /* Length of the sequence */
} Sequence;

/* Genome struct represents the full genome */
typedef struct Genome {
    char* data;
    int length; /* Total length of the genome */
} Genome;

/* Thread argument struct */
typedef struct ThreadArg {
    Genome* genome;
    Sequence* sequence;
} ThreadArg;

/* Function for generating random DNA sequence */
char* generateRandomSequence(int length) {
    char* seq = (char*) malloc((length + 1) * sizeof(char));
    int i;
    static const char alphabet[] ="ACGT";
    for (i = 0; i < length; i++) {
        seq[i] = alphabet[rand() % (sizeof(alphabet) - 1)];
    }
    seq[length] = '\0';
    return seq;
}

/* Function for creating a new sequence */
Sequence* createSequence(int start, int length) {
    Sequence* sequence = (Sequence*) malloc(sizeof(Sequence));
    sequence->data = generateRandomSequence(length);
    sequence->start = start;
    sequence->length = length;
    return sequence;
}

/* Function for creating a new genome */
Genome* createGenome(int length) {
    Genome* genome = (Genome*) malloc(sizeof(Genome));
    genome->data = generateRandomSequence(length);
    genome->length = length;
    return genome;
}

/* Async function that compares a sequence to the genome */
void* asyncSequenceComparison(void* arg) {
    ThreadArg* threadArg = (ThreadArg*) arg;

    Genome* genome = threadArg->genome;
    Sequence* sequence = threadArg->sequence;

    int i, j;
    for (i = 0; i < genome->length - sequence->length; i++) {
        bool match = true;
        for (j = 0; j < sequence->length; j++) {
            if (genome->data[i + j] != sequence->data[j]) {
                match = false;
                break;
            }
        }
        if (match) {
            printf("Sequence found at start index %d\n", i);
        }
    }
}

/* Start the async sequence comparison */
void startSequenceComparisonAsync(Genome* genome, Sequence* sequence) {
    ThreadArg* threadArg = (ThreadArg*) malloc(sizeof(ThreadArg));
    threadArg->genome = genome;
    threadArg->sequence = sequence;

    pthread_t thread;
    pthread_create(&thread, NULL, asyncSequenceComparison, threadArg);
    pthread_detach(thread);
}

int main() {
    srand(time(NULL));

    Genome* genome = createGenome(1000);

    int i, numSequences = 10;
    for (i = 0; i < numSequences; i++) {
        Sequence* sequence = createSequence(rand() % (genome->length - 1), 10);
        startSequenceComparisonAsync(genome, sequence);
    }

    // Wait for results to come back
    sleep(1);

    return 0;
}