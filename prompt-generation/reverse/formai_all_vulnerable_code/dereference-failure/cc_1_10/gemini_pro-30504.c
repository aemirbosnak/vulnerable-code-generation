//GEMINI-pro DATASET v1.0 Category: Music Library Management System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  struct music *next;
} music;

music *head = NULL;
music *current = NULL;

void add_music(char title[], char artist[], char album[], int year) {
  music *new_music = malloc(sizeof(music));
  strcpy(new_music->title, title);
  strcpy(new_music->artist, artist);
  strcpy(new_music->album, album);
  new_music->year = year;
  new_music->next = NULL;

  if (head == NULL) {
    head = new_music;
    current = new_music;
  } else {
    current->next = new_music;
    current = new_music;
  }
}

void print_music() {
  music *temp = head;
  while (temp != NULL) {
    printf("%s - %s - %s - %d\n", temp->title, temp->artist, temp->album, temp->year);
    temp = temp->next;
  }
}

int main() {
  add_music("Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975);
  add_music("Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971);
  add_music("Hotel California", "Eagles", "Hotel California", 1976);
  add_music("Imagine", "John Lennon", "Imagine", 1971);
  add_music("Yesterday", "The Beatles", "Help!", 1965);

  print_music();

  return 0;
}