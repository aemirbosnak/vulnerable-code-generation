//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000

// Define the nucleotide bases
#define A 0
#define C 1
#define G 2
#define T 3

typedef struct {
   char *seq;
   int length;
} Sequence;

Sequence *generate_random_sequence(int length) {
   Sequence *seq = (Sequence*) malloc(sizeof(Sequence));
   seq->seq = (char*) malloc((length + 1) * sizeof(char));
   seq->length = length;

   // Initialize the sequence with random nucleotides
   for (int i = 0; i < length; i++) {
      seq->seq[i] = rand() % 4;
   }
   seq->seq[length] = '\0';

   return seq;
}

void print_sequence(Sequence *seq) {
   printf("%s\n", seq->seq);
}

int main() {
   // Seed the random number generator
   srand(time(NULL));

   // Generate the reference genome
   Sequence *ref_genome = generate_random_sequence(MAX_SEQ_LENGTH);
   print_sequence(ref_genome);

   // Generate the reads
   Sequence *reads[NUM_READS];
   for (int i = 0; i < NUM_READS; i++) {
      int read_length = rand() % MAX_READ_LENGTH + 1;
      reads[i] = generate_random_sequence(read_length);
      print_sequence(reads[i]);
   }

   // Align the reads to the reference genome
   for (int i = 0; i < NUM_READS; i++) {
      int j = 0;
      int k = 0;
      while (j < reads[i]->length && k < ref_genome->length) {
         if (reads[i]->seq[j] == ref_genome->seq[k]) {
            j++;
            k++;
         } else {
            k++;
         }
      }
      printf("Read %d aligned to position %d\n", i, k);
   }

   return 0;
}