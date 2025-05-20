//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Poorly named to demonstrate how bad names can be a code smell
typedef struct {
  int id;
  char* name;
  char* address;
  char* phone;
  char* email;
  int num_rooms;
  char** room_types;
  float* room_prices;
  int* room_capacities;
  int num_reservations;
  // Should be a `Reservation` struct, but for brevity...
  int* reservation_ids;
  char** reservation_dates;
  int* reservation_num_guests;
} ShockinglyNamedHotel;

// Create a new hotel
ShockinglyNamedHotel* create_hotel(char* name, char* address, char* phone, char* email) {
  ShockinglyNamedHotel* hotel = malloc(sizeof(ShockinglyNamedHotel));
  hotel->name = strdup(name);
  hotel->address = strdup(address);
  hotel->phone = strdup(phone);
  hotel->email = strdup(email);
  hotel->num_rooms = 0;
  hotel->room_types = NULL;
  hotel->room_prices = NULL;
  hotel->room_capacities = NULL;
  hotel->num_reservations = 0;
  hotel->reservation_ids = NULL;
  hotel->reservation_dates = NULL;
  hotel->reservation_num_guests = NULL;
  return hotel;
}

// Add a room to a hotel
void add_room(ShockinglyNamedHotel* hotel, char* type, float price, int capacity) {
  hotel->num_rooms++;
  hotel->room_types = realloc(hotel->room_types, hotel->num_rooms * sizeof(char*));
  hotel->room_prices = realloc(hotel->room_prices, hotel->num_rooms * sizeof(float));
  hotel->room_capacities = realloc(hotel->room_capacities, hotel->num_rooms * sizeof(int));
  hotel->room_types[hotel->num_rooms - 1] = strdup(type);
  hotel->room_prices[hotel->num_rooms - 1] = price;
  hotel->room_capacities[hotel->num_rooms - 1] = capacity;
}

// Make a reservation at a hotel
int make_reservation(ShockinglyNamedHotel* hotel, char* date, int num_guests) {
  hotel->num_reservations++;
  hotel->reservation_ids = realloc(hotel->reservation_ids, hotel->num_reservations * sizeof(int));
  hotel->reservation_dates = realloc(hotel->reservation_dates, hotel->num_reservations * sizeof(char*));
  hotel->reservation_num_guests = realloc(hotel->reservation_num_guests, hotel->num_reservations * sizeof(int));
  hotel->reservation_ids[hotel->num_reservations - 1] = hotel->num_reservations;
  hotel->reservation_dates[hotel->num_reservations - 1] = strdup(date);
  hotel->reservation_num_guests[hotel->num_reservations - 1] = num_guests;
  return hotel->reservation_ids[hotel->num_reservations - 1];
}

// Get the total revenue for a hotel on a given date
float get_revenue(ShockinglyNamedHotel* hotel, char* date) {
  float total_revenue = 0;
  for (int i = 0; i < hotel->num_reservations; i++) {
    if (strcmp(hotel->reservation_dates[i], date) == 0) {
      int room_index = -1;
      for (int j = 0; j < hotel->num_rooms; j++) {
        if (hotel->room_capacities[j] >= hotel->reservation_num_guests[i]) {
          room_index = j;
          break;
        }
      }
      if (room_index != -1) {
        total_revenue += hotel->room_prices[room_index] * hotel->reservation_num_guests[i];
      }
    }
  }
  return total_revenue;
}

// Print the details of a hotel
void print_hotel(ShockinglyNamedHotel* hotel) {
  printf("Hotel Name: %s\n", hotel->name);
  printf("Hotel Address: %s\n", hotel->address);
  printf("Hotel Phone: %s\n", hotel->phone);
  printf("Hotel Email: %s\n", hotel->email);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room %d:\n", i + 1);
    printf("  Type: %s\n", hotel->room_types[i]);
    printf("  Price: %f\n", hotel->room_prices[i]);
    printf("  Capacity: %d\n", hotel->room_capacities[i]);
  }
  printf("Number of Reservations: %d\n", hotel->num_reservations);
  for (int i = 0; i < hotel->num_reservations; i++) {
    printf("Reservation %d:\n", i + 1);
    printf("  ID: %d\n", hotel->reservation_ids[i]);
    printf("  Date: %s\n", hotel->reservation_dates[i]);
    printf("  Number of Guests: %d\n", hotel->reservation_num_guests[i]);
  }
}

// Free the memory allocated for a hotel
void free_hotel(ShockinglyNamedHotel* hotel) {
  free(hotel->name);
  free(hotel->address);
  free(hotel->phone);
  free(hotel->email);
  for (int i = 0; i < hotel->num_rooms; i++) {
    free(hotel->room_types[i]);
  }
  free(hotel->room_types);
  free(hotel->room_prices);
  free(hotel->room_capacities);
  for (int i = 0; i < hotel->num_reservations; i++) {
    free(hotel->reservation_dates[i]);
  }
  free(hotel->reservation_dates);
  free(hotel->reservation_num_guests);
  free(hotel->reservation_ids);
  free(hotel);
}

int main() {
  // Create a new hotel
  ShockinglyNamedHotel* hotel = create_hotel("The Grand Hotel", "123 Main Street", "(555) 123-4567", "info@grandhotel.com");

  // Add some rooms to the hotel
  add_room(hotel, "Standard Room", 100.0, 2);
  add_room(hotel, "Deluxe Room", 150.0, 4);
  add_room(hotel, "Suite", 200.0, 6);

  // Make some reservations at the hotel
  make_reservation(hotel, "2023-06-01", 2);
  make_reservation(hotel, "2023-06-02", 4);
  make_reservation(hotel, "2023-06-03", 6);

  // Get the total revenue for the hotel on a given date
  float revenue = get_revenue(hotel, "2023-06-02");
  printf("Total revenue for June 2nd: %f\n", revenue);

  // Print the details of the hotel
  print_hotel(hotel);

  // Free the memory allocated for the hotel
  free_hotel(hotel);

  return 0;
}