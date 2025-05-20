//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1000

typedef struct {
    int pos;
    char base;
} Read;

void sequence(char *genome, int start, int end, int *counts) {
    if (start > end)
        return;

    char base = genome[start];
    counts[base]++;

    sequence(genome, start + 1, end, counts);
}

void readSequencing(char *genome, int len, int *counts) {
    int i;
    Read reads[MAX_LEN];

    for (i = 0; i < len; i++) {
        reads[i].pos = i;
        reads[i].base = genome[i];
    }

    sequence(genome, 0, len - 1, counts);

    for (i = 0; i < len; i++) {
        printf("Base %c at position %d occurs %d times.\n", reads[i].base, reads[i].pos, counts[reads[i].base]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <genome>\n", argv[0]);
        return 1;
    }

    int len = strlen(argv[1]);
    if (len > MAX_LEN) {
        printf("Genome too long.\n");
        return 1;
    }

    int counts[4] = {0};
    readSequencing(argv[1], len, counts);

    return 0;
}