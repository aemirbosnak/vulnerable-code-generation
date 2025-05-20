//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct room_t {
  char name[20];
  struct room_t* next;
  struct item_t* items;
} room_t;

typedef struct item_t {
  char name[20];
  int quantity;
  struct item_t* next;
} item_t;

room_t* generate_room(int num) {
  room_t* room = malloc(sizeof(room_t));
  room->name[0] = 'A' + num;
  room->next = NULL;
  room->items = NULL;

  for (int i = 0; i < rand() % MAX_ITEMS; i++) {
    item_t* item = malloc(sizeof(item_t));
    item->name[0] = 'a' + i;
    item->quantity = rand() % 5 + 1;
    item->next = room->items;
    room->items = item;
  }

  return room;
}

int main() {
  room_t* rooms = NULL;
  for (int i = 0; i < MAX_ROOMS; i++) {
    rooms = generate_room(i);
  }

  // Traverse the rooms and print items
  for (room_t* room = rooms; room; room = room->next) {
    printf("Room: %s\n", room->name);
    for (item_t* item = room->items; item; item = item->next) {
      printf("Item: %s, Quantity: %d\n", item->name, item->quantity);
    }
  }

  return 0;
}