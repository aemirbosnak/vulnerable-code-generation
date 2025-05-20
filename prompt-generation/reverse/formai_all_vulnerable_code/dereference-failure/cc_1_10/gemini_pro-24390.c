//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: retro
/* Retro Music Library Manager */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cassette tape structure
typedef struct Cassette {
  char title[50];
  char artist[50];
  int side_a_tracks;
  int side_b_tracks;
  struct Cassette *next;
} Cassette;

// Function to create a new cassette tape
Cassette *create_cassette(char *title, char *artist, int side_a_tracks, int side_b_tracks) {
  Cassette *new_cassette = (Cassette *)malloc(sizeof(Cassette));
  strcpy(new_cassette->title, title);
  strcpy(new_cassette->artist, artist);
  new_cassette->side_a_tracks = side_a_tracks;
  new_cassette->side_b_tracks = side_b_tracks;
  new_cassette->next = NULL;
  return new_cassette;
}

// Function to add a cassette tape to the library
void add_cassette(Cassette **library, Cassette *new_cassette) {
  if (*library == NULL) {
    *library = new_cassette;
  } else {
    Cassette *current = *library;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_cassette;
  }
}

// Function to print the library of cassette tapes
void print_library(Cassette *library) {
  Cassette *current = library;
  while (current != NULL) {
    printf("%s - %s - %d tracks on side A, %d tracks on side B\n", current->title, current->artist, current->side_a_tracks, current->side_b_tracks);
    current = current->next;
  }
}

// Function to search for a cassette tape in the library by title
Cassette *find_cassette_by_title(Cassette *library, char *title) {
  Cassette *current = library;
  while (current != NULL) {
    if (strcmp(current->title, title) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Function to delete a cassette tape from the library by title
void delete_cassette_by_title(Cassette **library, char *title) {
  Cassette *current = *library;
  Cassette *previous = NULL;
  while (current != NULL) {
    if (strcmp(current->title, title) == 0) {
      if (previous == NULL) {
        *library = current->next;
      } else {
        previous->next = current->next;
      }
      free(current);
      return;
    }
    previous = current;
    current = current->next;
  }
}

// Main function
int main() {
  Cassette *library = NULL;

  // Add some cassette tapes to the library
  add_cassette(&library, create_cassette("Thriller", "Michael Jackson", 9, 9));
  add_cassette(&library, create_cassette("Born in the U.S.A.", "Bruce Springsteen", 10, 10));
  add_cassette(&library, create_cassette("Purple Rain", "Prince", 9, 9));
  add_cassette(&library, create_cassette("Like a Prayer", "Madonna", 10, 10));
  add_cassette(&library, create_cassette("Appetite for Destruction", "Guns N' Roses", 12, 12));

  // Print the library of cassette tapes
  printf("Your Music Library:\n");
  print_library(library);

  // Search for a cassette tape in the library by title
  Cassette *cassette = find_cassette_by_title(library, "Thriller");
  if (cassette != NULL) {
    printf("Found cassette tape: %s - %s\n", cassette->title, cassette->artist);
  } else {
    printf("Cassette tape not found.\n");
  }

  // Delete a cassette tape from the library by title
  delete_cassette_by_title(&library, "Like a Prayer");
  printf("Deleted cassette tape: Like a Prayer\n");

  // Print the library of cassette tapes again
  printf("Your Music Library (after deletion):\n");
  print_library(library);

  return 0;
}