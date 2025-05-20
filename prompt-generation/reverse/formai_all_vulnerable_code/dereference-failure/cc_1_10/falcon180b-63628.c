//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000
#define MAX_NUM_MISMATCHES 10

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int num_mismatches;
} Read;

Sequence *generate_random_sequence(int length) {
    Sequence *sequence = (Sequence *) malloc(sizeof(Sequence));
    sequence->length = length;
    sequence->sequence = (char *) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = 'A' + rand() % 4;
    }
    sequence->sequence[length] = '\0';
    return sequence;
}

Read *generate_random_read(int length, Sequence *sequence) {
    Read *read = (Read *) malloc(sizeof(Read));
    read->length = length;
    read->sequence = (char *) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (rand() % 2 == 0) {
            read->sequence[i] = sequence->sequence[i];
        } else {
            switch (sequence->sequence[i]) {
                case 'A':
                    read->sequence[i] = 'C';
                    break;
                case 'C':
                    read->sequence[i] = 'G';
                    break;
                case 'G':
                    read->sequence[i] = 'T';
                    break;
                case 'T':
                    read->sequence[i] = 'A';
                    break;
            }
        }
    }
    read->sequence[length] = '\0';
    read->num_mismatches = 0;
    for (int i = 0; i < length; i++) {
        if (read->sequence[i]!= sequence->sequence[i]) {
            read->num_mismatches++;
        }
    }
    return read;
}

void print_sequence(Sequence *sequence) {
    printf("Sequence: %s\n", sequence->sequence);
    printf("Length: %d\n", sequence->length);
}

void print_read(Read *read) {
    printf("Read: %s\n", read->sequence);
    printf("Length: %d\n", read->length);
    printf("Num Mismatches: %d\n", read->num_mismatches);
}

int main() {
    srand(time(NULL));
    Sequence *sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    Read *read = generate_random_read(MAX_READ_LENGTH, sequence);
    print_sequence(sequence);
    print_read(read);
    return 0;
}