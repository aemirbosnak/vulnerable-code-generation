//Gemma-7B DATASET v1.0 Category: Phone Book ; Style: Alan Turing
// A unique C Phone Book program in the style of Alan Turing

#include <stdio.h>
#include <string.h>

// Define the maximum number of entries in the phone book
#define MAX_ENTRIES 100

// Define the structure of a phone book entry
typedef struct Entry {
  char name[50];
  char number[20];
  struct Entry* next;
} Entry;

// Create a linked list of phone book entries
Entry* head = NULL;

// Function to insert a new entry into the phone book
void insertEntry(char* name, char* number) {
  // Allocate memory for a new entry
  Entry* newEntry = malloc(sizeof(Entry));

  // Copy the name and number of the new entry
  strcpy(newEntry->name, name);
  strcpy(newEntry->number, number);

  // If the phone book is empty, make the new entry the head of the list
  if (head == NULL) {
    head = newEntry;
  } else {
    // Traverse the phone book to the end and insert the new entry there
    Entry* currentEntry = head;
    while (currentEntry->next != NULL) {
      currentEntry = currentEntry->next;
    }
    currentEntry->next = newEntry;
  }
}

// Function to search for an entry in the phone book
Entry* searchEntry(char* name) {
  // Traverse the phone book to find the entry with the specified name
  Entry* currentEntry = head;
  while (currentEntry) {
    if (strcmp(currentEntry->name, name) == 0) {
      return currentEntry;
    }
    currentEntry = currentEntry->next;
  }
  return NULL;
}

// Main function
int main() {
  // Insert some entries into the phone book
  insertEntry("John Doe", "555-123-4567");
  insertEntry("Jane Doe", "555-456-7890");
  insertEntry("Bill Smith", "555-341-5926");

  // Search for an entry in the phone book
  Entry* entry = searchEntry("Jane Doe");

  // If the entry was found, print its name and number
  if (entry) {
    printf("Name: %s\n", entry->name);
    printf("Number: %s\n", entry->number);
  } else {
    printf("Entry not found.\n");
  }

  return 0;
}