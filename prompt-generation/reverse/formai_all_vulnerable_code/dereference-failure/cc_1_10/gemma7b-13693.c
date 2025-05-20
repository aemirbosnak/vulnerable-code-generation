//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

#define ROOM_NUM 10
#define HOTEL_NAME "Surreal Hotel"

// Define a surreal room structure
typedef struct Room {
  char name[20];
  int number;
  struct Room* next;
} Room;

// Create a linked list of rooms
Room* head = NULL;

void addRoom() {
  Room* newRoom = (Room*)malloc(sizeof(Room));
  printf("Enter room name: ");
  scanf("%s", newRoom->name);
  printf("Enter room number: ");
  scanf("%d", &newRoom->number);
  newRoom->next = head;
  head = newRoom;
}

void checkIn() {
  Room* currentRoom = head;
  printf("Enter room number: ");
  int roomNumber = atoi(stdin);
  while (currentRoom) {
    if (currentRoom->number == roomNumber) {
      printf("Welcome to the %s, %s!", HOTEL_NAME, currentRoom->name);
      break;
    } else {
      currentRoom = currentRoom->next;
    }
  }
  if (currentRoom == NULL) {
    printf("Room not found.");
  }
}

void checkOut() {
  Room* currentRoom = head;
  printf("Enter room number: ");
  int roomNumber = atoi(stdin);
  while (currentRoom) {
    if (currentRoom->number == roomNumber) {
      printf("Thank you for staying at the %s, %s!", HOTEL_NAME, currentRoom->name);
      free(currentRoom);
      currentRoom = NULL;
      break;
    } else {
      currentRoom = currentRoom->next;
    }
  }
  if (currentRoom == NULL) {
    printf("Room not found.");
  }
}

int main() {
  int choice = 0;

  printf("Welcome to the %s!", HOTEL_NAME);

  while (choice != 3) {
    printf("\nPlease select an option:");
    printf("\n1. Add Room");
    printf("\n2. Check In");
    printf("\n3. Check Out");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addRoom();
        break;
      case 2:
        checkOut();
        break;
      case 3:
        printf("Thank you for your stay at the %s.", HOTEL_NAME);
        break;
      default:
        printf("Invalid choice.");
    }
  }

  return 0;
}