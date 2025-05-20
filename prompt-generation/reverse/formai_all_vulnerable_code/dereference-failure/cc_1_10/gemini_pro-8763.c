//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Visionary Phone Book Structure
typedef struct visionary_phone_book {
  char *name;
  char *number;
} visionary_phone_book;

// Function to create a new phone book entry
visionary_phone_book *create_phone_book_entry(char *name, char *number) {
  visionary_phone_book *entry = (visionary_phone_book *)malloc(sizeof(visionary_phone_book));
  entry->name = strdup(name);
  entry->number = strdup(number);
  return entry;
}

// Function to add a new entry to the phone book
void add_phone_book_entry(visionary_phone_book **phone_book, int *phone_book_size, visionary_phone_book *entry) {
  phone_book = (visionary_phone_book **)realloc(phone_book, (*phone_book_size + 1) * sizeof(visionary_phone_book *));
  phone_book[*phone_book_size] = entry;
  *phone_book_size = *phone_book_size + 1;
}

// Function to search for a phone number in the phone book
char *search_phone_book(visionary_phone_book **phone_book, int phone_book_size, char *name) {
  for (int i = 0; i < phone_book_size; i++) {
    if (strcmp(phone_book[i]->name, name) == 0) {
      return phone_book[i]->number;
    }
  }
  return NULL;
}

// Function to print the phone book
void print_phone_book(visionary_phone_book **phone_book, int phone_book_size) {
  for (int i = 0; i < phone_book_size; i++) {
    printf("%s: %s\n", phone_book[i]->name, phone_book[i]->number);
  }
}

// Main function
int main() {
  // Create a new phone book
  visionary_phone_book **phone_book = (visionary_phone_book **)malloc(0);
  int phone_book_size = 0;

  // Add some entries to the phone book
  add_phone_book_entry(phone_book, &phone_book_size, create_phone_book_entry("John Doe", "123-456-7890"));
  add_phone_book_entry(phone_book, &phone_book_size, create_phone_book_entry("Jane Doe", "098-765-4321"));
  add_phone_book_entry(phone_book, &phone_book_size, create_phone_book_entry("John Smith", "987-654-3210"));

  // Search for a phone number in the phone book
  char *number = search_phone_book(phone_book, phone_book_size, "John Doe");
  if (number != NULL) {
    printf("The phone number for John Doe is: %s\n", number);
  } else {
    printf("John Doe not found in the phone book.\n");
  }

  // Print the phone book
  printf("Phone Book:\n");
  print_phone_book(phone_book, phone_book_size);

  // Free the allocated memory
  for (int i = 0; i < phone_book_size; i++) {
    free(phone_book[i]->name);
    free(phone_book[i]->number);
    free(phone_book[i]);
  }
  free(phone_book);

  return 0;
}