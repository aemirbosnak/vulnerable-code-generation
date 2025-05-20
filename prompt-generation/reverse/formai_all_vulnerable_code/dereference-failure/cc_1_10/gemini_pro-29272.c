//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the linked list
typedef struct node {
  char *title;
  char *artist;
  char *album;
  int year;
  struct node *next;
} node_t;

// The head of the linked list
node_t *head = NULL;

// The tail of the linked list
node_t *tail = NULL;

// Add a song to the library
void add_song(char *title, char *artist, char *album, int year) {
  // Create a new node
  node_t *new_node = malloc(sizeof(node_t));
  new_node->title = strdup(title);
  new_node->artist = strdup(artist);
  new_node->album = strdup(album);
  new_node->year = year;
  new_node->next = NULL;

  // If the library is empty, set the head and tail to the new node
  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    // Add the new node to the end of the library
    tail->next = new_node;
    tail = new_node;
  }
}

// Print the library
void print_library() {
  // Print the header
  printf("%-30s %-20s %-20s %-4s\n", "Title", "Artist", "Album", "Year");

  // Print each song in the library
  node_t *current_node = head;
  while (current_node != NULL) {
    printf("%-30s %-20s %-20s %-4d\n", current_node->title, current_node->artist, current_node->album, current_node->year);
    current_node = current_node->next;
  }
}

// Free the library
void free_library() {
  // Free each song in the library
  node_t *current_node = head;
  while (current_node != NULL) {
    node_t *next_node = current_node->next;
    free(current_node->title);
    free(current_node->artist);
    free(current_node->album);
    free(current_node);
    current_node = next_node;
  }

  // Set the head and tail to NULL
  head = NULL;
  tail = NULL;
}

// Main function
int main() {
  // Add some songs to the library
  add_song("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
  add_song("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
  add_song("Hotel California", "The Eagles", "Hotel California", 1976);

  // Print the library
  print_library();

  // Free the library
  free_library();

  return 0;
}