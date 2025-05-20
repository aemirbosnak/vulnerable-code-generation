//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum rating {
  G,
  PG,
  PG13,
  R,
  NC17
};

// Define the movie genres
enum genre {
  ACTION,
  COMEDY,
  DRAMA,
  HORROR,
  ROMANCE,
  SCI_FI,
  THRILLER
};

// Define the movie struct
struct movie {
  char *title;
  enum rating rating;
  enum genre genre;
  int year;
};

// Create a new movie
struct movie *create_movie(char *title, enum rating rating, enum genre genre, int year) {
  struct movie *movie = malloc(sizeof(struct movie));
  movie->title = title;
  movie->rating = rating;
  movie->genre = genre;
  movie->year = year;
  return movie;
}

// Print the movie details
void print_movie(struct movie *movie) {
  printf("Title: %s\n", movie->title);
  printf("Rating: ");
  switch (movie->rating) {
    case G:
      printf("G\n");
      break;
    case PG:
      printf("PG\n");
      break;
    case PG13:
      printf("PG-13\n");
      break;
    case R:
      printf("R\n");
      break;
    case NC17:
      printf("NC-17\n");
      break;
  }
  printf("Genre: ");
  switch (movie->genre) {
    case ACTION:
      printf("Action\n");
      break;
    case COMEDY:
      printf("Comedy\n");
      break;
    case DRAMA:
      printf("Drama\n");
      break;
    case HORROR:
      printf("Horror\n");
      break;
    case ROMANCE:
      printf("Romance\n");
      break;
    case SCI_FI:
      printf("Sci-Fi\n");
      break;
    case THRILLER:
      printf("Thriller\n");
      break;
  }
  printf("Year: %d\n", movie->year);
}

// Get the user's input
void get_user_input(struct movie **movie) {
  char *title = malloc(100 * sizeof(char));
  printf("Enter the movie title: ");
  scanf("%s", title);

  int rating;
  printf("Enter the movie rating (G, PG, PG-13, R, NC-17): ");
  scanf("%d", &rating);

  int genre;
  printf("Enter the movie genre (Action, Comedy, Drama, Horror, Romance, Sci-Fi, Thriller): ");
  scanf("%d", &genre);

  int year;
  printf("Enter the movie year: ");
  scanf("%d", &year);

  *movie = create_movie(title, rating, genre, year);
}

// Main function
int main() {
  struct movie *movie;

  // Get the user's input
  get_user_input(&movie);

  // Print the movie details
  print_movie(movie);

  return 0;
}