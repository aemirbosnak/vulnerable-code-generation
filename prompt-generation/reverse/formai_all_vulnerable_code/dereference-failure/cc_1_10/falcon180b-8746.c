//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define ALPHABET_SIZE 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence *createSequence(char *sequence) {
    Sequence *s = malloc(sizeof(Sequence));
    s->sequence = strdup(sequence);
    s->length = strlen(sequence);
    return s;
}

void destroySequence(Sequence *s) {
    free(s->sequence);
    free(s);
}

void printSequence(Sequence *s) {
    printf("%s\n", s->sequence);
}

int countBases(Sequence *s, char base) {
    int count = 0;
    for (int i = 0; i < s->length; i++) {
        if (s->sequence[i] == base || s->sequence[i] == toupper(base)) {
            count++;
        }
    }
    return count;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <sequence>\n", argv[0]);
        return 1;
    }

    char *sequence = argv[1];
    Sequence *s = createSequence(sequence);

    printf("Sequence length: %d\n", s->length);
    printf("A: %d\n", countBases(s, 'A'));
    printf("C: %d\n", countBases(s, 'C'));
    printf("G: %d\n", countBases(s, 'G'));
    printf("T: %d\n", countBases(s, 'T'));

    destroySequence(s);
    return 0;
}