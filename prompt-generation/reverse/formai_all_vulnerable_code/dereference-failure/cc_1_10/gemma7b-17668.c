//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROOM_COUNT 5

struct Room {
  char name[20];
  struct Room* next;
  int isVisited;
  int ghosts;
  int traps;
};

struct Room* createRoom(char* name, int ghosts, int traps) {
  struct Room* newRoom = (struct Room*)malloc(sizeof(struct Room));
  strcpy(newRoom->name, name);
  newRoom->ghosts = ghosts;
  newRoom->traps = traps;
  newRoom->next = NULL;
  newRoom->isVisited = 0;
  return newRoom;
}

void traverseRooms(struct Room* currentRoom) {
  if (currentRoom->next) {
    traverseRooms(currentRoom->next);
  }

  printf("You are in the %s room.\n", currentRoom->name);

  if (currentRoom->ghosts) {
    printf("Warning: there are %d ghosts in this room.\n", currentRoom->ghosts);
  }

  if (currentRoom->traps) {
    printf("Warning: there are %d traps in this room.\n", currentRoom->traps);
  }

  printf("Please enter the number of the room you want to visit: ");
  int nextRoomNumber = atoi(stdin);

  if (nextRoomNumber < 1 || nextRoomNumber > ROOM_COUNT) {
    printf("Invalid input. Please try again.\n");
  } else {
    currentRoom->isVisited = 1;
    struct Room* nextRoom = currentRoom->next;
    for (int i = 0; i < nextRoomNumber - 1; i++) {
      nextRoom = nextRoom->next;
    }
    traverseRooms(nextRoom);
  }
}

int main() {
  struct Room* firstRoom = createRoom("The Living Room", 2, 3);
  struct Room* secondRoom = createRoom("The Kitchen", 1, 1);
  struct Room* thirdRoom = createRoom("The Bedroom", 0, 0);
  struct Room* fourthRoom = createRoom("The Dining Room", 0, 2);
  struct Room* fifthRoom = createRoom("The Basement", 3, 4);

  traverseRooms(firstRoom);

  return 0;
}