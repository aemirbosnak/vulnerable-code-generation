//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_NUM_READS 1000000
#define MAX_NUM_MISMATCHES 5

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    char *sequence;
    int length;
    int start_position;
} Read;

void generate_random_sequence(Sequence *sequence, int length) {
    sequence->length = length;
    sequence->sequence = (char *)malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        sequence->sequence[i] = (char)rand() % 4 + 'A';
    }
}

void generate_random_read(Read *read, Sequence *sequence) {
    read->length = rand() % MAX_READ_LENGTH + 1;
    read->start_position = rand() % sequence->length;
    read->sequence = (char *)malloc((read->length + 1) * sizeof(char));
    for (int i = 0; i < read->length; i++) {
        read->sequence[i] = sequence->sequence[read->start_position + i];
    }
    read->sequence[read->length] = '\0';
}

int count_mismatches(Sequence *sequence, Read *read) {
    int mismatches = 0;
    for (int i = 0; i < read->length; i++) {
        if (sequence->sequence[read->start_position + i]!= read->sequence[i]) {
            mismatches++;
            if (mismatches > MAX_NUM_MISMATCHES) {
                break;
            }
        }
    }
    return mismatches;
}

void print_sequence(Sequence *sequence) {
    for (int i = 0; i < sequence->length; i++) {
        printf("%c", sequence->sequence[i]);
    }
    printf("\n");
}

void print_read(Read *read) {
    printf("Read: ");
    for (int i = 0; i < read->length; i++) {
        printf("%c", read->sequence[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));

    Sequence genome;
    generate_random_sequence(&genome, MAX_SEQUENCE_LENGTH);

    Read *reads = (Read *)malloc(MAX_NUM_READS * sizeof(Read));

    int num_reads = 0;
    while (num_reads < MAX_NUM_READS) {
        Read read;
        generate_random_read(&read, &genome);
        int mismatches = count_mismatches(&genome, &read);
        if (mismatches <= MAX_NUM_MISMATCHES) {
            reads[num_reads] = read;
            num_reads++;
        }
    }

    printf("Genome:\n");
    print_sequence(&genome);

    printf("Reads:\n");
    for (int i = 0; i < num_reads; i++) {
        print_read(reads + i);
    }

    free(reads);
    free(genome.sequence);

    return 0;
}