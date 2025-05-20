//FormAI DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct movie {
  char title[50];
  char director[30];
  int year;
  float rating;
};

void add_movie(struct movie* movies, int* num_movies);
void list_movies(struct movie* movies, int num_movies);
void rate_movie(struct movie* movies, int num_movies);

int main() {
  int option, num_movies = 0, i;
  struct movie* movies = (struct movie*)malloc(50 * sizeof(struct movie));

  while(true) {
    printf("1. Add Movie\n2. List Movies\n3. Rate Movie\n4. Exit\nEnter your choice: ");
    scanf("%d", &option);

    switch(option) {
      case 1:
        add_movie(movies, &num_movies);
        break;
      case 2:
        list_movies(movies, num_movies);
        break;
      case 3:
        rate_movie(movies, num_movies);
        break;
      case 4:
        free(movies);
        printf("\nGoodbye!\n");
        exit(0);
      default:
        printf("\nInvalid choice. Try again.\n");
    }
  }

  return 0;
}

void add_movie(struct movie* movies, int* num_movies) {
  struct movie new_movie;

  printf("\nEnter movie title: ");
  scanf(" %[^\n]s", new_movie.title);

  for(int i = 0; i < *num_movies; i++) {
    if(strcmp(movies[i].title, new_movie.title) == 0) {
      printf("\nMovie already exists in the system.\n");
      return;
    }
  }

  printf("Enter movie director: ");
  scanf(" %[^\n]s", new_movie.director);

  printf("Enter movie year: ");
  scanf("%d", &new_movie.year);

  new_movie.rating = 0;

  movies[*num_movies] = new_movie;
  (*num_movies)++;

  printf("\nMovie added successfully!\n");
}

void list_movies(struct movie* movies, int num_movies) {
  if(num_movies == 0) {
    printf("\nNo movies in system.\n");
    return;
  }

  printf("\nList of Movies:\n");

  for(int i = 0; i < num_movies; i++) {
    printf("\nTitle: %s\n", movies[i].title);
    printf("Director: %s\n", movies[i].director);
    printf("Year: %d\n", movies[i].year);
    printf("Rating: %.1f\n", movies[i].rating);
  }

  printf("\n");
}

void rate_movie(struct movie* movies, int num_movies) {
  if(num_movies == 0) {
    printf("\nNo movies in system.\n");
    return;
  }

  char movie_title[50];
  int found = 0;
  float rating;

  printf("\nEnter movie title: ");
  scanf(" %[^\n]s", movie_title);

  for(int i = 0; i < num_movies; i++) {
    if(strcmp(movies[i].title, movie_title) == 0) {
      printf("Enter rating (0-10): ");
      scanf("%f", &rating);

      if(rating < 0 || rating > 10) {
        printf("\nWrong rating format. Please try again.\n");
        return;
      }

      movies[i].rating = rating;
      found = 1;
      break;
    }
  }

  if(found == 0) {
    printf("\nMovie not found in the system.\n");
    return;
  }

  printf("\nRating updated successfully!\n");
}