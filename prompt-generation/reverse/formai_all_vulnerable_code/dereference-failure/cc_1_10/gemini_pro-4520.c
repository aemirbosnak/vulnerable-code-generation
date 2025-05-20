//GEMINI-pro DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 256
#define MAX_NUMBER 16
#define MAX_ENTRIES 100

// A phone book entry
typedef struct {
  char name[MAX_NAME];
  char number[MAX_NUMBER];
} Entry;

// A phone book
typedef struct {
  Entry entries[MAX_ENTRIES];
  int num_entries;
} PhoneBook;

// Create a new phone book
PhoneBook* new_phone_book() {
  PhoneBook* phone_book = malloc(sizeof(PhoneBook));
  phone_book->num_entries = 0;
  return phone_book;
}

// Add an entry to a phone book
void add_entry(PhoneBook* phone_book, char* name, char* number) {
  Entry entry;
  strcpy(entry.name, name);
  strcpy(entry.number, number);
  phone_book->entries[phone_book->num_entries++] = entry;
}

// Find an entry in a phone book by name
Entry* find_entry_by_name(PhoneBook* phone_book, char* name) {
  for (int i = 0; i < phone_book->num_entries; i++) {
    if (strcmp(phone_book->entries[i].name, name) == 0) {
      return &phone_book->entries[i];
    }
  }
  return NULL;
}

// Find an entry in a phone book by number
Entry* find_entry_by_number(PhoneBook* phone_book, char* number) {
  for (int i = 0; i < phone_book->num_entries; i++) {
    if (strcmp(phone_book->entries[i].number, number) == 0) {
      return &phone_book->entries[i];
    }
  }
  return NULL;
}

// Print a phone book
void print_phone_book(PhoneBook* phone_book) {
  printf("|------------------------------------------------------------------------|\n");
  printf("|%-25s|%-16s|\n", "Name", "Number");
  printf("|------------------------------------------------------------------------|\n");
  for (int i = 0; i < phone_book->num_entries; i++) {
    printf("|%-25s|%-16s|\n", phone_book->entries[i].name, phone_book->entries[i].number);
  }
  printf("|------------------------------------------------------------------------|\n");
}

// Free a phone book
void free_phone_book(PhoneBook* phone_book) {
  free(phone_book);
}

int main() {
  // Create a new phone book
  PhoneBook* phone_book = new_phone_book();

  // Add some entries to the phone book
  add_entry(phone_book, "John Doe", "555-1212");
  add_entry(phone_book, "Jane Doe", "555-1213");
  add_entry(phone_book, "Bob Smith", "555-1214");
  add_entry(phone_book, "Alice Smith", "555-1215");
  add_entry(phone_book, "Tom Jones", "555-1216");
  add_entry(phone_book, "Mary Jones", "555-1217");

  // Print the phone book
  print_phone_book(phone_book);

  // Find an entry in the phone book by name
  Entry* entry = find_entry_by_name(phone_book, "John Doe");
  if (entry != NULL) {
    printf("Found entry for John Doe: %s\n", entry->number);
  } else {
    printf("Entry for John Doe not found.\n");
  }

  // Find an entry in the phone book by number
  entry = find_entry_by_number(phone_book, "555-1212");
  if (entry != NULL) {
    printf("Found entry for 555-1212: %s\n", entry->name);
  } else {
    printf("Entry for 555-1212 not found.\n");
  }

  // Free the phone book
  free_phone_book(phone_book);

  return 0;
}