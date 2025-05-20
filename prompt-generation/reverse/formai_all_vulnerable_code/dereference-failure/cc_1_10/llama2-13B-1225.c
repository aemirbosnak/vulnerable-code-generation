//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 20

// Define a struct to hold a person's name and phone number
struct person {
  char name[MAX_NAME_LENGTH];
  char phone_number[MAX_PHONE_NUMBER_LENGTH];
};

// Function to create a new person struct
struct person create_person(char *name, char *phone_number) {
  struct person new_person;
  strcpy(new_person.name, name);
  strcpy(new_person.phone_number, phone_number);
  return new_person;
}

// Function to print a person's information
void print_person(struct person person) {
  printf("Name: %s\nPhone Number: %s\n", person.name, person.phone_number);
}

// Function to add a new person to the phone book
void add_person(struct person *phone_book, char *name, char *phone_number) {
  struct person new_person = create_person(name, phone_number);
  int i = 0;
  while (phone_book[i].name != NULL) {
    i++;
  }
  phone_book[i] = new_person;
}

// Function to search for a person in the phone book
struct person *search_person(struct person *phone_book, char *name) {
  int i = 0;
  while (phone_book[i].name != NULL) {
    if (strcmp(name, phone_book[i].name) == 0) {
      return &phone_book[i];
    }
    i++;
  }
  return NULL;
}

// Function to remove a person from the phone book
void remove_person(struct person *phone_book, char *name) {
  int i = 0;
  while (phone_book[i].name != NULL) {
    if (strcmp(name, phone_book[i].name) == 0) {
      memset(phone_book[i].name, 0, MAX_NAME_LENGTH);
      memset(phone_book[i].phone_number, 0, MAX_PHONE_NUMBER_LENGTH);
      break;
    }
    i++;
  }
}

int main() {
  struct person *phone_book = malloc(sizeof(struct person) * 10);
  char name[MAX_NAME_LENGTH];
  char phone_number[MAX_PHONE_NUMBER_LENGTH];

  // Add some people to the phone book
  add_person(phone_book, "John Doe", "555-1234");
  add_person(phone_book, "Jane Doe", "555-5678");
  add_person(phone_book, "Bob Smith", "555-9012");

  // Search for a person in the phone book
  struct person *john = search_person(phone_book, "John Doe");
  if (john != NULL) {
    print_person(*john);
  } else {
    printf("Person not found.\n");
  }

  // Remove a person from the phone book
  remove_person(phone_book, "Jane Doe");

  // Print the remaining people in the phone book
  for (int i = 0; i < 10; i++) {
    if (phone_book[i].name != NULL) {
      print_person(phone_book[i]);
    }
  }

  free(phone_book);
  return 0;
}