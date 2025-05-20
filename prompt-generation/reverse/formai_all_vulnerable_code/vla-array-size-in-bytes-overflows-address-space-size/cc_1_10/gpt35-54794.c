//FormAI DATASET v1.0 Category: Movie Rating System ; Style: scalable
#include <stdio.h>
#include <stdbool.h>

// Initializing Rating System for Movies
typedef struct movieRatingSystem {
  char title[50];
  char genre[20];
  float rating;
  bool watched;
} movie;

// Function to get movie details as input
void getMovieDetails(movie *m) {
  printf("Enter Movie Title: ");
  scanf("%s", m->title);
  printf("Enter Movie Genre: ");
  scanf("%s", m->genre);
  printf("Enter Movie Rating (out of 10): ");
  scanf("%f", &m->rating);
  printf("Have you watched this movie? (Enter 0 for No & 1 for Yes): ");
  int watched;
  scanf("%d", &watched);
  m->watched = watched ? true : false;
}

// Function to display movie details as output
void displayMovieDetails(movie *m) {
  printf("\nTitle: %s\n", m->title);
  printf("Genre: %s\n", m->genre);
  printf("Rating: %.1f/10\n", m->rating);
  printf("Watched: %s\n", m->watched ? "Yes" : "No");
}

int main() {
  int numMovies;
  printf("How many movies do you want to rate today? ");
  scanf("%d", &numMovies);
  
  // Array of structures to store and rate multiple movies
  movie allMovies[numMovies];
  for(int i=0; i<numMovies; i++) {
    printf("\nEnter details for Movie %d:\n", i+1);
    getMovieDetails(&allMovies[i]);
  }

  // Display all movie details with ratings
  for(int i=0; i<numMovies; i++) {
    printf("\nMovie %d:", i+1);
    displayMovieDetails(&allMovies[i]);
  }

  printf("\nThank you for submitting movie ratings!\n");
  return 0;
}