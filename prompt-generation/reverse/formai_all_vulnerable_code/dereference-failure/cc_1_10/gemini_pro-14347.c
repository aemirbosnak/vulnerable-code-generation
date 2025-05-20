//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int room_number;
  char *room_type;
  double price;
} Room;

typedef struct {
  char *first_name;
  char *last_name;
  char *email;
  char *phone_number;
} Guest;

typedef struct {
  Room *room;
  Guest *guest;
  int check_in_date;
  int check_out_date;
} Reservation;

typedef struct {
  Reservation *reservations;
  int num_reservations;
} Hotel;

void create_hotel(Hotel *hotel) {
  hotel->reservations = malloc(sizeof(Reservation) * 100);
  hotel->num_reservations = 0;
}

void add_room(Hotel *hotel, Room *room) {
  hotel->reservations[hotel->num_reservations].room = room;
  hotel->num_reservations++;
}

void add_guest(Hotel *hotel, Guest *guest) {
  hotel->reservations[hotel->num_reservations].guest = guest;
  hotel->num_reservations++;
}

void add_reservation(Hotel *hotel, Reservation *reservation) {
  hotel->reservations[hotel->num_reservations] = *reservation;
  hotel->num_reservations++;
}

void print_hotel(Hotel *hotel) {
  for (int i = 0; i < hotel->num_reservations; i++) {
    printf("Reservation %d\n", i + 1);
    printf("Room: %s\n", hotel->reservations[i].room->room_type);
    printf("Guest: %s %s\n", hotel->reservations[i].guest->first_name, hotel->reservations[i].guest->last_name);
    printf("Check-in date: %d\n", hotel->reservations[i].check_in_date);
    printf("Check-out date: %d\n\n", hotel->reservations[i].check_out_date);
  }
}

int main() {
  Hotel hotel;
  create_hotel(&hotel);

  Room room1;
  room1.room_number = 101;
  room1.room_type = "Standard";
  room1.price = 100.0;

  Guest guest1;
  guest1.first_name = "John";
  guest1.last_name = "Doe";
  guest1.email = "john.doe@example.com";
  guest1.phone_number = "555-123-4567";

  Reservation reservation1;
  reservation1.room = &room1;
  reservation1.guest = &guest1;
  reservation1.check_in_date = 20230301;
  reservation1.check_out_date = 20230303;

  add_reservation(&hotel, &reservation1);

  print_hotel(&hotel);

  return 0;
}