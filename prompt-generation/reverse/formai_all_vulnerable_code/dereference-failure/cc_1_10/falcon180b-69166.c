//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100
#define MAX_ERROR_RATE 0.05

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->sequence[length] = '\0';

    return sequence;
}

Sequence *generate_mutated_sequence(Sequence *original, double error_rate) {
    Sequence *mutated = malloc(sizeof(Sequence));
    mutated->length = original->length;
    mutated->sequence = malloc(original->length + 1);

    for (int i = 0; i < original->length; i++) {
        if (rand() % 100 < error_rate * 100) {
            mutated->sequence[i] = 'A' + rand() % 4;
        } else {
            mutated->sequence[i] = original->sequence[i];
        }
    }
    mutated->sequence[original->length] = '\0';

    return mutated;
}

void print_sequence(Sequence *sequence) {
    printf("%s\n", sequence->sequence);
}

int main() {
    srand(time(NULL));

    Sequence *reference_sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Sequence *query_sequence = generate_mutated_sequence(reference_sequence, MAX_ERROR_RATE);

    int num_reads = 10;
    int read_length = MAX_READ_LENGTH;

    for (int i = 0; i < num_reads; i++) {
        int start_pos = rand() % (reference_sequence->length - read_length + 1);
        Sequence *read = generate_mutated_sequence(reference_sequence, MAX_ERROR_RATE);

        printf("Read %d: ", i + 1);
        for (int j = 0; j < read_length; j++) {
            printf("%c", read->sequence[j]);
        }
        printf("\n");

        free(read->sequence);
        free(read);
    }

    free(query_sequence->sequence);
    free(query_sequence);
    free(reference_sequence->sequence);
    free(reference_sequence);

    return 0;
}