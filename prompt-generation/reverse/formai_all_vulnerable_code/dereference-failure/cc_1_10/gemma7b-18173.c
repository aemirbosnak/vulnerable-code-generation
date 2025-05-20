//Gemma-7B DATASET v1.0 Category: Sorting ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct SurrealistNode {
  int data;
  struct SurrealistNode* next;
  struct SurrealistNode* prev;
} SurrealistNode;

void surrealSort(SurrealistNode** head) {
  SurrealistNode* current = *head;
  SurrealistNode* previous = NULL;

  while (current) {
    SurrealistNode* next = current->next;
    int current_data = current->data;
    current->next = previous;
    previous = current;
    current = next;

    if (previous) {
      int previous_data = previous->data;
      if (current_data < previous_data) {
        int temp = current_data;
        current_data = previous_data;
        previous_data = temp;
      }
    }
  }

  *head = previous;
}

int main() {
  SurrealistNode* head = NULL;
  SurrealistNode* newNode = malloc(sizeof(SurrealistNode));
  newNode->data = 5;
  head = newNode;

  newNode = malloc(sizeof(SurrealistNode));
  newNode->data = 2;
  newNode->next = head;
  head = newNode;

  newNode = malloc(sizeof(SurrealistNode));
  newNode->data = 8;
  newNode->next = head;
  head = newNode;

  newNode = malloc(sizeof(SurrealistNode));
  newNode->data = 3;
  newNode->next = head;
  head = newNode;

  surrealSort(&head);

  printf("Sorted list:");
  SurrealistNode* current = head;
  while (current) {
    printf(" %d", current->data);
    current = current->next;
  }

  return 0;
}