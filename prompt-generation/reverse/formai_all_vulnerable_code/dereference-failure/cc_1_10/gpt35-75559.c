//FormAI DATASET v1.0 Category: Computer Biology ; Style: expert-level
#include <stdio.h>
#include <string.h>

// Define a DNA sequence as a string
const char* dna_sequence = "GATTACA"; 

// Define a function to calculate the complement DNA sequence
char* complement_sequence(const char* seq){

    // Allocate memory for the complement sequence
    char* complement_seq = (char*) malloc((strlen(seq) + 1) * sizeof(char));

    // Loop through the sequence and replace each nucleotide with its complement
    for(int i=0; i<strlen(seq); i++){
        switch(seq[i]){
            case 'A':
                complement_seq[i] = 'T';
                break;
            case 'T':
                complement_seq[i] = 'A';
                break;
            case 'C':
                complement_seq[i] = 'G';
                break;
            case 'G':
                complement_seq[i] = 'C';
                break;
            default:
                complement_seq[i] = seq[i];
        }
    }

    return complement_seq;
}

// Define a function to calculate the reverse complement DNA sequence
char* reverse_complement_sequence(const char* seq){
    
    // Calculate the complement sequence first
    char* complement_seq = complement_sequence(seq);
    
    // Allocate memory for the reverse complement sequence
    char* reverse_complement_seq = (char*) malloc((strlen(seq) + 1) * sizeof(char));

    // Loop through the complement sequence and reverse it
    for(int i=strlen(seq)-1; i>=0; i--){
        reverse_complement_seq[strlen(seq)-i-1] = complement_seq[i];
    }

    return reverse_complement_seq;
}

int main(){
    
    // Print the original DNA sequence
    printf("Original DNA sequence: %s\n", dna_sequence);
    
    // Calculate the complement DNA sequence and print it
    char* complement_seq = complement_sequence(dna_sequence);
    printf("Complement DNA sequence: %s\n", complement_seq);
    
    // Calculate the reverse complement DNA sequence and print it
    char* reverse_complement_seq = reverse_complement_sequence(dna_sequence);
    printf("Reverse complement DNA sequence: %s\n", reverse_complement_seq);
    
    // Free memory
    free(complement_seq);
    free(reverse_complement_seq);

    return 0;
}