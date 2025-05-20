//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Random DNA base generator
char random_base() {
    int r = rand() % 4;
    switch (r) {
        case 0: return 'A';
        case 1: return 'C';
        case 2: return 'G';
        case 3: return 'T';
    }
    return '\0';  // This should never happen
}

// Generate a random DNA sequence of length n
char* generate_dna(int n) {
    char* dna = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        dna[i] = random_base();
    }
    dna[n] = '\0';
    return dna;
}

// K-mer counter
int kmer_count(char* dna, int k) {
    int n = strlen(dna);
    int count = 0;
    for (int i = 0; i <= n - k; i++) {
        char kmer[k + 1];
        strncpy(kmer, dna + i, k);
        kmer[k] = '\0';
        count++;
    }
    return count;
}

// Error rate model
double error_rate(double e) {
    double x = rand() / (RAND_MAX + 1.0);
    return x < e ? 1 : 0;
}

// Introduce sequencing errors into DNA sequence
char* introduce_errors(char* dna, double e) {
    int n = strlen(dna);
    char* dna_err = malloc(n + 1);
    for (int i = 0; i < n; i++) {
        if (error_rate(e)) {
            dna_err[i] = random_base();
        } else {
            dna_err[i] = dna[i];
        }
    }
    dna_err[n] = '\0';
    return dna_err;
}

// Find the longest common substring
int lcs(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    int lcs_len = 0;
    int lcs_start = 0;
    int lcs[n + 1][m + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            } else if (str1[i - 1] == str2[j - 1]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                if (lcs[i][j] > lcs_len) {
                    lcs_len = lcs[i][j];
                    lcs_start = i - lcs_len;
                }
            } else {
                lcs[i][j] = 0;
            }
        }
    }
    return lcs_len;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA sequence of length 1000
    char* dna = generate_dna(1000);

    // Introduce sequencing errors with an error rate of 0.1
    char* dna_err = introduce_errors(dna, 0.1);

    // Count the number of unique 5-mers in the original DNA sequence
    int kmer_count_orig = kmer_count(dna, 5);

    // Count the number of unique 5-mers in the error-introduced DNA sequence
    int kmer_count_err = kmer_count(dna_err, 5);

    // Find the longest common substring between the original and error-introduced DNA sequences
    int lcs_len = lcs(dna, dna_err);

    // Print the results
    printf("Original DNA sequence: %s\n", dna);
    printf("Error-introduced DNA sequence: %s\n", dna_err);
    printf("Number of unique 5-mers in the original DNA sequence: %d\n", kmer_count_orig);
    printf("Number of unique 5-mers in the error-introduced DNA sequence: %d\n", kmer_count_err);
    printf("Length of the longest common substring between the original and error-introduced DNA sequences: %d\n", lcs_len);

    // Free the allocated memory
    free(dna);
    free(dna_err);

    return 0;
}