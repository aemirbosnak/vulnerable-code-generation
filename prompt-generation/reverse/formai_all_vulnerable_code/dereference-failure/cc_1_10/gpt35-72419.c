//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SEQ_LEN 1000
#define MAX_MUTATIONS 10

char* generate_random_sequence(int len) {
    char* seq = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        int rand_num = rand() % 4;
        switch (rand_num) {
            case 0:
                seq[i] = 'A';
                break;
            case 1:
                seq[i] = 'C';
                break;
            case 2:
                seq[i] = 'G';
                break;
            case 3:
                seq[i] = 'T';
                break;
        }
    }

    seq[len] = '\0';
    return seq;
}

char* mutate_sequence(char* seq, int num_mutations) {
    int seq_len = strlen(seq);
    char* mutated_seq = malloc(seq_len + 1);
    strcpy(mutated_seq, seq);

    for (int i = 0; i < num_mutations; i++) {
        int rand_pos = rand() % seq_len;
        int rand_num = rand() % 4;
        switch (rand_num) {
            case 0:
                mutated_seq[rand_pos] = 'A';
                break;
            case 1:
                mutated_seq[rand_pos] = 'C';
                break;
            case 2:
                mutated_seq[rand_pos] = 'G';
                break;
            case 3:
                mutated_seq[rand_pos] = 'T';
                break;
        }
    }

    return mutated_seq;
}

int main() {
    srand(time(NULL));

    char* original_seq = generate_random_sequence(MAX_SEQ_LEN);
    printf("Original sequence: %s\n\n", original_seq);

    for (int i = 1; i <= MAX_MUTATIONS; i++) {
        printf("Mutated sequence after %d mutations: %s\n", i, mutate_sequence(original_seq, i));
    }

    free(original_seq);

    return 0;
}