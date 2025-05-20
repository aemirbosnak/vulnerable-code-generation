//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_PHONE_LEN 20
#define MAX_ADDR_LEN 50

// Global variables
char *phoneBook[10];
int numEntries = 0;

// Function to add an entry to the phone book
void addEntry(char *name, char *phone, char *addr) {
  if (numEntries >= 10) {
    printf("O_O Oh no! The phone book is full! :O\n");
    return;
  }

  // Check if the name is too long
  if (strlen(name) > MAX_NAME_LEN) {
    printf("O_O Whoa there! The name is too long! :O\n");
    return;
  }

  // Check if the phone number is too long
  if (strlen(phone) > MAX_PHONE_LEN) {
    printf("O_O That's a loooong phone number! :O\n");
    return;
  }

  // Check if the address is too long
  if (strlen(addr) > MAX_ADDR_LEN) {
    printf("O_O Whoa, that's a long address! :O\n");
    return;
  }

  // Add the entry to the phone book
  phoneBook[numEntries] = (char *)malloc(strlen(name) + 1 + strlen(phone) + 1 + strlen(addr) + 1);
  sprintf(phoneBook[numEntries], "%s %s %s", name, phone, addr);
  numEntries++;

  // Print the phone book
  printf("Here's the phone book:\n");
  for (int i = 0; i < numEntries; i++) {
    printf("%d. %s\n", i + 1, phoneBook[i]);
  }
}

int main() {
  // Add some entries to the phone book
  addEntry("John Doe", "123-4567", "123 Main St");
  addEntry("Jane Doe", "987-6543", "456 Elm St");
  addEntry("Bob Smith", "555-1234", "789 Oak St");

  // Print the phone book
  printf("Here's the phone book:\n");
  for (int i = 0; i < numEntries; i++) {
    printf("%d. %s\n", i + 1, phoneBook[i]);
  }

  return 0;
}