//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating system
typedef enum {
  ROMANCE_NONE,
  ROMANCE_TENDER,
  ROMANCE_PASSIONATE,
  ROMANCE_STEAMY,
  ROMANCE_SCANDALOUS
} RomanceRating;

// Define the movie structure
typedef struct {
  char *title;
  char *genre;
  int year;
  RomanceRating rating;
} Movie;

// Create a new movie
Movie* create_movie(char *title, char *genre, int year, RomanceRating rating) {
  Movie *movie = malloc(sizeof(Movie));
  if (movie == NULL) {
    fprintf(stderr, "Error: could not allocate memory for movie\n");
    return NULL;
  }

  movie->title = strdup(title);
  movie->genre = strdup(genre);
  movie->year = year;
  movie->rating = rating;

  return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
  printf("Title: %s\n", movie->title);
  printf("Genre: %s\n", movie->genre);
  printf("Year: %d\n", movie->year);
  printf("Rating: ");
  switch (movie->rating) {
    case ROMANCE_NONE:
      printf("None\n");
      break;
    case ROMANCE_TENDER:
      printf("Tender\n");
      break;
    case ROMANCE_PASSIONATE:
      printf("Passionate\n");
      break;
    case ROMANCE_STEAMY:
      printf("Steamy\n");
      break;
    case ROMANCE_SCANDALOUS:
      printf("Scandalous\n");
      break;
  }
}

// Free the memory allocated for the movie
void free_movie(Movie *movie) {
  free(movie->title);
  free(movie->genre);
  free(movie);
}

// Main function
int main() {
  // Create a few movies
  Movie *movie1 = create_movie("The Notebook", "Romance", 2004, ROMANCE_PASSIONATE);
  Movie *movie2 = create_movie("Titanic", "Romance", 1997, ROMANCE_STEAMY);
  Movie *movie3 = create_movie("Love Actually", "Romance", 2003, ROMANCE_TENDER);
  Movie *movie4 = create_movie("50 Shades of Grey", "Romance", 2015, ROMANCE_SCANDALOUS);

  // Print the movie information
  print_movie(movie1);
  print_movie(movie2);
  print_movie(movie3);
  print_movie(movie4);

  // Free the memory allocated for the movies
  free_movie(movie1);
  free_movie(movie2);
  free_movie(movie3);
  free_movie(movie4);

  return 0;
}