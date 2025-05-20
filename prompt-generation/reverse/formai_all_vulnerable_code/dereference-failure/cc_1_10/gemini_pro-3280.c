//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  int room_number;
  int nights_staying;
  float bill;
};

struct hotel {
  char name[50];
  char address[100];
  char phone[20];
  char email[50];
  int num_rooms;
  int num_guests;
  struct guest *guests;
};

void print_guest(struct guest *guest) {
  printf("Name: %s\n", guest->name);
  printf("Address: %s\n", guest->address);
  printf("Phone: %s\n", guest->phone);
  printf("Email: %s\n", guest->email);
  printf("Room Number: %d\n", guest->room_number);
  printf("Nights Staying: %d\n", guest->nights_staying);
  printf("Bill: %f\n", guest->bill);
}

void print_hotel(struct hotel *hotel) {
  printf("Name: %s\n", hotel->name);
  printf("Address: %s\n", hotel->address);
  printf("Phone: %s\n", hotel->phone);
  printf("Email: %s\n", hotel->email);
  printf("Number of Rooms: %d\n", hotel->num_rooms);
  printf("Number of Guests: %d\n", hotel->num_guests);
}

void add_guest(struct hotel *hotel, struct guest *guest) {
  hotel->guests = realloc(hotel->guests, (hotel->num_guests + 1) * sizeof(struct guest));
  hotel->guests[hotel->num_guests++] = *guest;
}

void check_in_guest(struct hotel *hotel, struct guest *guest) {
  guest->room_number = hotel->num_rooms++;
  add_guest(hotel, guest);
}

void check_out_guest(struct hotel *hotel, struct guest *guest) {
  for (int i = 0; i < hotel->num_guests; i++) {
    if (strcmp(hotel->guests[i].name, guest->name) == 0) {
      hotel->guests[i] = hotel->guests[hotel->num_guests - 1];
      hotel->num_guests--;
      break;
    }
  }
}

int main() {
  struct hotel hotel = {
    .name = "The Grand Hotel",
    .address = "123 Main Street",
    .phone = "555-555-5555",
    .email = "info@grandhotel.com"
  };

  struct guest guest1 = {
    .name = "John Doe",
    .address = "123 Any Street",
    .phone = "555-555-5555",
    .email = "john.doe@example.com"
  };

  struct guest guest2 = {
    .name = "Jane Doe",
    .address = "123 Any Street",
    .phone = "555-555-5556",
    .email = "jane.doe@example.com"
  };

  check_in_guest(&hotel, &guest1);
  check_in_guest(&hotel, &guest2);

  print_hotel(&hotel);
  printf("\n");

  print_guest(&guest1);
  printf("\n");

  print_guest(&guest2);
  printf("\n");

  check_out_guest(&hotel, &guest1);

  print_hotel(&hotel);
  printf("\n");

  return 0;
}