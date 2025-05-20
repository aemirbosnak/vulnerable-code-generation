//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_no;
  struct Guest* next;
} Guest;

typedef struct Room {
  int room_no;
  int occupancy;
  struct Room* next;
} Room;

Guest* head_guest = NULL;
Room* head_room = NULL;

void add_guest(char* name, int room_no) {
  Guest* new_guest = malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_no = room_no;
  new_guest->next = head_guest;
  head_guest = new_guest;
}

void add_room(int room_no, int occupancy) {
  Room* new_room = malloc(sizeof(Room));
  new_room->room_no = room_no;
  new_room->occupancy = occupancy;
  new_room->next = head_room;
  head_room = new_room;
}

int find_guest(char* name) {
  Guest* current_guest = head_guest;
  while (current_guest) {
    if (strcmp(current_guest->name, name) == 0) {
      return current_guest->room_no;
    }
    current_guest = current_guest->next;
  }
  return -1;
}

int main() {
  add_guest("Sherlock Holmes", 1);
  add_guest("John Watson", 2);
  add_guest("Inspector Lestrade", 3);
  add_room(1, 2);
  add_room(2, 1);
  add_room(3, 0);

  int room_no = find_guest("Sherlock Holmes");
  if (room_no != -1) {
    printf("Mr. Holmes is staying in room %d.\n", room_no);
  } else {
    printf("Mr. Holmes is not found.\n");
  }

  return 0;
}