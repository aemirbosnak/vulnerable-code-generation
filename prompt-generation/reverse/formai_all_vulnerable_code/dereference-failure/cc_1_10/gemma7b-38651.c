//Gemma-7B DATASET v1.0 Category: File Synchronizer ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Synchronizer {
  pthread_mutex_t mutex;
  pthread_cond_t cond_wait;
  int buffer_size;
  char **buffer;
  int head;
  int tail;
} Synchronizer;

Synchronizer *sync_init(int buffer_size) {
  Synchronizer *sync = malloc(sizeof(Synchronizer));
  sync->buffer_size = buffer_size;
  sync->buffer = malloc(buffer_size * MAX_BUFFER_SIZE);
  pthread_mutex_init(&sync->mutex, NULL);
  pthread_cond_init(&sync->cond_wait, NULL);
  sync->head = 0;
  sync->tail = 0;
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
}

char *sync_pop(Synchronizer *sync) {
  pthread_mutex_lock(&sync->mutex);
  while (sync->head == sync->tail) {
    pthread_cond_wait(&sync->cond_wait, &sync->mutex);
  }
  char *data = sync->buffer[sync->head];
  sync->head = (sync->head + 1) % sync->buffer_size;
  pthread_mutex_unlock(&sync->mutex);
  return data;
}

int main() {
  Synchronizer *sync = sync_init(10);
  sync_push(sync, "Hello, world!");
  char *data = sync_pop(sync);
  printf("%s\n", data);
  free(sync);
  return 0;
}