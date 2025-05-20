//FormAI DATASET v1.0 Category: Hotel Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct Room {
  int roomNumber;
  char guestName[50];
  bool occupied;
} Room;

Room* rooms[100];

void displayMenu() {
  printf("\n*** HOTEL MANAGEMENT SYSTEM ***\n\n");
  printf("1. Book a room\n");
  printf("2. Checkout a room\n");
  printf("3. Display room status\n");
  printf("4. Exit\n");
}

void initializeRooms() {
  printf("Initializing hotel rooms...\n");
  for(int i=0; i<100; i++) {
    Room* room = (Room*) malloc(sizeof(Room));
    room->roomNumber = i+1;
    room->occupied = false;
    strcpy(room->guestName, "");
    rooms[i] = room;
  }
  printf("Hotel rooms initialized successfully!\n");
}

void bookRoom() {
  int roomNumber;
  char guestName[50];

  printf("\nEnter room number: ");
  scanf("%d", &roomNumber);
  fflush(stdin);

  if (rooms[roomNumber-1]->occupied) {
    printf("Room %d is already occupied.\n", roomNumber);
  } else {
    printf("Enter guest name: ");
    fgets(guestName, 50, stdin);

    Room* room = rooms[roomNumber-1];
    room->occupied = true;
    strcpy(room->guestName, guestName);

    printf("Room %d has been booked by %s.\n", roomNumber, guestName);
  }
}

void checkoutRoom() {
  int roomNumber = -1;

  while (roomNumber < 0 || roomNumber > 100) {
    printf("\nEnter room number to checkout: ");
    scanf("%d", &roomNumber);
    fflush(stdin);

    if (roomNumber < 0 || roomNumber > 100) {
      printf("Invalid room number.\n");
    }
  }

  Room* room = rooms[roomNumber-1];
  if (room->occupied) {
    room->occupied = false;
    printf("%s has checked out from Room %d.\n", room->guestName, roomNumber);
    strcpy(room->guestName, "");
  } else {
    printf("Room %d is already unoccupied.\n", roomNumber);
  }
}

void displayRoomStatus() {
  printf("*** ROOM STATUS ***\n\n");
  printf("Room Number\tGuest Name\tOccupied\n");

  for (int i=0; i<100; i++) {
    printf("%d\t\t%s\t\t%s\n", rooms[i]->roomNumber, rooms[i]->guestName, rooms[i]->occupied ? "Yes" : "No");
  }
}

int main() {
  initializeRooms();

  int action = -1;

  while(action != 4) {
    displayMenu();
    printf("Enter action: ");
    scanf("%d", &action);
    fflush(stdin);

    switch(action) {
      case 1:
        bookRoom();
        break;
      case 2:
        checkoutRoom();
        break;
      case 3:
        displayRoomStatus();
        break;
      case 4:
        printf("Exiting hotel management system...\n");
        break;
      default:
        printf("Invalid action.\n");
        break;
    }
  }

  printf("Thank you for using the hotel management system.\n");

  return 0;
}