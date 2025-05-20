//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a music library entry
typedef struct {
  char *title;
  char *artist;
  char *album;
  int year;
  int track_number;
} music_entry;

// Define the structure of the music library
typedef struct {
  int num_entries;
  music_entry *entries;
} music_library;

// Create a new music library
music_library *create_music_library() {
  music_library *library = malloc(sizeof(music_library));
  library->num_entries = 0;
  library->entries = NULL;
  return library;
}

// Add a new entry to the music library
void add_music_entry(music_library *library, music_entry *entry) {
  library->num_entries++;
  library->entries = realloc(library->entries, library->num_entries * sizeof(music_entry));
  library->entries[library->num_entries - 1] = *entry;
}

// Print the music library
void print_music_library(music_library *library) {
  for (int i = 0; i < library->num_entries; i++) {
    music_entry *entry = &library->entries[i];
    printf("%s - %s - %s - %d - %d\n", entry->title, entry->artist, entry->album, entry->year, entry->track_number);
  }
}

// Free the memory allocated for the music library
void free_music_library(music_library *library) {
  for (int i = 0; i < library->num_entries; i++) {
    music_entry *entry = &library->entries[i];
    free(entry->title);
    free(entry->artist);
    free(entry->album);
  }
  free(library->entries);
  free(library);
}

// Main function
int main() {
  // Create a new music library
  music_library *library = create_music_library();

  // Add some entries to the music library
  music_entry entry1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  add_music_entry(library, &entry1);

  music_entry entry2 = {"Strawberry Fields Forever", "The Beatles", "Sgt. Pepper's Lonely Hearts Club Band", 1967, 2};
  add_music_entry(library, &entry2);

  music_entry entry3 = {"Imagine", "John Lennon", "Imagine", 1971, 1};
  add_music_entry(library, &entry3);

  // Print the music library
  print_music_library(library);

  // Free the memory allocated for the music library
  free_music_library(library);

  return 0;
}