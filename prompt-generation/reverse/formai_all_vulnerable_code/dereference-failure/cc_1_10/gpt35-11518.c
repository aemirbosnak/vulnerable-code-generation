//FormAI DATASET v1.0 Category: Computer Biology ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Given two DNA sequences of equal length, returns the number of base pairs that differ. */
int hamming_distance(char* seq1, char* seq2, int length) {
    int i, count = 0;
    for (i = 0; i < length; i++) {
        if (seq1[i] != seq2[i]) {
            count++;
        }
    }
    return count;
}

/* Given a DNA sequence, returns the reverse complement sequence. */
char* reverse_complement(char* seq, int length) {
    char* comp_seq = (char*) malloc((length + 1) * sizeof(char));
    int i;
    for (i = 0; i < length; i++) {
        switch (seq[i]) {
            case 'A':
                comp_seq[length - i - 1] = 'T';
                break;
            case 'T':
                comp_seq[length - i - 1] = 'A';
                break;
            case 'C':
                comp_seq[length - i - 1] = 'G';
                break;
            case 'G':
                comp_seq[length - i - 1] = 'C';
                break;
            default:
                comp_seq[length - i - 1] = seq[i];
        }
    }
    comp_seq[length] = '\0';
    return comp_seq;
}

int main() {
    char* seq1 = "AGCTATCGGACTAGCTCGATCG";
    char* seq2 = "AGCTGTGGAATGAGCTCGATTG";
    int length = 21;

    int dist = hamming_distance(seq1, seq2, length);
    printf("The Hamming distance between the sequences is %d\n", dist);

    char* comp_seq = reverse_complement(seq1, length);
    printf("The reverse complement of the first sequence is %s\n", comp_seq);
    free(comp_seq);

    return 0;
}