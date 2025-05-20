//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
  G,
  PG,
  PG13,
  R,
  NC17
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

// Get the movie rating
Rating get_movie_rating(char *rating) {
  if (strcmp(rating, "G") == 0) {
    return G;
  } else if (strcmp(rating, "PG") == 0) {
    return PG;
  } else if (strcmp(rating, "PG13") == 0) {
    return PG13;
  } else if (strcmp(rating, "R") == 0) {
    return R;
  } else if (strcmp(rating, "NC17") == 0) {
    return NC17;
  } else {
    return -1;
  }
}

// Main function
int main() {
  // Create a new movie
  Movie *movie = create_movie("The Shawshank Redemption", R, 1994);

  // Print the movie information
  print_movie(movie);

  // Free the movie
  free_movie(movie);

  return 0;
}