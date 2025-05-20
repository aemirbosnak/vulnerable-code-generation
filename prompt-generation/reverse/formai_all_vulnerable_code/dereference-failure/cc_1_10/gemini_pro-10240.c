//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: modular
// Movie rating system in C

#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
  G, // General audiences
  PG, // Parental guidance suggested
  PG_13, // Parents strongly cautioned
  R, // Restricted
  NC_17 // No one 17 and under admitted
} Rating;

// Define the movie struct
typedef struct {
  char *title;
  Rating rating;
  int year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, int year) {
  Movie *movie = malloc(sizeof(Movie));
  if (movie == NULL) {
    return NULL;
  }

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

// Main function
int main() {
  // Create a few movies
  Movie *movies[] = {
    create_movie("The Shawshank Redemption", PG_13, 1994),
    create_movie("The Godfather", R, 1972),
    create_movie("The Dark Knight", PG_13, 2008),
    create_movie("Schindler's List", R, 1993),
    create_movie("Pulp Fiction", R, 1994),
  };

  // Print the movie information
  for (int i = 0; i < 5; i++) {
    print_movie(movies[i]);
    printf("\n");
  }

  // Free the movies
  for (int i = 0; i < 5; i++) {
    free_movie(movies[i]);
  }

  return 0;
}