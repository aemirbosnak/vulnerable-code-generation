//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hotel data structures
typedef struct room {
  int room_number;
  int capacity;
  int price;
  int availability;
} room_t;

typedef struct booking {
  int booking_id;
  int room_number;
  int check_in_date;
  int check_out_date;
  int num_guests;
  char guest_name[50];
} booking_t;

// Hotel management functions
void add_room(room_t **rooms, int *num_rooms, int room_number, int capacity, int price) {
  *rooms = realloc(*rooms, (*num_rooms + 1) * sizeof(room_t));
  room_t *new_room = &(*rooms)[*num_rooms];
  new_room->room_number = room_number;
  new_room->capacity = capacity;
  new_room->price = price;
  new_room->availability = 1;
  (*num_rooms)++;
}

void remove_room(room_t **rooms, int *num_rooms, int room_number) {
  for (int i = 0; i < *num_rooms; i++) {
    if ((*rooms)[i].room_number == room_number) {
      for (int j = i; j < *num_rooms - 1; j++) {
        (*rooms)[j] = (*rooms)[j + 1];
      }
      (*num_rooms)--;
      break;
    }
  }
}

void add_booking(booking_t **bookings, int *num_bookings, int booking_id, int room_number, int check_in_date, int check_out_date, int num_guests, char *guest_name) {
  *bookings = realloc(*bookings, (*num_bookings + 1) * sizeof(booking_t));
  booking_t *new_booking = &(*bookings)[*num_bookings];
  new_booking->booking_id = booking_id;
  new_booking->room_number = room_number;
  new_booking->check_in_date = check_in_date;
  new_booking->check_out_date = check_out_date;
  new_booking->num_guests = num_guests;
  strcpy(new_booking->guest_name, guest_name);
  (*num_bookings)++;
}

void remove_booking(booking_t **bookings, int *num_bookings, int booking_id) {
  for (int i = 0; i < *num_bookings; i++) {
    if ((*bookings)[i].booking_id == booking_id) {
      for (int j = i; j < *num_bookings - 1; j++) {
        (*bookings)[j] = (*bookings)[j + 1];
      }
      (*num_bookings)--;
      break;
    }
  }
}

// Main program
int main() {
  // Create an array of rooms
  room_t *rooms = NULL;
  int num_rooms = 0;

  // Add some rooms to the array
  add_room(&rooms, &num_rooms, 101, 2, 100);
  add_room(&rooms, &num_rooms, 102, 4, 150);
  add_room(&rooms, &num_rooms, 103, 6, 200);

  // Create an array of bookings
  booking_t *bookings = NULL;
  int num_bookings = 0;

  // Add some bookings to the array
  add_booking(&bookings, &num_bookings, 1, 101, 20230301, 20230303, 2, "John Doe");
  add_booking(&bookings, &num_bookings, 2, 102, 20230305, 20230307, 4, "Jane Doe");
  add_booking(&bookings, &num_bookings, 3, 103, 20230310, 20230312, 6, "John Smith");

  // Print the list of rooms
  printf("Rooms:\n");
  for (int i = 0; i < num_rooms; i++) {
    printf("Room %d: %d guests, $%d per night\n", rooms[i].room_number, rooms[i].capacity, rooms[i].price);
  }

  // Print the list of bookings
  printf("\nBookings:\n");
  for (int i = 0; i < num_bookings; i++) {
    printf("Booking %d: Room %d, %d guests, %d nights, %s\n", bookings[i].booking_id, bookings[i].room_number, bookings[i].num_guests, bookings[i].check_out_date - bookings[i].check_in_date + 1, bookings[i].guest_name);
  }

  // Clean up
  free(rooms);
  free(bookings);

  return 0;
}