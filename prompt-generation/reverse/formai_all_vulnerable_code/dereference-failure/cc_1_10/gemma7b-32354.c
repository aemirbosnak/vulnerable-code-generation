//Gemma-7B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_Rooms 20

typedef struct Room {
  int x, y;
  struct Room* north, *south, *east, *west;
  char description[256];
} Room;

Room** generateRooms() {
  int numRooms = rand() % MAX_Rooms + 1;
  Room** rooms = malloc(numRooms * sizeof(Room*));

  for (int i = 0; i < numRooms; i++) {
    rooms[i] = malloc(sizeof(Room));
    rooms[i]->x = rand() % 10;
    rooms[i]->y = rand() % 10;
    rooms[i]->north = NULL;
    rooms[i]->south = NULL;
    rooms[i]->east = NULL;
    rooms[i]->west = NULL;
    rooms[i]->description[0] = '\0';
  }

  return rooms;
}

void exploreRoom(Room* room) {
  printf("%s\n", room->description);

  if (room->north) {
    printf("You can go north to the next room.\n");
  }
  if (room->south) {
    printf("You can go south to the next room.\n");
  }
  if (room->east) {
    printf("You can go east to the next room.\n");
  }
  if (room->west) {
    printf("You can go west to the next room.\n");
  }

  char command;
  scanf("Enter your command: ", &command);

  switch (command) {
    case 'n':
      exploreRoom(room->north);
      break;
    case 's':
      exploreRoom(room->south);
      break;
    case 'e':
      exploreRoom(room->east);
      break;
    case 'w':
      exploreRoom(room->west);
      break;
    default:
      printf("Invalid command.\n");
  }
}

int main() {
  Room** rooms = generateRooms();

  exploreRoom(rooms[0]);

  return 0;
}