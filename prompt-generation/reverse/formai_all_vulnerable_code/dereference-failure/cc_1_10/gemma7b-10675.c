//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100

typedef struct Room {
  int room_number;
  char status;
  char guest_name[20];
  int num_guests;
  struct Room* next;
} Room;

typedef struct Hotel {
  Room* head;
  int num_rooms;
  int occupancy_rate;
  char name[20];
  struct Hotel* next;
} Hotel;

Hotel* create_hotel(char* name, int num_rooms) {
  Hotel* hotel = (Hotel*)malloc(sizeof(Hotel));
  hotel->head = NULL;
  hotel->num_rooms = num_rooms;
  hotel->occupancy_rate = 0;
  strcpy(hotel->name, name);
  hotel->next = NULL;
  return hotel;
}

void add_room(Hotel* hotel, int room_number, char status, char* guest_name, int num_guests) {
  Room* room = (Room*)malloc(sizeof(Room));
  room->room_number = room_number;
  room->status = status;
  strcpy(room->guest_name, guest_name);
  room->num_guests = num_guests;
  room->next = NULL;

  if (hotel->head == NULL) {
    hotel->head = room;
  } else {
    Room* last_room = hotel->head;
    while (last_room->next != NULL) {
      last_room = last_room->next;
    }
    last_room->next = room;
  }
  hotel->occupancy_rate++;
}

void check_room_status(Hotel* hotel, int room_number) {
  Room* room = hotel->head;
  while (room) {
    if (room->room_number == room_number) {
      printf("Room status: %c\n", room->status);
      printf("Guest name: %s\n", room->guest_name);
      printf("Number of guests: %d\n", room->num_guests);
      break;
    }
    room = room->next;
  }
  if (room == NULL) {
    printf("Room not found.\n");
  }
}

void update_room_status(Hotel* hotel, int room_number, char new_status) {
  Room* room = hotel->head;
  while (room) {
    if (room->room_number == room_number) {
      room->status = new_status;
      break;
    }
    room = room->next;
  }
  if (room == NULL) {
    printf("Room not found.\n");
  }
}

int main() {
  Hotel* hotel = create_hotel("The Grand Hotel", 100);

  add_room(hotel, 101, 'O', "John Doe", 2);
  add_room(hotel, 102, 'A', "Jane Doe", 1);
  add_room(hotel, 103, 'F', "Peter Pan", 3);

  check_room_status(hotel, 101);
  update_room_status(hotel, 102, 'C');

  check_room_status(hotel, 102);

  return 0;
}