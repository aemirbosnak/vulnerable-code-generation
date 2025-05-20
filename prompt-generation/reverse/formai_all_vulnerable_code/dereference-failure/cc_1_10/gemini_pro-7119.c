//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the nucleotide characters
char nucleotides[] = {'A', 'C', 'G', 'T'};

// Get a random nucleotide
char get_random_nucleotide() {
    int index = rand() % 4;
    return nucleotides[index];
}

// Generate a random DNA sequence of a given length
char *generate_random_dna(int length) {
    char *dna = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        dna[i] = get_random_nucleotide();
    }
    dna[length] = '\0';
    return dna;
}

// Print a DNA sequence
void print_dna(char *dna) {
    printf("%s\n", dna);
}

// Write a DNA sequence to a file
void write_dna_to_file(char *dna, char *filename) {
    FILE *fp = fopen(filename, "w");
    fprintf(fp, "%s", dna);
    fclose(fp);
}

// Read a DNA sequence from a file
char *read_dna_from_file(char *filename) {
    FILE *fp = fopen(filename, "r");
    char *dna;
    fscanf(fp, "%s", dna);
    fclose(fp);
    return dna;
}

// Get the length of a DNA sequence
int get_dna_length(char *dna) {
    int length = strlen(dna);
    return length;
}

// Get the reverse complement of a DNA sequence
char *get_reverse_complement(char *dna) {
    int length = get_dna_length(dna);
    char *reverse_complement = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        switch (dna[i]) {
        case 'A':
            reverse_complement[length - i - 1] = 'T';
            break;
        case 'C':
            reverse_complement[length - i - 1] = 'G';
            break;
        case 'G':
            reverse_complement[length - i - 1] = 'C';
            break;
        case 'T':
            reverse_complement[length - i - 1] = 'A';
            break;
        }
    }
    reverse_complement[length] = '\0';
    return reverse_complement;
}

// Get the GC content of a DNA sequence
float get_gc_content(char *dna) {
    int length = get_dna_length(dna);
    int gc_count = 0;
    for (int i = 0; i < length; i++) {
        if (dna[i] == 'G' || dna[i] == 'C') {
            gc_count++;
        }
    }
    float gc_content = (float)gc_count / (float)length;
    return gc_content;
}

// Main function
int main() {
    // Set the random seed
    srand(time(NULL));

    // Generate a random DNA sequence of length 100
    char *dna = generate_random_dna(100);

    // Print the DNA sequence
    print_dna(dna);

    // Write the DNA sequence to a file
    write_dna_to_file(dna, "dna.txt");

    // Read the DNA sequence from the file
    char *dna_from_file = read_dna_from_file("dna.txt");

    // Get the length of the DNA sequence
    int length = get_dna_length(dna_from_file);

    // Get the reverse complement of the DNA sequence
    char *reverse_complement = get_reverse_complement(dna_from_file);

    // Get the GC content of the DNA sequence
    float gc_content = get_gc_content(dna_from_file);

    // Print the length of the DNA sequence
    printf("Length: %d\n", length);

    // Print the reverse complement of the DNA sequence
    printf("Reverse complement: %s\n", reverse_complement);

    // Print the GC content of the DNA sequence
    printf("GC content: %.2f%%\n", gc_content * 100);

    // Free the allocated memory
    free(dna);
    free(dna_from_file);
    free(reverse_complement);

    return 0;
}