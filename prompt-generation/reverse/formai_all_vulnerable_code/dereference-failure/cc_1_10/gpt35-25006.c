//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH 10000 // Maximum length of genome sequence

// Function to generate random genome sequence
void generate_genome_sequence(char genome_sequence[], int length) {
    int i;
    char nucleotides[4] = {'A', 'C', 'G', 'T'}; // A, C, G, T are the four nucleotides in DNA sequence
    
    srand(time(NULL)); // Seed for random function
    
    for(i=0; i<length; i++) {
        genome_sequence[i] = nucleotides[rand() % 4];
    }
    
    genome_sequence[length] = '\0';
}

// Function to print genome sequence
void print_genome_sequence(char genome_sequence[], int length) {
    FILE *file_pointer;
    char file_name[20];
    int i;
    
    printf("\n\nGenome Sequence:\n");
    for(i=0; i<length; i++) {
        printf("%c", genome_sequence[i]);
    }
    
    // Write genome sequence to a file
    printf("\n\nEnter a file name to save genome sequence: ");
    scanf("%s", file_name);
    
    file_pointer = fopen(file_name, "w");
    if(file_pointer == NULL) {
        printf("\nError opening file!");
        exit(1);
    }
    
    fprintf(file_pointer, "%s", genome_sequence);
    fclose(file_pointer);
    
    printf("\nGenome sequence saved to file %s", file_name);
}

int main() {
    char genome_sequence[MAX_LENGTH];
    int length;
    
    // Get length of genome sequence from user
    printf("Enter the length of genome sequence (maximum %d): ", MAX_LENGTH);
    scanf("%d", &length);
    
    if(length > MAX_LENGTH) {
        printf("\nInvalid length! Maximum length allowed is %d", MAX_LENGTH);
        exit(1);
    }
    
    generate_genome_sequence(genome_sequence, length);
    print_genome_sequence(genome_sequence, length);
    
    return 0;
}