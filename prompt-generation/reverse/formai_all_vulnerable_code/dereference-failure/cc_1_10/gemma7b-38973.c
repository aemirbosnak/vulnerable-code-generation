//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5

typedef struct Room {
  char name[20];
  struct Room *next;
  int visited;
  char description[100];
} Room;

Room **createRoom(char *name, char *description) {
  Room *newRoom = malloc(sizeof(Room));
  strcpy(newRoom->name, name);
  newRoom->next = NULL;
  newRoom->visited = 0;
  strcpy(newRoom->description, description);
  return newRoom;
}

void explore(Room **rooms) {
  char input[20];
  int roomIndex = 0;

  printf("You wake up in a mysterious room. You have no memory of how you got here.\n");

  while (1) {
    printf("Please enter the number of the room you want to explore (1-%d): ", MAX_ROOMS);
    scanf("%s", input);

    roomIndex = atoi(input) - 1;

    if (roomIndex < 0 || roomIndex >= MAX_ROOMS) {
      printf("Invalid room number.\n");
    } else if (rooms[roomIndex]->visited) {
      printf("You have already explored this room.\n");
    } else {
      rooms[roomIndex]->visited = 1;
      printf("You enter the room and find...\n");
      printf("%s\n", rooms[roomIndex]->description);

      if (rooms[roomIndex]->next) {
        printf("There is a door to the next room. You can go through it if you want.\n");
      }

      break;
    }
  }
}

int main() {
  Room **rooms = createRoom("The Grand Hall", "You are in a grand hall with a lot of paintings on the walls.");
  rooms = createRoom("The Library", "You are in a library with many books.");
  rooms = createRoom("The Dining Hall", "You are in a dining hall with a table and chairs.");
  rooms = createRoom("The Bedroom", "You are in a bedroom with a bed and a dresser.");
  rooms = createRoom("The Secret Room", "You are in a secret room with a lot of treasures.");

  explore(rooms);

  return 0;
}