//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating system
#define NUM_RATINGS 5
char *ratings[] = {"G", "PG", "PG-13", "R", "NC-17"};

// Define the movie struct
typedef struct movie {
  char *title;
  char *rating;
  int year;
} movie;

// Create a new movie
movie *create_movie(char *title, char *rating, int year) {
  movie *m = malloc(sizeof(movie));
  m->title = strdup(title);
  m->rating = strdup(rating);
  m->year = year;
  return m;
}

// Print a movie
void print_movie(movie *m) {
  printf("%s (%s, %d)\n", m->title, m->rating, m->year);
}

// Compare two movies by rating
int compare_movies_by_rating(const void *a, const void *b) {
  movie *m1 = (movie *)a;
  movie *m2 = (movie *)b;
  return strcmp(m1->rating, m2->rating);
}

// Compare two movies by year
int compare_movies_by_year(const void *a, const void *b) {
  movie *m1 = (movie *)a;
  movie *m2 = (movie *)b;
  return m1->year - m2->year;
}

// Get the rating of a movie
char *get_rating(movie *m) {
  return m->rating;
}

// Get the year of a movie
int get_year(movie *m) {
  return m->year;
}

// Main function
int main() {
  // Create an array of movies
  movie *movies[] = {
    create_movie("The Shawshank Redemption", "R", 1994),
    create_movie("The Godfather", "R", 1972),
    create_movie("The Dark Knight", "PG-13", 2008),
    create_movie("12 Angry Men", "PG", 1957),
    create_movie("Schindler's List", "R", 1993),
  };

  // Print the movies in order of rating
  qsort(movies, 5, sizeof(movie *), compare_movies_by_rating);
  printf("Movies in order of rating:\n");
  for (int i = 0; i < 5; i++) {
    print_movie(movies[i]);
  }

  // Print the movies in order of year
  qsort(movies, 5, sizeof(movie *), compare_movies_by_year);
  printf("\nMovies in order of year:\n");
  for (int i = 0; i < 5; i++) {
    print_movie(movies[i]);
  }

  // Get the rating of a movie
  char *rating = get_rating(movies[0]);
  printf("\nRating of The Shawshank Redemption: %s\n", rating);

  // Get the year of a movie
  int year = get_year(movies[0]);
  printf("Year of The Shawshank Redemption: %d\n", year);

  return 0;
}