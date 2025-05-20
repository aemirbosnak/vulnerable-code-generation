//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a song
typedef struct song {
  char *title;
  char *artist;
  int year;
  int duration;
} song;

// Structure to store a linked list of songs
typedef struct node {
  song *data;
  struct node *next;
} node;

// Create a new song
song *new_song(char *title, char *artist, int year, int duration) {
  song *new_song = malloc(sizeof(song));
  new_song->title = strdup(title);
  new_song->artist = strdup(artist);
  new_song->year = year;
  new_song->duration = duration;
  return new_song;
}

// Insert a new song into a linked list
void insert_song(node **head, song *new_song) {
  node *new_node = malloc(sizeof(node));
  new_node->data = new_song;
  new_node->next = *head;
  *head = new_node;
}

// Print a song
void print_song(song *song) {
  printf("Title: %s\n", song->title);
  printf("Artist: %s\n", song->artist);
  printf("Year: %d\n", song->year);
  printf("Duration: %d\n", song->duration);
  printf("\n");
}

// Print a linked list of songs
void print_songs(node *head) {
  node *current = head;
  while (current != NULL) {
    print_song(current->data);
    current = current->next;
  }
}

// Free a song
void free_song(song *song) {
  free(song->title);
  free(song->artist);
  free(song);
}

// Free a linked list of songs
void free_songs(node *head) {
  node *current = head;
  while (current != NULL) {
    node *next = current->next;
    free_song(current->data);
    free(current);
    current = next;
  }
}

// Main function
int main() {
  // Create a new linked list of songs
  node *head = NULL;

  // Insert some songs into the linked list
  insert_song(&head, new_song("Bohemian Rhapsody", "Queen", 1975, 5));
  insert_song(&head, new_song("Stairway to Heaven", "Led Zeppelin", 1971, 8));
  insert_song(&head, new_song("Hotel California", "Eagles", 1976, 6));

  // Print the linked list of songs
  printf("Songs:\n");
  print_songs(head);

  // Free the linked list of songs
  free_songs(head);

  return 0;
}