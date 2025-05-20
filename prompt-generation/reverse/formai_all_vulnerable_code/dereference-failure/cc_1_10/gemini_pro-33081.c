//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
  char *name;
  char *phone_number;
} Person;

typedef struct PhoneBook {
  int capacity;
  int size;
  Person **entries;
} PhoneBook;

PhoneBook *create_phone_book(int capacity) {
  PhoneBook *phone_book = (PhoneBook *)malloc(sizeof(PhoneBook));
  phone_book->capacity = capacity;
  phone_book->size = 0;
  phone_book->entries = (Person **)malloc(sizeof(Person *) * capacity);
  return phone_book;
}

void destroy_phone_book(PhoneBook *phone_book) {
  for (int i = 0; i < phone_book->size; i++) {
    free(phone_book->entries[i]->name);
    free(phone_book->entries[i]->phone_number);
    free(phone_book->entries[i]);
  }
  free(phone_book->entries);
  free(phone_book);
}

void add_person(PhoneBook *phone_book, char *name, char *phone_number) {
  if (phone_book->size == phone_book->capacity) {
    phone_book->capacity *= 2;
    phone_book->entries = (Person **)realloc(phone_book->entries,
                                               sizeof(Person *) * phone_book->capacity);
  }

  Person *person = (Person *)malloc(sizeof(Person));
  person->name = (char *)malloc(strlen(name) + 1);
  strcpy(person->name, name);
  person->phone_number = (char *)malloc(strlen(phone_number) + 1);
  strcpy(person->phone_number, phone_number);

  phone_book->entries[phone_book->size++] = person;
}

void remove_person(PhoneBook *phone_book, char *name) {
  for (int i = 0; i < phone_book->size; i++) {
    if (strcmp(phone_book->entries[i]->name, name) == 0) {
      free(phone_book->entries[i]->name);
      free(phone_book->entries[i]->phone_number);
      free(phone_book->entries[i]);

      for (int j = i; j < phone_book->size - 1; j++) {
        phone_book->entries[j] = phone_book->entries[j + 1];
      }

      phone_book->size--;
      break;
    }
  }
}

Person *find_person(PhoneBook *phone_book, char *name) {
  for (int i = 0; i < phone_book->size; i++) {
    if (strcmp(phone_book->entries[i]->name, name) == 0) {
      return phone_book->entries[i];
    }
  }

  return NULL;
}

void print_phone_book(PhoneBook *phone_book) {
  for (int i = 0; i < phone_book->size; i++) {
    printf("%s (%s)\n", phone_book->entries[i]->name, phone_book->entries[i]->phone_number);
  }
}

int main() {
  PhoneBook *phone_book = create_phone_book(10);
  add_person(phone_book, "John Doe", "555-1212");
  add_person(phone_book, "Jane Doe", "555-1213");
  add_person(phone_book, "Bill Smith", "555-1214");
  add_person(phone_book, "Alice Johnson", "555-1215");
  add_person(phone_book, "Bob Johnson", "555-1216");

  print_phone_book(phone_book);

  remove_person(phone_book, "John Doe");
  remove_person(phone_book, "Bill Smith");

  print_phone_book(phone_book);

  Person *person = find_person(phone_book, "Jane Doe");
  if (person) {
    printf("Found person: %s (%s)\n", person->name, person->phone_number);
  } else {
    printf("Person not found.\n");
  }

  destroy_phone_book(phone_book);

  return 0;
}