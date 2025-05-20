//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[50];
  int room_no;
  char status;
  struct Guest* next;
} Guest;

Guest* insertGuest(Guest* head, char* name, int room_no, char status) {
  Guest* newGuest = (Guest*)malloc(sizeof(Guest));
  strcpy(newGuest->name, name);
  newGuest->room_no = room_no;
  newGuest->status = status;
  newGuest->next = NULL;

  if (head == NULL) {
    head = newGuest;
  } else {
    Guest* temp = head;
    while (temp->next) {
      temp = temp->next;
    }
    temp->next = newGuest;
  }

  return head;
}

void printGuests(Guest* head) {
  Guest* temp = head;
  while (temp) {
    printf("%s, Room No: %d, Status: %c\n", temp->name, temp->room_no, temp->status);
    temp = temp->next;
  }
}

int main() {
  Guest* head = NULL;

  insertGuest(head, "John Doe", 101, 'O');
  insertGuest(head, "Jane Doe", 102, 'C');
  insertGuest(head, "Peter Pan", 103, 'A');

  printGuests(head);

  return 0;
}