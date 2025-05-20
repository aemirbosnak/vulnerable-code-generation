//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: protected
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

// Free the memory allocated for a movie
void free_movie(Movie *movie) {
  free(movie->title);
  free(movie);
}

// Print the details of a movie
void print_movie(Movie *movie) {
  printf("Title: %s\n", movie->title);
  printf("Rating: ");
  switch (movie->rating) {
    case G:
      printf("G (General Audiences)\n");
      break;
    case PG:
      printf("PG (Parental Guidance Suggested)\n");
      break;
    case PG13:
      printf("PG-13 (Parents Strongly Cautioned)\n");
      break;
    case R:
      printf("R (Restricted)\n");
      break;
    case NC17:
      printf("NC-17 (No One 17 and Under Admitted)\n");
      break;
  }
  printf("Year: %d\n", movie->year);
}

// Compare two movies by title
int compare_movies_by_title(const void *a, const void *b) {
  const Movie *movie1 = *(const Movie **)a;
  const Movie *movie2 = *(const Movie **)b;
  return strcmp(movie1->title, movie2->title);
}

// Compare two movies by rating
int compare_movies_by_rating(const void *a, const void *b) {
  const Movie *movie1 = *(const Movie **)a;
  const Movie *movie2 = *(const Movie **)b;
  return movie1->rating - movie2->rating;
}

// Compare two movies by year
int compare_movies_by_year(const void *a, const void *b) {
  const Movie *movie1 = *(const Movie **)a;
  const Movie *movie2 = *(const Movie **)b;
  return movie1->year - movie2->year;
}

// Main function
int main() {
  // Create an array of movies
  Movie *movies[] = {
    create_movie("The Shawshank Redemption", PG13, 1994),
    create_movie("The Godfather", R, 1972),
    create_movie("The Dark Knight", PG13, 2008),
    create_movie("12 Angry Men", PG, 1957),
    create_movie("Schindler's List", R, 1993),
  };

  // Get the number of movies
  int num_movies = sizeof(movies) / sizeof(movies[0]);

  // Sort the movies by title
  qsort(movies, num_movies, sizeof(Movie *), compare_movies_by_title);

  // Print the sorted movies
  printf("Movies sorted by title:\n");
  for (int i = 0; i < num_movies; i++) {
    print_movie(movies[i]);
  }

  // Sort the movies by rating
  qsort(movies, num_movies, sizeof(Movie *), compare_movies_by_rating);

  // Print the sorted movies
  printf("\nMovies sorted by rating:\n");
  for (int i = 0; i < num_movies; i++) {
    print_movie(movies[i]);
  }

  // Sort the movies by year
  qsort(movies, num_movies, sizeof(Movie *), compare_movies_by_year);

  // Print the sorted movies
  printf("\nMovies sorted by year:\n");
  for (int i = 0; i < num_movies; i++) {
    print_movie(movies[i]);
  }

  // Free the memory allocated for each movie
  for (int i = 0; i < num_movies; i++) {
    free_movie(movies[i]);
  }

  return 0;
}