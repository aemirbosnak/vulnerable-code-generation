//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SEQ_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define NUM_READS 100000
#define MIN_READ_OVERLAP 50
#define MAX_READ_ERRORS 5

typedef struct {
    char *seq;
    int length;
} Sequence;

typedef struct {
    char *seq;
    int length;
    int start;
    int end;
} Read;

Sequence *generateSequence(int length) {
    Sequence *seq = (Sequence *)malloc(sizeof(Sequence));
    seq->seq = (char *)malloc(length + 1);
    seq->length = length;
    for (int i = 0; i < length; i++) {
        seq->seq[i] = 'A' + rand() % 4;
    }
    seq->seq[length] = '\0';
    return seq;
}

Read *generateRead(Sequence *seq, int readLength, int start) {
    Read *read = (Read *)malloc(sizeof(Read));
    read->seq = (char *)malloc(readLength + 1);
    read->length = readLength;
    read->start = start;
    read->end = start + readLength - 1;
    strncpy(read->seq, seq->seq + start, readLength);
    read->seq[readLength] = '\0';
    return read;
}

void printSequence(Sequence *seq) {
    printf("Sequence: %s\n", seq->seq);
    printf("Length: %d\n", seq->length);
}

void printRead(Read *read) {
    printf("Read: %s\n", read->seq);
    printf("Length: %d\n", read->length);
    printf("Start: %d\n", read->start);
    printf("End: %d\n", read->end);
}

int main() {
    srand(time(NULL));
    Sequence *genome = generateSequence(MAX_SEQ_LENGTH);
    Read **reads = (Read **)malloc(NUM_READS * sizeof(Read *));
    int i, j;
    for (i = 0; i < NUM_READS; i++) {
        int readLength = MIN_READ_OVERLAP + rand() % (MAX_READ_LENGTH - MIN_READ_OVERLAP);
        int start = rand() % (genome->length - readLength);
        reads[i] = generateRead(genome, readLength, start);
        printf("Read %d: ", i + 1);
        printRead(reads[i]);
    }
    for (i = 0; i < NUM_READS; i++) {
        for (j = i + 1; j < NUM_READS; j++) {
            if (reads[i]->end >= reads[j]->start && reads[i]->start <= reads[j]->end) {
                printf("Overlap between reads %d and %d\n", i + 1, j + 1);
                break;
            }
        }
    }
    return 0;
}