//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

typedef struct HotelRoom {
  int number;
  char type;
  int occupancy;
  struct HotelRoom* next;
} HotelRoom;

typedef struct Receptionist {
  char name[50];
  int extension;
  struct Receptionist* next;
} Receptionist;

HotelRoom* createRoom(int number, char type, int occupancy);
Receptionist* createReceptionist(char name, int extension);

int main() {
  HotelRoom* head = createRoom(101, 'A', 2);
  Receptionist* headR = createReceptionist("John Doe", 123);

  headR->next = createReceptionist("Jane Doe", 456);

  head->next = createRoom(102, 'B', 1);

  head->next->next = createRoom(103, 'A', 0);

  printf("Room number: %d, type: %c, occupancy: %d\n", head->number, head->type, head->occupancy);

  printf("Receptionist name: %s, extension: %d\n", headR->name, headR->extension);

  printf("Receptionist name: %s, extension: %d\n", headR->next->name, headR->next->extension);

  return 0;
}

HotelRoom* createRoom(int number, char type, int occupancy) {
  HotelRoom* newRoom = (HotelRoom*)malloc(sizeof(HotelRoom));
  newRoom->number = number;
  newRoom->type = type;
  newRoom->occupancy = occupancy;
  newRoom->next = NULL;
  return newRoom;
}

Receptionist* createReceptionist(char name, int extension) {
  Receptionist* newReceptionist = (Receptionist*)malloc(sizeof(Receptionist));
  strcpy(newReceptionist->name, name);
  newReceptionist->extension = extension;
  newReceptionist->next = NULL;
  return newReceptionist;
}