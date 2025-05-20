//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int temperature;
  struct Node* next;
};

void insertNode(struct Node** head, int temperature) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->temperature = temperature;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    (*head)->next = newNode;
  }
}

int convertTemperature(struct Node* head, int targetTemperature) {
  struct Node* current = head;
  while (current) {
    if (current->temperature == targetTemperature) {
      return 1;
    } else if (current->temperature < targetTemperature) {
      current = current->next;
    } else {
      return 0;
    }
  }

  return 0;
}

int main() {
  struct Node* head = NULL;
  insertNode(&head, 20);
  insertNode(&head, 30);
  insertNode(&head, 40);
  insertNode(&head, 50);

  if (convertTemperature(head, 35) == 1) {
    printf("Temperature found!\n");
  } else {
    printf("Temperature not found.\n");
  }

  return 0;
}