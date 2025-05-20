//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating scale
#define MIN_RATING 0
#define MAX_RATING 10

// Define the movie struct
typedef struct movie {
  char title[50];
  int year;
  int rating;
} Movie;

// Function to create a new movie
Movie* create_movie(char* title, int year, int rating) {
  Movie* movie = (Movie*) malloc(sizeof(Movie));
  strcpy(movie->title, title);
  movie->year = year;
  movie->rating = rating;

  return movie;
}

// Function to print the movie
void print_movie(Movie* movie) {
  printf("%s (%d) - %d\n", movie->title, movie->year, movie->rating);
}

// Function to calculate the average rating of a list of movies
double calculate_average_rating(Movie** movies, int num_movies) {
  double sum = 0;
  for (int i = 0; i < num_movies; i++) {
    sum += movies[i]->rating;
  }

  return sum / num_movies;
}

// Function to find the movie with the highest rating
Movie* find_highest_rated_movie(Movie** movies, int num_movies) {
  Movie* highest_rated_movie = NULL;
  int highest_rating = MIN_RATING;

  for (int i = 0; i < num_movies; i++) {
    if (movies[i]->rating > highest_rating) {
      highest_rated_movie = movies[i];
      highest_rating = movies[i]->rating;
    }
  }

  return highest_rated_movie;
}

// Main function
int main() {
  // Create a list of movies
  Movie* movies[] = {
    create_movie("The Godfather", 1972, 9),
    create_movie("The Dark Knight", 2008, 9),
    create_movie("12 Angry Men", 1957, 9),
    create_movie("Schindler's List", 1993, 9),
    create_movie("The Shawshank Redemption", 1994, 9)
  };

  // Print the list of movies
  printf("Movies:\n");
  for (int i = 0; i < 5; i++) {
    print_movie(movies[i]);
  }

  // Calculate the average rating of the movies
  double average_rating = calculate_average_rating(movies, 5);
  printf("Average rating: %.2f\n", average_rating);

  // Find the movie with the highest rating
  Movie* highest_rated_movie = find_highest_rated_movie(movies, 5);
  printf("Highest rated movie: ");
  print_movie(highest_rated_movie);

  return 0;
}