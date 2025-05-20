//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the haunted house
#define NUM_ROOMS 10
#define MAX_SCARES 5

struct room {
  char *description;
  int num_scares;
  struct room *next;
};

// Create the haunted house
struct room *create_haunted_house() {
  struct room *head = NULL;
  struct room *current = NULL;

  // Create the rooms
  for (int i = 0; i < NUM_ROOMS; i++) {
    struct room *new_room = malloc(sizeof(struct room));
    new_room->description = malloc(100);
    sprintf(new_room->description, "Room %d", i + 1);
    new_room->num_scares = rand() % MAX_SCARES;
    new_room->next = NULL;

    if (head == NULL) {
      head = new_room;
      current = new_room;
    } else {
      current->next = new_room;
      current = new_room;
    }
  }

  return head;
}

// Walk through the haunted house
void walk_through_haunted_house(struct room *head) {
  struct room *current = head;

  while (current != NULL) {
    // Print the room description
    printf("%s\n", current->description);

    // Generate a random number of scares
    int num_scares = rand() % current->num_scares;

    // Scare the visitor
    for (int i = 0; i < num_scares; i++) {
      printf("BOO!\n");
    }

    // Move to the next room
    current = current->next;
  }
}

// Destroy the haunted house
void destroy_haunted_house(struct room *head) {
  struct room *current = head;

  while (current != NULL) {
    struct room *next = current->next;
    free(current->description);
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Create the haunted house
  struct room *head = create_haunted_house();

  // Walk through the haunted house
  walk_through_haunted_house(head);

  // Destroy the haunted house
  destroy_haunted_house(head);

  return 0;
}