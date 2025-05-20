//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct Room {
  char name[20];
  struct Room* next;
  struct Item* items;
} Room;

typedef struct Item {
  char name[20];
  int quantity;
  struct Item* next;
} Item;

void generate_map(Room** head) {
  int num_rooms = rand() % MAX_ROOMS + 1;
  for (int i = 0; i < num_rooms; i++) {
    Room* new_room = malloc(sizeof(Room));
    new_room->name[0] = 'A' + i;
    new_room->next = NULL;
    new_room->items = NULL;

    if (*head == NULL) {
      *head = new_room;
    } else {
      (*head)->next = new_room;
    }
  }
}

void generate_items(Item** head) {
  int num_items = rand() % MAX_ITEMS + 1;
  for (int i = 0; i < num_items; i++) {
    Item* new_item = malloc(sizeof(Item));
    new_item->name[0] = 'a' + i;
    new_item->quantity = rand() % 10 + 1;
    new_item->next = NULL;

    if (*head == NULL) {
      *head = new_item;
    } else {
      (*head)->next = new_item;
    }
  }
}

int main() {
  Room* head = NULL;
  generate_map(&head);

  Item* items = NULL;
  generate_items(&items);

  // Traverse the map and items
  for (Room* room = head; room; room = room->next) {
    printf("Room: %s\n", room->name);
    for (Item* item = room->items; item; item = item->next) {
      printf("Item: %s, Quantity: %d\n", item->name, item->quantity);
    }
  }

  return 0;
}