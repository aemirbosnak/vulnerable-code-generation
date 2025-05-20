//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a room
typedef struct Room {
  int number;
  char type;
  int occupancy;
  struct Room* next;
} Room;

// Define the structure of a guest
typedef struct Guest {
  char name[50];
  int room_number;
  int days_stayed;
  struct Guest* next;
} Guest;

// Create a linked list of rooms
Room* create_room_list() {
  Room* head = NULL;
  Room* tail = NULL;

  // Allocate memory for the first room
  head = malloc(sizeof(Room));
  tail = head;
  tail->number = 1;
  tail->type = 'A';
  tail->occupancy = 0;
  tail->next = NULL;

  // Create the remaining rooms
  for (int i = 2; i <= 10; i++) {
    tail->next = malloc(sizeof(Room));
    tail = tail->next;
    tail->number = i;
    tail->type = 'A' + i - 2;
    tail->occupancy = 0;
    tail->next = NULL;
  }

  return head;
}

// Create a linked list of guests
Guest* create_guest_list() {
  Guest* head = NULL;
  Guest* tail = NULL;

  // Allocate memory for the first guest
  head = malloc(sizeof(Guest));
  tail = head;
  strcpy(tail->name, "John Doe");
  tail->room_number = 1;
  tail->days_stayed = 2;
  tail->next = NULL;

  // Create the remaining guests
  for (int i = 2; i <= 5; i++) {
    tail->next = malloc(sizeof(Guest));
    tail = tail->next;
    strcpy(tail->name, "Guest" + i);
    tail->room_number = i;
    tail->days_stayed = 3 - i;
    tail->next = NULL;
  }

  return head;
}

// Check if a room is available
int is_room_available(Room* room_list, int room_number) {
  Room* current_room = room_list;

  // Iterate over the rooms until the room number is found or the end of the list is reached
  while (current_room) {
    if (current_room->number == room_number && current_room->occupancy == 0) {
      return 1;
    }
    current_room = current_room->next;
  }

  return 0;
}

// Book a room
void book_room(Room* room_list, Guest* guest_list) {
  int room_number;

  // Get the room number from the guest
  printf("Enter the room number you want to book: ");
  scanf("%d", &room_number);

  // Check if the room is available
  if (is_room_available(room_list, room_number)) {
    // Allocate memory for the guest
    Guest* new_guest = malloc(sizeof(Guest));
    strcpy(new_guest->name, guest_list->name);
    new_guest->room_number = room_number;
    new_guest->days_stayed = guest_list->days_stayed;
    new_guest->next = guest_list;

    // Update the room occupancy
    room_list->occupancy = 1;

    // Print a confirmation message
    printf("Your room has been booked.\n");
  } else {
    // Print an error message
    printf("Sorry, that room is not available.\n");
  }
}

// Main function
int main() {
  // Create the room list
  Room* room_list = create_room_list();

  // Create the guest list
  Guest* guest_list = create_guest_list();

  // Book a room
  book_room(room_list, guest_list);

  return 0;
}