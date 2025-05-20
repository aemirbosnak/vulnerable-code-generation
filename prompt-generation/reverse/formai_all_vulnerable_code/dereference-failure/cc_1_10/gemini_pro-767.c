//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel structure
typedef struct hotel {
  char name[50];
  char address[100];
  int num_rooms;
  int num_occupied;
  float avg_rate;
} hotel_t;

// Define the guest structure
typedef struct guest {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  int num_nights;
  float rate;
} guest_t;

// Define the reservation structure
typedef struct reservation {
  int guest_id;
  int hotel_id;
  int room_number;
  char check_in_date[20];
  char check_out_date[20];
} reservation_t;

// Create a new hotel
hotel_t *create_hotel(char *name, char *address, int num_rooms, float avg_rate) {
  hotel_t *hotel = malloc(sizeof(hotel_t));
  strcpy(hotel->name, name);
  strcpy(hotel->address, address);
  hotel->num_rooms = num_rooms;
  hotel->num_occupied = 0;
  hotel->avg_rate = avg_rate;
  return hotel;
}

// Create a new guest
guest_t *create_guest(char *name, char *address, char *phone, char *email, int num_nights, float rate) {
  guest_t *guest = malloc(sizeof(guest_t));
  strcpy(guest->name, name);
  strcpy(guest->address, address);
  strcpy(guest->phone, phone);
  strcpy(guest->email, email);
  guest->num_nights = num_nights;
  guest->rate = rate;
  return guest;
}

// Create a new reservation
reservation_t *create_reservation(int guest_id, int hotel_id, int room_number, char *check_in_date, char *check_out_date) {
  reservation_t *reservation = malloc(sizeof(reservation_t));
  reservation->guest_id = guest_id;
  reservation->hotel_id = hotel_id;
  reservation->room_number = room_number;
  strcpy(reservation->check_in_date, check_in_date);
  strcpy(reservation->check_out_date, check_out_date);
  return reservation;
}

// Print the hotel information
void print_hotel(hotel_t *hotel) {
  printf("Hotel Name: %s\n", hotel->name);
  printf("Hotel Address: %s\n", hotel->address);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  printf("Number of Occupied Rooms: %d\n", hotel->num_occupied);
  printf("Average Rate: %.2f\n", hotel->avg_rate);
}

// Print the guest information
void print_guest(guest_t *guest) {
  printf("Guest Name: %s\n", guest->name);
  printf("Guest Address: %s\n", guest->address);
  printf("Guest Phone: %s\n", guest->phone);
  printf("Guest Email: %s\n", guest->email);
  printf("Number of Nights: %d\n", guest->num_nights);
  printf("Rate: %.2f\n", guest->rate);
}

// Print the reservation information
void print_reservation(reservation_t *reservation) {
  printf("Guest ID: %d\n", reservation->guest_id);
  printf("Hotel ID: %d\n", reservation->hotel_id);
  printf("Room Number: %d\n", reservation->room_number);
  printf("Check-In Date: %s\n", reservation->check_in_date);
  printf("Check-Out Date: %s\n", reservation->check_out_date);
}

// Main function
int main() {
  // Create a new hotel
  hotel_t *hotel = create_hotel("The Grand Hotel", "123 Main Street", 100, 150.00);

  // Create a new guest
  guest_t *guest = create_guest("John Smith", "123 Elm Street", "555-1212", "john.smith@email.com", 3, 120.00);

  // Create a new reservation
  reservation_t *reservation = create_reservation(1, 1, 101, "2023-06-01", "2023-06-04");

  // Print the hotel information
  print_hotel(hotel);

  // Print the guest information
  print_guest(guest);

  // Print the reservation information
  print_reservation(reservation);

  return 0;
}