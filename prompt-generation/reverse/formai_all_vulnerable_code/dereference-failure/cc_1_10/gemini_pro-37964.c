//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a hotel room
typedef struct room {
  int room_number;
  char *room_type;
  float price;
  int availability;
} room;

// Structure to represent a hotel booking
typedef struct booking {
  int booking_id;
  int room_number;
  char *customer_name;
  char *check_in_date;
  char *check_out_date;
  float total_cost;
} booking;

// Function to create a new hotel room
room *create_room(int room_number, char *room_type, float price, int availability) {
  room *new_room = (room *)malloc(sizeof(room));
  new_room->room_number = room_number;
  new_room->room_type = (char *)malloc(strlen(room_type) + 1);
  strcpy(new_room->room_type, room_type);
  new_room->price = price;
  new_room->availability = availability;
  return new_room;
}

// Function to create a new hotel booking
booking *create_booking(int booking_id, int room_number, char *customer_name, char *check_in_date, char *check_out_date, float total_cost) {
  booking *new_booking = (booking *)malloc(sizeof(booking));
  new_booking->booking_id = booking_id;
  new_booking->room_number = room_number;
  new_booking->customer_name = (char *)malloc(strlen(customer_name) + 1);
  strcpy(new_booking->customer_name, customer_name);
  new_booking->check_in_date = (char *)malloc(strlen(check_in_date) + 1);
  strcpy(new_booking->check_in_date, check_in_date);
  new_booking->check_out_date = (char *)malloc(strlen(check_out_date) + 1);
  strcpy(new_booking->check_out_date, check_out_date);
  new_booking->total_cost = total_cost;
  return new_booking;
}

// Function to print the details of a hotel room
void print_room(room *room) {
  printf("Room Number: %d\n", room->room_number);
  printf("Room Type: %s\n", room->room_type);
  printf("Price: %.2f\n", room->price);
  printf("Availability: %d\n", room->availability);
  printf("\n");
}

// Function to print the details of a hotel booking
void print_booking(booking *booking) {
  printf("Booking ID: %d\n", booking->booking_id);
  printf("Room Number: %d\n", booking->room_number);
  printf("Customer Name: %s\n", booking->customer_name);
  printf("Check-In Date: %s\n", booking->check_in_date);
  printf("Check-Out Date: %s\n", booking->check_out_date);
  printf("Total Cost: %.2f\n", booking->total_cost);
  printf("\n");
}

// Main function
int main() {
  // Create a few hotel rooms
  room *room1 = create_room(101, "Standard", 100.00, 1);
  room *room2 = create_room(102, "Deluxe", 150.00, 1);
  room *room3 = create_room(103, "Suite", 200.00, 1);

  // Create a few hotel bookings
  booking *booking1 = create_booking(1, 101, "John Doe", "2023-03-01", "2023-03-05", 400.00);
  booking *booking2 = create_booking(2, 102, "Jane Doe", "2023-03-10", "2023-03-15", 750.00);
  booking *booking3 = create_booking(3, 103, "Bob Smith", "2023-03-20", "2023-03-25", 1000.00);

  // Print the details of the hotel rooms
  printf("Hotel Rooms:\n");
  print_room(room1);
  print_room(room2);
  print_room(room3);

  // Print the details of the hotel bookings
  printf("\nHotel Bookings:\n");
  print_booking(booking1);
  print_booking(booking2);
  print_booking(booking3);

  return 0;
}