//Falcon2-11B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void genome_simulator(char *sequence, int length) {
    char *mutation_point = (char *)malloc(sizeof(char) * (length + 1));
    int mutation_index = 0;

    while (mutation_index < length) {
        mutation_point[mutation_index] = sequence[mutation_index];
        mutation_index++;
    }

    mutation_point[length] = '\0';

    int i, j;
    for (i = 0; i < length; i++) {
        if (i == 0) {
            for (j = 0; j < 10; j++) {
                mutation_point[j] = (char)((int)'A' + (j % 5));
            }
        } else if (i == 1) {
            for (j = 0; j < 10; j++) {
                mutation_point[j] = (char)((int)'T' + (j % 5));
            }
        } else if (i == 2) {
            for (j = 0; j < 10; j++) {
                mutation_point[j] = (char)((int)'G' + (j % 5));
            }
        } else if (i == 3) {
            for (j = 0; j < 10; j++) {
                mutation_point[j] = (char)((int)'C' + (j % 5));
            }
        } else if (i == 4) {
            for (j = 0; j < 10; j++) {
                mutation_point[j] = (char)((int)'A' + (j % 5));
            }
        }
    }

    printf("Mutated Sequence: %s\n", mutation_point);

    free(mutation_point);
}

int main() {
    char sequence[] = "ATGCATG";
    int length = strlen(sequence);
    genome_simulator(sequence, length);
    return 0;
}