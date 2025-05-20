//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

struct guest_record {
  char name[50];
  int room_number;
  struct guest_record* next;
};

struct hotel_management {
  struct guest_record* head;
  int num_guests;
  int rooms_available;
  struct hotel_management* next;
};

void insert_guest(struct hotel_management* hotel, char* name, int room_number) {
  struct guest_record* new_guest = malloc(sizeof(struct guest_record));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->next = NULL;

  if (hotel->head == NULL) {
    hotel->head = new_guest;
  } else {
    struct guest_record* current = hotel->head;
    while (current->next) {
      current = current->next;
    }
    current->next = new_guest;
  }

  hotel->num_guests++;
  hotel->rooms_available--;
}

void check_in(struct hotel_management* hotel, char* name) {
  struct guest_record* guest = hotel->head;

  while (guest) {
    if (strcmp(guest->name, name) == 0) {
      printf("Room number: %d\n", guest->room_number);
      return;
    }
    guest = guest->next;
  }

  printf("Guest not found.\n");
}

int main() {
  struct hotel_management* hotel = malloc(sizeof(struct hotel_management));
  hotel->head = NULL;
  hotel->num_guests = 0;
  hotel->rooms_available = 100;

  insert_guest(hotel, "John Doe", 101);
  insert_guest(hotel, "Jane Doe", 102);
  insert_guest(hotel, "Peter Pan", 103);

  check_in(hotel, "John Doe");

  return 0;
}