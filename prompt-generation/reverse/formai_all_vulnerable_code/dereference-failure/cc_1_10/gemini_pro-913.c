//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Room {
  int room_number;
  char* room_type;
  int capacity;
  float price;
  int is_occupied;
};

struct Hotel {
  char* hotel_name;
  struct Room* rooms;
  int num_rooms;
};

struct Guest {
  char* name;
  char* address;
  char* phone_number;
  char* email;
  int num_days;
  struct Room* room;
};

void initialize_hotel(struct Hotel* hotel, char* hotel_name, int num_rooms) {
  hotel->hotel_name = hotel_name;
  hotel->num_rooms = num_rooms;
  hotel->rooms = malloc(sizeof(struct Room) * num_rooms);
  for (int i = 0; i < num_rooms; i++) {
    hotel->rooms[i].room_number = i + 1;
    hotel->rooms[i].room_type = "Standard";
    hotel->rooms[i].capacity = 2;
    hotel->rooms[i].price = 100.00;
    hotel->rooms[i].is_occupied = 0;
  }
}

void print_hotel_info(struct Hotel* hotel) {
  printf("Hotel Name: %s\n", hotel->hotel_name);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  for (int i = 0; i < hotel->num_rooms; i++) {
    printf("Room %d: %s, Capacity: %d, Price: %.2f, Occupied: %d\n", hotel->rooms[i].room_number, hotel->rooms[i].room_type, hotel->rooms[i].capacity, hotel->rooms[i].price, hotel->rooms[i].is_occupied);
  }
}

void check_in_guest(struct Hotel* hotel, struct Guest* guest) {
  int room_number;
  printf("Enter the room number you want to check in to: ");
  scanf("%d", &room_number);
  if (room_number < 1 || room_number > hotel->num_rooms) {
    printf("Invalid room number. Please enter a valid room number.\n");
    return;
  }
  if (hotel->rooms[room_number - 1].is_occupied) {
    printf("Sorry, that room is already occupied. Please choose another room.\n");
    return;
  }
  hotel->rooms[room_number - 1].is_occupied = 1;
  guest->room = &hotel->rooms[room_number - 1];
  printf("Check-in successful. Your room number is %d.\n", room_number);
}

void check_out_guest(struct Hotel* hotel, struct Guest* guest) {
  if (guest->room == NULL) {
    printf("Error: Guest is not checked in.\n");
    return;
  }
  guest->room->is_occupied = 0;
  guest->room = NULL;
  printf("Check-out successful.\n");
}

int main() {
  struct Hotel hotel;
  struct Guest guest;
  int choice;

  initialize_hotel(&hotel, "Grand Hotel", 10);

  while (1) {
    printf("\n======= Hotel Management System =======\n");
    printf("1. Check In Guest\n");
    printf("2. Check Out Guest\n");
    printf("3. Print Hotel Info\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your name: ");
        scanf(" %[^\n]%*c", guest.name);
        printf("Enter your address: ");
        scanf(" %[^\n]%*c", guest.address);
        printf("Enter your phone number: ");
        scanf(" %[^\n]%*c", guest.phone_number);
        printf("Enter your email address: ");
        scanf(" %[^\n]%*c", guest.email);
        printf("Enter the number of days you want to stay: ");
        scanf("%d", &guest.num_days);
        check_in_guest(&hotel, &guest);
        break;
      case 2:
        printf("Enter your name: ");
        scanf(" %[^\n]%*c", guest.name);
        check_out_guest(&hotel, &guest);
        break;
      case 3:
        print_hotel_info(&hotel);
        break;
      case 4:
        exit(0);
      default:
        printf("Invalid choice. Please enter a valid choice.\n");
    }
  }

  return 0;
}