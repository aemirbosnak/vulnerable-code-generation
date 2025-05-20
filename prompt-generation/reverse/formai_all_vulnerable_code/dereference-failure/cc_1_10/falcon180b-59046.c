//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_SEQUENCE_COUNT 10000

struct sequence {
    char *name;
    char *sequence;
    int length;
};

struct sequence *generate_random_sequences(int count, int length) {
    struct sequence *sequences = (struct sequence *)malloc(count * sizeof(struct sequence));
    for (int i = 0; i < count; i++) {
        char *sequence = (char *)malloc((length + 1) * sizeof(char));
        for (int j = 0; j < length; j++) {
            sequence[j] = 'A' + rand() % 4;
        }
        sequence[length] = '\0';
        sequences[i].name = (char *)malloc(10 * sizeof(char));
        sprintf(sequences[i].name, "Sequence %d", i + 1);
        sequences[i].sequence = sequence;
        sequences[i].length = length;
    }
    return sequences;
}

void print_sequences(struct sequence *sequences, int count) {
    for (int i = 0; i < count; i++) {
        printf("Sequence %s:\n%s\n", sequences[i].name, sequences[i].sequence);
    }
}

int main() {
    srand(time(NULL));

    int sequence_count = MAX_SEQUENCE_COUNT;
    struct sequence *sequences = generate_random_sequences(sequence_count, MAX_SEQUENCE_LENGTH);

    print_sequences(sequences, sequence_count);

    for (int i = 0; i < sequence_count; i++) {
        free(sequences[i].name);
        free(sequences[i].sequence);
    }
    free(sequences);

    return 0;
}