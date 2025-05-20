//GPT-4o-mini DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEQUENCE_LENGTH 1000
#define NUM_SEQUENCES 10
#define MAX_MISMATCHES 5

typedef struct {
    char sequence[SEQUENCE_LENGTH + 1]; // +1 for null terminator
    char id[50];
} DNASequence;

void generate_sequence(DNASequence *seq) {
    const char *nucleotides = "ACGT";
    for (int i = 0; i < SEQUENCE_LENGTH; i++) {
        seq->sequence[i] = nucleotides[rand() % 4];
    }
    seq->sequence[SEQUENCE_LENGTH] = '\0'; // null terminate the string
}

void print_sequence(DNASequence seq) {
    printf("ID: %s\n", seq.id);
    printf("Sequence: %s\n", seq.sequence);
}

void introduce_mismatches(DNASequence *seq) {
    int num_mismatches = rand() % (MAX_MISMATCHES + 1);
    for (int i = 0; i < num_mismatches; i++) {
        int position = rand() % SEQUENCE_LENGTH;
        const char *nucleotides = "ACGT";
        char original_nucleotide = seq->sequence[position];
        char new_nucleotide;
        do {
            new_nucleotide = nucleotides[rand() % 4];
        } while (new_nucleotide == original_nucleotide);
        seq->sequence[position] = new_nucleotide;
    }
}

void simulate_genome_sequencing(DNASequence sequences[], int n) {
    for (int i = 0; i < n; i++) {
        strcpy(sequences[i].id, "Seq_");
        char index[3];
        sprintf(index, "%02d", i + 1);
        strcat(sequences[i].id, index);
        
        generate_sequence(&sequences[i]);
        introduce_mismatches(&sequences[i]);
    }
}

void write_sequences_to_file(DNASequence sequences[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s for writing\n", filename);
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(file, ">%s\n%s\n", sequences[i].id, sequences[i].sequence);
    }
    
    fclose(file);
}

void read_sequences_from_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s for reading\n", filename);
        exit(EXIT_FAILURE);
    }
    
    char line[SEQUENCE_LENGTH + 50];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '>') {
            printf("%s", line);
            fgets(line, sizeof(line), file);
            printf("%s", line);
        }
    }
    
    fclose(file);
}

int main() {
    srand(time(NULL));
    
    DNASequence sequences[NUM_SEQUENCES];
    
    printf("Simulating genome sequencing...\n");
    simulate_genome_sequencing(sequences, NUM_SEQUENCES);
    
    const char *filename = "sequenced_genome.txt";
    write_sequences_to_file(sequences, NUM_SEQUENCES, filename);
    
    printf("Sequences written to %s\n", filename);
    printf("Reading sequences from file...\n");
    read_sequences_from_file(filename);
    
    return 0;
}