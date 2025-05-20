//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Dennis Ritchie
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  char *title;
  int year;
  int rating;
} movie;

movie *new_movie(char *title, int year, int rating) {
  movie *m = malloc(sizeof(movie));
  m->title = strdup(title);
  m->year = year;
  m->rating = rating;
  return m;
}

void free_movie(movie *m) {
  free(m->title);
  free(m);
}

int compare_movies(const void *a, const void *b) {
  movie *ma = *(movie **)a;
  movie *mb = *(movie **)b;
  return strcmp(ma->title, mb->title);
}

int main(void) {
  movie *movies[] = {
    new_movie("The Shawshank Redemption", 1994, 9.3),
    new_movie("The Godfather", 1972, 9.2),
    new_movie("The Dark Knight", 2008, 9.0),
    new_movie("12 Angry Men", 1957, 9.0),
    new_movie("Schindler's List", 1993, 8.9),
    new_movie("The Lord of the Rings: The Return of the King", 2003, 8.9),
    new_movie("Pulp Fiction", 1994, 8.9),
    new_movie("The Good, the Bad and the Ugly", 1966, 8.8),
    new_movie("The Matrix", 1999, 8.7),
    new_movie("Star Wars: Episode V - The Empire Strikes Back", 1980, 8.7),
  };

  qsort(movies, sizeof(movies) / sizeof(movie *), sizeof(movie *), compare_movies);

  for (size_t i = 0; i < sizeof(movies) / sizeof(movie *); i++) {
    printf("%2d. %s (%d) - %.1f\n", i + 1, movies[i]->title, movies[i]->year, movies[i]->rating);
  }

  for (size_t i = 0; i < sizeof(movies) / sizeof(movie *); i++) {
    free_movie(movies[i]);
  }

  return 0;
}