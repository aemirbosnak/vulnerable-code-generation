//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: single-threaded
#include <stdio.h>
#include <string.h>

#define MAX_GUESTS 10

struct guest_record {
  char name[50];
  int room_no;
  char status;
  struct guest_record* next;
};

struct guest_record* head = NULL;

void add_guest(char* name, int room_no) {
  struct guest_record* new_guest = (struct guest_record*)malloc(sizeof(struct guest_record));

  strcpy(new_guest->name, name);
  new_guest->room_no = room_no;
  new_guest->status = 'O';

  if (head == NULL) {
    head = new_guest;
  } else {
    struct guest_record* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = new_guest;
  }
}

void check_guest(char* name) {
  struct guest_record* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      printf("Room No: %d\n", temp->room_no);
      printf("Status: %c\n", temp->status);
      break;
    }
    temp = temp->next;
  }
  if (temp == NULL) {
    printf("Guest not found.\n");
  }
}

int main() {
  add_guest("John Doe", 101);
  add_guest("Jane Doe", 102);
  add_guest("Peter Pan", 103);

  check_guest("John Doe");
  check_guest("Jane Doe");
  check_guest("Jack Sparrow");

  return 0;
}