//Gemma-7B DATASET v1.0 Category: Text-Based Adventure Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOM_NUM 5

typedef struct Room {
  char name[20];
  struct Room* next;
} Room;

void createRoom(Room** head) {
  *head = malloc(sizeof(Room));
  (*head)->name[0] = '\0';
  (*head)->next = NULL;
}

void addRoom(Room* head, char* name) {
  Room* newRoom = malloc(sizeof(Room));
  newRoom->name[0] = '\0';
  strcpy(newRoom->name, name);
  newRoom->next = NULL;

  if (head == NULL) {
    head = newRoom;
  } else {
    head->next = newRoom;
  }
}

void playGame() {
  Room* head = NULL;
  addRoom(head, "The Grand Hall");
  addRoom(head, "The Dining Hall");
  addRoom(head, "The Library");
  addRoom(head, "The Bedroom");
  addRoom(head, "The Secret Room");

  Room* currentRoom = head;
  char input[20];

  printf("You wake up in %s.\n", currentRoom->name);

  while (1) {
    printf("What do you want to do? (quit, explore, interact): ");
    scanf("%s", input);

    if (strcmp(input, "quit") == 0) {
      break;
    } else if (strcmp(input, "explore") == 0) {
      currentRoom = currentRoom->next;
      printf("You are now in %s.\n", currentRoom->name);
    } else if (strcmp(input, "interact") == 0) {
      // Interact with objects in the current room
    } else {
      printf("Invalid input.\n");
    }
  }

  printf("Thank you for playing. See you next time!\n");
}

int main() {
  playGame();

  return 0;
}