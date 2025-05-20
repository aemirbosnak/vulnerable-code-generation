//FormAI DATASET v1.0 Category: Queue Implementation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

// A queue node
struct QueueNode {
  int data;
  struct QueueNode* next;
};

// The queue structure
struct Queue {
  struct QueueNode *front, *rear;
};

// Create an empty queue
struct Queue* createQueue() {
  struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
  q->front = q->rear = NULL;
  return q;
}

// Add an item to the queue
void enqueue(struct Queue* q, int item) {
  struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
  newNode->data = item;
  newNode->next = NULL;
  if (q->rear == NULL) {
    q->front = q->rear = newNode;
    return;
  }
  q->rear->next = newNode;
  q->rear = newNode;
}

// Remove an item from the queue
void dequeue(struct Queue* q) {
  if (q->front == NULL)
    return;
  struct QueueNode* temp = q->front;
  q->front = q->front->next;
  if (q->front == NULL)
    q->rear = NULL;
  free(temp);
}

// Print the queue
void printQueue(struct Queue* q) {
  struct QueueNode* temp = q->front;
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  printf("Welcome to the Mind-Bending C Queue Implementation program!\n\n");
  
  // Create the queue
  struct Queue* q = createQueue();
  
  printf("You can now add items to the queue using the command 'enqueue <item>'.\n");
  printf("To remove an item from the queue, use the command 'dequeue'.\n");
  printf("To print the current queue, use the command 'print'.\n");
  printf("Use the command 'exit' to exit the program.\n\n");

  while (1) {
    // Read user input
    char input[100];
    printf("> ");
    fgets(input, 100, stdin);

    // Determine user command
    if (strstr(input, "enqueue") != NULL) {
      int item = atoi(strtok(input, " "));
      enqueue(q, item);
      printf("Item '%d' added to the queue.\n\n", item); 
    }
    else if (strstr(input, "dequeue") != NULL) {
      dequeue(q);
      printf("Item removed from the queue.\n\n");
    }
    else if (strstr(input, "print") != NULL) {
      printf("Current queue: ");
      printQueue(q);
      printf("\n");
    }
    else if (strstr(input, "exit") != NULL) {
      printf("Exiting program...\n");
      break;
    }
    else {
      printf("Invalid command. Please try again.\n\n");
    }
  }

  return 0;
}