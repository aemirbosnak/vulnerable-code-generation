//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000

typedef struct {
    char *id;
    char *sequence;
    int length;
} Read;

typedef struct {
    int num_reads;
    Read *reads;
} ReadSet;

ReadSet *create_read_set(int num_reads) {
    ReadSet *read_set = malloc(sizeof(ReadSet));
    read_set->num_reads = num_reads;
    read_set->reads = malloc(sizeof(Read) * num_reads);

    for (int i = 0; i < num_reads; i++) {
        read_set->reads[i].id = malloc(sizeof(char) * 10);
        sprintf(read_set->reads[i].id, "read_%d", i);
        read_set->reads[i].sequence = malloc(sizeof(char) * MAX_READ_LENGTH);
        read_set->reads[i].length = rand() % MAX_READ_LENGTH + 1;
        for (int j = 0; j < read_set->reads[i].length; j++) {
            read_set->reads[i].sequence[j] = rand() % 4 + 'A';
        }
    }

    return read_set;
}

void print_read(Read *read) {
    printf("ID: %s\n", read->id);
    printf("Sequence: %s\n", read->sequence);
    printf("Length: %d\n\n", read->length);
}

void print_read_set(ReadSet *read_set) {
    printf("Number of reads: %d\n", read_set->num_reads);
    for (int i = 0; i < read_set->num_reads; i++) {
        print_read(&read_set->reads[i]);
    }
}

void destroy_read_set(ReadSet *read_set) {
    for (int i = 0; i < read_set->num_reads; i++) {
        free(read_set->reads[i].id);
        free(read_set->reads[i].sequence);
    }
    free(read_set->reads);
    free(read_set);
}

int main() {
    srand(time(NULL));

    ReadSet *read_set = create_read_set(10);
    print_read_set(read_set);
    destroy_read_set(read_set);

    return 0;
}