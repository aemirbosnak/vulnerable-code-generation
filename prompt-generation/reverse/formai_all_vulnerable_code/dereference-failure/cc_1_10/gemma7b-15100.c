//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct Room {
  char name[20];
  struct Room *next;
  int has_key;
  int has_monster;
} Room;

Room *create_room(char *name, int has_key, int has_monster) {
  Room *new_room = malloc(sizeof(Room));
  strcpy(new_room->name, name);
  new_room->next = NULL;
  new_room->has_key = has_key;
  new_room->has_monster = has_monster;
  return new_room;
}

void play_game() {
  Room *current_room = create_room("The Hallway", 1, 0);
  Room *next_room = create_room("The Kitchen", 0, 1);
  current_room->next = next_room;

  // Game loop
  while (1) {
    printf("You are in %s.\n", current_room->name);

    // Check if there is a key or a monster
    if (current_room->has_key) {
      printf("You found the key!\n");
      current_room->has_key = 0;
    } else if (current_room->has_monster) {
      printf("A monster attacks!\n");
      // Combat mechanics
    }

    // Get user input
    char input;
    printf("Enter your move: ");
    scanf("%c", &input);

    // Move to the next room
    if (input == 'f' && current_room->next) {
      current_room = current_room->next;
    } else {
      printf("Invalid input.\n");
    }
  }
}

int main() {
  play_game();
  return 0;
}