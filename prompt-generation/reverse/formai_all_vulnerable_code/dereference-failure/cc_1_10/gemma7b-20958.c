//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 10

typedef struct Room {
  char name[20];
  struct Room* next;
  int has_key;
  int has_monster;
} Room;

Room* create_room(char* name, int has_key, int has_monster) {
  Room* new_room = malloc(sizeof(Room));
  strcpy(new_room->name, name);
  new_room->next = NULL;
  new_room->has_key = has_key;
  new_room->has_monster = has_monster;
  return new_room;
}

void play_game() {
  Room* current_room = create_room("The Lobby", 1, 0);
  Room* next_room = create_room("The Kitchen", 0, 1);

  current_room->next = next_room;

  // Game loop
  while (1) {
    // Prompt the player for input
    char input[20];
    printf("What do you want to do? (quit, go north, go south, go east, go west): ");
    scanf("%s", input);

    // Check if the player wants to quit
    if (strcmp(input, "quit") == 0) {
      break;
    }

    // Check if the player wants to go in a direction
    else if (strcmp(input, "go north") == 0) {
      // Go north to the next room
      current_room = current_room->next;
    }

    // ... Implement other directions ...
  }

  // End the game
  printf("Thank you for playing!\n");
}

int main() {
  play_game();
  return 0;
}