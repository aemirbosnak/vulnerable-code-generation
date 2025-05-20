//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 100
#define ALPHABET_SIZE 4

const char nucleotides[ALPHABET_SIZE] = {'A', 'C', 'G', 'T'};

// Function to generate a random nucleotide sequence
void generate_sequence(char *sequence, int length) {
    srand(time(NULL));
    
    for (int i = 0; i < length; i++) {
        sequence[i] = nucleotides[rand() % ALPHABET_SIZE];
    }
    sequence[length] = '\0'; // Null-terminate the string
}

// Function to simulate genome sequencing
void simulate_genome_sequencing(int num_sequences, int seq_length) {
    char *sequences[num_sequences];

    printf("Hark! Behold the great act of Genome Sequencing!\n");
    printf("Generating %d sequences of length %d...\n", num_sequences, seq_length);
    
    // Generate sequences
    for (int i = 0; i < num_sequences; i++) {
        sequences[i] = (char *)malloc((seq_length + 1) * sizeof(char));
        generate_sequence(sequences[i], seq_length);
    }

    // Present the sequences to the noble audience
    for (int i = 0; i < num_sequences; i++) {
        printf("Sequence %d: %s\n", i + 1, sequences[i]);
    }
  
    // Free memory
    for (int i = 0; i < num_sequences; i++) {
        free(sequences[i]);
    }
}

// Function to find the longest common prefix among sequences
char *longest_common_prefix(char **sequences, int count) {
    if (count == 0) return "";

    char *prefix = (char *)malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    int index = 0;

    for (int i = 0; i < MAX_SEQUENCE_LENGTH; i++) {
        char current_char = sequences[0][i];
        for (int j = 1; j < count; j++) {
            if (sequences[j][i] != current_char) {
                prefix[index] = '\0'; // Null-terminate the prefix
                return prefix;
            }
        }
        prefix[index++] = current_char;
    }
    prefix[index] = '\0'; // Null-terminate the prefix
    return prefix;
}

int main() {
    printf("Welcome, noble coder, to the Genome Sequencing Simulator!\n");
    int number_of_sequences;
    int length_of_each_sequence;
    
    // Input: Number of sequences and their length
    printf("Enter the number of sequences to generate: ");
    scanf("%d", &number_of_sequences);
    printf("Enter the length of each sequence: ");
    scanf("%d", &length_of_each_sequence);
    
    // Simulate genome sequencing
    simulate_genome_sequencing(number_of_sequences, length_of_each_sequence);
    
    // To find the longest common prefix
    printf("Wouldst thou like to find the longest common prefix of generated sequences? (y/n): ");
    char response;
    scanf(" %c", &response); // Space before %c to ignore any newline
    
    if (response == 'y') {
        char *sequences[number_of_sequences];
        for (int i = 0; i < number_of_sequences; i++) {
            sequences[i] = (char *)malloc((length_of_each_sequence + 1) * sizeof(char));
            generate_sequence(sequences[i], length_of_each_sequence);
        } 
        
        char *prefix = longest_common_prefix(sequences, number_of_sequences);
        printf("The longest common prefix is: %s\n", prefix);
        
        free(prefix);
        for (int i = 0; i < number_of_sequences; i++) {
            free(sequences[i]);
        }
    } else {
        printf("Very well, noble coder! May the winds of fortune be at thy back!\n");
    }
    
    return 0;
}