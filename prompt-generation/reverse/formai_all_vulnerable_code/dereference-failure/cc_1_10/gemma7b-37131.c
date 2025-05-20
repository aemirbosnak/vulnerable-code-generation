//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_GOATS 10

typedef struct goat {
  char name[20];
  int room;
  struct goat* next;
} goat_t;

goat_t* create_goat(char* name, int room) {
  goat_t* goat = malloc(sizeof(goat_t));
  strcpy(goat->name, name);
  goat->room = room;
  goat->next = NULL;
  return goat;
}

void add_goat(goat_t* head, char* name, int room) {
  goat_t* new_goat = create_goat(name, room);
  if (head) {
    head->next = new_goat;
  } else {
    head = new_goat;
  }
}

int main() {
  srand(time(NULL));
  goat_t* head = NULL;
  for (int i = 0; i < MAX_GOATS; i++) {
    add_goat(head, "Goat", rand() % 5);
  }

  printf("Welcome to the Haunted House!\n");
  printf("Please enter a room number: ");
  int room_number = atoi(gets(NULL));

  goat_t* current_goat = head;
  while (current_goat && current_goat->room != room_number) {
    current_goat = current_goat->next;
  }

  if (current_goat) {
    printf("Welcome, %s! You are in room %d.\n", current_goat->name, current_goat->room);
  } else {
    printf("Sorry, there is no goat in that room.\n");
  }

  return 0;
}