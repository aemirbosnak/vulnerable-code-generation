//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000000
#define MAX_NUM_VARIANTS 1000000

typedef struct {
    int start_pos;
    int end_pos;
    int ref_base;
    int alt_base;
    int depth;
} Variant;

void generate_sequence(char *seq, int length) {
    for (int i = 0; i < length; i++) {
        int base = rand() % 4;
        switch (base) {
            case 0:
                seq[i] = 'A';
                break;
            case 1:
                seq[i] = 'C';
                break;
            case 2:
                seq[i] = 'G';
                break;
            case 3:
                seq[i] = 'T';
                break;
        }
    }
    seq[length] = '\0';
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    char *sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    generate_sequence(sequence, MAX_SEQUENCE_LENGTH);

    printf("Sequence: %s\n", sequence);

    int num_reads = rand() % MAX_NUM_READS + 1;
    int read_length = rand() % MAX_READ_LENGTH + 1;

    printf("Number of reads: %d\n", num_reads);
    printf("Read length: %d\n", read_length);

    int num_variants = rand() % MAX_NUM_VARIANTS + 1;
    Variant variants[MAX_NUM_VARIANTS];

    for (int i = 0; i < num_variants; i++) {
        variants[i].start_pos = rand() % MAX_SEQUENCE_LENGTH;
        variants[i].end_pos = rand() % MAX_SEQUENCE_LENGTH;
        variants[i].ref_base = sequence[variants[i].start_pos];
        variants[i].alt_base = sequence[variants[i].end_pos];
        variants[i].depth = rand() % 50 + 1;
    }

    printf("Number of variants: %d\n", num_variants);

    for (int i = 0; i < num_variants; i++) {
        printf("Variant %d: %d-%d, %c->%c, depth: %d\n", i+1, variants[i].start_pos, variants[i].end_pos, variants[i].ref_base, variants[i].alt_base, variants[i].depth);
    }

    free(sequence);
    return 0;
}