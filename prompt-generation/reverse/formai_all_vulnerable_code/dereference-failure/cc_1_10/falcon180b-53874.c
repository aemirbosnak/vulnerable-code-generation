//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_SEQUENCE_COUNT 1000000

struct sequence {
    char *name;
    char *sequence;
    int length;
};

struct sequence *sequences;
int sequence_count;

void init_sequences() {
    sequences = (struct sequence *) malloc(sizeof(struct sequence) * MAX_SEQUENCE_COUNT);
    sequence_count = 0;
}

void add_sequence(char *name, char *sequence) {
    if (sequence_count >= MAX_SEQUENCE_COUNT) {
        printf("Error: Maximum number of sequences reached.\n");
        exit(1);
    }

    sequences[sequence_count].name = strdup(name);
    sequences[sequence_count].sequence = strdup(sequence);
    sequences[sequence_count].length = strlen(sequence);

    sequence_count++;
}

void print_sequences() {
    for (int i = 0; i < sequence_count; i++) {
        printf("Sequence %d:\nName: %s\nSequence: %s\nLength: %d\n\n", i + 1, sequences[i].name, sequences[i].sequence, sequences[i].length);
    }
}

void cleanup() {
    for (int i = 0; i < sequence_count; i++) {
        free(sequences[i].name);
        free(sequences[i].sequence);
    }

    free(sequences);
}

int main() {
    init_sequences();

    while (1) {
        printf("Enter name of sequence:\n");
        char *name = (char *) malloc(256);
        scanf("%s", name);

        printf("Enter sequence:\n");
        char *sequence = (char *) malloc(MAX_SEQUENCE_LENGTH);
        scanf("%s", sequence);

        add_sequence(name, sequence);

        printf("Do you want to add another sequence? (y/n)\n");
        char input;
        scanf(" %c", &input);

        if (input == 'n') {
            break;
        }
    }

    print_sequences();

    cleanup();

    return 0;
}