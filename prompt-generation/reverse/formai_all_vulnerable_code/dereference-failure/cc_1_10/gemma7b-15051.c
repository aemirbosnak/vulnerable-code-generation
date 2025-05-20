//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: paranoid
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[20];
  int room_num;
  struct Guest* next;
} Guest;

Guest* create_guest(char* name, int room_num) {
  Guest* new_guest = (Guest*)malloc(sizeof(Guest));
  strcpy(new_guest->name, name);
  new_guest->room_num = room_num;
  new_guest->next = NULL;
  return new_guest;
}

void add_guest(Guest* head, char* name, int room_num) {
  Guest* new_guest = create_guest(name, room_num);
  if (head == NULL) {
    head = new_guest;
  } else {
    head->next = new_guest;
  }
  head = new_guest;
}

int check_guest(Guest* head, char* name) {
  Guest* current_guest = head;
  while (current_guest) {
    if (strcmp(current_guest->name, name) == 0) {
      return current_guest->room_num;
    }
    current_guest = current_guest->next;
  }
  return -1;
}

int main() {
  Guest* head = NULL;
  add_guest(head, "John Doe", 101);
  add_guest(head, "Jane Doe", 102);
  add_guest(head, "Jack Doe", 103);

  int room_num = check_guest(head, "John Doe");
  if (room_num != -1) {
    printf("Room number: %d\n", room_num);
  } else {
    printf("Guest not found.\n");
  }

  return 0;
}