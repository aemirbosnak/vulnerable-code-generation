//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define READ_LENGTH 100
#define COVERAGE 10
#define GC_CONTENT 0.5

typedef struct {
    char *sequence;
    int length;
} Read;

typedef struct {
    Read *reads;
    int num_reads;
} Dataset;

Dataset *generate_dataset(int num_reads) {
    Dataset *dataset = malloc(sizeof(Dataset));
    dataset->reads = malloc(num_reads * sizeof(Read));
    dataset->num_reads = num_reads;

    for (int i = 0; i < num_reads; i++) {
        dataset->reads[i].length = READ_LENGTH;
        dataset->reads[i].sequence = malloc(READ_LENGTH + 1);

        for (int j = 0; j < READ_LENGTH; j++) {
            double r = (double)rand() / RAND_MAX;
            if (r < GC_CONTENT) {
                dataset->reads[i].sequence[j] = 'G' + (rand() % 2);
            } else {
                dataset->reads[i].sequence[j] = 'A' + (rand() % 2);
            }
        }

        dataset->reads[i].sequence[READ_LENGTH] = '\0';
    }

    return dataset;
}

void free_dataset(Dataset *dataset) {
    for (int i = 0; i < dataset->num_reads; i++) {
        free(dataset->reads[i].sequence);
    }

    free(dataset->reads);
    free(dataset);
}

int main() {
    int num_reads = COVERAGE * 1000000;
    Dataset *dataset = generate_dataset(num_reads);

    // Do something with the dataset

    free_dataset(dataset);

    return 0;
}