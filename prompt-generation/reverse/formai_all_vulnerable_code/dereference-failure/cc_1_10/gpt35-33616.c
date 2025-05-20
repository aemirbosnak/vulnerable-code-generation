//FormAI DATASET v1.0 Category: Music Library Management System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct song {
  char title[50];
  char artist[50];
  char album[50];
  int year;
  char genre[20];
};

struct node {
  struct song song;
  struct node* next;
};

struct library {
  struct node* head;
  struct node* tail;
};

void print_song(struct song s) {
  printf("Title: %s\n", s.title);
  printf("Artist: %s\n", s.artist);
  printf("Album: %s\n", s.album);
  printf("Year: %d\n", s.year);
  printf("Genre: %s\n\n", s.genre);
}

void print_library(struct library l) {
  struct node* current = l.head;
  while (current != NULL) {
    print_song(current->song);
    current = current->next;
  }
}

void add_song(struct library* l, struct song s) {
  struct node* new_node = (struct node*) malloc(sizeof(struct node));
  new_node->song = s;
  new_node->next = NULL;

  if (l->head == NULL) {
    l->head = new_node;
    l->tail = new_node;
  } else {
    l->tail->next = new_node;
    l->tail = new_node;
  }
}

struct song search_song(struct library l, char* title) {
  struct node* current = l.head;
  while (current != NULL) {
    if (strcmp(current->song.title, title) == 0) {
      return current->song;
    }
    current = current->next;
  }
  struct song empty_song = {"", "", "", 0, ""};
  return empty_song;
}

int main() {
  struct library my_library = {NULL, NULL};

  struct song s1 = {"Bohemian Rhapsody", "Queen", "A Night at the Opera", 1975, "Rock"};
  struct song s2 = {"Stairway to Heaven", "Led Zeppelin", "Led Zeppelin IV", 1971, "Rock"};
  struct song s3 = {"Hotel California", "Eagles", "Hotel California", 1976, "Rock"};
  struct song s4 = {"Smells Like Teen Spirit", "Nirvana", "Nevermind", 1991, "Grunge"};
  struct song s5 = {"Billie Jean", "Michael Jackson", "Thriller", 1982, "Pop"};

  add_song(&my_library, s1);
  add_song(&my_library, s2);
  add_song(&my_library, s3);
  add_song(&my_library, s4);
  add_song(&my_library, s5);

  printf("Library:\n");
  print_library(my_library);

  struct song search_result = search_song(my_library, "Bohemian Rhapsody");
  if (strcmp(search_result.title, "") == 0) {
    printf("Song not found.\n");
  } else {
    printf("Search result:\n");
    print_song(search_result);
  }

  return 0;
}