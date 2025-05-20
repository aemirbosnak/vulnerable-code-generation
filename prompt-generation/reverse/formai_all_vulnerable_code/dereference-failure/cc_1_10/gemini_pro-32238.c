//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store music library data
typedef struct music_library {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track_number;
  int duration;
} music_library;

// Function to create a new music library
music_library *create_music_library(char *title, char *artist, char *album, int year, int track_number, int duration) {
  music_library *new_library = malloc(sizeof(music_library));
  strcpy(new_library->title, title);
  strcpy(new_library->artist, artist);
  strcpy(new_library->album, album);
  new_library->year = year;
  new_library->track_number = track_number;
  new_library->duration = duration;
  return new_library;
}

// Function to print the music library
void print_music_library(music_library *library) {
  printf("Title: %s\n", library->title);
  printf("Artist: %s\n", library->artist);
  printf("Album: %s\n", library->album);
  printf("Year: %d\n", library->year);
  printf("Track number: %d\n", library->track_number);
  printf("Duration: %d\n", library->duration);
}

// Function to compare two music libraries by title
int compare_music_libraries_by_title(music_library *a, music_library *b) {
  return strcmp(a->title, b->title);
}

// Function to sort the music library by title
void sort_music_library_by_title(music_library **library, int size) {
  qsort(library, size, sizeof(music_library *), compare_music_libraries_by_title);
}

// Main function
int main() {
  // Create a music library
  music_library *library = create_music_library("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1, 5);

  // Print the music library
  printf("Original music library:\n");
  print_music_library(library);

  // Sort the music library by title
  sort_music_library_by_title(&library, 1);

  // Print the sorted music library
  printf("Sorted music library:\n");
  print_music_library(library);

  // Free the allocated memory
  free(library);

  return 0;
}