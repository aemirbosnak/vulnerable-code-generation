//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *seq = (Sequence *) malloc(sizeof(Sequence));
    seq->sequence = (char *) malloc(length + 1);
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->sequence[i] = 'A' + rand() % 4;
    }
    seq->sequence[length] = '\0';

    return seq;
}

void print_sequence(Sequence *seq) {
    printf("%s\n", seq->sequence);
}

int main() {
    srand(time(NULL));

    Sequence genome = {NULL, 0};
    Sequence *reads[NUM_READS];

    for (int i = 0; i < NUM_READS; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        reads[i] = generate_random_sequence(read_length);
    }

    for (int i = 0; i < NUM_READS; i++) {
        int start_pos = rand() % genome.length;
        int end_pos = start_pos + reads[i]->length - 1;

        if (end_pos >= genome.length) {
            end_pos = genome.length - 1;
        }

        char *subsequence = (char *) malloc((end_pos - start_pos + 1) * sizeof(char));
        strncpy(subsequence, genome.sequence + start_pos, end_pos - start_pos + 1);
        subsequence[end_pos - start_pos] = '\0';

        if (strcmp(subsequence, reads[i]->sequence)!= 0) {
            printf("Mismatch at position %d\n", i);
        } else {
            printf("Match at position %d\n", i);
        }

        free(subsequence);
    }

    return 0;
}