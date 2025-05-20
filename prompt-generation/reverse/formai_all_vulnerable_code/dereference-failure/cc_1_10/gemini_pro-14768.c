//GEMINI-pro DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Romeo and Juliet characters
#define ROMEO "Romeo"
#define JULIET "Juliet"

// Define the diary entry structure
typedef struct diary_entry {
  char *date;
  char *time;
  char *entry;
} diary_entry;

// Create a new diary entry
diary_entry *create_diary_entry(char *date, char *time, char *entry) {
  diary_entry *new_entry = malloc(sizeof(diary_entry));
  new_entry->date = strdup(date);
  new_entry->time = strdup(time);
  new_entry->entry = strdup(entry);
  return new_entry;
}

// Free a diary entry
void free_diary_entry(diary_entry *entry) {
  free(entry->date);
  free(entry->time);
  free(entry->entry);
  free(entry);
}

// Print a diary entry
void print_diary_entry(diary_entry *entry) {
  printf("Date: %s\n", entry->date);
  printf("Time: %s\n", entry->time);
  printf("Entry: %s\n", entry->entry);
}

// Main function
int main() {
  // Create a diary entry for Romeo
  diary_entry *romeo_entry = create_diary_entry(
      "April 13, 1597", "10:00 PM",
      "Oh, Juliet, my love, my life, my all!\n"
      "I cannot believe that I have found you.\n"
      "You are the most beautiful woman I have ever seen.\n"
      "And more than that, you are kind and loving.\n"
      "I feel like I have known you for a lifetime.\n"
      "I promise to love you forever and ever.\n"
      "With all my heart and soul, I am yours.\n"
      "Your Romeo"
  );

  // Create a diary entry for Juliet
  diary_entry *juliet_entry = create_diary_entry(
      "April 14, 1597", "11:00 PM",
      "Romeo, my dearest Romeo,\n"
      "I am so happy to have found you.\n"
      "You are everything I have ever dreamed of in a man.\n"
      "You are handsome, kind, and intelligent.\n"
      "I feel like I have known you for a lifetime.\n"
      "I promise to love you forever and ever.\n"
      "With all my heart and soul, I am yours.\n"
      "Your Juliet"
  );

  // Print the diary entries
  print_diary_entry(romeo_entry);
  print_diary_entry(juliet_entry);

  // Free the diary entries
  free_diary_entry(romeo_entry);
  free_diary_entry(juliet_entry);

  return 0;
}