//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

struct room {
  int number;
  char type;
  int available;
  struct room* next;
};

struct guest {
  char name[20];
  int room_number;
  struct guest* next;
};

void insert_room(struct room** head, int number, char type, int available) {
  struct room* new_room = (struct room*)malloc(sizeof(struct room));
  new_room->number = number;
  new_room->type = type;
  new_room->available = available;
  new_room->next = NULL;

  if (*head == NULL) {
    *head = new_room;
  } else {
    (*head)->next = new_room;
  }
}

void insert_guest(struct guest** head, char name, int room_number) {
  struct guest* new_guest = (struct guest*)malloc(sizeof(struct guest));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->next = NULL;

  if (*head == NULL) {
    *head = new_guest;
  } else {
    (*head)->next = new_guest;
  }
}

void check_availability(struct room* head, int room_number) {
  while (head) {
    if (head->number == room_number && head->available) {
      printf("Room %d is available.\n", room_number);
      return;
    }
    head = head->next;
  }

  printf("Room %d is not available.\n", room_number);
}

void list_guests(struct guest* head) {
  while (head) {
    printf("Guest: %s, Room number: %d\n", head->name, head->room_number);
    head = head->next;
  }
}

int main() {
  struct room* head_room = NULL;
  struct guest* head_guest = NULL;

  insert_room(&head_room, 101, 'A', 1);
  insert_room(&head_room, 102, 'B', 0);
  insert_room(&head_room, 103, 'A', 1);
  insert_room(&head_room, 104, 'B', 0);

  insert_guest(&head_guest, "John Doe", 101);
  insert_guest(&head_guest, "Jane Doe", 102);
  insert_guest(&head_guest, "Peter Pan", 103);

  check_availability(head_room, 102);
  list_guests(head_guest);

  return 0;
}