//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 5

typedef struct Room {
  char name[20];
  struct Room* next;
  int visited;
  int items;
} Room;

Room* createRoom(char* name, Room* next) {
  Room* room = malloc(sizeof(Room));
  strcpy(room->name, name);
  room->next = next;
  room->visited = 0;
  room->items = 0;
  return room;
}

void playGame() {
  Room* currentRoom = createRoom("The Hallway", NULL);
  currentRoom->items = 5;
  currentRoom = createRoom("The Kitchen", currentRoom);
  currentRoom->items = 10;
  currentRoom = createRoom("The Bedroom", currentRoom);
  currentRoom->items = 15;
  currentRoom = createRoom("The Library", currentRoom);
  currentRoom->items = 20;
  currentRoom = createRoom("The Treasure Room", currentRoom);
  currentRoom->items = 25;

  char command[20];
  int roomNumber = 1;

  printf("You are in the %s.\n", currentRoom->name);
  printf("There are %d items in this room.\n", currentRoom->items);

  while (1) {
    printf("Please enter your command: ");
    scanf("%s", command);

    if (strcmp(command, "quit") == 0) {
      break;
    } else if (strcmp(command, "look") == 0) {
      printf("You see: ");
      for (int i = 0; i < currentRoom->items; i++) {
        printf("%d. ", i + 1);
      }
      printf("\n");
    } else if (strcmp(command, "take") == 0) {
      int itemNumber;
      printf("Enter the item number you want to take: ");
      scanf("%d", &itemNumber);

      if (itemNumber > currentRoom->items || itemNumber < 1) {
        printf("Invalid item number.\n");
      } else {
        currentRoom->items--;
        printf("You took the item. \n");
      }
    } else if (strcmp(command, "go") == 0) {
      char direction[20];
      printf("Enter the direction you want to go: ");
      scanf("%s", direction);

      if (direction[0] == 'n') {
        currentRoom = currentRoom->next;
        roomNumber++;
      }
    }
  }

  printf("Thank you for playing. You have found the treasure!\n");
}

int main() {
  playGame();
  return 0;
}