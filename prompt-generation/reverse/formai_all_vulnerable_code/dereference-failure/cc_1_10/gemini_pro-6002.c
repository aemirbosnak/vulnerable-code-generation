//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *title;
  int year;
  char *genre;
  float rating;
} Movie;

Movie *createMovie(char *title, int year, char *genre, float rating) {
  Movie *movie = malloc(sizeof(Movie));
  movie->title = strdup(title);
  movie->year = year;
  movie->genre = strdup(genre);
  movie->rating = rating;
  return movie;
}

void printMovie(Movie *movie) {
  printf("%s (%d) - %s - %.1f\n", movie->title, movie->year, movie->genre, movie->rating);
}

int main() {
  Movie *movies[] = {
    createMovie("The Shawshank Redemption", 1994, "Drama", 9.3),
    createMovie("The Godfather", 1972, "Crime", 9.2),
    createMovie("The Dark Knight", 2008, "Action", 9.0),
    createMovie("12 Angry Men", 1957, "Drama", 9.0),
    createMovie("Schindler's List", 1993, "Drama", 9.0),
    createMovie("Pulp Fiction", 1994, "Crime", 8.9),
    createMovie("The Lord of the Rings: The Return of the King", 2003, "Fantasy", 8.9),
    createMovie("The Good, the Bad and the Ugly", 1966, "Western", 8.8),
    createMovie("The Matrix", 1999, "Sci-Fi", 8.7),
    createMovie("Star Wars: Episode V - The Empire Strikes Back", 1980, "Sci-Fi", 8.7),
  };

  int numMovies = sizeof(movies) / sizeof(movies[0]);

  // Print the movies in order of their rating
  for (int i = 0; i < numMovies; i++) {
    for (int j = i + 1; j < numMovies; j++) {
      if (movies[i]->rating < movies[j]->rating) {
        Movie *temp = movies[i];
        movies[i] = movies[j];
        movies[j] = temp;
      }
    }
  }

  // Print the movies
  for (int i = 0; i < numMovies; i++) {
    printMovie(movies[i]);
  }

  // Free the movies
  for (int i = 0; i < numMovies; i++) {
    free(movies[i]->title);
    free(movies[i]->genre);
    free(movies[i]);
  }

  return 0;
}