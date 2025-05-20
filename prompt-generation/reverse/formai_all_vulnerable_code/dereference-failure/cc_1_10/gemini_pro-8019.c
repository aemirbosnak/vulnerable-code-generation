//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel details
typedef struct Hotel {
  char name[50];
  char address[100];
  int num_rooms;
  int num_occupied;
  float avg_price;
} Hotel;

// Function to create a new hotel
Hotel* create_hotel(char* name, char* address, int num_rooms, float avg_price) {
  Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
  strcpy(hotel->name, name);
  strcpy(hotel->address, address);
  hotel->num_rooms = num_rooms;
  hotel->num_occupied = 0;
  hotel->avg_price = avg_price;
  return hotel;
}

// Function to check in a guest
void check_in(Hotel* hotel) {
  if (hotel->num_occupied < hotel->num_rooms) {
    hotel->num_occupied++;
  } else {
    printf("Sorry, the hotel is full.\n");
  }
}

// Function to check out a guest
void check_out(Hotel* hotel) {
  if (hotel->num_occupied > 0) {
    hotel->num_occupied--;
  } else {
    printf("Sorry, there are no guests checked in.\n");
  }
}

// Function to print hotel details
void print_hotel_details(Hotel* hotel) {
  printf("Hotel Name: %s\n", hotel->name);
  printf("Hotel Address: %s\n", hotel->address);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  printf("Number of Rooms Occupied: %d\n", hotel->num_occupied);
  printf("Average Price: %.2f\n", hotel->avg_price);
}

int main() {
  // Create a new hotel
  Hotel* hotel = create_hotel("The Grand Hotel", "123 Main Street", 100, 150.00);

  // Check in a guest
  check_in(hotel);

  // Print hotel details
  print_hotel_details(hotel);

  // Check out a guest
  check_out(hotel);

  // Print hotel details
  print_hotel_details(hotel);

  return 0;
}