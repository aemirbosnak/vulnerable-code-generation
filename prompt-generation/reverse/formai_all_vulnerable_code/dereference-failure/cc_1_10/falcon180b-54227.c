//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SEQUENCE_LENGTH 1000000

char *sequence = NULL;
int sequence_length = 0;

void initialize_sequence(int length) {
    sequence = (char *)malloc(length + 1);
    sequence_length = length;
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A';
    }
    sequence[length] = '\0';
}

void print_sequence() {
    printf("Sequence: %s\n", sequence);
}

int main() {
    // Initialize sequence with length 10000
    initialize_sequence(10000);

    // Print initial sequence
    print_sequence();

    // Mutate sequence
    for (int i = 0; i < sequence_length; i++) {
        if (sequence[i] == 'A') {
            sequence[i] = 'C';
        } else if (sequence[i] == 'C') {
            sequence[i] = 'G';
        } else if (sequence[i] == 'G') {
            sequence[i] = 'T';
        } else {
            sequence[i] = 'A';
        }
    }

    // Print mutated sequence
    print_sequence();

    // Analyze sequence
    int a_count = 0;
    int c_count = 0;
    int g_count = 0;
    int t_count = 0;
    for (int i = 0; i < sequence_length; i++) {
        if (sequence[i] == 'A') {
            a_count++;
        } else if (sequence[i] == 'C') {
            c_count++;
        } else if (sequence[i] == 'G') {
            g_count++;
        } else {
            t_count++;
        }
    }
    printf("A count: %d\n", a_count);
    printf("C count: %d\n", c_count);
    printf("G count: %d\n", g_count);
    printf("T count: %d\n", t_count);

    return 0;
}