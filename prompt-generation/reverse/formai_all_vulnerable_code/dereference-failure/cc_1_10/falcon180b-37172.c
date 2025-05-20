//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Function to generate a random DNA sequence
char* generate_dna(int length) {
    char *dna = malloc(length + 1);
    char bases[] = "ACGT";
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        dna[i] = bases[rand() % 4];
    }

    dna[length] = '\0';
    return dna;
}

// Function to print a DNA sequence
void print_dna(char* dna, int length) {
    for (int i = 0; i < length; i++) {
        printf("%c", dna[i]);
    }
    printf("\n");
}

// Function to reverse a DNA sequence
char* reverse_dna(char* dna, int length) {
    char *rev_dna = malloc(length + 1);
    for (int i = length - 1; i >= 0; i--) {
        rev_dna[i] = dna[length - i - 1];
    }
    rev_dna[length] = '\0';
    return rev_dna;
}

// Function to complement a DNA sequence
char* complement_dna(char* dna, int length) {
    char *comp_dna = malloc(length + 1);
    char bases[] = "ACGT";
    for (int i = 0; i < length; i++) {
        if (dna[i] == 'A') {
            comp_dna[i] = 'T';
        } else if (dna[i] == 'C') {
            comp_dna[i] = 'G';
        } else if (dna[i] == 'G') {
            comp_dna[i] = 'C';
        } else if (dna[i] == 'T') {
            comp_dna[i] = 'A';
        }
    }
    comp_dna[length] = '\0';
    return comp_dna;
}

// Function to count the number of occurrences of a character in a DNA sequence
int count_char(char* dna, int length, char c) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (dna[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    // Generate a random DNA sequence of length 100
    char* dna = generate_dna(100);
    print_dna(dna, 100);

    // Reverse the DNA sequence
    char* rev_dna = reverse_dna(dna, 100);
    printf("Reversed DNA sequence: ");
    print_dna(rev_dna, 100);

    // Complement the DNA sequence
    char* comp_dna = complement_dna(dna, 100);
    printf("Complement DNA sequence: ");
    print_dna(comp_dna, 100);

    // Count the number of occurrences of 'A' in the DNA sequence
    int a_count = count_char(dna, 100, 'A');
    printf("Number of 'A's in the DNA sequence: %d\n", a_count);

    return 0;
}