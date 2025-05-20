//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100

typedef struct {
    int id;
    char *sequence;
    int length;
} Contig;

typedef struct {
    int id;
    int start;
    int end;
    int strand;
} Gene;

typedef struct {
    int id;
    int start;
    int end;
    float score;
} Repeat;

void generate_random_sequence(char *sequence, int length) {
    for (int i = 0; i < length; i++) {
        sequence[i] = 'A' + rand() % 4;
    }
    sequence[length] = '\0';
}

int main() {
    srand(time(NULL));

    int num_contigs = rand() % 100 + 1;
    Contig *contigs = malloc(sizeof(Contig) * num_contigs);

    for (int i = 0; i < num_contigs; i++) {
        contigs[i].id = i + 1;
        contigs[i].length = rand() % MAX_SEQUENCE_LENGTH + 1;
        contigs[i].sequence = malloc(sizeof(char) * contigs[i].length);
        generate_random_sequence(contigs[i].sequence, contigs[i].length);
    }

    int num_genes = rand() % 100 + 1;
    Gene *genes = malloc(sizeof(Gene) * num_genes);

    for (int i = 0; i < num_genes; i++) {
        genes[i].id = i + 1;
        genes[i].start = rand() % MAX_SEQUENCE_LENGTH + 1;
        genes[i].end = genes[i].start + rand() % MAX_SEQUENCE_LENGTH - 1;
        genes[i].strand = rand() % 2;
    }

    int num_repeats = rand() % 100 + 1;
    Repeat *repeats = malloc(sizeof(Repeat) * num_repeats);

    for (int i = 0; i < num_repeats; i++) {
        repeats[i].id = i + 1;
        repeats[i].start = rand() % MAX_SEQUENCE_LENGTH + 1;
        repeats[i].end = repeats[i].start + rand() % MAX_SEQUENCE_LENGTH - 1;
        repeats[i].score = rand() % 101;
    }

    printf("Contigs:\n");
    for (int i = 0; i < num_contigs; i++) {
        printf("ID: %d\n", contigs[i].id);
        printf("Sequence:\n%s\n", contigs[i].sequence);
    }

    printf("\nGenes:\n");
    for (int i = 0; i < num_genes; i++) {
        printf("ID: %d\n", genes[i].id);
        printf("Start: %d\n", genes[i].start);
        printf("End: %d\n", genes[i].end);
        printf("Strand: %d\n", genes[i].strand);
    }

    printf("\nRepeats:\n");
    for (int i = 0; i < num_repeats; i++) {
        printf("ID: %d\n", repeats[i].id);
        printf("Start: %d\n", repeats[i].start);
        printf("End: %d\n", repeats[i].end);
        printf("Score: %.2f\n", repeats[i].score);
    }

    return 0;
}