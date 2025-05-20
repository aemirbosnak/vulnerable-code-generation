//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct guest {
  char *name;
  int room_number;
  int nights_staying;
  float bill;
};

struct hotel {
  char *name;
  int num_rooms;
  struct guest *guests;
};

int main() {
  // Create a hotel
  struct hotel hotel = {
    .name = "The Dreamatorium",
    .num_rooms = 10,
    .guests = NULL,
  };

  // Add some guests to the hotel
  struct guest guest1 = {
    .name = "Alice",
    .room_number = 1,
    .nights_staying = 3,
    .bill = 100.0f,
  };

  struct guest guest2 = {
    .name = "Bob",
    .room_number = 2,
    .nights_staying = 2,
    .bill = 75.0f,
  };

  hotel.guests = realloc(hotel.guests, sizeof(struct guest) * 2);
  hotel.guests[0] = guest1;
  hotel.guests[1] = guest2;

  // Print the hotel's information
  printf("Hotel: %s\n", hotel.name);
  printf("Number of rooms: %d\n", hotel.num_rooms);

  // Print the guests' information
  for (int i = 0; i < 2; i++) {
    printf("Guest: %s\n", hotel.guests[i].name);
    printf("Room number: %d\n", hotel.guests[i].room_number);
    printf("Nights staying: %d\n", hotel.guests[i].nights_staying);
    printf("Bill: %f\n", hotel.guests[i].bill);
  }

  return 0;
}