//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct Room {
  char name[20];
  struct Room* next;
  int has_key;
} Room;

Room* create_room(char* name, int has_key) {
  Room* new_room = (Room*)malloc(sizeof(Room));
  strcpy(new_room->name, name);
  new_room->next = NULL;
  new_room->has_key = has_key;
  return new_room;
}

void play_adventure() {
  Room* rooms = NULL;
  rooms = create_room("The Hallway", 0);
  rooms = create_room("The Kitchen", 1);
  rooms = create_room("The Living Room", 0);
  rooms = create_room("The Bedroom", 1);
  rooms = create_room("The Bathroom", 0);

  Room* current_room = rooms;

  // Game loop
  while (1) {
    // Display current room information
    printf("You are in: %s\n", current_room->name);

    // Check if the current room has a key
    if (current_room->has_key) {
      printf("You have a key.\n");
    }

    // Get user input
    char input[20];
    printf("Enter your command: ");
    scanf("%s", input);

    // Check user input for valid commands
    if (strcmp(input, "go north") == 0) {
      // Go north to the next room
      if (current_room->next) {
        current_room = current_room->next;
      } else {
        printf("There is no north exit.\n");
      }
    } else if (strcmp(input, "go south") == 0) {
      // Go south to the previous room
      if (current_room->next) {
        current_room = current_room->next->next;
      } else {
        printf("There is no south exit.\n");
      }
    } else if (strcmp(input, "use key") == 0) {
      // Use the key to unlock the next room
      if (current_room->has_key) {
        current_room->has_key = 0;
        printf("You have unlocked the next room.\n");
        current_room = current_room->next;
      } else {
        printf("You do not have a key.\n");
      }
    } else {
      printf("Invalid command.\n");
    }

    // Check if the player has won
    if (current_room->name == "The Bedroom") {
      printf("Congratulations! You have won the game!\n");
      break;
    }
  }
}

int main() {
  play_adventure();
  return 0;
}