//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_GENome_SIZE 100000
#define ALPHABET_SIZE 4
typedef struct {
    char base;
    int count;
} nucleotide;
nucleotide genome[MAX_GENome_SIZE];
int genome_size = 0;
void read_genome(char *filename) {
    FILE *fp;
    char ch;
    fp = fopen(filename, "r");
    while ((ch = fgetc(fp)) != EOF) {
        if (genome_size >= MAX_GENome_SIZE) {
            printf("Error: Genome size exceeds the limit.\n");
            exit(1);
        }
        if (ch == 'A') {
            genome[genome_size].base = 'A';
            genome[genome_size].count++;
        } else if (ch == 'C') {
            genome[genome_size].base = 'C';
            genome[genome_size].count++;
        } else if (ch == 'G') {
            genome[genome_size].base = 'G';
            genome[genome_size].count++;
        } else if (ch == 'T' || ch == 't') {
            genome[genome_size].base = 'T';
            genome[genome_size].count++;
        } else {
            printf("Error: Invalid base encountered in the genome sequence.\n");
            exit(1);
        }
        genome_size++;
    }
    fclose(fp);
}
void print_genome() {
    int i;
    printf("Genome sequence:\n");
    for (i = 0; i < genome_size; i++) {
        printf("%c (%d): %c\n", (i + 1), genome[i].count, genome[i].base);
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <genome_sequence.txt>\n", argv[0]);
        exit(1);
    }
    read_genome(argv[1]);
    print_genome();
    return 0;
}