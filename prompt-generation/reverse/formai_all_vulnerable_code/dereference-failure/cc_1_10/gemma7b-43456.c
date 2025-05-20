//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
  struct Node* next;
  char data;
} Node;

void insert_at_tail(Node** head, char data) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    ((*head)->next = newNode);
    *head = newNode;
  }
}

int main() {
  Node* head = NULL;
  char buffer[MAX_BUFFER_SIZE];

  time_t start_time = time(NULL);

  // Type as fast as you can
  fgets(buffer, MAX_BUFFER_SIZE, stdin);

  time_t end_time = time(NULL);

  // Calculate the time taken
  int time_taken = end_time - start_time;

  // Insert the user's text into the linked list
  for (int i = 0; buffer[i] != '\0'; i++) {
    insert_at_tail(&head, buffer[i]);
  }

  // Print the user's text
  printf("Your text: ");
  for (Node* node = head; node; node = node->next) {
    printf("%c ", node->data);
  }

  printf("\nTime taken: %d seconds", time_taken);

  return 0;
}