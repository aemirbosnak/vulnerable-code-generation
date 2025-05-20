//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random DNA sequence
char* get_sequence(int n) {
    char* seq = (char*)malloc(n * sizeof(char));
    char nucleotides[] = {'A', 'C', 'G', 'T'};
    int i;
    for (i = 0; i < n; i++) {
        int index = rand() % 4;
        seq[i] = nucleotides[index];
    }
    seq[n] = '\0';
    return seq;
}

// Function to generate random genome with mutations
char* get_genome(int n, int m) {
    char* seq = get_sequence(n);
    int i;
    for (i = 0; i < m; i++) {
        int index = rand() % n;
        char mut;
        do {
            mut = rand() % 4;
        } while (mut == seq[index]);
        seq[index] = mut;
    }
    return seq;
}

// Function to print DNA sequence
void print_sequence(char* seq) {
    printf("%s\n", seq);
}

// Function to print genome with mutations
void print_genome(char* genome) {
    int i;
    for (i = 0; i < sizeof(genome); i++) {
        printf("%c", genome[i]);
        if ((i + 1) % 50 == 0) {
            printf("\n");
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 1000; // length of sequence/genome
    int m = 10; // number of mutations

    char* sequence = get_sequence(n);
    print_sequence(sequence);

    char* genome = get_genome(n, m);
    print_genome(genome);
    
    free(sequence);
    free(genome);
    return 0;
}