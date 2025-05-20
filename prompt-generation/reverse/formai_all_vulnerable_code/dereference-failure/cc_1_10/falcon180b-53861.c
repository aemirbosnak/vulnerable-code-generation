//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 1000

typedef struct {
    char *sequence;
    int length;
} DNA;

DNA *generate_sequence(int length) {
    char *bases = "ACGT";
    DNA *sequence = malloc(sizeof(DNA));
    sequence->length = length;
    sequence->sequence = malloc(sizeof(char) * length);

    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = bases[rand() % 4];
    }

    return sequence;
}

void print_sequence(DNA *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    int num_sequences = 10;
    int max_length = 100;

    DNA **sequences = malloc(sizeof(DNA *) * num_sequences);

    for (int i = 0; i < num_sequences; i++) {
        int length = rand() % max_length + 1;
        sequences[i] = generate_sequence(length);
        print_sequence(sequences[i]);
    }

    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i]->sequence);
        free(sequences[i]);
    }
    free(sequences);

    return 0;
}