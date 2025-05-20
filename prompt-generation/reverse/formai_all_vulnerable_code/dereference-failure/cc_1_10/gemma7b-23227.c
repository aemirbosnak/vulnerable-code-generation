//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MovieRating {
  char title[50];
  int year;
  float rating;
  char genre[20];
  struct MovieRating* next;
};

struct MovieRating* insertMovie(struct MovieRating* head, char* title, int year, float rating, char* genre) {
  struct MovieRating* newNode = malloc(sizeof(struct MovieRating));

  strcpy(newNode->title, title);
  newNode->year = year;
  newNode->rating = rating;
  strcpy(newNode->genre, genre);
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void printMovieList(struct MovieRating* head) {
  struct MovieRating* current = head;

  while (current) {
    printf("%s (%d) - %.1f stars, genre: %s\n", current->title, current->year, current->rating, current->genre);
    current = current->next;
  }
}

int main() {
  struct MovieRating* head = NULL;

  insertMovie(head, "The Shawshank Redemption", 1994, 9.3, "Drama");
  insertMovie(head, "The Godfather", 1972, 9.2, "Crime");
  insertMovie(head, "The Dark Knight Rises", 2008, 8.0, "Action");

  printMovieList(head);

  return 0;
}