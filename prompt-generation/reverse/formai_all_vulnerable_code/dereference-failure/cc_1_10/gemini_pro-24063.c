//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hotel data structure
typedef struct hotel {
  char *name;
  int num_rooms;
  int num_floors;
  int *room_prices;
} hotel_t;

// Guest data structure
typedef struct guest {
  char *name;
  int room_number;
  int num_nights;
  float bill;
} guest_t;

// Function to create a new hotel
hotel_t *create_hotel(char *name, int num_rooms, int num_floors) {
  hotel_t *hotel = malloc(sizeof(hotel_t));
  hotel->name = strdup(name);
  hotel->num_rooms = num_rooms;
  hotel->num_floors = num_floors;
  hotel->room_prices = malloc(sizeof(int) * num_rooms);
  for (int i = 0; i < num_rooms; i++) {
    hotel->room_prices[i] = rand() % 1000 + 1; // Random price between $1 and $1000
  }
  return hotel;
}

// Function to check in a guest
guest_t *check_in_guest(hotel_t *hotel, char *name, int room_number, int num_nights) {
  guest_t *guest = malloc(sizeof(guest_t));
  guest->name = strdup(name);
  guest->room_number = room_number;
  guest->num_nights = num_nights;
  guest->bill = hotel->room_prices[room_number - 1] * num_nights; // Calculate bill
  return guest;
}

// Function to check out a guest
void check_out_guest(hotel_t *hotel, guest_t *guest) {
  free(guest->name);
  free(guest);
}

// Function to print hotel information
void print_hotel_info(hotel_t *hotel) {
  printf("Hotel name: %s\n", hotel->name);
  printf("Number of rooms: %d\n", hotel->num_rooms);
  printf("Number of floors: %d\n", hotel->num_floors);
  printf("Room prices:\n");
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room %d: $%d\n", i + 1, hotel->room_prices[i]);
  }
}

// Function to print guest information
void print_guest_info(guest_t *guest) {
  printf("Guest name: %s\n", guest->name);
  printf("Room number: %d\n", guest->room_number);
  printf("Number of nights: %d\n", guest->num_nights);
  printf("Bill: $%.2f\n", guest->bill);
}

int main() {
  // Create a new hotel
  hotel_t *hotel = create_hotel("The Neon Palace", 100, 20);

  // Check in a few guests
  guest_t *guest1 = check_in_guest(hotel, "Neo", 101, 3);
  guest_t *guest2 = check_in_guest(hotel, "Trinity", 202, 5);

  // Print hotel and guest information
  print_hotel_info(hotel);
  printf("\n");
  print_guest_info(guest1);
  printf("\n");
  print_guest_info(guest2);
  printf("\n");

  // Check out the guests
  check_out_guest(hotel, guest1);
  check_out_guest(hotel, guest2);

  // Free the hotel memory
  free(hotel->name);
  free(hotel->room_prices);
  free(hotel);

  return 0;
}