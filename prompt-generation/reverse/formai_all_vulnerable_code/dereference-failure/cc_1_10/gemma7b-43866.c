//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_number;
  struct Guest* next;
} Guest;

typedef struct Room {
  int number;
  char status;
  struct Room* next;
} Room;

Guest* head_guest = NULL;
Room* head_room = NULL;

void insert_guest(char* name, int room_number) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->next = NULL;

  if (head_guest == NULL) {
    head_guest = new_guest;
  } else {
    Guest* temp = head_guest;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_guest;
  }
}

void insert_room(int number, char status) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  new_room->number = number;
  new_room->status = status;
  new_room->next = NULL;

  if (head_room == NULL) {
    head_room = new_room;
  } else {
    Room* temp = head_room;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_room;
  }
}

void print_guests() {
  Guest* temp = head_guest;
  while (temp) {
    printf("Name: %s, Room Number: %d\n", temp->name, temp->room_number);
    temp = temp->next;
  }
}

void print_rooms() {
  Room* temp = head_room;
  while (temp) {
    printf("Number: %d, Status: %c\n", temp->number, temp->status);
    temp = temp->next;
  }
}

int main() {
  insert_guest("John Doe", 1);
  insert_guest("Jane Doe", 2);
  insert_guest("Peter Pan", 3);
  insert_room(4, 'A');
  insert_room(5, 'B');
  insert_room(6, 'C');

  print_guests();
  print_rooms();

  return 0;
}