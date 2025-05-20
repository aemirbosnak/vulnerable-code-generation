//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the diary entry structure
typedef struct diary_entry {
  char *date;
  char *time;
  char *title;
  char *body;
} diary_entry;

// Create a new diary entry
diary_entry *create_entry(char *date, char *time, char *title, char *body) {
  diary_entry *entry = malloc(sizeof(diary_entry));
  entry->date = strdup(date);
  entry->time = strdup(time);
  entry->title = strdup(title);
  entry->body = strdup(body);
  return entry;
}

// Free the memory allocated for a diary entry
void free_entry(diary_entry *entry) {
  free(entry->date);
  free(entry->time);
  free(entry->title);
  free(entry->body);
  free(entry);
}

// Print a diary entry
void print_entry(diary_entry *entry) {
  printf("Date: %s\n", entry->date);
  printf("Time: %s\n", entry->time);
  printf("Title: %s\n", entry->title);
  printf("Body: %s\n", entry->body);
}

// Main function
int main() {
  // Create a new diary entry
  diary_entry *entry = create_entry("2023-02-14", "11:59 PM", "My Dearest Juliet", "My heart is heavy with love for you, my Juliet. I fear that our love is forbidden, but I cannot help myself. I am drawn to you like a moth to a flame. I know that our families would never approve of our love, but I do not care. I would rather die than live without you.");

  // Print the diary entry
  print_entry(entry);

  // Free the memory allocated for the diary entry
  free_entry(entry);

  return 0;
}