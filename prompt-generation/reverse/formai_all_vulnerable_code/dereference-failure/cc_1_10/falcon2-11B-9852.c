//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a DNA sequence from a file
char* read_dna_sequence(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }
    
    char* sequence = (char*)malloc(sizeof(char) * 5000);
    if (sequence == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    
    fread(sequence, sizeof(char), 5000, file);
    fclose(file);
    
    return sequence;
}

// Function to print a DNA sequence
void print_dna_sequence(const char* sequence) {
    for (int i = 0; i < strlen(sequence); i++) {
        printf("%c", sequence[i]);
    }
    printf("\n");
}

// Function to reverse a DNA sequence
char* reverse_dna_sequence(const char* sequence) {
    char* reversed = (char*)malloc(sizeof(char) * strlen(sequence));
    if (reversed == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    
    for (int i = 0; i < strlen(sequence); i++) {
        reversed[i] = sequence[strlen(sequence) - 1 - i];
    }
    
    return reversed;
}

// Function to find the length of a DNA sequence
int find_dna_sequence_length(const char* sequence) {
    int length = 0;
    for (int i = 0; i < strlen(sequence); i++) {
        if (sequence[i] == 'A') {
            length++;
        } else if (sequence[i] == 'T') {
            length++;
        } else if (sequence[i] == 'C') {
            length++;
        } else if (sequence[i] == 'G') {
            length++;
        } else {
            perror("Invalid DNA sequence");
            exit(1);
        }
    }
    
    return length;
}

// Function to generate a random DNA sequence
char* generate_dna_sequence(int length) {
    char* sequence = (char*)malloc(sizeof(char) * length);
    if (sequence == NULL) {
        perror("Memory allocation failed");
        exit(1);
    }
    
    for (int i = 0; i < length; i++) {
        sequence[i] = rand() % 4 + 'A';
    }
    
    return sequence;
}

int main() {
    // Read a DNA sequence from a file
    char* sequence = read_dna_sequence("input.txt");
    if (sequence == NULL) {
        printf("Failed to read DNA sequence from file.\n");
        exit(1);
    }
    
    // Print the DNA sequence
    print_dna_sequence(sequence);
    
    // Reverse the DNA sequence
    char* reversed_sequence = reverse_dna_sequence(sequence);
    if (reversed_sequence == NULL) {
        printf("Failed to reverse DNA sequence.\n");
        exit(1);
    }
    
    // Print the reversed DNA sequence
    print_dna_sequence(reversed_sequence);
    
    // Find the length of the DNA sequence
    int length = find_dna_sequence_length(sequence);
    printf("DNA sequence length: %d\n", length);
    
    // Generate a random DNA sequence
    char* random_sequence = generate_dna_sequence(length);
    if (random_sequence == NULL) {
        printf("Failed to generate DNA sequence.\n");
        exit(1);
    }
    
    // Print the random DNA sequence
    print_dna_sequence(random_sequence);
    
    free(sequence);
    free(reversed_sequence);
    free(random_sequence);
    
    return 0;
}