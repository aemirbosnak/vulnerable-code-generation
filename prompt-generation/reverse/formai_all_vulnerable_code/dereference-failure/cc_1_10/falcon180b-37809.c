//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000000

struct Sequence {
    char *data;
    int length;
};

struct Sequence *readSequence(FILE *fp) {
    struct Sequence *sequence = malloc(sizeof(struct Sequence));
    sequence->data = malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    sequence->length = 0;

    int c;
    while ((c = fgetc(fp))!= EOF) {
        if (isalpha(c)) {
            sequence->data[sequence->length++] = tolower(c);
        }
    }

    if (sequence->length == 0) {
        free(sequence->data);
        free(sequence);
        return NULL;
    }

    sequence->data[sequence->length] = '\0';
    return sequence;
}

void printSequence(struct Sequence *sequence) {
    printf("Sequence: %s\n", sequence->data);
}

int main() {
    FILE *fp;
    struct Sequence *sequence;

    fp = fopen("sequence.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    sequence = readSequence(fp);
    if (sequence == NULL) {
        printf("Error reading sequence.\n");
        fclose(fp);
        return 1;
    }

    printSequence(sequence);

    free(sequence->data);
    free(sequence);
    fclose(fp);

    return 0;
}