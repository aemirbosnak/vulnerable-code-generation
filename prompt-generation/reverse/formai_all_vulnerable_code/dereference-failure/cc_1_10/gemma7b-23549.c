//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
  char name[20];
  struct Room* next;
} Room;

Room* createRoom(char* name) {
  Room* newRoom = malloc(sizeof(Room));
  strcpy(newRoom->name, name);
  newRoom->next = NULL;
  return newRoom;
}

void exploreRoom(Room* currentRoom) {
  printf("You are in the %s.\n", currentRoom->name);
  // List the items in the room
  printf("Items in the room: ");
  // List the exits from the room
  printf("Exits: ");
  for (Room* nextRoom = currentRoom->next; nextRoom; nextRoom) {
    printf("%s, ", nextRoom->name);
  }
  printf("\n");
  // Get the user's input
  char input[20];
  printf("Enter your command: ");
  scanf("%s", input);

  // Check if the user wants to exit the room
  if (strcmp(input, "exit") == 0) {
    exit(0);
  }

  // Check if the user wants to go to another room
  for (Room* nextRoom = currentRoom->next; nextRoom; nextRoom) {
    if (strcmp(input, nextRoom->name) == 0) {
      currentRoom = nextRoom;
      exploreRoom(currentRoom);
    }
  }

  // If the user input is invalid, print an error message
  printf("Invalid command.\n");
}

int main() {
  Room* roomList = createRoom("The Entrance");
  roomList = createRoom("The Kitchen");
  roomList = createRoom("The Living Room");
  roomList = createRoom("The Bedroom");
  roomList = createRoom("The Garden");

  exploreRoom(roomList);

  return 0;
}