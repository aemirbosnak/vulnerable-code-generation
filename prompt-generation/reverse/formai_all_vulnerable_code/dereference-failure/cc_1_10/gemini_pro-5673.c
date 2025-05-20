//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  G,
  PG,
  PG13,
  R,
  NC17
} rating;

typedef struct {
  char *title;
  rating rating;
} movie;

movie *create_movie(const char *title, rating rating) {
  movie *m = malloc(sizeof(movie));
  if (!m) {
    fprintf(stderr, "Error: could not allocate memory for movie.\n");
    return NULL;
  }
  m->title = strdup(title);
  if (!m->title) {
    fprintf(stderr, "Error: could not allocate memory for movie title.\n");
    free(m);
    return NULL;
  }
  m->rating = rating;
  return m;
}

void destroy_movie(movie *m) {
  free(m->title);
  free(m);
}

int compare_movies(const void *a, const void *b) {
  const movie *m1 = (const movie *)a;
  const movie *m2 = (const movie *)b;
  return strcmp(m1->title, m2->title);
}

int main(void) {
  // Create an array of movies.
  movie *movies[] = {
    create_movie("The Shawshank Redemption", PG13),
    create_movie("The Godfather", R),
    create_movie("The Dark Knight", PG13),
    create_movie("12 Angry Men", PG),
    create_movie("Schindler's List", R),
    create_movie("The Lord of the Rings: The Return of the King", PG13),
    create_movie("Pulp Fiction", R),
    create_movie("The Silence of the Lambs", R),
    create_movie("Forrest Gump", PG13),
    create_movie("Good Will Hunting", R)
  };

  // Sort the array of movies by title.
  qsort(movies, sizeof(movies) / sizeof(movies[0]), sizeof(movies[0]), compare_movies);

  // Print the sorted array of movies.
  for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++) {
    printf("%s (%d)\n", movies[i]->title, movies[i]->rating);
  }

  // Destroy the array of movies.
  for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++) {
    destroy_movie(movies[i]);
  }

  return 0;
}