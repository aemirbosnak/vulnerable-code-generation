//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the hotel management system structure
typedef struct HotelManagementSystem {
  char name[50];
  int rooms;
  int availableRooms;
  double ratePerNight;
  double totalRevenue;
  struct HotelManagementSystem* next;
} HotelManagementSystem;

// Function to create a new hotel management system node
HotelManagementSystem* createNode(char* name, int rooms, double ratePerNight) {
  HotelManagementSystem* newNode = (HotelManagementSystem*)malloc(sizeof(HotelManagementSystem));
  strcpy(newNode->name, name);
  newNode->rooms = rooms;
  newNode->availableRooms = rooms;
  newNode->ratePerNight = ratePerNight;
  newNode->totalRevenue = 0;
  newNode->next = NULL;
  return newNode;
}

// Function to insert a new hotel management system node at the end
void insertNode(HotelManagementSystem* head, char* name, int rooms, double ratePerNight) {
  HotelManagementSystem* newNode = createNode(name, rooms, ratePerNight);
  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }
  head = newNode;
}

// Function to check if a room is available
int isRoomAvailable(HotelManagementSystem* head, char* name, int rooms) {
  HotelManagementSystem* current = head;
  while (current) {
    if (strcmp(current->name, name) == 0 && current->availableRooms >= rooms) {
      return 1;
    }
    current = current->next;
  }
  return 0;
}

// Function to book a room
void bookRoom(HotelManagementSystem* head, char* name, int rooms, double days) {
  int available = isRoomAvailable(head, name, rooms);
  if (available) {
    HotelManagementSystem* current = head;
    while (current) {
      if (strcmp(current->name, name) == 0) {
        current->availableRooms -= rooms;
        current->totalRevenue += rooms * days * current->ratePerNight;
      }
      current = current->next;
    }
    printf("Room booked successfully.\n");
  } else {
    printf("Sorry, no rooms available.\n");
  }
}

int main() {
  HotelManagementSystem* head = NULL;
  insertNode(head, "The Grand Hotel", 100, 100);
  insertNode(head, "The Palace Hotel", 50, 150);
  insertNode(head, "The Royal Hotel", 75, 200);

  bookRoom(head, "The Grand Hotel", 20, 3);

  return 0;
}