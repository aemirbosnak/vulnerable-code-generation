//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void manage_hotel(int room_number, int available_rooms, char **bookings) {
  int choice;
  char name[20];
  int num_rooms;

  // Check if the room number is available
  if (available_rooms >= room_number) {
    printf("Room number %d is available.\n", room_number);

    // Get the guest's name and number of rooms
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the number of rooms you want to book: ");
    scanf("%d", &num_rooms);

    // Book the room
    bookings[room_number] = name;

    // Update the number of available rooms
    available_rooms -= num_rooms;

    // Ask the guest if they want to book another room
    printf("Do you want to book another room? (Y/N) ");
    scanf(" %c", &choice);

    // Recursively call the manage_hotel function
    if (choice == 'Y') {
      manage_hotel(room_number, available_rooms, bookings);
    }
  } else {
    printf("Room number %d is not available.\n", room_number);
  }
}

int main() {
  int available_rooms = 100;
  char **bookings = NULL;

  // Allocate memory for the bookings array
  bookings = (char **)malloc(available_rooms * sizeof(char *));

  // Initialize the bookings array
  for (int i = 0; i < available_rooms; i++) {
    bookings[i] = NULL;
  }

  // Manage the hotel
  manage_hotel(1, available_rooms, bookings);

  // Free the memory allocated for the bookings array
  free(bookings);

  return 0;
}