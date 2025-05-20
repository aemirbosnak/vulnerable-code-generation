//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct Movie {
  char title[256];
  char genre[256];
  int year;
  float rating;
  struct Movie* next;
} Movie;

Movie* createMovie(char* title, char* genre, int year, float rating) {
  Movie* newMovie = malloc(sizeof(Movie));
  strcpy(newMovie->title, title);
  strcpy(newMovie->genre, genre);
  newMovie->year = year;
  newMovie->rating = rating;
  newMovie->next = NULL;
  return newMovie;
}

void addMovie(Movie* head, char* title, char* genre, int year, float rating) {
  Movie* newMovie = createMovie(title, genre, year, rating);
  if (head == NULL) {
    head = newMovie;
  } else {
    Movie* currentMovie = head;
    while (currentMovie->next) {
      currentMovie = currentMovie->next;
    }
    currentMovie->next = newMovie;
  }
}

void printMovies(Movie* head) {
  Movie* currentMovie = head;
  while (currentMovie) {
    printf("%s (%d) - %f\n", currentMovie->title, currentMovie->year, currentMovie->rating);
    currentMovie = currentMovie->next;
  }
}

int main() {
  Movie* head = NULL;
  addMovie(head, "The Shawshank Redemption", "Drama", 1994, 9.3);
  addMovie(head, "The Godfather", "Crime", 1972, 9.2);
  addMovie(head, "The Dark Knight Rises", "Action", 2008, 8.8);
  addMovie(head, "The Matrix Reloaded", "Sci-Fi", 2003, 8.6);

  printMovies(head);

  return 0;
}