//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ken Thompson
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_QUE_SIZE 1024
#define TIMEOUT_SEC 5

struct sock_packet {
  int seq_num;
  char data[MAX_QUE_SIZE];
  struct sock_packet* next;
};

struct sock_queue {
  struct sock_packet* head;
  struct sock_packet* tail;
  pthread_mutex_t mutex;
  pthread_cond_t cond_empty;
  pthread_cond_t cond_full;
};

void sock_queue_init(struct sock_queue* queue) {
  queue->head = NULL;
  queue->tail = NULL;
  pthread_mutex_init(&queue->mutex, NULL);
  pthread_cond_init(&queue->cond_empty, NULL);
  pthread_cond_init(&queue->cond_full, NULL);
}

int sock_queue_insert(struct sock_queue* queue, int seq_num, char* data) {
  struct sock_packet* new_packet = malloc(sizeof(struct sock_packet));
  new_packet->seq_num = seq_num;
  memcpy(new_packet->data, data, MAX_QUE_SIZE);
  new_packet->next = NULL;

  pthread_mutex_lock(&queue->mutex);

  if (queue->tail) {
    queue->tail->next = new_packet;
    queue->tail = new_packet;
  } else {
    queue->head = new_packet;
    queue->tail = new_packet;
  }

  pthread_cond_signal(&queue->cond_full);

  pthread_mutex_unlock(&queue->mutex);

  return 0;
}

int sock_queue_extract(struct sock_queue* queue, int* seq_num, char* data) {
  pthread_mutex_lock(&queue->mutex);

  if (queue->head == NULL) {
    pthread_cond_wait(&queue->cond_empty, &queue->mutex);
  }

  struct sock_packet* old_head = queue->head;
  *seq_num = old_head->seq_num;
  memcpy(data, old_head->data, MAX_QUE_SIZE);
  free(old_head);

  queue->head = old_head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }

  pthread_cond_signal(&queue->cond_full);

  pthread_mutex_unlock(&queue->mutex);

  return 0;
}

int main() {
  struct sock_queue queue;
  sock_queue_init(&queue);

  // Simulate some traffic
  for (int i = 0; i < TIMEOUT_SEC; i++) {
    sock_queue_insert(&queue, i, "Hello, world!");
  }

  // Extract the traffic
  for (int i = 0; i < TIMEOUT_SEC; i++) {
    int seq_num;
    char data[MAX_QUE_SIZE];
    sock_queue_extract(&queue, &seq_num, data);
    printf("Sequence number: %d, Data: %s\n", seq_num, data);
  }

  return 0;
}