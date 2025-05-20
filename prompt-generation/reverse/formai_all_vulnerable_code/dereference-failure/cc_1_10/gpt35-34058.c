//FormAI DATASET v1.0 Category: Database querying ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_ADDRESS_LEN 200
#define MAX_PHONE_LEN 20

typedef struct {
  int id;
  char name[MAX_NAME_LEN];
  char address[MAX_ADDRESS_LEN];
  char phone[MAX_PHONE_LEN];
} person;

void insert_person(person* p) {
  // Code to insert person into database
}

person* query_person(int id) {
  // Code to query person from database by id
  // Return NULL if person is not found in database
}

void update_person(person* p) {
  // Code to update person in database
}

void delete_person(int id) {
  // Code to delete person from database by id
}

void print_person(person* p) {
  printf("ID: %d\n", p->id);
  printf("Name: %s\n", p->name);
  printf("Address: %s\n", p->address);
  printf("Phone: %s\n", p->phone);
}

int main() {
  // Example usage
  person* p = (person*) malloc(sizeof(person));
  p->id = 1234;
  strcpy(p->name, "John Doe");
  strcpy(p->address, "123 Main St");
  strcpy(p->phone, "555-1234");

  insert_person(p);

  person* queried_p = query_person(1234);
  if (queried_p != NULL) {
    print_person(queried_p);
    strcpy(queried_p->name, "Jane Doe");
    update_person(queried_p);
    delete_person(queried_p->id);
  }

  free(p);
  free(queried_p);
  return 0;
}