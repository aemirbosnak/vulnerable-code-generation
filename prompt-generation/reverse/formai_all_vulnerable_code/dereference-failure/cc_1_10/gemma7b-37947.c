//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUEST_ROOMS 10

typedef struct Room {
  int room_no;
  char guest_name[50];
  char room_type;
  int no_of_occupants;
  struct Room* next;
} Room;

Room* insert_room(Room* head) {
  Room* new_room = (Room*)malloc(sizeof(Room));

  new_room->room_no = head->room_no + 1;
  new_room->guest_name[0] = '\0';
  new_room->room_type = 'A';
  new_room->no_of_occupants = 0;
  new_room->next = NULL;

  head->next = new_room;

  return new_room;
}

void print_room(Room* head) {
  Room* current_room = head;

  while (current_room) {
    printf("Room No: %d\n", current_room->room_no);
    printf("Guest Name: %s\n", current_room->guest_name);
    printf("Room Type: %c\n", current_room->room_type);
    printf("No. of Occupants: %d\n", current_room->no_of_occupants);
    printf("\n");
    current_room = current_room->next;
  }
}

int main() {
  Room* head = (Room*)malloc(sizeof(Room));
  head->room_no = 1;
  head->guest_name[0] = '\0';
  head->room_type = 'A';
  head->no_of_occupants = 0;
  head->next = NULL;

  insert_room(head);
  insert_room(head);
  insert_room(head);

  print_room(head);

  return 0;
}