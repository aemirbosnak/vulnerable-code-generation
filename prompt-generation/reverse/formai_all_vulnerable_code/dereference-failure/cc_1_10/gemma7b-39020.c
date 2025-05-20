//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_NUM 10

struct Room {
  char room_number[6];
  char occupancy;
  char type;
  int price;
  struct Room* next;
};

struct Room* create_room(char* number, char occupancy, char type, int price) {
  struct Room* room = (struct Room*)malloc(sizeof(struct Room));
  strcpy(room->room_number, number);
  room->occupancy = occupancy;
  room->type = type;
  room->price = price;
  room->next = NULL;
  return room;
}

void print_room(struct Room* room) {
  printf("Room number: %s\n", room->room_number);
  printf("Occupancy: %c\n", room->occupancy);
  printf("Type: %c\n", room->type);
  printf("Price: %d\n", room->price);
}

struct Room* find_room(struct Room* head, char* number) {
  while (head) {
    if (strcmp(head->room_number, number) == 0) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

int main() {
  struct Room* head = NULL;
  head = create_room("101", 'O', 'A', 100);
  head = create_room("102", 'A', 'B', 150);
  head = create_room("103", 'C', 'C', 200);

  print_room(head);

  struct Room* room = find_room(head, "102");
  print_room(room);

  return 0;
}