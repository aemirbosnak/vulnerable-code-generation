//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define BASES 4
#define NUCLEOTIDE_LENGTH 1000
#define BUFFER_SIZE 1000

typedef struct {
    char base;
    int count;
} base_count;

void read_sequence(char *sequence, FILE *fp) {
    char buffer[BUFFER_SIZE];
    int len = 0;

    while (fgets(buffer, BUFFER_SIZE, fp)) {
        if (buffer[0] == '>') {
            continue;
        }

        for (int i = 0; i < strlen(buffer) && i < NUCLEOTIDE_LENGTH - len; i++) {
            sequence[len + i] = toupper(buffer[i]);
        }
        len += strlen(buffer) - 1;
    }

    sequence[NUCLEOTIDE_LENGTH - 1] = '\0';
}

void print_base_counts(base_count *counts) {
    for (int i = 0; i < BASES; i++) {
        printf("%c: %d\n", counts[i].base, counts[i].count);
    }
}

void count_bases(char *sequence, base_count *counts) {
    for (int i = 0; i < NUCLEOTIDE_LENGTH; i++) {
        int index = sequence[i] - 'A';
        counts[index].count++;
    }
}

int main() {
    char sequence[NUCLEOTIDE_LENGTH];
    base_count counts[BASES];
    FILE *fp = fopen("sequence.fasta", "r");

    if (fp == NULL) {
        perror("Error opening file\n");
        return 1;
    }

    read_sequence(sequence, fp);
    count_bases(sequence, counts);
    print_base_counts(counts);

    fclose(fp);
    return 0;
}