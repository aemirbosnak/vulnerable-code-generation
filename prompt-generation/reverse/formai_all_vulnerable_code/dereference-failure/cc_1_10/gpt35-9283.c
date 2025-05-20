//FormAI DATASET v1.0 Category: Computer Biology ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Defining a struct for DNA
typedef struct {
    char *sequence;
    int length;
} DNA;

// Function to generate DNA of given length
DNA generate_DNA(int length) {
    DNA dna;
    dna.length = length;
    dna.sequence = (char*) malloc((length+1) * sizeof(char)); // Adding 1 for null character
    for (int i = 0; i < length; ++i) {
        int random_num = rand() % 4;
        switch (random_num) {
            case 0:
                dna.sequence[i] = 'A';
                break;
            case 1:
                dna.sequence[i] = 'C';
                break;
            case 2:
                dna.sequence[i] = 'G';
                break;
            case 3:
                dna.sequence[i] = 'T';
                break;
        }
    }
    dna.sequence[length] = '\0'; // Adding null character at the end
    return dna;
}

// Function to print DNA sequence
void print_DNA(DNA dna) {
    printf("DNA sequence:\n%s\n", dna.sequence);
}

// Function to obtain the reverse complement of DNA sequence
DNA reverse_complement(DNA dna) {
    DNA reverse_dna;
    reverse_dna.length = dna.length;
    reverse_dna.sequence = (char*) malloc((dna.length+1) * sizeof(char)); // Adding 1 for null character
    for (int i = 0; i < dna.length; ++i) {
        switch (dna.sequence[i]) {
            case 'A':
                reverse_dna.sequence[dna.length-i-1] = 'T';
                break;
            case 'C':
                reverse_dna.sequence[dna.length-i-1] = 'G';
                break;
            case 'G':
                reverse_dna.sequence[dna.length-i-1] = 'C';
                break;
            case 'T':
                reverse_dna.sequence[dna.length-i-1] = 'A';
                break;
        }
    }
    reverse_dna.sequence[dna.length] = '\0'; // Adding null character at the end
    return reverse_dna;
}

int main() {
    srand(time(NULL)); // Initializing random seed
    int dna_length = 30;
    DNA dna = generate_DNA(dna_length);
    print_DNA(dna);
    DNA reverse_dna = reverse_complement(dna);
    printf("Reverse complement of DNA sequence:\n%s\n", reverse_dna.sequence);
    free(dna.sequence);
    free(reverse_dna.sequence);
    return 0;
}