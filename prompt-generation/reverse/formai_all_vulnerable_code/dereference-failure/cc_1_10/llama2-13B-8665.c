//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: invasive
// Invasive Phone Book Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables
char *phoneBook[100];
int numEntries = 0;

// Function to add an entry to the phone book
void addEntry(char *name, char *number) {
  // Check if the phone book is full
  if (numEntries == 100) {
    printf("Phone book is full! Sorry, cannot add any more entries.\n");
    return;
  }

  // Allocate memory for the new entry
  char *newEntry = (char *)malloc(strlen(name) + strlen(number) + 2);
  sprintf(newEntry, "%s %s", name, number);

  // Add the new entry to the phone book
  phoneBook[numEntries] = newEntry;
  numEntries++;

  // Print the updated phone book
  printf("Phone book updated with entry: %s %s\n", name, number);
}

// Function to search for an entry in the phone book
char *searchEntry(char *name) {
  int i;

  // Search for the name in the phone book
  for (i = 0; i < numEntries; i++) {
    if (strcmp(phoneBook[i], name) == 0) {
      return phoneBook[i];
    }
  }

  // If the name is not found, return a null pointer
  return NULL;
}

int main() {
  // Test the addEntry function
  addEntry("John Doe", "555-1234");
  addEntry("Jane Doe", "555-5678");
  addEntry("Bob Smith", "555-9012");

  // Test the searchEntry function
  char *foundEntry = searchEntry("John Doe");
  if (foundEntry != NULL) {
    printf("Found entry: %s\n", foundEntry);
  } else {
    printf("Entry not found\n");
  }

  return 0;
}