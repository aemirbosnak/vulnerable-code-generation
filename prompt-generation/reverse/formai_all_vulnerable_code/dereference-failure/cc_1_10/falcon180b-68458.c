//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEQUENCE_LENGTH 1000000

char *sequence;
int sequence_length;

void read_sequence_file(char *filename) {
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open sequence file.\n");
        exit(1);
    }
    sequence_length = 0;
    sequence = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    char c;
    while ((c = fgetc(file))!= EOF) {
        if (sequence_length >= MAX_SEQUENCE_LENGTH) {
            printf("Error: sequence too long.\n");
            exit(1);
        }
        sequence[sequence_length++] = c;
    }
    fclose(file);
}

void write_sequence_file(char *filename) {
    FILE *file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }
    fwrite(sequence, sequence_length, sizeof(char), file);
    fclose(file);
}

void reverse_sequence() {
    char *start = sequence;
    char *end = sequence + sequence_length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <sequence_file>\n", argv[0]);
        exit(1);
    }
    read_sequence_file(argv[1]);
    reverse_sequence();
    write_sequence_file("reversed.seq");
    printf("Sequence reversed and saved to reversed.seq.\n");
    return 0;
}