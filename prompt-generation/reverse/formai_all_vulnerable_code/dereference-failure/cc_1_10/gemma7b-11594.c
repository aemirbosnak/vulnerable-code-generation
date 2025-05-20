//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define EAST_SIDE 1
#define WEST_SIDE 2

typedef struct PhoneBookEntry {
  char name[20];
  int side;
  struct PhoneBookEntry* next;
} PhoneBookEntry;

PhoneBookEntry* insertEntry(PhoneBookEntry* head, char* name, int side) {
  PhoneBookEntry* newNode = (PhoneBookEntry*)malloc(sizeof(PhoneBookEntry));
  strcpy(newNode->name, name);
  newNode->side = side;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void printBook(PhoneBookEntry* head) {
  PhoneBookEntry* current = head;
  while (current) {
    printf("%s (%d) - ", current->name, current->side);
    current = current->next;
  }
  printf("\n");
}

int main() {
  PhoneBookEntry* eastHead = NULL;
  PhoneBookEntry* westHead = NULL;

  insertEntry(&eastHead, "Montague", EAST_SIDE);
  insertEntry(&eastHead, "Capulet", EAST_SIDE);
  insertEntry(&westHead, "Mercutio", WEST_SIDE);
  insertEntry(&westHead, "Tybalt", WEST_SIDE);

  printBook(eastHead);
  printBook(westHead);

  return 0;
}