//FormAI DATASET v1.0 Category: Computer Biology ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random DNA sequence of given length
char* generate_DNA_sequence(int length) {
    // Allocate memory for the DNA sequence
    char* DNA_sequence = (char*) malloc((length+1) * sizeof(char));
    
    // Generate random base pairs for the DNA sequence
    for(int i=0; i<length; i++) {
        int random_num = rand() % 4;
        switch(random_num) {
            case 0: DNA_sequence[i] = 'A'; break;
            case 1: DNA_sequence[i] = 'C'; break;
            case 2: DNA_sequence[i] = 'G'; break;
            case 3: DNA_sequence[i] = 'T'; break;
        }
    }
    // Add a null terminator at the end of the DNA sequence
    DNA_sequence[length] = '\0';
    return DNA_sequence;
}

// Function to compute the reverse complement of a DNA sequence
char* reverse_complement_DNA(char* DNA_sequence, int length) {
    // Allocate memory for the reverse complement sequence
    char* reverse_complement = (char*) malloc((length+1) * sizeof(char));
    
    // Compute the reverse complement sequence
    for(int i=0; i<length; i++) {
        switch(DNA_sequence[i]) {
            case 'A': reverse_complement[length-i-1] = 'T'; break;
            case 'C': reverse_complement[length-i-1] = 'G'; break;
            case 'G': reverse_complement[length-i-1] = 'C'; break;
            case 'T': reverse_complement[length-i-1] = 'A'; break;
        }
    }
    // Add a null terminator at the end of the reverse complement sequence
    reverse_complement[length] = '\0';
    return reverse_complement;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Generate a random DNA sequence of length 50
    char* DNA_sequence = generate_DNA_sequence(50);
    
    // Compute the reverse complement of the DNA sequence
    char* reverse_complement = reverse_complement_DNA(DNA_sequence, 50);
    
    // Print out the DNA sequence and its reverse complement
    printf("DNA sequence: %s\n", DNA_sequence);
    printf("Reverse complement: %s\n", reverse_complement);
    
    // Free memory allocated for the DNA sequence and its reverse complement
    free(DNA_sequence);
    free(reverse_complement);
    
    return 0;
}