//Gemma-7B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBER_OF_BAGS 10

typedef struct Bag {
  char* name;
  int weight;
  struct Bag* next;
} Bag;

void insert_bag(Bag** head, char* name, int weight) {
  Bag* new_bag = (Bag*)malloc(sizeof(Bag));
  new_bag->name = name;
  new_bag->weight = weight;
  new_bag->next = NULL;

  if (*head == NULL) {
    *head = new_bag;
  } else {
    (*head)->next = new_bag;
  }
}

void handle_baggage(Bag* head) {
  printf("List of bags:\n");
  while (head) {
    printf("Name: %s, Weight: %d\n", head->name, head->weight);
    head = head->next;
  }

  printf("Total weight of baggage: %d\n", total_weight(head));
}

int total_weight(Bag* head) {
  int total_weight = 0;
  while (head) {
    total_weight += head->weight;
    head = head->next;
  }
  return total_weight;
}

int main() {
  Bag* head = NULL;

  insert_bag(&head, "John Doe's Bag", 20);
  insert_bag(&head, "Jane Doe's Bag", 15);
  insert_bag(&head, "Peter Pan's Bag", 30);

  handle_baggage(head);

  return 0;
}