//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MIN_RATING 1
#define MAX_RATING 5

// Structure to store a movie
typedef struct {
  char title[50];
  int ratings[MAX_RATINGS];
  int num_ratings;
  double average_rating;
} Movie;

// Function to create a new movie
Movie* create_movie(char* title) {
  Movie* movie = (Movie*)malloc(sizeof(Movie));
  strcpy(movie->title, title);
  movie->num_ratings = 0;
  movie->average_rating = 0.0;
  return movie;
}

// Function to add a rating to a movie
void add_rating(Movie* movie, int rating) {
  if (movie->num_ratings < MAX_RATINGS) {
    movie->ratings[movie->num_ratings] = rating;
    movie->num_ratings++;
    // Recalculate the average rating
    double total = 0.0;
    for (int i = 0; i < movie->num_ratings; i++) {
      total += movie->ratings[i];
    }
    movie->average_rating = total / movie->num_ratings;
  }
}

// Function to print the details of a movie
void print_movie(Movie* movie) {
  printf("Title: %s\n", movie->title);
  printf("Number of ratings: %d\n", movie->num_ratings);
  printf("Average rating: %.2f\n", movie->average_rating);
  printf("Ratings: ");
  for (int i = 0; i < movie->num_ratings; i++) {
    printf("%d ", movie->ratings[i]);
  }
  printf("\n");
}

// Main function
int main() {
  // Create an array of movies
  Movie* movies[MAX_MOVIES];

  // Initialize the random number generator
  srand(time(NULL));

  // Create some movies
  movies[0] = create_movie("The Shawshank Redemption");
  movies[1] = create_movie("The Godfather");
  movies[2] = create_movie("The Dark Knight");
  movies[3] = create_movie("12 Angry Men");
  movies[4] = create_movie("Schindler's List");

  // Add some ratings to the movies
  for (int i = 0; i < MAX_MOVIES; i++) {
    for (int j = 0; j < MAX_RATINGS; j++) {
      int rating = rand() % (MAX_RATING - MIN_RATING + 1) + MIN_RATING;
      add_rating(movies[i], rating);
    }
  }

  // Print the details of the movies
  for (int i = 0; i < MAX_MOVIES; i++) {
    print_movie(movies[i]);
  }

  return 0;
}