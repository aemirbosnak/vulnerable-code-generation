//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM 5

typedef struct room {
  char name[20];
  struct room *next;
  int has_key;
  int has_potion;
} room_t;

room_t *create_room(char *name, int has_key, int has_potion) {
  room_t *new_room = malloc(sizeof(room_t));
  strcpy(new_room->name, name);
  new_room->next = NULL;
  new_room->has_key = has_key;
  new_room->has_potion = has_potion;
  return new_room;
}

void play_game() {
  room_t *current_room = create_room("The Hall", 1, 0);
  room_t *second_room = create_room("The Kitchen", 0, 1);
  room_t *third_room = create_room("The Library", 0, 0);

  current_room->next = second_room;
  second_room->next = third_room;

  int current_room_index = 0;

  while (1) {
    printf("You are in the %s.\n", current_room->name);

    // Check if the current room has a key or potion.
    if (current_room->has_key) {
      printf("You found a key!\n");
    }
    if (current_room->has_potion) {
      printf("You found a potion!\n");
    }

    // Get the user's input.
    char input[20];
    printf("What do you want to do? (north, south, east, west): ");
    scanf("%s", input);

    // Move to the next room.
    if (strcmp(input, "north") == 0) {
      current_room_index++;
    } else if (strcmp(input, "south") == 0) {
      current_room_index--;
    } else if (strcmp(input, "east") == 0) {
      current_room_index++;
    } else if (strcmp(input, "west") == 0) {
      current_room_index--;
    }

    // Check if the user has reached the end of the game.
    if (current_room_index == MAX_ROOM - 1) {
      printf("You have won the game!\n");
      break;
    }

    // Move to the next room.
    current_room = current_room->next;
  }
}

int main() {
  play_game();
  return 0;
}