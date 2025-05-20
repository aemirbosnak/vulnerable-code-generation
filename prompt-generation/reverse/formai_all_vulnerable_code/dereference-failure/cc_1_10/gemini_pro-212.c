//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
  G,
  PG,
  PG_13,
  R,
  NC_17
} MovieRating;

// Define the movie structure
typedef struct {
  char *title;
  MovieRating rating;
  int year;
} Movie;

// Create a new movie
Movie *new_movie(char *title, MovieRating rating, int year) {
  Movie *movie = malloc(sizeof(Movie));
  movie->title = strdup(title);
  movie->rating = rating;
  movie->year = year;
  return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
  printf("Title: %s\n", movie->title);
  printf("Rating: %d\n", movie->rating);
  printf("Year: %d\n", movie->year);
}

// Free the movie
void free_movie(Movie *movie) {
  free(movie->title);
  free(movie);
}

// Get the movie rating from the user
MovieRating get_movie_rating() {
  int rating;
  printf("Enter the movie rating (0-4): ");
  scanf("%d", &rating);
  return rating;
}

// Get the movie title from the user
char *get_movie_title() {
  char *title = malloc(100);
  printf("Enter the movie title: ");
  scanf("%s", title);
  return title;
}

// Get the movie year from the user
int get_movie_year() {
  int year;
  printf("Enter the movie year: ");
  scanf("%d", &year);
  return year;
}

// Main function
int main() {
  // Create a new movie
  Movie *movie = new_movie("The Shawshank Redemption", R, 1994);

  // Print the movie information
  print_movie(movie);

  // Free the movie
  free_movie(movie);

  return 0;
}