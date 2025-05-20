//Gemma-7B DATASET v1.0 Category: Queue Implementation ; Style: medieval
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Knight {
  int data;
  struct Knight* next;
} Knight;

Knight* createQueue() {
  Knight* head = malloc(sizeof(Knight));
  head->next = NULL;
  return head;
}

void enqueue(Knight* head, int data) {
  Knight* newKnight = malloc(sizeof(Knight));
  newKnight->data = data;
  newKnight->next = NULL;

  if (head->next == NULL) {
    head->next = newKnight;
  } else {
    Knight* tempKnight = head->next;
    while (tempKnight->next != NULL) {
      tempKnight = tempKnight->next;
    }
    tempKnight->next = newKnight;
  }
}

int dequeue(Knight* head) {
  if (head->next == NULL) {
    return -1;
  }

  Knight* tempKnight = head->next;
  head->next = tempKnight->next;
  free(tempKnight);

  return tempKnight->data;
}

int main() {
  Knight* myQueue = createQueue();

  enqueue(myQueue, 10);
  enqueue(myQueue, 20);
  enqueue(myQueue, 30);

  int data = dequeue(myQueue);
  printf("Dequed data: %d\n", data);

  data = dequeue(myQueue);
  printf("Dequed data: %d\n", data);

  data = dequeue(myQueue);
  printf("Dequed data: %d\n", data);

  data = dequeue(myQueue);
  printf("Dequed data: %d\n", data);

  return 0;
}