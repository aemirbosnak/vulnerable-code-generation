//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: retro
// Ye olde Mailing List Manager
#include <stdio.h>
#include <stdlib.h>

// A missive, verily a message to be sent
typedef struct {
  char *from;
  char *to;
  char *subject;
  char *body;
} Missive;

// A queue of missives, a line of messages awaiting dispatch
typedef struct {
  Missive **messages;
  int head;
  int tail;
  int size;
} Queue;

// Create a new missive
Missive *create_missive(char *from, char *to, char *subject, char *body) {
  Missive *missive = malloc(sizeof(Missive));
  missive->from = from;
  missive->to = to;
  missive->subject = subject;
  missive->body = body;
  return missive;
}

// Create a new queue
Queue *create_queue(int size) {
  Queue *queue = malloc(sizeof(Queue));
  queue->messages = malloc(sizeof(Missive *) * size);
  queue->head = 0;
  queue->tail = 0;
  queue->size = size;
  return queue;
}

// Enqueue a missive
void enqueue(Queue *queue, Missive *missive) {
  if ((queue->tail + 1) % queue->size == queue->head) {
    printf("Queue is full, cannot enqueue missive\n");
    return;
  }
  queue->messages[queue->tail] = missive;
  queue->tail = (queue->tail + 1) % queue->size;
}

// Dequeue a missive
Missive *dequeue(Queue *queue) {
  if (queue->head == queue->tail) {
    printf("Queue is empty, cannot dequeue missive\n");
    return NULL;
  }
  Missive *missive = queue->messages[queue->head];
  queue->head = (queue->head + 1) % queue->size;
  return missive;
}

// Send a missive
int send_missive(Missive *missive) {
  printf("Sending missive:\n");
  printf("From: %s\n", missive->from);
  printf("To: %s\n", missive->to);
  printf("Subject: %s\n", missive->subject);
  printf("Body: %s\n", missive->body);
  return 0;
}

// Main function
int main() {
  // Create a queue of missives
  Queue *queue = create_queue(10);

  // Enqueue some missives
  enqueue(queue, create_missive("John", "Mary", "Hello", "How are you doing?"));
  enqueue(queue, create_missive("Mary", "John", "Re: Hello", "I'm doing well, thanks"));

  // Send missives until the queue is empty
  while (queue->head != queue->tail) {
    send_missive(dequeue(queue));
  }

  // Free the queue and its missives
  free(queue->messages);
  free(queue);

  return 0;
}