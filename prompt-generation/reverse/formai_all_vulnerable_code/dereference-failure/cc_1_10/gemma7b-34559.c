//Gemma-7B DATASET v1.0 Category: Digital Diary ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a struct to store diary entries
typedef struct Entry {
  char *title;
  char *content;
  struct Entry *next;
} Entry;

// Function to insert a new entry into the diary
Entry *insertEntry(Entry *head) {
  Entry *newEntry = (Entry *)malloc(sizeof(Entry));
  newEntry->title = malloc(20);
  newEntry->content = malloc(100);

  // Get the title and content from the user
  printf("Enter the title of the entry:");
  scanf("%s", newEntry->title);

  printf("Enter the content of the entry:");
  scanf("%[^\n]%*c", newEntry->content);

  // Insert the new entry into the head of the list
  newEntry->next = head;
  head = newEntry;

  return head;
}

// Function to print all entries in the diary
void printEntries(Entry *head) {
  Entry *currentEntry = head;

  while (currentEntry) {
    printf("Title: %s\n", currentEntry->title);
    printf("Content: %s\n", currentEntry->content);
    printf("\n");
    currentEntry = currentEntry->next;
  }
}

int main() {
  // Create a new diary entry
  Entry *head = NULL;

  // Insert some entries
  head = insertEntry(head);
  insertEntry(head);
  insertEntry(head);

  // Print all entries
  printEntries(head);

  return 0;
}