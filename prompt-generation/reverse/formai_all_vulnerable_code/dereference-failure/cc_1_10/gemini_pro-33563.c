//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <pthread.h>

// Nucleotide types
#define A 0
#define C 1
#define G 2
#define T 3

// Read lengths
#define MIN_READ_LENGTH 50
#define MAX_READ_LENGTH 150

// Number of reads
#define NUM_READS 1000000

// Error rate
#define ERROR_RATE 0.01

// Thread data
typedef struct {
    int start;
    int end;
    char *sequence;
    char *reads[NUM_READS];
} thread_data;

// Generate a random nucleotide
char random_nucleotide() {
    int r = rand() % 4;
    switch (r) {
        case 0:
            return 'A';
        case 1:
            return 'C';
        case 2:
            return 'G';
        case 3:
            return 'T';
        default:
            return 'N';
    }
}

// Generate a random read
char *random_read(int length) {
    char *read = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        read[i] = random_nucleotide();
    }
    read[length] = '\0';
    return read;
}

// Generate a random sequence
char *random_sequence(int length) {
    char *sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = random_nucleotide();
    }
    sequence[length] = '\0';
    return sequence;
}

// Introduce errors into a read
void introduce_errors(char *read, int length) {
    for (int i = 0; i < length; i++) {
        if (rand() / (RAND_MAX + 1.0) < ERROR_RATE) {
            read[i] = random_nucleotide();
        }
    }
}

// Thread function
void *thread_function(void *arg) {
    thread_data *data = (thread_data *)arg;
    for (int i = data->start; i < data->end; i++) {
        data->reads[i] = random_read(MIN_READ_LENGTH + (rand() % (MAX_READ_LENGTH - MIN_READ_LENGTH + 1)));
        introduce_errors(data->reads[i], strlen(data->reads[i]));
    }
    return NULL;
}

// Main function
int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random sequence
    char *sequence = random_sequence(1000000);

    // Create thread data
    thread_data data[8];
    for (int i = 0; i < 8; i++) {
        data[i].start = i * NUM_READS / 8;
        data[i].end = (i + 1) * NUM_READS / 8;
        data[i].sequence = sequence;
    }

    // Create threads
    pthread_t threads[8];
    for (int i = 0; i < 8; i++) {
        pthread_create(&threads[i], NULL, thread_function, &data[i]);
    }

    // Join threads
    for (int i = 0; i < 8; i++) {
        pthread_join(threads[i], NULL);
    }

    // Write reads to file
    FILE *fp = fopen("reads.fasta", "w");
    for (int i = 0; i < NUM_READS; i++) {
        fprintf(fp, ">read%d\n", i);
        fprintf(fp, "%s\n", data[0].reads[i]);
    }
    fclose(fp);

    // Free memory
    free(sequence);
    for (int i = 0; i < NUM_READS; i++) {
        free(data[0].reads[i]);
    }

    return 0;
}