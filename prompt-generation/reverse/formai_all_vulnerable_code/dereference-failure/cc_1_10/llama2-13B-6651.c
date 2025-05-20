//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: lively
// The Ultimate C Phone Book Program! 📞📱

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Global variables 🌎
const int MAX_NAME_LENGTH = 25;
const int MAX_PHONE_NUMBER_LENGTH = 15;
const int MAX_ENTRIES = 100;

// Function declarations 📝
void addEntry(char** phoneBook, int* numEntries, const char* name, const char* phoneNumber);
void searchEntry(char** phoneBook, int numEntries, const char* name);
void removeEntry(char** phoneBook, int numEntries, const char* name);

int main() {
  // Initialize phone book 📞
  char** phoneBook = (char**) malloc(MAX_ENTRIES * sizeof(char*));
  int numEntries = 0;

  // Add some entries 📣
  addEntry(phoneBook, &numEntries, "John Doe", "555-1234");
  addEntry(phoneBook, &numEntries, "Jane Doe", "555-5678");
  addEntry(phoneBook, &numEntries, "Bob Smith", "555-9012");

  // Search for an entry 🔎
  searchEntry(phoneBook, numEntries, "John Doe");

  // Remove an entry 💥
  removeEntry(phoneBook, numEntries, "Jane Doe");

  // Print the updated phone book 📝
  printf("Phone Book:\n");
  for (int i = 0; i < numEntries; i++) {
    printf("%d: %s %s\n", i, phoneBook[i], phoneBook[i + 1]);
  }

  // Free memory 💥
  free(phoneBook);

  return 0;
}

// Function implementations 🔧
void addEntry(char** phoneBook, int* numEntries, const char* name, const char* phoneNumber) {
  // Check if the name is too long 🤷‍♀️
  if (strlen(name) > MAX_NAME_LENGTH) {
    printf("Error: Name too long!\n");
    return;
  }

  // Check if the phone number is too long 📞
  if (strlen(phoneNumber) > MAX_PHONE_NUMBER_LENGTH) {
    printf("Error: Phone number too long!\n");
    return;
  }

  // Allocate memory for the new entry 📈
  char* newEntry = (char*) malloc(sizeof(char) * (strlen(name) + 1 + strlen(phoneNumber) + 1));
  sprintf(newEntry, "%s %s", name, phoneNumber);

  // Add the new entry to the phone book 📝
  phoneBook[(*numEntries)++] = newEntry;
  phoneBook[(*numEntries)++] = NULL;
}

void searchEntry(char** phoneBook, int numEntries, const char* name) {
  int i;
  for (i = 0; i < numEntries; i++) {
    if (strcmp(phoneBook[i], name) == 0) {
      printf("%d: %s\n", i, phoneBook[i + 1]);
      break;
    }
  }
}

void removeEntry(char** phoneBook, int numEntries, const char* name) {
  int i;
  for (i = 0; i < numEntries; i++) {
    if (strcmp(phoneBook[i], name) == 0) {
      // Found the entry, remove it 💥
      for (int j = i; j < numEntries - 1; j++) {
        phoneBook[j] = phoneBook[j + 1];
      }
      numEntries--;
      break;
    }
  }
}