//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define LENGTH 100000
#define ALPHABET_SIZE 4

typedef struct {
    char base;
    int count;
} BaseCount;

void readFile(char *filename, char sequence[][LENGTH]) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < 5; i++) {
        fgets(sequence[i], LENGTH, fp);
        sequence[i][strlen(sequence[i]) - 1] = '\0';
    }

    fclose(fp);
}

void simulateSequencing(char reference[], char *sequences[], BaseCount bases[]) {
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v;
    char read[LENGTH], currentBase;
    int readsCompleted = 0;

    for (i = 0; i < 5 && readsCompleted < 5; i++) {
        strcpy(read, sequences[i]);
        currentBase = reference[0];
        bases[currentBase].count++;

        for (j = 1; j < strlen(read) && readsCompleted < 5; j++) {
            if (isalpha(read[j]) && toupper(read[j]) != currentBase) {
                currentBase = toupper(read[j]);
                bases[currentBase].count++;
            }
            readsCompleted++;
        }
    }
}

void printResults(BaseCount bases[]) {
    int i;

    for (i = 0; i < ALPHABET_SIZE; i++) {
        printf("%c: %d\n", i + 'A', bases[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 7) {
        printf("Usage: %s <reference.txt> <read1.txt> <read2.txt> <read3.txt> <read4.txt> <read5.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    char reference[LENGTH];
    char sequences[5][LENGTH];
    BaseCount bases[ALPHABET_SIZE];

    readFile(argv[1], sequences);
    strcpy(reference, argv[1]);

    simulateSequencing(reference, sequences, bases);
    printResults(bases);

    return EXIT_SUCCESS;
}