//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  int track;
} Song;

typedef struct node {
  Song song;
  struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;

void add_song(Song song) {
  Node *new_node = malloc(sizeof(Node));
  new_node->song = song;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    tail = new_node;
  }
}

void print_songs() {
  Node *current = head;

  while (current != NULL) {
    printf("Title: %s\n", current->song.title);
    printf("Artist: %s\n", current->song.artist);
    printf("Album: %s\n", current->song.album);
    printf("Year: %d\n", current->song.year);
    printf("Track: %d\n\n", current->song.track);

    current = current->next;
  }
}

void search_song(char *title) {
  Node *current = head;

  while (current != NULL) {
    if (strcmp(current->song.title, title) == 0) {
      printf("Title: %s\n", current->song.title);
      printf("Artist: %s\n", current->song.artist);
      printf("Album: %s\n", current->song.album);
      printf("Year: %d\n", current->song.year);
      printf("Track: %d\n\n", current->song.track);

      return;
    }

    current = current->next;
  }

  printf("Song not found.\n");
}

void main() {
  Song song1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, 1};
  Song song2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, 4};
  Song song3 = {"Hotel California", "Eagles", "Hotel California", 1976, 3};

  add_song(song1);
  add_song(song2);
  add_song(song3);

  print_songs();

  printf("Searching for song: Bohemian Rhapsody\n");
  search_song("Bohemian Rhapsody");

  printf("Searching for song: Stairway to Heaven\n");
  search_song("Stairway to Heaven");

  printf("Searching for song: Hotel California\n");
  search_song("Hotel California");

  printf("Searching for song: Not found\n");
  search_song("Not found");
}