//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Music_Record {
  char title[50];
  char artist[50];
  char genre[50];
  int year;
  struct Music_Record* next;
} Music_Record;

Music_Record* insert_at_tail(Music_Record* head, Music_Record* new_record) {
  if (head == NULL) {
    head = new_record;
  } else {
    head->next = new_record;
    head = new_record;
  }
  return head;
}

void search_music(Music_Record* head, char* title) {
  Music_Record* current = head;
  while (current) {
    if (strcmp(current->title, title) == 0) {
      printf("Title: %s\n", current->title);
      printf("Artist: %s\n", current->artist);
      printf("Genre: %s\n", current->genre);
      printf("Year: %d\n", current->year);
    }
    current = current->next;
  }
}

int main() {
  Music_Record* head = NULL;
  Music_Record* new_record = malloc(sizeof(Music_Record));

  strcpy(new_record->title, "The Darkest Hour");
  strcpy(new_record->artist, "The Who");
  strcpy(new_record->genre, "Rock");
  new_record->year = 1969;

  head = insert_at_tail(head, new_record);

  new_record = malloc(sizeof(Music_Record));

  strcpy(new_record->title, "Stairway to Heaven");
  strcpy(new_record->artist, "Led Zeppelin");
  strcpy(new_record->genre, "Rock");
  new_record->year = 1969;

  head = insert_at_tail(head, new_record);

  search_music(head, "Stairway to Heaven");

  return 0;
}