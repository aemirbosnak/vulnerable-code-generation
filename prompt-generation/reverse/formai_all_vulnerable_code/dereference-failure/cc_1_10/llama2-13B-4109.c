//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the phone book structure
struct phone_book {
  char name[50];
  char number[20];
  struct phone_book *next;
};

// Function to insert a new entry into the phone book
void insert_entry(struct phone_book **head_ref, char *name, char *number) {
  struct phone_book *new_entry = (struct phone_book *)malloc(sizeof(struct phone_book));
  strcpy(new_entry->name, name);
  strcpy(new_entry->number, number);
  new_entry->next = *head_ref;
  *head_ref = new_entry;
}

// Function to search for an entry in the phone book
struct phone_book *search_entry(struct phone_book *head, char *name) {
  struct phone_book *current = head;
  while (current != NULL && strcmp(current->name, name) != 0) {
    current = current->next;
  }
  return current;
}

// Function to print the phone book
void print_phone_book(struct phone_book *head) {
  struct phone_book *current = head;
  while (current != NULL) {
    printf("%s %s\n", current->name, current->number);
    current = current->next;
  }
}

int main() {
  // Create a new phone book
  struct phone_book *head = NULL;

  // Insert some entries
  insert_entry(&head, "John Doe", "555-1234");
  insert_entry(&head, "Jane Doe", "555-5678");
  insert_entry(&head, "Bob Smith", "555-9012");

  // Search for an entry
  struct phone_book *found = search_entry(head, "Jane Doe");
  if (found != NULL) {
    printf("Found Jane Doe's number: %s\n", found->number);
  } else {
    printf("No such entry found\n");
  }

  // Print the phone book
  print_phone_book(head);

  return 0;
}