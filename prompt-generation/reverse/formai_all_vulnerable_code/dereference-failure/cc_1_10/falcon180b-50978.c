//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define NUM_BASES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

static void generate_random_sequence(Sequence *seq) {
    int i;
    for (i = 0; i < seq->length; i++) {
        seq->sequence[i] = 'A' + rand() % NUM_BASES;
    }
}

static int compare_sequences(const void *a, const void *b) {
    const Sequence *s1 = a;
    const Sequence *s2 = b;
    return strcmp(s1->sequence, s2->sequence);
}

int main(int argc, char *argv[]) {
    int num_sequences = 10;
    int max_length = 100;
    int min_length = 50;
    char **sequences;
    int i;

    srand(time(NULL));

    sequences = malloc(num_sequences * sizeof(char *));
    for (i = 0; i < num_sequences; i++) {
        sequences[i] = malloc(max_length * sizeof(char));
        generate_random_sequence(&(Sequence) {.sequence = sequences[i],.length = rand() % (max_length - min_length + 1) + min_length });
    }

    qsort(sequences, num_sequences, sizeof(char *), compare_sequences);

    for (i = 0; i < num_sequences; i++) {
        printf("%s\n", sequences[i]);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}