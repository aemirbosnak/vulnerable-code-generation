//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 255

struct Person {
  char name[MAX_NAME_LENGTH];
  int age;
  double income;
  double assets;
  double liabilities;
  struct Person* next;
};

struct Person* insert_person(struct Person* head, char* name, int age, double income, double assets, double liabilities) {
  struct Person* new_person = malloc(sizeof(struct Person));
  strcpy(new_person->name, name);
  new_person->age = age;
  new_person->income = income;
  new_person->assets = assets;
  new_person->liabilities = liabilities;
  new_person->next = NULL;

  if (head == NULL) {
    head = new_person;
  } else {
    head->next = new_person;
  }

  return head;
}

void print_person(struct Person* person) {
  printf("Name: %s\n", person->name);
  printf("Age: %d\n", person->age);
  printf("Income: %.2lf\n", person->income);
  printf("Assets: %.2lf\n", person->assets);
  printf("Liabilities: %.2lf\n", person->liabilities);
  printf("\n");
}

int main() {
  struct Person* head = NULL;

  insert_person(head, "John Doe", 25, 50000, 100000, 20000);
  insert_person(head, "Jane Doe", 30, 60000, 150000, 30000);
  insert_person(head, "Bill Smith", 40, 70000, 200000, 40000);

  print_person(head);

  return 0;
}