//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
char *phonebook[10];
int numEntries = 0;

// Function to insert an entry into the phone book
void insertEntry(char *name, char *phone) {
  // Check if the name already exists in the phone book
  int i;
  for (i = 0; i < numEntries; i++) {
    if (strcmp(phonebook[i], name) == 0) {
      printf("Error: Name already exists in the phone book!\n");
      return;
    }
  }

  // If the name does not exist, allocate memory for the new entry
  phonebook[numEntries] = malloc(strlen(name) + strlen(phone) + 2);
  sprintf(phonebook[numEntries], "%s %s", name, phone);
  numEntries++;
}

// Function to search for an entry in the phone book
char *searchEntry(char *name) {
  int i;
  for (i = 0; i < numEntries; i++) {
    if (strcmp(phonebook[i], name) == 0) {
      return phonebook[i];
    }
  }
  return NULL;
}

int main() {
  // Insert some entries into the phone book
  insertEntry("John Doe", "555-1234");
  insertEntry("Jane Doe", "555-5678");
  insertEntry("Bob Smith", "555-9012");

  // Search for an entry in the phone book
  char *phone = searchEntry("John Doe");
  if (phone != NULL) {
    printf("Found %s's phone number: %s\n", phone, phonebook[0]);
  } else {
    printf("Error: No such entry in the phone book\n");
  }

  return 0;
}