//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  char *artist;
  int year;
  struct node *next;
} MusicEntry;

MusicEntry *head = NULL;

void add_entry(char *title, char *artist, int year) {
  MusicEntry *new_entry = (MusicEntry *)malloc(sizeof(MusicEntry));
  new_entry->title = strdup(title);
  new_entry->artist = strdup(artist);
  new_entry->year = year;
  new_entry->next = NULL;

  if (head == NULL) {
    head = new_entry;
  } else {
    MusicEntry *current = head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_entry;
  }
}

void print_library() {
  MusicEntry *current = head;
  while (current != NULL) {
    printf("%s - %s (%d)\n", current->title, current->artist, current->year);
    current = current->next;
  }
}

void destroy_library() {
  MusicEntry *current = head;
  while (current != NULL) {
    MusicEntry *next = current->next;
    free(current->title);
    free(current->artist);
    free(current);
    current = next;
  }
  head = NULL;
}

int main() {
  // Initialize the library with some post-apocalyptic tunes
  add_entry("The End of the World", "The Misfits", 1985);
  add_entry("God's Gonna Cut You Down", "Johnny Cash", 1959);
  add_entry("I Walk the Line", "Johnny Cash", 1956);
  add_entry("Ring of Fire", "Johnny Cash", 1963);
  add_entry("Folsom Prison Blues", "Johnny Cash", 1955);

  // Print the library
  printf("The Post-Apocalyptic Music Library:\n");
  print_library();

  // Destroy the library
  destroy_library();

  return 0;
}