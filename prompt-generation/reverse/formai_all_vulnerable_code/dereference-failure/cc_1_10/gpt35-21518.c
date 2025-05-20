//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

char *generate_sequence(int length) {
    char *seq = (char*)malloc((length+1)*sizeof(char));
    for(int i=0; i<length; i++) {
        int r = rand()%4;
        switch(r) {
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
        }
    }
    seq[length] = '\0';
    return seq;
}

int main() {
    int n;
    printf("Enter the length of the DNA sequence to simulate: ");
    scanf("%d", &n);
    char *seq = generate_sequence(n);
    printf("The generated DNA sequence is: %s\n", seq);

    // reverse complement
    char *revcomp_seq = (char*)malloc((n+1)*sizeof(char));
    for(int i=n-1; i>=0; i--) {
        switch(seq[i]) {
            case 'A':
                revcomp_seq[n-i-1] = 'T';
                break;
            case 'C':
                revcomp_seq[n-i-1] = 'G';
                break;
            case 'G':
                revcomp_seq[n-i-1] = 'C';
                break;
            case 'T':
                revcomp_seq[n-i-1] = 'A';
        }
    }
    revcomp_seq[n] = '\0';
    printf("The reverse complement of the generated sequence is: %s\n", revcomp_seq);

    // mutate random base
    int r = rand()%n;
    char original_base = seq[r];
    char mutated_base = generate_sequence(1)[0];
    seq[r] = mutated_base;
    printf("A random base in the generated sequence (position %d) was mutated from %c to %c\n", r+1, original_base, mutated_base);
    printf("The new sequence is: %s\n", seq);

    free(seq);
    free(revcomp_seq);
    return 0;
}