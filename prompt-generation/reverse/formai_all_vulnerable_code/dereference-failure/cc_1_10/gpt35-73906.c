//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SEQUENCE_LENGTH 1000
#define MUTATION_RATE 0.01

char* random_sequence(int length) {
    char* sequence = malloc(length + 1);
    sequence[length] = '\0';
    for (int i = 0; i < length; i++) {
        int r = rand() % 4;
        switch(r) {
            case 0:
                sequence[i] = 'A';
                break;
            case 1:
                sequence[i] = 'C';
                break;
            case 2:
                sequence[i] = 'G';
                break;
            case 3:
                sequence[i] = 'T';
                break;
            default:
                fprintf(stderr, "Error: invalid random integer\n");
                exit(1);
        }
    }
    return sequence;
}

char mutate(char c) {
    double r = (double) rand() / RAND_MAX;
    if (r > MUTATION_RATE) {
        return c;
    } else {
        switch(c) {
            case 'A':
                return 'C';
            case 'C':
                return 'G';
            case 'G':
                return 'T';
            case 'T':
                return 'A';
            default:
                fprintf(stderr, "Error: invalid nucleotide\n");
                exit(1);
        }
    }
}

char* mutate_sequence(char* sequence, int length) {
    char* mutated_sequence = malloc(length + 1);
    mutated_sequence[length] = '\0';
    for (int i = 0; i < length; i++) {
        mutated_sequence[i] = mutate(sequence[i]);
    }
    return mutated_sequence;
}

void print_alignment(char* sequence1, char* sequence2, int length) {
    for (int i = 0; i < length; i++) {
        if (sequence1[i] == sequence2[i]) {
            printf("|");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    char* reference_sequence = random_sequence(SEQUENCE_LENGTH);
    printf("Reference sequence: %s\n", reference_sequence);
    char* sample_sequence = mutate_sequence(reference_sequence, SEQUENCE_LENGTH);
    printf("Sample sequence: %s\n", sample_sequence);
    int num_differences = 0;
    printf("Alignment:\n");
    print_alignment(reference_sequence, sample_sequence, SEQUENCE_LENGTH);
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        if (reference_sequence[i] != sample_sequence[i]) {
            num_differences++;
        }
    }
    double percent_difference = (double) num_differences / SEQUENCE_LENGTH * 100;
    printf("Number of differences: %d\n", num_differences);
    printf("Percent difference: %.2f%%\n", percent_difference);
    free(reference_sequence);
    free(sample_sequence);
    return 0;
}