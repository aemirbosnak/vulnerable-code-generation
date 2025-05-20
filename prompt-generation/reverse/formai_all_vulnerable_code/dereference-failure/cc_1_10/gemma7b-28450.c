//Gemma-7B DATASET v1.0 Category: System administration ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

typedef struct Person {
  char name[MAX_NAME_LENGTH];
  int age;
  struct Person* next;
} Person;

int main() {
  Person* pHead = NULL;
  Person* pTail = NULL;

  // Create a few people
  Person* p1 = malloc(sizeof(Person));
  strcpy(p1->name, "Romeo");
  p1->age = 16;
  p1->next = NULL;

  Person* p2 = malloc(sizeof(Person));
  strcpy(p2->name, "Juliet");
  p2->age = 15;
  p2->next = NULL;

  Person* p3 = malloc(sizeof(Person));
  strcpy(p3->name, "Benvolio");
  p3->age = 17;
  p3->next = NULL;

  // Add people to the list
  if (pHead == NULL) {
    pHead = p1;
    pTail = p1;
  } else {
    pTail->next = p2;
    pTail = p2;
  }
  pTail->next = p3;

  // Print the list of people
  Person* current = pHead;
  while (current) {
    printf("%s (age: %d)\n", current->name, current->age);
    current = current->next;
  }

  return 0;
}