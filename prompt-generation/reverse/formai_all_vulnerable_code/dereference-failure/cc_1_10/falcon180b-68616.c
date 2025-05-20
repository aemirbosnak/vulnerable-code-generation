//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_NUM_SEQUENCES 100

typedef struct {
    char *name;
    char *sequence;
    int length;
} Sequence;

Sequence *read_sequences(FILE *file, int *num_sequences) {
    Sequence *sequences = NULL;
    char line[MAX_SEQUENCE_LENGTH];
    int current_sequence = 0;
    while (fgets(line, MAX_SEQUENCE_LENGTH, file)!= NULL) {
        if (line[0] == '>') {
            if (current_sequence >= MAX_NUM_SEQUENCES) {
                printf("Error: Too many sequences in the file.\n");
                exit(1);
            }
            sequences = realloc(sequences, sizeof(Sequence) * ++current_sequence);
            sequences[current_sequence-1].name = strdup(line+1);
            sequences[current_sequence-1].sequence = NULL;
            sequences[current_sequence-1].length = 0;
        } else {
            int sequence_length = 0;
            while (line[sequence_length]!= '\0' && line[sequence_length]!= '\n') {
                sequence_length++;
            }
            if (sequence_length > MAX_SEQUENCE_LENGTH) {
                printf("Error: Sequence too long.\n");
                exit(1);
            }
            sequences[current_sequence-1].sequence = malloc(sequence_length+1);
            strncpy(sequences[current_sequence-1].sequence, line, sequence_length);
            sequences[current_sequence-1].sequence[sequence_length] = '\0';
            sequences[current_sequence-1].length = sequence_length;
        }
    }
    *num_sequences = current_sequence;
    return sequences;
}

void write_sequences(Sequence *sequences, int num_sequences, FILE *file) {
    for (int i = 0; i < num_sequences; i++) {
        if (sequences[i].name == NULL) {
            continue;
        }
        fprintf(file, ">%s\n", sequences[i].name);
        if (sequences[i].sequence!= NULL) {
            fprintf(file, "%s\n", sequences[i].sequence);
        }
    }
}

int main() {
    srand(time(NULL));
    Sequence *sequences = NULL;
    int num_sequences = 0;
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }
    sequences = read_sequences(input_file, &num_sequences);
    fclose(input_file);
    if (num_sequences == 0) {
        printf("Error: No sequences found in input file.\n");
        exit(1);
    }
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    write_sequences(sequences, num_sequences, output_file);
    fclose(output_file);
    return 0;
}