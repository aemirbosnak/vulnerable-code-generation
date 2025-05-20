//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LEN 10000
#define NUM_MUTATIONS 100
#define MIN_MUTATION_LEN 1
#define MAX_MUTATION_LEN 5
#define MUTATION_PROBABILITY 0.01
#define PRINT_PROGRESS 1000

char *generate_random_sequence(int len) {
    char *seq = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        seq[i] = 'A' + rand() % 4;
    }
    seq[len] = '\0';
    return seq;
}

void print_sequence(char *seq, int start, int end) {
    for (int i = start; i <= end; i++) {
        printf("%c", seq[i]);
    }
}

void simulate_mutations(char *seq, int num_mutations) {
    for (int i = 0; i < num_mutations; i++) {
        int mutation_len = rand() % (MAX_MUTATION_LEN - MIN_MUTATION_LEN + 1) + MIN_MUTATION_LEN;
        int start_pos = rand() % (MAX_SEQ_LEN - mutation_len + 1);
        int end_pos = start_pos + mutation_len - 1;
        char *mutated_seq = malloc(MAX_SEQ_LEN + 1);
        strncpy(mutated_seq, seq, start_pos);
        for (int j = start_pos; j <= end_pos; j++) {
            mutated_seq[j] = 'A' + rand() % 4;
        }
        strncpy(mutated_seq + end_pos + 1, seq + end_pos + 1, MAX_SEQ_LEN - end_pos - 1);
        mutated_seq[MAX_SEQ_LEN] = '\0';
        free(seq);
        seq = mutated_seq;
    }
}

int main() {
    srand(time(NULL));
    char *seq = generate_random_sequence(MAX_SEQ_LEN);
    printf("Original sequence:\n");
    print_sequence(seq, 0, MAX_SEQ_LEN - 1);
    printf("\n");

    int num_mutations = rand() % NUM_MUTATIONS + 1;
    simulate_mutations(seq, num_mutations);

    printf("Mutated sequence:\n");
    print_sequence(seq, 0, MAX_SEQ_LEN - 1);
    printf("\n");

    free(seq);
    return 0;
}