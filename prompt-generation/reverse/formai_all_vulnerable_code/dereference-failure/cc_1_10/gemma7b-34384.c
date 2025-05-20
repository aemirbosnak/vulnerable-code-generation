//Gemma-7B DATASET v1.0 Category: Music Library Management System ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

// Define the Music Library Management System (MLMS) structure
typedef struct MusicLibrary {
  char title[50];
  char artist[50];
  char genre[20];
  int year;
  struct MusicLibrary* next;
} MusicLibrary;

// Create a new music library item
MusicLibrary* createMusicLibraryItem(char* title, char* artist, char* genre, int year) {
  MusicLibrary* newMusicLibraryItem = malloc(sizeof(MusicLibrary));
  strcpy(newMusicLibraryItem->title, title);
  strcpy(newMusicLibraryItem->artist, artist);
  strcpy(newMusicLibraryItem->genre, genre);
  newMusicLibraryItem->year = year;
  newMusicLibraryItem->next = NULL;
  return newMusicLibraryItem;
}

// Insert a new music library item into the head of the list
void insertMusicLibraryItem(MusicLibrary** head, MusicLibrary* newMusicLibraryItem) {
  if (*head == NULL) {
    *head = newMusicLibraryItem;
  } else {
    (*head)->next = newMusicLibraryItem;
    *head = newMusicLibraryItem;
  }
}

// Search for a music library item by title
MusicLibrary* searchMusicLibraryItemByTitle(MusicLibrary* head, char* title) {
  while (head) {
    if (strcmp(head->title, title) == 0) {
      return head;
    }
    head = head->next;
  }
  return NULL;
}

// Print all music library items
void printMusicLibraryItems(MusicLibrary* head) {
  while (head) {
    printf("Title: %s\n", head->title);
    printf("Artist: %s\n", head->artist);
    printf("Genre: %s\n", head->genre);
    printf("Year: %d\n", head->year);
    printf("\n");
    head = head->next;
  }
}

int main() {
  MusicLibrary* head = NULL;
  MusicLibrary* newMusicLibraryItem1 = createMusicLibraryItem("Thriller", "Michael Jackson", "Pop", 1987);
  insertMusicLibraryItem(&head, newMusicLibraryItem1);
  MusicLibrary* newMusicLibraryItem2 = createMusicLibraryItem("Hey There", "Avril Lavigne", "Pop Punk", 2002);
  insertMusicLibraryItem(&head, newMusicLibraryItem2);
  MusicLibrary* newMusicLibraryItem3 = createMusicLibraryItem("Rock Me Gently", "Roy Orbison", "Rock", 1961);
  insertMusicLibraryItem(&head, newMusicLibraryItem3);

  printMusicLibraryItems(head);

  MusicLibrary* item = searchMusicLibraryItemByTitle(head, "Hey There");
  if (item) {
    printf("Item found: \n");
    printf("Title: %s\n", item->title);
    printf("Artist: %s\n", item->artist);
    printf("Genre: %s\n", item->genre);
    printf("Year: %d\n", item->year);
  } else {
    printf("Item not found.\n");
  }

  return 0;
}