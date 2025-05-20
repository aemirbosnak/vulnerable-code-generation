//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
  char name[20];
  struct Room* next;
  int num;
} Room;

Room* createRoom(char* name, int num) {
  Room* newRoom = (Room*)malloc(sizeof(Room));
  strcpy(newRoom->name, name);
  newRoom->num = num;
  newRoom->next = NULL;
  return newRoom;
}

void playGame() {
  Room* currentRoom = createRoom("The Grand Hall", 1);
  Room* northRoom = createRoom("The Library", 2);
  Room* southRoom = createRoom("The Kitchen", 3);
  Room* eastRoom = createRoom("The Dining Hall", 4);
  Room* westRoom = createRoom("The Bedroom", 5);

  currentRoom->next = northRoom;
  currentRoom->next = southRoom;
  currentRoom->next = eastRoom;
  currentRoom->next = westRoom;

  int choice;
  printf("You are in the %s. What direction do you want to go? (n/s/e/w)\n", currentRoom->name);
  scanf("%d", &choice);

  switch (choice) {
    case 1:
      currentRoom = northRoom;
      printf("You have traveled north to the %s.\n", currentRoom->name);
      break;
    case 2:
      currentRoom = southRoom;
      printf("You have traveled south to the %s.\n", currentRoom->name);
      break;
    case 3:
      currentRoom = eastRoom;
      printf("You have traveled east to the %s.\n", currentRoom->name);
      break;
    case 4:
      currentRoom = westRoom;
      printf("You have traveled west to the %s.\n", currentRoom->name);
      break;
    default:
      printf("Invalid choice.\n");
  }

  playGame();
}

int main() {
  playGame();

  return 0;
}