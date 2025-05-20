//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

struct guest {
  char name[50];
  int room_number;
  char status;
  struct guest* next;
};

struct room {
  int number;
  struct guest* head;
  struct room* next;
};

struct hotel {
  struct room* head;
  int num_rooms;
  int num_guests;
  struct guest* guest_list;
};

void add_guest(struct hotel* h, char* name, int room_number)
{
  struct guest* new_guest = malloc(sizeof(struct guest));
  strcpy(new_guest->name, name);
  new_guest->room_number = room_number;
  new_guest->status = 'O';
  new_guest->next = NULL;

  if (h->guest_list == NULL)
  {
    h->guest_list = new_guest;
  }
  else
  {
    struct guest* temp = h->guest_list;
    while (temp->next)
    {
      temp = temp->next;
    }
    temp->next = new_guest;
  }

  h->num_guests++;
}

void check_in(struct hotel* h, char* name)
{
  struct guest* temp = h->guest_list;
  while (temp)
  {
    if (strcmp(temp->name, name) == 0)
    {
      temp->status = 'I';
      printf("Welcome, %s. Your room number is %d.\n", temp->name, temp->room_number);
      return;
    }
    temp = temp->next;
  }

  printf("Error: Guest not found.\n");
}

void check_out(struct hotel* h, char* name)
{
  struct guest* temp = h->guest_list;
  while (temp)
  {
    if (strcmp(temp->name, name) == 0)
    {
      temp->status = 'O';
      printf("Goodbye, %s. We hope you enjoyed your stay.\n", temp->name);
      return;
    }
    temp = temp->next;
  }

  printf("Error: Guest not found.\n");
}

int main()
{
  struct hotel h;
  h.num_rooms = 100;
  h.num_guests = 0;
  h.guest_list = NULL;
  h.head = NULL;

  add_guest(&h, "John Doe", 101);
  add_guest(&h, "Jane Doe", 102);
  add_guest(&h, "Bill Smith", 103);

  check_in(&h, "John Doe");
  check_out(&h, "Jane Doe");

  return 0;
}