//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void explode(char **arr, int size) {
  for (int i = 0; i < size; i++) {
    free(arr[i]);
  }
  free(arr);
}

int main() {
  int num_movies = 0;
  char ***movies = NULL;

  // Allocate memory for the movie list
  movies = (char ***)malloc(sizeof(char **));
  movies[0] = (char **)malloc(sizeof(char *) * 10);
  movies[0][0] = (char *)malloc(100);

  // Get the movie title
  printf("Enter the movie title: ");
  getline(movies[0][0], 100, stdin);

  // Increment the number of movies
  num_movies++;

  // Allocate more memory if necessary
  if (num_movies % 10 == 0) {
    movies = (char ***)realloc(movies, sizeof(char **) * (num_movies + 1));
    movies[num_movies] = (char **)malloc(sizeof(char *) * 10);
  }

  // Get the movie rating
  printf("Enter the movie rating (out of 10): ");
  int rating = atoi(stdin);

  // Store the movie rating
  movies[num_movies - 1][0] = (char *)malloc(10);
  sprintf(movies[num_movies - 1][0], "%d", rating);

  // Print the movie list
  for (int i = 0; i < num_movies; i++) {
    printf("Movie title: %s\n", movies[i][0]);
    printf("Movie rating: %s\n", movies[i][0]);
    printf("\n");
  }

  // Free the memory
  explode(movies, num_movies);

  return 0;
}