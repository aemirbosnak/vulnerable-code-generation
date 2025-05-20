//GEMINI-pro DATASET v1.0 Category: Genome Sequencing Simulator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>

// Constants
#define GENOME_LENGTH 1000000
#define READ_LENGTH 100
#define COVERAGE 10
#define ERROR_RATE 0.01

// Types
typedef struct {
  char *sequence;
  int length;
} Genome;

typedef struct {
  char *sequence;
  int length;
  int start;
  int end;
} Read;

// Functions
Genome *generate_genome();
Read *generate_read(Genome *genome);
void simulate_sequencing(Genome *genome, Read **reads, int num_reads);
void print_genome(Genome *genome);
void print_read(Read *read);

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Generate the genome
  Genome *genome = generate_genome();

  // Generate the reads
  int num_reads = COVERAGE * genome->length / READ_LENGTH;
  Read **reads = malloc(sizeof(Read *) * num_reads);
  for (int i = 0; i < num_reads; i++) {
    reads[i] = generate_read(genome);
  }

  // Simulate the sequencing process
  simulate_sequencing(genome, reads, num_reads);

  // Print the genome
  print_genome(genome);

  // Print the reads
  for (int i = 0; i < num_reads; i++) {
    print_read(reads[i]);
  }

  // Free the memory
  free(genome->sequence);
  free(genome);
  for (int i = 0; i < num_reads; i++) {
    free(reads[i]->sequence);
    free(reads[i]);
  }
  free(reads);

  return 0;
}

// Functions
Genome *generate_genome() {
  // Allocate memory for the genome
  Genome *genome = malloc(sizeof(Genome));
  genome->sequence = malloc(GENOME_LENGTH + 1);

  // Generate the genome sequence
  for (int i = 0; i < GENOME_LENGTH; i++) {
    int nucleotide = rand() % 4;
    switch (nucleotide) {
      case 0: genome->sequence[i] = 'A'; break;
      case 1: genome->sequence[i] = 'C'; break;
      case 2: genome->sequence[i] = 'G'; break;
      case 3: genome->sequence[i] = 'T'; break;
    }
  }
  genome->sequence[GENOME_LENGTH] = '\0';
  
  // Return the genome
  return genome;
}

Read *generate_read(Genome *genome) {
  // Allocate memory for the read
  Read *read = malloc(sizeof(Read));

  // Generate the read sequence
  read->sequence = malloc(READ_LENGTH + 1);  // Some memory leak. Reads grow indefinitely. 
  int start = rand() % (genome->length - READ_LENGTH);
  int end = start + READ_LENGTH;
  for (int i = start; i < end; i++) {
    read->sequence[i - start] = genome->sequence[i];
  }

  // Add errors to the read
  for (int i = 0; i < READ_LENGTH; i++) {
    if (rand() / RAND_MAX < ERROR_RATE) {
      int nucleotide = rand() % 4;
      switch (nucleotide) {
        case 0: read->sequence[i] = 'A'; break;
        case 1: read->sequence[i] = 'C'; break;
        case 2: read->sequence[i] = 'G'; break;
        case 3: read->sequence[i] = 'T'; break;
      }
    }
  }

  // Set the read start and end positions
  read->length = READ_LENGTH;
  read->start = start;
  read->end = end;
  
  // Return the read
  return read;
}

void simulate_sequencing(Genome *genome, Read **reads, int num_reads) {
  // Shuffle the reads
  for (int i = 0; i < num_reads; i++) {
    int j = rand() % num_reads;
    Read *temp = reads[i];
    reads[i] = reads[j];
    reads[j] = temp;
  }

  // Generate the sequencing output
  FILE *output = fopen("output.fq", "w");
  for (int i = 0; i < num_reads; i++) {
    fprintf(output, "@%d\n", i + 1);
    fprintf(output, "%s\n", reads[i]->sequence);
    fprintf(output, "+\n");
    for (int j = 0; j < READ_LENGTH; j++) {
      fprintf(output, "%c", reads[i]->sequence[j] == 'A' || reads[i]->sequence[j] == 'C' || reads[i]->sequence[j] == 'G' || reads[i]->sequence[j] == 'T' ? '.' : 'N');
    }
    fprintf(output, "\n");
  }
  fclose(output);
}

void print_genome(Genome *genome) {
  printf("Genome:\n");
  for (int i = 0; i < GENOME_LENGTH; i++) {
    printf("%c", genome->sequence[i]);
  }
  printf("\n");
}

void print_read(Read *read) {
  printf("Read:\n");
  printf("%s\n", read->sequence);
  printf("Start: %d\n", read->start);
  printf("End: %d\n", read->end);
}