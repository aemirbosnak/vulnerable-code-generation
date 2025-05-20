//Gemma-7B DATASET v1.0 Category: Database querying ; Style: funny
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 255

typedef struct Person {
  char name[MAX_NAME_LENGTH];
  int age;
  struct Person* next;
} Person;

int main() {
  Person* head = NULL;
  Person* tail = NULL;

  // Create a bunch of people
  Person* bob = malloc(sizeof(Person));
  strcpy(bob->name, "Bob");
  bob->age = 30;

  Person* alice = malloc(sizeof(Person));
  strcpy(alice->name, "Alice");
  alice->age = 25;

  Person* tom = malloc(sizeof(Person));
  strcpy(tom->name, "Tom");
  tom->age = 40;

  // Link the people together
  head = bob;
  tail = bob;

  tail->next = alice;
  tail = alice;

  tail->next = tom;
  tail = tom;

  // Query the database
  printf("People over 30:\n");

  Person* current = head;
  while (current) {
    if (current->age > 30) {
      printf("%s is over 30.\n", current->name);
    }
    current = current->next;
  }

  // Free the memory
  free(bob);
  free(alice);
  free(tom);

  return 0;
}