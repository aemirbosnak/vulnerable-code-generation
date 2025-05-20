//FormAI DATASET v1.0 Category: Movie Rating System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure for storing movie ratings
struct movieRating {
  char title[50];
  char genre[20];
  int rating;
};

//Function to read in movie details from user
void inputMovies(struct movieRating movies[], int n) {
  for(int i=0; i<n; i++) {
    printf("Enter movie title: ");
    scanf("%s", movies[i].title);
    printf("Enter movie genre: ");
    scanf("%s", movies[i].genre);
    printf("Enter movie rating (out of 10): ");
    scanf("%d", &movies[i].rating);
  }
  printf("\n");
}

//Function to display all movies and their ratings
void displayMovies(struct movieRating movies[], int n) {
  printf("All movies and their ratings:\n");
  for(int i=0; i<n; i++) {
    printf("%s (%s): %d/10\n", movies[i].title, movies[i].genre, movies[i].rating);
  }
  printf("\n");
}

//Function to display top rated movies
void displayTopRatedMovies(struct movieRating movies[], int n) {
  printf("Top rated movies:\n");
  //Sort the movies in descending order of rating
  for(int i=0; i<n-1; i++) {
    for(int j=0; j<n-i-1; j++) {
      if(movies[j].rating < movies[j+1].rating) {
        //Swap the two movies
        struct movieRating temp = movies[j];
        movies[j] = movies[j+1];
        movies[j+1] = temp;
      }
    }
  }
  //Display top 3 movies
  for(int i=0; i<3; i++) {
    printf("%d. %s (%s): %d/10\n", i+1, movies[i].title, movies[i].genre, movies[i].rating);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Enter number of movies: ");
  scanf("%d", &n);

  //Dynamically allocate memory
  struct movieRating *movies = (struct movieRating*) malloc(n * sizeof(struct movieRating));

  inputMovies(movies, n);
  displayMovies(movies, n);
  displayTopRatedMovies(movies, n);

  //Free dynamically allocated memory
  free(movies);

  return 0;
}