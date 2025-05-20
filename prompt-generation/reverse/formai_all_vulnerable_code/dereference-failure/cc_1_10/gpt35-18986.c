//FormAI DATASET v1.0 Category: Computer Biology ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for storing the DNA sequence
typedef struct {
    char *sequence;
    int length;
} DNA;

// Define a function for generating a random DNA sequence
DNA *generate_random_dna(int length) {
    DNA *dna = (DNA *) malloc(sizeof(DNA));
    dna->sequence = (char *) malloc((length + 1) * sizeof(char));
    dna->length = length;
    int i;
    for (i = 0; i < length; i++) {
        int random_number = rand() % 4;
        switch (random_number) {
            case 0:
                dna->sequence[i] = 'A';
                break;
            case 1:
                dna->sequence[i] = 'T';
                break;
            case 2:
                dna->sequence[i] = 'C';
                break;
            case 3:
                dna->sequence[i] = 'G';
                break;
        }
    }
    dna->sequence[length] = '\0';
    return dna;
}

// Define a function for counting the number of occurrences of a character in a DNA sequence
int count_char_in_dna(DNA *dna, char c) {
    int count = 0;
    int i;
    for (i = 0; i < dna->length; i++) {
        if (dna->sequence[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    // Generate two random DNA sequences
    srand(time(0));
    DNA *dna1 = generate_random_dna(100);
    DNA *dna2 = generate_random_dna(100);

    // Print the DNA sequences
    printf("DNA sequence 1: %s\n", dna1->sequence);
    printf("DNA sequence 2: %s\n", dna2->sequence);

    // Count the number of occurrences of each nucleotide in each sequence
    int dna1_a = count_char_in_dna(dna1, 'A');
    int dna1_t = count_char_in_dna(dna1, 'T');
    int dna1_c = count_char_in_dna(dna1, 'C');
    int dna1_g = count_char_in_dna(dna1, 'G');
    int dna2_a = count_char_in_dna(dna2, 'A');
    int dna2_t = count_char_in_dna(dna2, 'T');
    int dna2_c = count_char_in_dna(dna2, 'C');
    int dna2_g = count_char_in_dna(dna2, 'G');

    // Print the results
    printf("Nucleotide frequencies in DNA sequence 1:\n");
    printf("A: %d\n", dna1_a);
    printf("T: %d\n", dna1_t);
    printf("C: %d\n", dna1_c);
    printf("G: %d\n", dna1_g);
    printf("Nucleotide frequencies in DNA sequence 2:\n");
    printf("A: %d\n", dna2_a);
    printf("T: %d\n", dna2_t);
    printf("C: %d\n", dna2_c);
    printf("G: %d\n", dna2_g);

    // Free the memory used by the DNA sequences
    free(dna1->sequence);
    free(dna1);
    free(dna2->sequence);
    free(dna2);

    return 0;
}