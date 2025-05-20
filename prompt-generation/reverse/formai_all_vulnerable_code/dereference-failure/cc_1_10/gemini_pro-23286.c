//GEMINI-pro DATASET v1.0 Category: Haunted House Simulator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ROOMS 10

typedef struct room {
  char *description;
  struct room *north;
  struct room *east;
  struct room *south;
  struct room *west;
} room;

room *create_room(char *description) {
  room *new_room = malloc(sizeof(room));
  new_room->description = strdup(description);
  new_room->north = NULL;
  new_room->east = NULL;
  new_room->south = NULL;
  new_room->west = NULL;
  return new_room;
}

void destroy_room(room *room) {
  free(room->description);
  free(room);
}

void connect_rooms(room *room1, room *room2, char direction) {
  switch (direction) {
    case 'n':
      room1->north = room2;
      room2->south = room1;
      break;
    case 'e':
      room1->east = room2;
      room2->west = room1;
      break;
    case 's':
      room1->south = room2;
      room2->north = room1;
      break;
    case 'w':
      room1->west = room2;
      room2->east = room1;
      break;
  }
}

void print_room(room *room) {
  printf("%s\n", room->description);
}

void play_game(room *starting_room) {
  room *current_room = starting_room;

  while (1) {
    print_room(current_room);

    char input[100];
    printf("> ");
    scanf("%s", input);

    if (strcmp(input, "n") == 0) {
      if (current_room->north != NULL) {
        current_room = current_room->north;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "e") == 0) {
      if (current_room->east != NULL) {
        current_room = current_room->east;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "s") == 0) {
      if (current_room->south != NULL) {
        current_room = current_room->south;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "w") == 0) {
      if (current_room->west != NULL) {
        current_room = current_room->west;
      } else {
        printf("You can't go that way.\n");
      }
    } else if (strcmp(input, "q") == 0) {
      break;
    }
  }
}

int main() {
  srand(time(NULL));

  // Create the rooms
  room *room1 = create_room("You are standing in a dimly lit room. The walls are covered in graffiti and the floor is littered with trash.");
  room *room2 = create_room("You are standing in a small, windowless room. The air is thick with the smell of decay.");
  room *room3 = create_room("You are standing in a large, open room. The walls are lined with shelves, and the floor is covered in books.");
  room *room4 = create_room("You are standing in a narrow hallway. The walls are covered in peeling paint and the floor is littered with broken glass.");
  room *room5 = create_room("You are standing in a small, square room. The walls are bare and the floor is covered in a thick layer of dust.");
  room *room6 = create_room("You are standing in a large, ornate room. The walls are covered in tapestries and the floor is covered in a thick carpet.");
  room *room7 = create_room("You are standing in a small, windowless room. The walls are covered in mirrors and the floor is covered in a thick layer of fog.");
  room *room8 = create_room("You are standing in a large, open room. The walls are covered in graffiti and the floor is littered with trash.");
  room *room9 = create_room("You are standing in a small, windowless room. The air is thick with the smell of smoke.");
  room *room10 = create_room("You are standing in a large, open room. The walls are covered in mirrors and the floor is covered in a thick layer of fog.");

  // Connect the rooms
  connect_rooms(room1, room2, 'n');
  connect_rooms(room1, room3, 'e');
  connect_rooms(room2, room4, 'e');
  connect_rooms(room3, room5, 'e');
  connect_rooms(room4, room5, 's');
  connect_rooms(room5, room6, 'e');
  connect_rooms(room6, room7, 'e');
  connect_rooms(room7, room8, 'e');
  connect_rooms(room8, room9, 'e');
  connect_rooms(room9, room10, 'e');

  // Play the game
  play_game(room1);

  // Clean up
  destroy_room(room1);
  destroy_room(room2);
  destroy_room(room3);
  destroy_room(room4);
  destroy_room(room5);
  destroy_room(room6);
  destroy_room(room7);
  destroy_room(room8);
  destroy_room(room9);
  destroy_room(room10);

  return 0;
}