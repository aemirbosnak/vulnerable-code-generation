//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
  char name[50];
  int room_num;
  struct Guest* next;
} Guest;

Guest* head = NULL;

void insertGuest(char* name, int room_num) {
  Guest* newGuest = (Guest*)malloc(sizeof(Guest));
  strcpy(newGuest->name, name);
  newGuest->room_num = room_num;
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
}

void printGuests() {
  Guest* temp = head;
  while (temp) {
    printf("%s in room %d\n", temp->name, temp->room_num);
    temp = temp->next;
  }
}

void searchGuest(char* name) {
  Guest* temp = head;
  while (temp) {
    if (strcmp(temp->name, name) == 0) {
      printf("%s is in room %d\n", temp->name, temp->room_num);
      return;
    }
    temp = temp->next;
  }
  printf("Guest not found\n");
}

int main() {
  insertGuest("John Doe", 101);
  insertGuest("Jane Doe", 102);
  insertGuest("Peter Pan", 103);

  printGuests();

  searchGuest("Jane Doe");

  return 0;
}