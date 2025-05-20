//FormAI DATASET v1.0 Category: Music Library Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures

typedef struct Artist {
  char name[100];
  int birth_year;
} Artist;

typedef struct Song {
  char title[100];
  Artist artist;
  int year;
  char genre[50];
} Song;

typedef struct Node {
  Song song;
  struct Node* next;
} Node;

typedef struct Library {
  Node* head;
  int size;
} Library;

// Function prototypes

void addSong(Library* library);
void printLibrary(Library library);
void searchSong(Library library);

int main() {

  // Create a library
  Library library;
  library.head = NULL;
  library.size = 0;

  int choice;
  do {
    printf("\nMusic Library Management System\n");
    printf("1. Add song\n");
    printf("2. Print library\n");
    printf("3. Search for song\n");
    printf("4. Quit\n\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        addSong(&library);
        break;
      case 2:
        printLibrary(library);
        break;
      case 3:
        searchSong(library);
        break;
      case 4:
        printf("Exiting program...\n");
        break;
      default:
        printf("Invalid option, please try again\n");
        break;
    }
  } while(choice != 4);

  return 0;
}

// Function definitions

void addSong(Library* library) {
  Song song;

  printf("\nEnter song title: ");
  scanf(" %[^\n]", song.title);

  printf("Enter artist name: ");
  scanf(" %[^\n]", song.artist.name);

  printf("Enter artist birth year: ");
  scanf("%d", &song.artist.birth_year);

  printf("Enter song release year: ");
  scanf("%d", &song.year);

  printf("Enter song genre: ");
  scanf(" %[^\n]", song.genre);

  Node* new_node = (Node*) malloc(sizeof(Node));
  new_node->song = song;
  new_node->next = NULL;

  if(library->head == NULL) {
    library->head = new_node;
  } else {
    Node* current_node = library->head;
    while(current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }

  library->size++;
  printf("\nSong added successfully!\n");
}

void printLibrary(Library library) {
  printf("\n%-20s %-20s %-10s %-10s %-10s\n", "Title", "Artist", "Birth Year", "Year", "Genre");
  printf("--------------------------------------------------------------------\n");

  Node* current_node = library.head;
  while(current_node != NULL) {
    printf("%-20s %-20s %-10d %-10d %-10s\n", current_node->song.title, current_node->song.artist.name,
    current_node->song.artist.birth_year, current_node->song.year, current_node->song.genre);
    current_node = current_node->next;
  }
}

void searchSong(Library library) {
  char search_key[100];
  printf("\nEnter search term: ");
  scanf(" %[^\n]", search_key);

  Node* current_node = library.head;
  int found = 0;

  while(current_node != NULL) {
    if(strstr(current_node->song.title, search_key) != NULL) {
      printf("\n%-20s %-20s %-10s %-10s %-10s\n", "Title", "Artist", "Birth Year", "Year", "Genre");
      printf("--------------------------------------------------------------------\n");
      printf("%-20s %-20s %-10d %-10d %-10s\n", current_node->song.title, current_node->song.artist.name,
      current_node->song.artist.birth_year, current_node->song.year, current_node->song.genre);
      found = 1;
    }
    current_node = current_node->next;
  }

  if(!found) {
    printf("\nSong not found!\n");
  }
}