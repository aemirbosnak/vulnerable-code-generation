//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

#define MAX_ITEMS 10

typedef struct item {
  int item_id;
  int quantity;
  struct item* next;
} item;

item* insert_item(item* head, int item_id, int quantity) {
  item* new_item = malloc(sizeof(item));
  new_item->item_id = item_id;
  new_item->quantity = quantity;
  new_item->next = NULL;

  if (head == NULL) {
    head = new_item;
  } else {
    item* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_item;
  }

  return head;
}

void greedy_algorithm(item* head) {
  item* current = head;
  int total_quantity = 0;
  while (current) {
    total_quantity += current->quantity;
    current = current->next;
  }

  int items_taken = 0;
  current = head;
  while (total_quantity > items_taken) {
    int item_quantity = current->quantity;
    if (item_quantity > items_taken) {
      items_taken += item_quantity;
    } else {
      items_taken += item_quantity;
      current = current->next;
    }
  }

  printf("Total items taken: %d\n", items_taken);
}

int main() {
  item* head = insert_item(NULL, 1, 5);
  insert_item(head, 2, 3);
  insert_item(head, 3, 2);
  insert_item(head, 4, 4);
  insert_item(head, 5, 1);

  greedy_algorithm(head);

  return 0;
}