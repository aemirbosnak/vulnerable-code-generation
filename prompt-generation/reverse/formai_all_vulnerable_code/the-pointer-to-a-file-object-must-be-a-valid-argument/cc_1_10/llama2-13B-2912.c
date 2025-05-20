//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a custom comparator for sorting DNA sequences
int cmp_dna(const void *a, const void *b) {
    const char *seq_a = *(const char **)a;
    const char *seq_b = *(const char **)b;
    size_t len = strlen(seq_a);
    for (size_t i = 0; i < len; i++) {
        if (seq_a[i] != seq_b[i]) {
            return seq_a[i] - seq_b[i];
        }
    }
    return 0; // identical sequences are considered equal
}

// Define a struct to represent a DNA sequence
struct dna {
    char sequence[101]; // up to 100 base pairs, plus a null terminator
};

// Define a function to read a DNA sequence from a file
struct dna read_dna(const char *filename) {
    struct dna seq;
    FILE *file = fopen(filename, "r");
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        // trim the newline character
        line[strcspn(line, "\n")] = 0;
        // copy the sequence into the struct
        strcpy(seq.sequence, line);
    }
    fclose(file);
    return seq;
}

// Define a function to print the sorted DNA sequences
void print_sorted_dna(struct dna *seqs, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", seqs[i].sequence);
    }
}

int main() {
    // Load the DNA sequences from a file
    struct dna seqs[5];
    for (int i = 0; i < 5; i++) {
        seqs[i] = read_dna("dna_sequences.txt");
    }

    // Sort the DNA sequences using the cmp_dna comparator
    qsort(seqs, 5, sizeof(struct dna), cmp_dna);

    // Print the sorted DNA sequences
    print_sorted_dna(seqs, 5);

    return 0;
}