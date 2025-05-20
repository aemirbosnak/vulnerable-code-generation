//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 10

typedef struct Synchronizer {
  pthread_mutex_t mutex;
  pthread_cond_t cond_wait;
  int buffer_size;
  int head;
  int tail;
  char **buffer;
} Synchronizer;

Synchronizer *sync_init(int size) {
  Synchronizer *sync = malloc(sizeof(Synchronizer));
  sync->buffer_size = size;
  sync->head = 0;
  sync->tail = 0;
  sync->buffer = malloc(size * sizeof(char *));
  pthread_mutex_init(&sync->mutex, NULL);
  pthread_cond_init(&sync->cond_wait, NULL);
  return sync;
}

void sync_push(Synchronizer *sync, char *data) {
  pthread_mutex_lock(&sync->mutex);

  while ((sync->tail - sync->head) % sync->buffer_size == 0) {
    pthread_cond_wait(&sync->cond_wait, &sync->mutex);
  }

  sync->buffer[sync->tail] = data;
  sync->tail = (sync->tail + 1) % sync->buffer_size;

  pthread_mutex_unlock(&sync->mutex);
  pthread_cond_signal(&sync->cond_wait);
}

char *sync_pop(Synchronizer *sync) {
  pthread_mutex_lock(&sync->mutex);

  while (sync->head == sync->tail) {
    pthread_cond_wait(&sync->cond_wait, &sync->mutex);
  }

  char *data = sync->buffer[sync->head];
  sync->head = (sync->head + 1) % sync->buffer_size;

  pthread_mutex_unlock(&sync->mutex);
  pthread_cond_signal(&sync->cond_wait);
  return data;
}

int main() {
  Synchronizer *sync = sync_init(MAX_BUFFER_SIZE);

  char *data = malloc(10);
  data = "Hello, world!";

  sync_push(sync, data);

  char *ret_data = sync_pop(sync);

  printf("%s\n", ret_data);

  free(data);
  free(sync);

  return 0;
}