//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_RATINGS 5

typedef struct Movie {
  char title[50];
  int year;
  double rating;
  struct Movie* next;
} Movie;

typedef struct Rating {
  char reviewer[50];
  int rating_value;
  struct Rating* next;
} Rating;

Movie* createMovie(char* title, int year, double rating) {
  Movie* movie = malloc(sizeof(Movie));
  strcpy(movie->title, title);
  movie->year = year;
  movie->rating = rating;
  movie->next = NULL;
  return movie;
}

Rating* createRating(char* reviewer, int rating_value) {
  Rating* rating = malloc(sizeof(Rating));
  strcpy(rating->reviewer, reviewer);
  rating->rating_value = rating_value;
  rating->next = NULL;
  return rating;
}

void printMovies(Movie* movie) {
  while (movie) {
    printf("%s (%d) - %.1f\n", movie->title, movie->year, movie->rating);
    movie = movie->next;
  }
}

void printRatings(Rating* rating) {
  while (rating) {
    printf("%s - %d\n", rating->reviewer, rating->rating_value);
    rating = rating->next;
  }
}

int main() {
  Movie* movies = NULL;
  Rating* ratings = NULL;

  // Create some movies
  movies = createMovie("The Shawshank Redemption", 1994, 9.3);
  movies = createMovie("The Godfather", 1972, 9.2);
  movies = createMovie("The Lord of the Flies", 1954, 8.8);

  // Create some ratings
  ratings = createRating("Roger Ebert", 4);
  ratings = createRating("Anthony Hopkins", 5);
  ratings = createRating("Peter Travers", 3);

  // Print the movies
  printMovies(movies);

  // Print the ratings
  printRatings(ratings);

  return 0;
}