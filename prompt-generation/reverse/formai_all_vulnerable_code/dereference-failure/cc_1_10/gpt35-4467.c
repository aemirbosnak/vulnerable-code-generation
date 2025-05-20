//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BASES 4
#define SEQ_LENGTH 50

// Function to generate a random DNA sequence
char *generate_DNA_sequence(int n) {
    static const char bases[] = "ACTG";
    char *seq = (char *) malloc(n + 1);
    for (int i = 0; i < n; i++) {
        seq[i] = bases[rand() % NUM_BASES];
    }
    seq[n] = '\0';
    return seq;
}

// Function to perform genome sequencing
void perform_genome_sequencing(char *seq) {
    int length = strlen(seq);
    int i = 0, j = 0, k = 0;
    int found_match = 0;
    char *temp_seq = (char *) malloc(length + 1);
    while (i < length) {
        temp_seq[k] = seq[i];
        j = i + 1;
        while (j < length) {
            if (temp_seq[k] == seq[j]) {
                found_match = 1;
                k++;
                temp_seq[k] = seq[j];
            }
            j++;
        }
        i++;
        if (!found_match) {
            printf("%s\n", temp_seq);
            k = 0;
        }
        found_match = 0;
    }
    free(temp_seq);
}

int main() {
    srand(time(NULL));
    char *seq = generate_DNA_sequence(SEQ_LENGTH);
    printf("Random DNA sequence: %s\n", seq);
    perform_genome_sequencing(seq);
    free(seq);
    return 0;
}