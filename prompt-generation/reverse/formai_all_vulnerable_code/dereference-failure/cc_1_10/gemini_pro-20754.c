//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of movies
#define MAX_MOVIES 100

// Define the maximum length of a movie title
#define MAX_TITLE_LENGTH 100

// Define the maximum number of ratings per movie
#define MAX_RATINGS 10

// Define the data structure for a movie
typedef struct movie {
  char title[MAX_TITLE_LENGTH];
  int ratings[MAX_RATINGS];
  int num_ratings;
} movie;

// Define the data structure for the movie rating system
typedef struct movie_rating_system {
  movie movies[MAX_MOVIES];
  int num_movies;
} movie_rating_system;

// Create a new movie rating system
movie_rating_system *create_movie_rating_system() {
  movie_rating_system *mrs = malloc(sizeof(movie_rating_system));
  if (mrs == NULL) {
    return NULL;
  }

  mrs->num_movies = 0;

  return mrs;
}

// Add a new movie to the movie rating system
int add_movie(movie_rating_system *mrs, char *title) {
  if (mrs->num_movies >= MAX_MOVIES) {
    return -1;
  }

  strcpy(mrs->movies[mrs->num_movies].title, title);
  mrs->movies[mrs->num_movies].num_ratings = 0;

  mrs->num_movies++;

  return 0;
}

// Add a new rating to a movie
int add_rating(movie_rating_system *mrs, char *title, int rating) {
  int i;

  for (i = 0; i < mrs->num_movies; i++) {
    if (strcmp(mrs->movies[i].title, title) == 0) {
      if (mrs->movies[i].num_ratings >= MAX_RATINGS) {
        return -1;
      }

      mrs->movies[i].ratings[mrs->movies[i].num_ratings] = rating;
      mrs->movies[i].num_ratings++;

      return 0;
    }
  }

  return -1;
}

// Get the average rating for a movie
double get_average_rating(movie_rating_system *mrs, char *title) {
  int i;
  double sum = 0;

  for (i = 0; i < mrs->num_movies; i++) {
    if (strcmp(mrs->movies[i].title, title) == 0) {
      for (int j = 0; j < mrs->movies[i].num_ratings; j++) {
        sum += mrs->movies[i].ratings[j];
      }

      return sum / mrs->movies[i].num_ratings;
    }
  }

  return -1;
}

// Get the highest rated movie
char *get_highest_rated_movie(movie_rating_system *mrs) {
  int i;
  double highest_rating = -1;
  char *highest_rated_movie = NULL;

  for (i = 0; i < mrs->num_movies; i++) {
    double average_rating = get_average_rating(mrs, mrs->movies[i].title);
    if (average_rating > highest_rating) {
      highest_rating = average_rating;
      highest_rated_movie = mrs->movies[i].title;
    }
  }

  return highest_rated_movie;
}

// Get the lowest rated movie
char *get_lowest_rated_movie(movie_rating_system *mrs) {
  int i;
  double lowest_rating = 10;
  char *lowest_rated_movie = NULL;

  for (i = 0; i < mrs->num_movies; i++) {
    double average_rating = get_average_rating(mrs, mrs->movies[i].title);
    if (average_rating < lowest_rating) {
      lowest_rating = average_rating;
      lowest_rated_movie = mrs->movies[i].title;
    }
  }

  return lowest_rated_movie;
}

// Print the movie rating system
void print_movie_rating_system(movie_rating_system *mrs) {
  int i;

  printf("Movie Rating System:\n");

  for (i = 0; i < mrs->num_movies; i++) {
    printf("%s: ", mrs->movies[i].title);

    for (int j = 0; j < mrs->movies[i].num_ratings; j++) {
      printf("%d ", mrs->movies[i].ratings[j]);
    }

    printf("\n");
  }
}

// Free the memory allocated for the movie rating system
void free_movie_rating_system(movie_rating_system *mrs) {
  free(mrs);
}

// Main function
int main() {
  // Create a new movie rating system
  movie_rating_system *mrs = create_movie_rating_system();

  // Add some movies to the movie rating system
  add_movie(mrs, "The Shawshank Redemption");
  add_movie(mrs, "The Godfather");
  add_movie(mrs, "The Dark Knight");
  add_movie(mrs, "The Lord of the Rings: The Return of the King");
  add_movie(mrs, "Pulp Fiction");

  // Add some ratings to the movies
  add_rating(mrs, "The Shawshank Redemption", 9);
  add_rating(mrs, "The Shawshank Redemption", 10);
  add_rating(mrs, "The Godfather", 9);
  add_rating(mrs, "The Godfather", 10);
  add_rating(mrs, "The Dark Knight", 9);
  add_rating(mrs, "The Dark Knight", 8);
  add_rating(mrs, "The Lord of the Rings: The Return of the King", 10);
  add_rating(mrs, "The Lord of the Rings: The Return of the King", 9);
  add_rating(mrs, "Pulp Fiction", 9);
  add_rating(mrs, "Pulp Fiction", 8);

  // Print the movie rating system
  print_movie_rating_system(mrs);

  // Get the average rating for a movie
  double average_rating = get_average_rating(mrs, "The Shawshank Redemption");
  printf("The average rating for The Shawshank Redemption is: %.1f\n", average_rating);

  // Get the highest rated movie
  char *highest_rated_movie = get_highest_rated_movie(mrs);
  printf("The highest rated movie is: %s\n", highest_rated_movie);

  // Get the lowest rated movie
  char *lowest_rated_movie = get_lowest_rated_movie(mrs);
  printf("The lowest rated movie is: %s\n", lowest_rated_movie);

  // Free the memory allocated for the movie rating system
  free_movie_rating_system(mrs);

  return 0;
}