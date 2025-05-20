//Falcon-180B DATASET v1.0 Category: Genome Sequencing Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>

#define NUM_THREADS 4
#define MAX_SEQUENCE_LENGTH 1000000

typedef struct {
  char *sequence;
  int length;
} Sequence;

Sequence *sequences[NUM_THREADS];

void *thread_func(void *arg) {
  int thread_id = *(int *)arg;
  Sequence *seq = sequences[thread_id];

  for (int i = 0; i < seq->length; i++) {
    printf("%c", seq->sequence[i]);
  }

  pthread_exit(NULL);
}

int main() {
  srand(time(NULL));

  int i;
  for (i = 0; i < NUM_THREADS; i++) {
    sequences[i] = (Sequence *)malloc(sizeof(Sequence));
    sequences[i]->sequence = (char *)malloc(MAX_SEQUENCE_LENGTH * sizeof(char));
    sequences[i]->length = rand() % MAX_SEQUENCE_LENGTH;

    int j;
    for (j = 0; j < sequences[i]->length; j++) {
      sequences[i]->sequence[j] = 'A' + rand() % 4;
    }
  }

  pthread_t threads[NUM_THREADS];
  int thread_ids[NUM_THREADS];

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
  }

  for (i = 0; i < NUM_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  for (i = 0; i < NUM_THREADS; i++) {
    free(sequences[i]->sequence);
    free(sequences[i]);
  }

  return 0;
}