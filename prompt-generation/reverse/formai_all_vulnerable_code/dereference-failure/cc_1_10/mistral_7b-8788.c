//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BASES 4
#define SEQ_LEN 100

typedef struct {
    char base;
    int count;
} Base;

void read_sequence(char sequence[SEQ_LEN]) {
    FILE *fp;
    char c;
    int i = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((c = fgetc(fp)) != EOF) {
        if (isalpha(c)) {
            sequence[i] = tolower(c);
            i++;
        }
        if (i == SEQ_LEN) break;
    }

    sequence[i] = '\0';
    fclose(fp);
}

void simulate_sequencing(char sequence[SEQ_LEN], Base bases[BASES]) {
    int i, j, k;
    int base_index;
    int reads[SEQ_LEN];
    int read_length = 0;

    for (i = 0; i < SEQ_LEN; i++) {
        for (j = 0; j < BASES; j++) {
            bases[j].count = 0;
        }

        base_index = 0;
        for (k = i; k < SEQ_LEN && k - i <= 50; k++) {
            reads[read_length++] = sequence[k];
            bases[(int)sequence[k]].count++;
        }

        for (j = 0; j < BASES; j++) {
            if (bases[j].count > reads[0]) {
                base_index = j;
                break;
            }
        }

        sequence[i] = base_index + 'A';
    }
}

void write_results(char sequence[SEQ_LEN]) {
    FILE *fp;
    fp = fopen("output.txt", "w");

    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%s\n", sequence);
    fclose(fp);
}

int main() {
    char sequence[SEQ_LEN];
    Base bases[BASES] = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    read_sequence(sequence);
    simulate_sequencing(sequence, bases);
    write_results(sequence);

    return 0;
}