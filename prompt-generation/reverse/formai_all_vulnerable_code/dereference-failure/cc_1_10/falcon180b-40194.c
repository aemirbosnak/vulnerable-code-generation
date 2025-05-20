//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_READ_LENGTH 100
#define NUM_THREADS 4
#define NUM_SEQUENCES 1000
#define NUM_NUCLEOTIDES 4

typedef struct {
    char *sequence;
    int length;
} Sequence;

typedef struct {
    Sequence *sequences;
    int num_sequences;
} SequenceSet;

SequenceSet *load_sequences(char *filename) {
    FILE *fp = fopen(filename, "r");
    SequenceSet *set = malloc(sizeof(SequenceSet));
    set->num_sequences = 0;
    while (fscanf(fp, "%s\n", set->sequences[set->num_sequences].sequence)!= EOF) {
        set->sequences[set->num_sequences].length = strlen(set->sequences[set->num_sequences].sequence);
        set->num_sequences++;
    }
    fclose(fp);
    return set;
}

void *run_thread(void *arg) {
    int thread_id = *(int *) arg;
    SequenceSet *set = load_sequences("sequences.txt");
    int start_pos = thread_id * set->num_sequences / NUM_THREADS;
    int end_pos = (thread_id + 1) * set->num_sequences / NUM_THREADS;
    int i;
    for (i = start_pos; i < end_pos; i++) {
        Sequence *seq = &set->sequences[i];
        char *rev_seq = malloc(seq->length + 1);
        strcpy(rev_seq, seq->sequence);
        rev_seq[seq->length] = '\0';
        char *rev_seq_ptr = rev_seq;
        while (rev_seq_ptr[0]!= '\0') {
            printf("%c", rev_seq_ptr[0]);
            rev_seq_ptr++;
        }
        free(rev_seq);
    }
    free(set);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int i;
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, run_thread, &i);
    }
    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}