//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  const char *nucleotides = "ACTG"; // valid nucleotides
  const int genome_length = 10000000; // define genome length
  char *genome = (char*) malloc(genome_length * sizeof(char)); // allocate memory for genome
 
  // generate random genome sequence
  srand(time(NULL));
  for (int i = 0; i < genome_length; i++){
    genome[i] = nucleotides[rand() % 4];
  }

  // simulate mutations
  int num_mutations = genome_length / 1000; // define number of mutations to occur 
  printf("Number of mutations: %d\n", num_mutations);
  
  srand(time(NULL)); // re-seed random generator
  for(int i = 0; i < num_mutations; i++){
    int index = rand() % genome_length; // choose random index to mutate
    if (genome[index] == 'A'){ // mutate A nucleotide
      genome[index] = nucleotides[rand() % 3 + 1]; 
    } else if (genome[index] == 'C'){ // mutate C nucleotide
      int direction = rand() % 2;
      if (direction == 0){
        genome[index] = 'A';
      } else {
        genome[index] = 'G';
      }      
    } else if (genome[index] == 'T'){ // mutate T nucleotide
      genome[index] = nucleotides[rand() % 3];
    } else { // mutate G nucleotide
      genome[index] = 'T';
    }
  }

  // Output mutated genome to file
  FILE *f = fopen("mutated_genome.txt", "w");
  if (f == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  for(int i = 0; i < genome_length; i++){
      fputc(genome[i], f);
  }
  fclose(f);
  printf("Mutation completed. Mutated genome saved to mutated_genome.txt\n");

  free(genome); // free memory allocated for the genome
  return 0;
}