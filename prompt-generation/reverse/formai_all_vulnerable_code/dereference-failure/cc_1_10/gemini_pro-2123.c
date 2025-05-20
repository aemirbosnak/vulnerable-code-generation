//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a fitness tracker entry
typedef struct fitness_entry {
  int steps;
  int calories;
  int distance;
  struct fitness_entry *next;
} fitness_entry;

// Create a new fitness tracker entry
fitness_entry *new_entry(int steps, int calories, int distance) {
  fitness_entry *entry = malloc(sizeof(fitness_entry));
  entry->steps = steps;
  entry->calories = calories;
  entry->distance = distance;
  entry->next = NULL;
  return entry;
}

// Insert a new entry into a fitness tracker list
fitness_entry *insert_entry(fitness_entry *head, fitness_entry *new_entry) {
  if (head == NULL) {
    return new_entry;
  } else {
    head->next = insert_entry(head->next, new_entry);
    return head;
  }
}

// Print a fitness tracker list
void print_list(fitness_entry *head) {
  if (head == NULL) {
    printf("No entries to print.\n");
  } else {
    printf("Steps: %d, Calories: %d, Distance: %d\n", head->steps, head->calories, head->distance);
    print_list(head->next);
  }
}

// Free a fitness tracker list
void free_list(fitness_entry *head) {
  if (head == NULL) {
    return;
  } else {
    free_list(head->next);
    free(head);
  }
}

// Main function
int main() {
  // Create a new fitness tracker list
  fitness_entry *head = NULL;

  // Insert some entries into the list
  head = insert_entry(head, new_entry(10000, 500, 5));
  head = insert_entry(head, new_entry(12000, 600, 6));
  head = insert_entry(head, new_entry(14000, 700, 7));

  // Print the list
  print_list(head);

  // Free the list
  free_list(head);

  return 0;
}