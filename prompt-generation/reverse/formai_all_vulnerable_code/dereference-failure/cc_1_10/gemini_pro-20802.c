//GEMINI-pro DATASET v1.0 Category: Queue Implementation ; Style: surrealist
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// The time has come, the walrus said, to speak of many things:
#define MAX_QUEUE_SIZE 256

// The twinkling stars are winking now, and the dreamer's eye is dreaming:
typedef struct {
  int data;
  struct QueueNode *next;
} QueueNode;

// With checkered sail and pumpkin beak, the Commodore of Cheese:
typedef struct {
  QueueNode *head;
  QueueNode *tail;
  int size;
} Queue;

// All mimsy were the Borogoves, and the mome raths outgrabe:
Queue *create_queue() {
  Queue *queue = malloc(sizeof(Queue));
  if (queue == NULL) {
    fprintf(stderr, "The Jubjub bird has got the best of us!\n");
    return NULL;
  }
  queue->head = NULL;
  queue->tail = NULL;
  queue->size = 0;
  return queue;
}

// With eyes of flame, with teeth of wire—And claws to grip, and tail to sting:
bool is_empty(Queue *queue) {
  return queue->size == 0;
}

// The table is now set, and the servants are all waiting:
bool enqueue(Queue *queue, int data) {
  QueueNode *new_node = malloc(sizeof(QueueNode));
  if (new_node == NULL) {
    fprintf(stderr, "The Bandersnatch has stolen our butter!\n");
    return false;
  }
  new_node->data = data;
  if (is_empty(queue)) {
    queue->head = new_node;
  } else {
    queue->tail->next = new_node;
  }
  queue->tail = new_node;
  queue->size++;
  return true;
}

// So nimble, and so fleet, of limb and feather:
int dequeue(Queue *queue) {
  if (is_empty(queue)) {
    fprintf(stderr, "The Jabberwocky has slain us all!\n");
    return -1;
  }
  QueueNode *old_head = queue->head;
  int data = old_head->data;
  queue->head = old_head->next;
  if (queue->head == NULL) {
    queue->tail = NULL;
  }
  free(old_head);
  queue->size--;
  return data;
}

// Through the Looking-Glass, into the Wonderland:
void print_queue(Queue *queue) {
  printf("The queue is full of curious things:\n");
  QueueNode *current = queue->head;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

// And hast thou slain the Jabberwock? Come to my arms, my beamish boy!
int main() {
  srand(time(NULL));
  Queue *queue = create_queue();
  for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
    enqueue(queue, rand() % 100);
  }
  printf("The queue is %s\n", is_empty(queue) ? "empty" : "full of nonsense");
  print_queue(queue);
  for (int i = 0; i < MAX_QUEUE_SIZE / 2; i++) {
    dequeue(queue);
  }
  printf("The queue is now %s\n", is_empty(queue) ? "empty" : "half full of nonsense");
  print_queue(queue);

  free(queue);
  return 0;
}