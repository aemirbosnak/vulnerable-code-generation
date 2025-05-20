//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQUENCE_LENGTH 1000000
#define MAX_READ_LENGTH 100
#define MAX_ERR_RATE 0.05

typedef struct {
    char *sequence;
    int length;
} Sequence;

Sequence generate_random_sequence(int length) {
    Sequence seq = {0};
    seq.length = length;
    seq.sequence = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        seq.sequence[i] = rand() % 4; // A, C, G, or T
    }
    seq.sequence[length] = '\0';
    return seq;
}

void print_sequence(Sequence seq) {
    printf("%s\n", seq.sequence);
}

void simulate_genome_sequencing(Sequence genome, int read_length, double err_rate) {
    srand(time(NULL));
    int num_reads = (int) (genome.length / read_length);
    Sequence *reads = malloc(num_reads * sizeof(Sequence));
    for (int i = 0; i < num_reads; i++) {
        int start_pos = i * read_length;
        int end_pos = (i == num_reads - 1)? genome.length : (i + 1) * read_length - 1;
        reads[i] = generate_random_sequence(read_length);
        for (int j = 0; j < read_length; j++) {
            int k = rand() % (end_pos - start_pos + 1);
            reads[i].sequence[j] = genome.sequence[start_pos + k];
            if (rand() % 100 < err_rate * 100) {
                reads[i].sequence[j] = rand() % 4; // Introduce error with given error rate
            }
        }
        reads[i].length = read_length;
    }
    for (int i = 0; i < num_reads; i++) {
        print_sequence(reads[i]);
    }
    free(reads);
}

int main() {
    Sequence genome = generate_random_sequence(MAX_SEQUENCE_LENGTH);
    printf("Genome sequence:\n");
    print_sequence(genome);

    int read_length = MAX_READ_LENGTH;
    double err_rate = MAX_ERR_RATE;
    printf("Read length: %d\n", read_length);
    printf("Error rate: %.2f%%\n", err_rate * 100);

    simulate_genome_sequencing(genome, read_length, err_rate);

    return 0;
}