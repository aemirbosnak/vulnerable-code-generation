//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 10000
#define MAX_READ_LENGTH 100
#define NUM_READS 100

//Struct to hold genome and read information
typedef struct {
    char *sequence;
    int length;
} Genome;

typedef struct {
    char *sequence;
    int length;
    int start_position;
    int end_position;
} Read;

//Function to generate random DNA sequence
char *generate_random_sequence(int length) {
    char *sequence = (char *) malloc(length + 1);
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
    return sequence;
}

//Function to generate random reads from genome
void generate_reads(Genome *genome, Read *reads, int num_reads) {
    srand(time(NULL));
    for (int i = 0; i < num_reads; i++) {
        int read_length = rand() % MAX_READ_LENGTH + 1;
        int start_position = rand() % genome->length;
        int end_position = start_position + read_length - 1;
        if (end_position >= genome->length) {
            end_position = genome->length - 1;
        }
        reads[i].sequence = generate_random_sequence(read_length);
        reads[i].length = read_length;
        reads[i].start_position = start_position;
        reads[i].end_position = end_position;
    }
}

//Function to print genome and read sequences
void print_sequences(Genome *genome, Read *reads, int num_reads) {
    printf("Genome sequence:\n%s\n", genome->sequence);
    for (int i = 0; i < num_reads; i++) {
        printf("Read %d: %s\n", i + 1, reads[i].sequence);
    }
}

//Main function
int main() {
    Genome genome;
    Read reads[NUM_READS];

    //Generate random genome sequence
    genome.sequence = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    genome.length = strlen(genome.sequence);

    //Generate random reads from genome
    generate_reads(&genome, reads, NUM_READS);

    //Print genome and read sequences
    print_sequences(&genome, reads, NUM_READS);

    return 0;
}