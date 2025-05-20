//FormAI DATASET v1.0 Category: Genome Sequencing Simulator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GENOME_LENGTH 1000000
#define NUM_NUCLEOTIDES 4

char nucleotides[NUM_NUCLEOTIDES] = {'A', 'C', 'G', 'T'};

void generate_genome(char *genome, int length) {
    int i;
    for(i = 0; i < length; i++) {
        int rand_num = rand() % NUM_NUCLEOTIDES;
        genome[i] = nucleotides[rand_num];
    }
}

void print_genome(char *genome, int length) {
    int i;
    for(i = 0; i < length; i++) {
        printf("%c", genome[i]);
    }
    printf("\n");
}

void mutate_genome(char *genome, int length, float mutation_rate) {
    int i;
    for(i = 0; i < length; i++) {
        float rand_float = (float)rand() / RAND_MAX;
        if(rand_float < mutation_rate) {
            int rand_num = rand() % NUM_NUCLEOTIDES;
            genome[i] = nucleotides[rand_num];
        }
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int genome_length;
    float mutation_rate;
    if(argc == 3) {
        genome_length = atoi(argv[1]);
        mutation_rate = atof(argv[2]);
    } else {
        printf("Usage: ./genome_simulator [genome_length] [mutation_rate]\n");
        return 1;
    }
    if(genome_length > MAX_GENOME_LENGTH) {
        printf("Error: maximum genome length exceeded\n");
        return 1;
    }
    char genome[MAX_GENOME_LENGTH];
    generate_genome(genome, genome_length);
    printf("Original genome:\n");
    print_genome(genome, genome_length);
    mutate_genome(genome, genome_length, mutation_rate);
    printf("Mutated genome:\n");
    print_genome(genome, genome_length);
    return 0;
}