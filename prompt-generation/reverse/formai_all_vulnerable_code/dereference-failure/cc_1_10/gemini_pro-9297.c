//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the node structure
struct node {
  char *name;
  struct node *next;
};

// Define the library structure
struct library {
  struct node *head;
  int size;
};

// Initialize the library
void init_library(struct library *lib) {
  lib->head = NULL;
  lib->size = 0;
}

// Add a song to the library
void add_song(struct library *lib, char *name) {
  // Allocate memory for the new node
  struct node *new_node = malloc(sizeof(struct node));

  // Copy the song name into the new node
  new_node->name = strdup(name);

  // Insert the new node at the beginning of the list
  new_node->next = lib->head;
  lib->head = new_node;

  // Increment the library size
  lib->size++;
}

// Remove a song from the library
void remove_song(struct library *lib, char *name) {
  // Find the song in the list
  struct node *current_node = lib->head;
  while (current_node != NULL) {
    if (strcmp(current_node->name, name) == 0) {
      break;
    }
    current_node = current_node->next;
  }

  // If the song was found, remove it from the list
  if (current_node != NULL) {
    // If the song is the first song in the list, update the head pointer
    if (current_node == lib->head) {
      lib->head = current_node->next;
    } else {
      // Find the previous node and update its next pointer
      struct node *previous_node = lib->head;
      while (previous_node->next != current_node) {
        previous_node = previous_node->next;
      }
      previous_node->next = current_node->next;
    }

    // Free the memory allocated for the song
    free(current_node->name);
    free(current_node);

    // Decrement the library size
    lib->size--;
  }
}

// Print the library
void print_library(struct library *lib) {
  // Iterate over the list of songs and print each song name
  struct node *current_node = lib->head;
  while (current_node != NULL) {
    printf("%s\n", current_node->name);
    current_node = current_node->next;
  }
}

// Free the memory allocated for the library
void free_library(struct library *lib) {
  // Iterate over the list of songs and free the memory allocated for each song
  struct node *current_node = lib->head;
  while (current_node != NULL) {
    struct node *next_node = current_node->next;
    free(current_node->name);
    free(current_node);
    current_node = next_node;
  }

  // Free the memory allocated for the library
  free(lib);
}

int main() {
  // Create a new library
  struct library *lib = malloc(sizeof(struct library));
  init_library(lib);

  // Add some songs to the library
  add_song(lib, "Song 1");
  add_song(lib, "Song 2");
  add_song(lib, "Song 3");

  // Print the library
  printf("Library:\n");
  print_library(lib);

  // Remove a song from the library
  remove_song(lib, "Song 2");

  // Print the library again
  printf("\nLibrary after removing a song:\n");
  print_library(lib);

  // Free the memory allocated for the library
  free_library(lib);

  return 0;
}