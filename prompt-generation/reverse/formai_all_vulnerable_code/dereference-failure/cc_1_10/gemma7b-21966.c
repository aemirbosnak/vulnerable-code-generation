//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROOM_NUMBER_MAX 99

typedef struct Room {
  int number;
  char status;
  char guest_name[50];
  struct Room* next;
} Room;

typedef struct Hotel {
  Room* head;
  int num_rooms;
  char name[50];
} Hotel;

Hotel* hotel_create(char* name, int num_rooms) {
  Hotel* h = malloc(sizeof(Hotel));
  h->head = NULL;
  h->num_rooms = num_rooms;
  strcpy(h->name, name);
  return h;
}

void room_add(Hotel* h, int number, char status, char* guest_name) {
  Room* r = malloc(sizeof(Room));
  r->number = number;
  r->status = status;
  strcpy(r->guest_name, guest_name);
  r->next = h->head;
  h->head = r;
  h->num_rooms++;
}

void room_status(Hotel* h, int number) {
  Room* r = h->head;
  while (r) {
    if (r->number == number) {
      printf("Room number: %d\n", r->number);
      printf("Status: %c\n", r->status);
      printf("Guest name: %s\n", r->guest_name);
      break;
    }
    r = r->next;
  }
  if (r == NULL) {
    printf("Room not found.\n");
  }
}

int main() {
  Hotel* h = hotel_create("The Surrealist Hotel", 50);
  room_add(h, 1, 'O', "Alice");
  room_add(h, 3, 'F', "Bob");
  room_status(h, 1);
  room_status(h, 3);
  return 0;
}