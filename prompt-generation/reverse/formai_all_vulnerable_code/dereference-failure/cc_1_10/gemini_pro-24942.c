//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int room_number;
  int nights;
  float price;
} guest;

typedef struct {
  int room_number;
  int capacity;
  float price;
  char type[20];
} room;

typedef struct {
  guest* guests;
  int num_guests;
  room* rooms;
  int num_rooms;
} hotel;

hotel* create_hotel() {
  hotel* h = (hotel*)malloc(sizeof(hotel));
  h->guests = NULL;
  h->num_guests = 0;
  h->rooms = NULL;
  h->num_rooms = 0;
  return h;
}

void add_guest(hotel* h, guest* g) {
  h->guests = (guest*)realloc(h->guests, (h->num_guests + 1) * sizeof(guest));
  h->guests[h->num_guests++] = *g;
}

void add_room(hotel* h, room* r) {
  h->rooms = (room*)realloc(h->rooms, (h->num_rooms + 1) * sizeof(room));
  h->rooms[h->num_rooms++] = *r;
}

void print_hotel(hotel* h) {
  printf("Guests:\n");
  for (int i = 0; i < h->num_guests; i++) {
    printf("  - %s, room %d, %d nights, $%.2f\n", h->guests[i].name, h->guests[i].room_number, h->guests[i].nights, h->guests[i].price);
  }
  printf("Rooms:\n");
  for (int i = 0; i < h->num_rooms; i++) {
    printf("  - Room %d, capacity %d, $%.2f, type %s\n", h->rooms[i].room_number, h->rooms[i].capacity, h->rooms[i].price, h->rooms[i].type);
  }
}

int main() {
  hotel* h = create_hotel();

  guest g1 = {"John Smith", 101, 3, 120.00};
  add_guest(h, &g1);

  guest g2 = {"Jane Doe", 102, 2, 100.00};
  add_guest(h, &g2);

  room r1 = {101, 2, 120.00, "Standard"};
  add_room(h, &r1);

  room r2 = {102, 4, 150.00, "Deluxe"};
  add_room(h, &r2);

  print_hotel(h);

  return 0;
}