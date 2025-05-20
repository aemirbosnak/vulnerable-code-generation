//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ROOM_NUMBER_LIMIT 100
#define GUEST_NAME_LENGTH 20

struct Room {
  int room_number;
  char guest_name[GUEST_NAME_LENGTH];
  int days_stayed;
  struct Room* next;
};

struct Room* insert_room(struct Room* head, int room_number, char* guest_name, int days_stayed) {
  struct Room* new_room = (struct Room*)malloc(sizeof(struct Room));
  new_room->room_number = room_number;
  strcpy(new_room->guest_name, guest_name);
  new_room->days_stayed = days_stayed;
  new_room->next = NULL;

  if (head == NULL) {
    head = new_room;
  } else {
    struct Room* current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_room;
  }

  return head;
}

struct Room* search_room(struct Room* head, int room_number) {
  struct Room* current = head;
  while (current) {
    if (current->room_number == room_number) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

void check_out(struct Room* head, int room_number) {
  struct Room* room = search_room(head, room_number);
  if (room) {
    free(room);
    room = NULL;
  }
}

int main() {
  struct Room* head = NULL;

  // Insert rooms
  insert_room(head, 101, "John Doe", 3);
  insert_room(head, 102, "Jane Doe", 2);
  insert_room(head, 103, "Peter Pan", 4);

  // Search for room
  struct Room* room = search_room(head, 102);
  if (room) {
    printf("Guest name: %s\n", room->guest_name);
    printf("Days stayed: %d\n", room->days_stayed);
  }

  // Check out room
  check_out(head, 101);

  // Search for room after check out
  room = search_room(head, 101);
  if (room) {
    printf("Error: Room is still occupied.\n");
  }

  return 0;
}