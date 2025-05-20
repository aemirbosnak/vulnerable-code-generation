//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct room {
  int number;
  char type;
  double price;
  int occupied;
} room;

typedef struct hotel {
  char name[50];
  int num_rooms;
  room *rooms;
} hotel;

hotel *create_hotel(char *name, int num_rooms) {
  hotel *h = malloc(sizeof(hotel));
  strcpy(h->name, name);
  h->num_rooms = num_rooms;
  h->rooms = malloc(sizeof(room) * num_rooms);
  return h;
}

void destroy_hotel(hotel *h) {
  free(h->rooms);
  free(h);
}

void print_hotel(hotel *h) {
  printf("Hotel: %s\n", h->name);
  printf("Number of rooms: %d\n", h->num_rooms);
  for (int i = 0; i < h->num_rooms; i++) {
    printf("Room %d: type %c, price %f, occupied %d\n", h->rooms[i].number, h->rooms[i].type, h->rooms[i].price, h->rooms[i].occupied);
  }
}

void check_in(hotel *h, int room_number) {
  if (room_number < 1 || room_number > h->num_rooms) {
    printf("Invalid room number\n");
    return;
  }
  if (h->rooms[room_number - 1].occupied) {
    printf("Room is already occupied\n");
    return;
  }
  h->rooms[room_number - 1].occupied = 1;
}

void check_out(hotel *h, int room_number) {
  if (room_number < 1 || room_number > h->num_rooms) {
    printf("Invalid room number\n");
    return;
  }
  if (!h->rooms[room_number - 1].occupied) {
    printf("Room is already empty\n");
    return;
  }
  h->rooms[room_number - 1].occupied = 0;
}

int main() {
  hotel *h = create_hotel("The Grand Hotel", 100);

  // Print the hotel
  print_hotel(h);

  // Check in to room 10
  check_in(h, 10);

  // Print the hotel again
  print_hotel(h);

  // Check out of room 10
  check_out(h, 10);

  // Print the hotel one last time
  print_hotel(h);

  // Destroy the hotel
  destroy_hotel(h);

  return 0;
}