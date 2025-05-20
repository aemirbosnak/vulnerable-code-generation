//GEMINI-pro DATASET v1.0 Category: Memory management ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Imagine this is a fancy mansion with many rooms.
int num_rooms = 100;
int** mansion;

// Let's welcome our guests!
void check_in_guests(int num_guests) {
  // Allocate space for our guests.
  mansion = (int**)malloc(sizeof(int*) * num_rooms);
  for (int i = 0; i < num_rooms; i++) {
    mansion[i] = (int*)malloc(sizeof(int) * num_guests);
  }

  // Populate the rooms with guests.
  for (int i = 0; i < num_rooms; i++) {
    for (int j = 0; j < num_guests; j++) {
      mansion[i][j] = j;
    }
  }

  printf("Welcome to the mansion! Your rooms have been allocated.\n");
}

// Time to say goodbye!
void check_out_guests() {
  // Let's release the rooms.
  for (int i = 0; i < num_rooms; i++) {
    free(mansion[i]);
  }

  free(mansion);

  printf("Thank you for staying at the mansion! Come visit again soon.\n");
  mansion = NULL; // Just to be extra careful!
}

int main() {
  int num_guests = 50;

  printf("Welcome to our memory management mansion!\n");

  // Let's create a memory mansion for our guests.
  check_in_guests(num_guests);

  // Now, let's use our mansion to its full potential.
  // (Imagine them having a grand party in there.)

  // Time to say our farewells.
  check_out_guests();

  return 0;
}