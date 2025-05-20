//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Item {
  int item_id;
  double value;
  struct Item* next;
} Item;

int main() {
  Item* head = NULL;
  Item* tail = NULL;

  // Simulate a futuristic space hopper
  int num_items = 0;
  while (num_items < MAX_SIZE) {
    double value = rand() % 1000;
    Item* new_item = (Item*)malloc(sizeof(Item));
    new_item->item_id = num_items;
    new_item->value = value;
    new_item->next = NULL;

    if (head == NULL) {
      head = new_item;
      tail = new_item;
    } else {
      tail->next = new_item;
      tail = new_item;
    }

    num_items++;
  }

  // Greedy Algorithm - Sort items by value in descending order
  tail = head;
  while (tail) {
    Item* current = tail;
    Item* previous = NULL;
    for (Item* comparison = head; comparison; comparison = comparison->next) {
      if (comparison->value > current->value) {
        current->value = comparison->value;
        previous = comparison;
      }
    }

    if (previous) {
      previous->next = current->next;
      tail = current->next;
    } else {
      tail = NULL;
    }
  }

  // Print sorted items
  tail = head;
  while (tail) {
    printf("%d: %.2lf\n", tail->item_id, tail->value);
    tail = tail->next;
  }

  return 0;
}