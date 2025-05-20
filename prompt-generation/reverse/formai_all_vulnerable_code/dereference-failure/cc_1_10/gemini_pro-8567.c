//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A node in the library
struct node {
  char *title;
  char *artist;
  char *album;
  int year;
  struct node *next;
};

// The head of the library
struct node *head = NULL;

// Create a new node
struct node *create_node(char *title, char *artist, char *album, int year) {
  struct node *new_node = malloc(sizeof(struct node));
  new_node->title = strdup(title);
  new_node->artist = strdup(artist);
  new_node->album = strdup(album);
  new_node->year = year;
  new_node->next = NULL;
  return new_node;
}

// Add a node to the library
void add_node(struct node *new_node) {
  if (head == NULL) {
    head = new_node;
  } else {
    struct node *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

// Print the library
void print_library() {
  struct node *current_node = head;
  while (current_node != NULL) {
    printf("%s, %s, %s, %d\n", current_node->title, current_node->artist, current_node->album, current_node->year);
    current_node = current_node->next;
  }
}

// Free the library
void free_library() {
  struct node *current_node = head;
  while (current_node != NULL) {
    struct node *next_node = current_node->next;
    free(current_node->title);
    free(current_node->artist);
    free(current_node->album);
    free(current_node);
    current_node = next_node;
  }
  head = NULL;
}

int main() {
  // Add some songs to the library
  add_node(create_node("The Beatles", "Hey Jude", "The Beatles", 1968));
  add_node(create_node("The Rolling Stones", "Paint It Black", "Aftermath", 1966));
  add_node(create_node("Bob Dylan", "Blowin' in the Wind", "The Freewheelin' Bob Dylan", 1963));
  add_node(create_node("The Beach Boys", "Wouldn't It Be Nice", "Pet Sounds", 1966));
  add_node(create_node("The Kinks", "Waterloo Sunset", "Something Else", 1967));

  // Print the library
  print_library();

  // Free the library
  free_library();

  return 0;
}