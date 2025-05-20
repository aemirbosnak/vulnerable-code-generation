//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 20

typedef struct guest {
  char name[50];
  int room_no;
  int num_nights;
  struct guest* next;
} guest;

typedef struct room {
  int no;
  int capacity;
  struct room* next;
} room;

guest* insert_guest(guest* head) {
  guest* new_guest = (guest*)malloc(sizeof(guest));
  printf("Enter guest name: ");
  scanf("%s", new_guest->name);
  printf("Enter room number: ");
  scanf("%d", &new_guest->room_no);
  printf("Enter number of nights: ");
  scanf("%d", &new_guest->num_nights);
  new_guest->next = head;
  return new_guest;
}

room* insert_room(room* head) {
  room* new_room = (room*)malloc(sizeof(room));
  printf("Enter room number: ");
  scanf("%d", &new_room->no);
  printf("Enter capacity: ");
  scanf("%d", &new_room->capacity);
  new_room->next = head;
  return new_room;
}

int main() {
  guest* head = NULL;
  room* head_room = NULL;

  // Insert guests and rooms
  insert_guest(head);
  insert_guest(head);
  insert_room(head_room);
  insert_room(head_room);

  // Print guest information
  guest* current_guest = head;
  while (current_guest) {
    printf("Guest name: %s\n", current_guest->name);
    printf("Room number: %d\n", current_guest->room_no);
    printf("Number of nights: %d\n", current_guest->num_nights);
    current_guest = current_guest->next;
  }

  // Print room information
  room* current_room = head_room;
  while (current_room) {
    printf("Room number: %d\n", current_room->no);
    printf("Capacity: %d\n", current_room->capacity);
    current_room = current_room->next;
  }

  return 0;
}