//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STARS 5

typedef struct Movie {
  char title[256];
  int year;
  float rating;
  struct Movie* next;
} Movie;

void printStars(int stars) {
  for (int i = 0; i < stars; i++) {
    printf("%c", '*');
  }
}

Movie* createMovie(char* title, int year, float rating) {
  Movie* newMovie = malloc(sizeof(Movie));
  strcpy(newMovie->title, title);
  newMovie->year = year;
  newMovie->rating = rating;
  newMovie->next = NULL;
  return newMovie;
}

void addMovie(Movie* head, char* title, int year, float rating) {
  Movie* newMovie = createMovie(title, year, rating);
  if (head == NULL) {
    head = newMovie;
  } else {
    newMovie->next = head;
    head = newMovie;
  }
}

void printMovies(Movie* head) {
  while (head) {
    printf("%s (%d) - %.1f stars\n", head->title, head->year, head->rating);
    printStars(head->rating);
    printf("\n");
    head = head->next;
  }
}

int main() {
  Movie* head = NULL;
  addMovie(head, "The Shawshank Redemption", 1994, 4.8);
  addMovie(head, "The Godfather", 1972, 4.2);
  addMovie(head, "The Dark Knight Rises", 2008, 3.6);
  addMovie(head, "Spider-Man: Far From Home", 2019, 4.1);

  printMovies(head);

  return 0;
}