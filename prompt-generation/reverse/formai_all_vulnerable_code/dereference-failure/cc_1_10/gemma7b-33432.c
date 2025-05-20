//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct Room {
  int number;
  char type;
  int available;
  struct Guest *guest;
};

struct Guest {
  char name[20];
  int room_number;
  char type_of_room;
  int days_stayed;
  struct Payment *payment;
};

struct Payment {
  int amount;
  char payment_method;
  struct Guest *guest;
};

void create_room(struct Room **room) {
  *room = malloc(sizeof(struct Room));
  (*room)->number = 1;
  (*room)->type = 'D';
  (*room)->available = 1;
  (*room)->guest = NULL;
}

void create_guest(struct Guest **guest) {
  *guest = malloc(sizeof(struct Guest));
  (*guest)->name[0] = '\0';
  (*guest)->room_number = 0;
  (*guest)->type_of_room = '\0';
  (*guest)->days_stayed = 0;
  (*guest)->payment = NULL;
}

void create_payment(struct Payment **payment) {
  *payment = malloc(sizeof(struct Payment));
  (*payment)->amount = 0;
  (*payment)->payment_method = '\0';
  (*payment)->guest = NULL;
}

int main() {
  struct Room *room;
  create_room(&room);

  struct Guest *guest;
  create_guest(&guest);

  struct Payment *payment;
  create_payment(&payment);

  guest->room_number = room->number;
  guest->type_of_room = room->type;

  payment->amount = 100;
  payment->payment_method = 'C';
  payment->guest = guest;

  printf("Room number: %d\n", guest->room_number);
  printf("Type of room: %c\n", guest->type_of_room);
  printf("Days stayed: %d\n", guest->days_stayed);
  printf("Total payment: %d\n", payment->amount);
  printf("Payment method: %c\n", payment->payment_method);

  return 0;
}