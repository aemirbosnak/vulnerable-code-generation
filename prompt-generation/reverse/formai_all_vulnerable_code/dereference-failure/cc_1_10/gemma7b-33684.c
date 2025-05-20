//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10
#define MAX_ROOMS 20

typedef struct Guest {
  char name[50];
  int room_num;
  struct Guest* next;
} Guest;

typedef struct Room {
  int room_num;
  int available;
  struct Room* next;
} Room;

Guest* insert_guest(Guest* head) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  printf("Enter guest name: ");
  scanf("%s", new_guest->name);
  printf("Enter room number: ");
  scanf("%d", &new_guest->room_num);
  new_guest->next = head;
  head = new_guest;
  return head;
}

Room* insert_room(Room* head) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  printf("Enter room number: ");
  scanf("%d", &new_room->room_num);
  printf("Enter availability (1/0): ");
  scanf("%d", &new_room->available);
  new_room->next = head;
  head = new_room;
  return head;
}

void print_guests(Guest* head) {
  Guest* current_guest = head;
  while (current_guest) {
    printf("Name: %s, Room Number: %d\n", current_guest->name, current_guest->room_num);
    current_guest = current_guest->next;
  }
}

void print_rooms(Room* head) {
  Room* current_room = head;
  while (current_room) {
    printf("Room Number: %d, Available: %d\n", current_room->room_num, current_room->available);
    current_room = current_room->next;
  }
}

int main() {
  Guest* guests = NULL;
  Room* rooms = NULL;

  // Insert guests and rooms
  insert_guest(guests);
  insert_guest(guests);
  insert_room(rooms);
  insert_room(rooms);

  // Print guests and rooms
  print_guests(guests);
  print_rooms(rooms);

  return 0;
}