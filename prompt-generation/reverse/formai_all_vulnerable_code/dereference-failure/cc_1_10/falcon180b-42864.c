//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SEQ_LEN 1000
#define MAX_NUM_SEQS 1000

typedef struct {
    char *seq;
    int len;
} Sequence;

Sequence *generate_random_seq(int len) {
    char *seq = malloc(len + 1);
    for (int i = 0; i < len; i++) {
        seq[i] = 'A' + rand() % 4;
    }
    seq[len] = '\0';
    Sequence *result = malloc(sizeof(Sequence));
    result->seq = seq;
    result->len = len;
    return result;
}

Sequence *read_seq_from_file(FILE *fp) {
    char line[MAX_SEQ_LEN];
    Sequence *result = malloc(sizeof(Sequence));
    while (fgets(line, MAX_SEQ_LEN, fp)!= NULL) {
        result->seq = realloc(result->seq, strlen(line) + 1);
        strcat(result->seq, line);
    }
    result->len = strlen(result->seq);
    return result;
}

void print_seq(Sequence *seq) {
    printf("%s\n", seq->seq);
}

int main() {
    srand(time(NULL));
    Sequence *seq1 = generate_random_seq(50);
    Sequence *seq2 = generate_random_seq(100);
    print_seq(seq1);
    print_seq(seq2);
    Sequence *merged_seq = malloc(sizeof(Sequence));
    merged_seq->seq = malloc(seq1->len + seq2->len + 1);
    strcat(merged_seq->seq, seq1->seq);
    strcat(merged_seq->seq, seq2->seq);
    merged_seq->len = seq1->len + seq2->len;
    print_seq(merged_seq);
    free(seq1->seq);
    free(seq2->seq);
    free(seq1);
    free(seq2);
    free(merged_seq->seq);
    free(merged_seq);
    return 0;
}