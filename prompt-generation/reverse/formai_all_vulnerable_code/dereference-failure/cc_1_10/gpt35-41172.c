//FormAI DATASET v1.0 Category: Threading Library Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 5
#define MAX_QUEUE_SIZE 10

typedef struct {
  int buffer[MAX_QUEUE_SIZE];
  pthread_mutex_t *mutex;
  int head, tail;
  int full, empty;
  pthread_cond_t *not_full, *not_empty;
}queue;

void queue_init(queue *q) {
  q->mutex = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(q->mutex, NULL);
  q->not_full = (pthread_cond_t*)malloc(sizeof(pthread_cond_t));
  pthread_cond_init(q->not_full, NULL);
  q->not_empty = (pthread_cond_t*)malloc(sizeof(pthread_cond_t));
  pthread_cond_init(q->not_empty, NULL);
  q->head = q->tail = q->full = q->empty = 0;
}

void queue_destroy(queue *q) {
  free(q->mutex);
  free(q->not_full);
  free(q->not_empty);
}

void queue_put(queue *q, int item) {
  pthread_mutex_lock(q->mutex);
  while (q->full) {
    pthread_cond_wait(q->not_full, q->mutex);
  }
  q->buffer[q->tail] = item;
  q->tail = (q->tail+1)%MAX_QUEUE_SIZE;
  q->empty = 0;
  q->full = (q->head == q->tail);
  pthread_cond_broadcast(q->not_empty);
  pthread_mutex_unlock(q->mutex);
}

int queue_get(queue *q) {
  pthread_mutex_lock(q->mutex);
  while (q->empty) {
    pthread_cond_wait(q->not_empty, q->mutex);
  }
  int item = q->buffer[q->head];
  q->head = (q->head+1)%MAX_QUEUE_SIZE;
  q->full = 0;
  q->empty = (q->head == q->tail);
  pthread_cond_broadcast(q->not_full);
  pthread_mutex_unlock(q->mutex);
  return item;
}

queue q;

void *producer(void *arg) {
  long n = (long)arg;
  printf("Producer %ld started.\n", n);
  for (int i = 0; i < 10; i++) {
    printf("Producer %ld produced item%d.\n", n, i);
    queue_put(&q, i);
  }
  pthread_exit(NULL);
}

void *consumer(void *arg) {
  long n = (long)arg;
  printf("Consumer %ld started.\n", n);
  int items[MAX_QUEUE_SIZE];
  for (int i = 0; i < 10; i++) {
    items[i] = queue_get(&q);
    printf("Consumer %ld consumed item%d.\n", n, items[i]);
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t threads[MAX_THREADS];
  queue_init(&q);
  for (long i = 0; i < 3; i++) {
    pthread_create(&threads[i], NULL, producer, (void *)i);
  }
  for (long i = 3; i < MAX_THREADS; i++) {
    pthread_create(&threads[i], NULL, consumer, (void *)i);
  }
  for (int i = 0; i < MAX_THREADS; i++) {
    pthread_join(threads[i], NULL);
  }
  queue_destroy(&q);
  return 0;
}