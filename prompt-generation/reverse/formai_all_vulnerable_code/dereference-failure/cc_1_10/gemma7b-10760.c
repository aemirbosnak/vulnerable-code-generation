//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

// Define the Music Library Management System (MLMS) structure.
typedef struct MLMS {
  char title[50];
  char artist[50];
  char genre[20];
  int year;
  struct MLMS* next;
} MLMS;

// Create a new music library item.
MLMS* create_music_item(char* title, char* artist, char* genre, int year) {
  MLMS* new_item = malloc(sizeof(MLMS));
  strcpy(new_item->title, title);
  strcpy(new_item->artist, artist);
  strcpy(new_item->genre, genre);
  new_item->year = year;
  new_item->next = NULL;
  return new_item;
}

// Insert a new music item into the library.
void insert_music_item(MLMS* library, char* title, char* artist, char* genre, int year) {
  MLMS* new_item = create_music_item(title, artist, genre, year);
  if (library == NULL) {
    library = new_item;
  } else {
    library->next = new_item;
  }
  library = new_item;
}

// Search for a music item by title.
MLMS* search_music_item_by_title(MLMS* library, char* title) {
  while (library) {
    if (strcmp(library->title, title) == 0) {
      return library;
    }
    library = library->next;
  }
  return NULL;
}

// Print all music items in the library.
void print_music_items(MLMS* library) {
  while (library) {
    printf("%s by %s (%d) - %s\n", library->title, library->artist, library->year, library->genre);
    library = library->next;
  }
}

int main() {
  // Create a new music library.
  MLMS* library = NULL;

  // Insert some music items.
  insert_music_item(library, "The Darkest Shadow", "The Doors", "Rock", 1967);
  insert_music_item(library, "Like a Rolling Stone", "The Rolling Stones", "Rock", 1965);
  insert_music_item(library, "Stairway to Heaven", "Led Zeppelin", "Rock", 1969);

  // Search for a music item by title.
  MLMS* item = search_music_item_by_title(library, "Stairway to Heaven");

  // Print the music item.
  if (item) {
    printf("%s by %s (%d) - %s\n", item->title, item->artist, item->year, item->genre);
  } else {
    printf("Item not found.\n");
  }

  // Print all music items.
  print_music_items(library);

  return 0;
}