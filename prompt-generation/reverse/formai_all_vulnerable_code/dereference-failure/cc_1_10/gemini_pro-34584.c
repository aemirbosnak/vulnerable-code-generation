//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct queue {
  int *data;
  int head;
  int tail;
  int size;
};

struct queue *
queue_create(int size)
{
  struct queue *q;

  q = malloc(sizeof(*q));
  if (!q)
    return NULL;

  q->data = malloc(size * sizeof(*q->data));
  if (!q->data) {
    free(q);
    return NULL;
  }

  q->head = 0;
  q->tail = 0;
  q->size = size;

  return q;
}

void
queue_destroy(struct queue *q)
{
  free(q->data);
  free(q);
}

int
queue_empty(struct queue *q)
{
  return q->head == q->tail;
}

int
queue_full(struct queue *q)
{
  return (q->tail + 1) % q->size == q->head;
}

int
queue_push(struct queue *q, int data)
{
  if (queue_full(q))
    return -1;

  q->data[q->tail] = data;
  q->tail = (q->tail + 1) % q->size;

  return 0;
}

int
queue_pop(struct queue *q)
{
  int data;

  if (queue_empty(q))
    return -1;

  data = q->data[q->head];
  q->head = (q->head + 1) % q->size;

  return data;
}

int
main(void)
{
  struct queue *q;
  int i;

  q = queue_create(10);
  if (!q) {
    perror("queue_create");
    return EXIT_FAILURE;
  }

  for (i = 0; i < 10; i++) {
    if (queue_push(q, i) < 0) {
      perror("queue_push");
      return EXIT_FAILURE;
    }
  }

  while (!queue_empty(q)) {
    printf("%d\n", queue_pop(q));
  }

  queue_destroy(q);

  return EXIT_SUCCESS;
}