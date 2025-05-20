//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 50
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_num;
  struct Guest* next;
} Guest;

typedef struct Room {
  int room_num;
  char status;
  struct Room* next;
} Room;

Guest* head_guest = NULL;
Room* head_room = NULL;

void add_guest(char* name, int room_num) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_num = room_num;
  new_guest->next = head_guest;
  head_guest = new_guest;
}

void add_room(int room_num, char status) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  new_room->room_num = room_num;
  new_room->status = status;
  new_room->next = head_room;
  head_room = new_room;
}

void print_guests() {
  Guest* current_guest = head_guest;
  while (current_guest) {
    printf("%s in room %d\n", current_guest->name, current_guest->room_num);
    current_guest = current_guest->next;
  }
}

void print_rooms() {
  Room* current_room = head_room;
  while (current_room) {
    printf("Room %d: %c\n", current_room->room_num, current_room->status);
    current_room = current_room->next;
  }
}

int main() {
  add_guest("John Doe", 101);
  add_guest("Jane Doe", 102);
  add_guest("Peter Pan", 103);
  add_room(101, 'O');
  add_room(102, 'A');
  add_room(103, 'B');
  print_guests();
  print_rooms();
  return 0;
}