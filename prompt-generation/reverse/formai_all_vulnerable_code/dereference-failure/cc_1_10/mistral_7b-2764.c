//MISTRAL-7B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 100003

typedef struct {
    char sequence[51];
    int count;
} HashNode;

unsigned long hash(char *str) {
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % TABLE_SIZE;
}

void init_table() {
    HashNode *table = calloc(TABLE_SIZE, sizeof(HashNode));

    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i].count = 0;
    }
}

void insert_sequence(HashNode *table, char *sequence) {
    unsigned long index = hash(sequence);

    if (strcmp(table[index].sequence, sequence) == 0) {
        table[index].count++;
    } else {
        strcpy(table[index].sequence, sequence);
        table[index].count = 1;
    }
}

int find_sequence(HashNode *table, char *sequence) {
    unsigned long index = hash(sequence);

    if (strcmp(table[index].sequence, sequence) == 0) {
        return table[index].count;
    } else {
        return -1;
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <reference_genome> <sequences_file>\n", argv[0]);
        return 1;
    }

    init_table();

    FILE *fp_reference = fopen(argv[1], "r");
    char reference[51];
    fgets(reference, sizeof(reference), fp_reference);
    fclose(fp_reference);
    reference[strlen(reference) - 1] = '\0';

    FILE *fp_sequences = fopen(argv[2], "r");
    char line[1024], sequence[51];

    while (fgets(line, sizeof(line), fp_sequences)) {
        sscanf(line, "%s", sequence);
        insert_sequence(sequence, sequence);
    }

    fclose(fp_sequences);

    int match_count = find_sequence(sequence, reference);

    printf("Matches found: %d\n", match_count);

    free(sequence);

    return 0;
}