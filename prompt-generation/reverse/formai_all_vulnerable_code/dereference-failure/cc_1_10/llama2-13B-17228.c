//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a knight on the list
struct knight {
  int id;   // Unique identifier for each knight
  char name[20]; // Name of the knight
  int armor;  // Armor class for the knight
  int attack; // Attack strength for the knight
  struct knight *next; // Pointer to the next knight on the list
};

// Function to create a new knight and add it to the list
struct knight *add_knight(struct knight **head_ref, int id, char *name, int armor, int attack) {
  struct knight *new_knight = malloc(sizeof(struct knight));
  new_knight->id = id;
  strcpy(new_knight->name, name);
  new_knight->armor = armor;
  new_knight->attack = attack;
  new_knight->next = *head_ref;
  *head_ref = new_knight;
  return new_knight;
}

// Function to remove a knight from the list
struct knight *remove_knight(struct knight **head_ref, int id) {
  struct knight *current = *head_ref;
  struct knight *prev = NULL;

  while (current != NULL && current->id != id) {
    prev = current;
    current = current->next;
  }

  if (current != NULL) {
    if (prev == NULL) {
      *head_ref = current->next;
    } else {
      prev->next = current->next;
    }
    free(current);
    return current;
  }

  return NULL;
}

// Function to print all the knights on the list
void print_knights(struct knight *head) {
  while (head != NULL) {
    printf("%d: %s (%d armor, %d attack)\n", head->id, head->name, head->armor, head->attack);
    head = head->next;
  }
}

int main() {
  struct knight *head = NULL;

  // Add some knights to the list
  add_knight(&head, 1, "Sir Lancelot", 5, 10);
  add_knight(&head, 2, "Sir Gawain", 4, 8);
  add_knight(&head, 3, "Sir Percival", 3, 6);

  // Remove a knight from the list
  struct knight *removed = remove_knight(&head, 2);
  if (removed != NULL) {
    printf("Removed Sir Gawain from the list\n");
  } else {
    printf("Sir Gawain was not found on the list\n");
  }

  // Print all the knights on the list
  print_knights(head);

  return 0;
}