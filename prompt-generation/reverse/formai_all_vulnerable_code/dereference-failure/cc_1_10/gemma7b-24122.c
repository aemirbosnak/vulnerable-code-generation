//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

struct room {
  int number;
  char status;
  int occupied;
  struct room *next;
};

struct hotel {
  struct room *head;
  int num_rooms;
  int occupancy_rate;
};

void insert_room(struct hotel *h, int number) {
  struct room *new_room = malloc(sizeof(struct room));
  new_room->number = number;
  new_room->status = 'O';
  new_room->occupied = 0;
  new_room->next = NULL;

  if (h->head == NULL) {
    h->head = new_room;
  } else {
    struct room *temp = h->head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_room;
  }

  h->num_rooms++;
}

void check_room(struct hotel *h, int number) {
  struct room *temp = h->head;
  while (temp) {
    if (temp->number == number) {
      printf("Room number: %d, Status: %c, Occupied: %d\n", temp->number, temp->status, temp->occupied);
      break;
    }
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Room number not found.\n");
  }
}

int main() {
  struct hotel h;
  h.head = NULL;
  h.num_rooms = 0;
  h.occupancy_rate = 0;

  insert_room(&h, 101);
  insert_room(&h, 102);
  insert_room(&h, 103);

  check_room(&h, 101);
  check_room(&h, 102);
  check_room(&h, 104);

  return 0;
}