//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000

struct sequence {
    char *data;
    int length;
};

struct sequence *generate_random_sequence(int length) {
    struct sequence *seq = malloc(sizeof(struct sequence));
    seq->data = malloc(length * sizeof(char));
    seq->length = length;

    for (int i = 0; i < length; i++) {
        seq->data[i] = rand() % 4;
    }

    return seq;
}

void print_sequence(struct sequence *seq) {
    for (int i = 0; i < seq->length; i++) {
        printf("%c", seq->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int sequence_count = 10;
    int max_sequence_length = MAX_SEQUENCE_LENGTH / sequence_count;

    struct sequence **sequences = malloc(sequence_count * sizeof(struct sequence *));

    for (int i = 0; i < sequence_count; i++) {
        int length = rand() % max_sequence_length + 1;
        sequences[i] = generate_random_sequence(length);
    }

    for (int i = 0; i < sequence_count; i++) {
        print_sequence(sequences[i]);
    }

    for (int i = 0; i < sequence_count; i++) {
        free(sequences[i]->data);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}