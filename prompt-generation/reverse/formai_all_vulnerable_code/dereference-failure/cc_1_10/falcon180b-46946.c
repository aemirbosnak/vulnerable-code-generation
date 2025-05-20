//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_NUCLEOTIDES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *read_sequence_from_file(FILE *file) {
    char line[MAX_SEQUENCE_LENGTH];
    Sequence *sequence = malloc(sizeof(Sequence));
    sequence->length = 0;
    sequence->sequence = malloc(MAX_SEQUENCE_LENGTH);

    while (fgets(line, MAX_SEQUENCE_LENGTH, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\n' && line[i]!= '\r') {
            if (isalpha(line[i])) {
                sequence->sequence[sequence->length++] = tolower(line[i]);
            }
            i++;
        }
    }

    return sequence;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

int count_nucleotides(Sequence *sequence, char nucleotide) {
    int count = 0;
    for (int i = 0; i < sequence->length; i++) {
        if (sequence->sequence[i] == nucleotide) {
            count++;
        }
    }
    return count;
}

int main() {
    FILE *file = fopen("sequence.txt", "r");
    Sequence *sequence = read_sequence_from_file(file);

    printf("Sequence length: %d\n", sequence->length);
    printf("Sequence:\n");
    print_sequence(sequence);

    int a_count = count_nucleotides(sequence, 'a');
    int c_count = count_nucleotides(sequence, 'c');
    int g_count = count_nucleotides(sequence, 'g');
    int t_count = count_nucleotides(sequence, 't');

    printf("A count: %d\n", a_count);
    printf("C count: %d\n", c_count);
    printf("G count: %d\n", g_count);
    printf("T count: %d\n", t_count);

    free(sequence->sequence);
    free(sequence);
    fclose(file);

    return 0;
}