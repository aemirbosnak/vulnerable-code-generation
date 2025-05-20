//FormAI DATASET v1.0 Category: Movie Rating System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct movie {
  char title[50];
  char genre[20];
  int rating;
} Movie;

// Function prototypes
void add_movie(Movie *, int *);
void display_movies(Movie *, int);
void rate_movie(Movie *, int);
void sort_movies(Movie *, int);
void search_movie(Movie *, int);
void remove_movie(Movie *, int *);

int main() {
  int movie_count = 0;
  Movie *movies = malloc(sizeof(Movie));

  char choice;
  do {
    printf("Welcome to the C Movie Rating System!\n");
    printf("Please select an option:\n");
    printf("1. Add a movie\n");
    printf("2. Display movies\n");
    printf("3. Rate a movie\n");
    printf("4. Sort movies\n");
    printf("5. Search for a movie\n");
    printf("6. Remove a movie\n");
    printf("7. Exit\n");

    // Get user choice
    choice = getchar();
    // Clear input buffer
    while ((getchar()) != '\n');

    switch (choice) {
      case '1':
        add_movie(movies, &movie_count);
        break;
      
      case '2':
        display_movies(movies, movie_count);
        break;

      case '3':
        rate_movie(movies, movie_count);
        break;

      case '4':
        sort_movies(movies, movie_count);
        break;

      case '5':
        search_movie(movies, movie_count);
        break;

      case '6':
        remove_movie(movies, &movie_count);
        break;

      case '7':
        printf("Thank you for using the C Movie Rating System!\n");
        break;

      default:
        printf("Invalid option. Please try again.\n");
        break;
    }
  } while (choice != '7');

  free(movies);
  return 0;
}

void add_movie(Movie *movies, int *movie_count) {
  printf("Enter the title of the movie: ");
  fgets(movies[*movie_count].title, 50, stdin);
  strtok(movies[*movie_count].title, "\n");

  printf("Enter the genre of the movie: ");
  fgets(movies[*movie_count].genre, 20, stdin);
  strtok(movies[*movie_count].genre, "\n");

  printf("Enter the rating of the movie (out of 10): ");
  scanf("%d", &movies[*movie_count].rating);
  while ((getchar()) != '\n');

  (*movie_count)++;
  movies = realloc(movies, (*movie_count + 1) * sizeof(Movie));

  printf("Movie added successfully!\n");
}

void display_movies(Movie *movies, int movie_count) {
  if (movie_count == 0) {
    printf("No movies found!\n");
  } else {
    printf("Title\t\tGenre\t\tRating\n");
    for (int i = 0; i < movie_count; i++) {
      printf("%s\t%s\t%d\n", movies[i].title, movies[i].genre, movies[i].rating);
    }
  }
}

void rate_movie(Movie *movies, int movie_count) {
  int index, rating;

  printf("Enter the index of the movie you want to rate: ");
  scanf("%d", &index);
  while ((getchar()) != '\n');

  if (index >= movie_count || index < 0) {
    printf("Index out of range!\n");
  } else {
    printf("Enter the new rating for %s: ", movies[index].title);
    scanf("%d", &rating);
    while ((getchar()) != '\n');

    movies[index].rating = rating;

    printf("%s has been rated successfully!\n", movies[index].title);
  }
}

void sort_movies(Movie *movies, int movie_count) {
  Movie temp;

  for (int i = 0; i < movie_count - 1; i++) {
    for (int j = i + 1; j < movie_count; j++) {
      if (strcmp(movies[i].title, movies[j].title) > 0) {
        temp = movies[i];
        movies[i] = movies[j];
        movies[j] = temp;
      }
    }
  }

  printf("Movies sorted successfully!\n");
}

void search_movie(Movie *movies, int movie_count) {
  char search[50];
  int found = 0;

  printf("Enter the title of the movie you want to search for: ");
  fgets(search, 50, stdin);
  strtok(search, "\n");

  for (int i = 0; i < movie_count; i++) {
    if (strcmp(search, movies[i].title) == 0) {
      printf("Title\t\tGenre\t\tRating\n");
      printf("%s\t%s\t%d\n", movies[i].title, movies[i].genre, movies[i].rating);
      found = 1;
      break;
    }
  }

  if (!found) {
    printf("Movie not found!\n");
  }
}

void remove_movie(Movie *movies, int *movie_count) {
  int index;

  printf("Enter the index of the movie you want to remove: ");
  scanf("%d", &index);
  while ((getchar()) != '\n');

  if (index >= *movie_count || index < 0) {
    printf("Index out of range!\n");
  } else {
    for (int i = index; i < *movie_count - 1; i++) {
      movies[i] = movies[i+1];
    }
    (*movie_count)--;
    movies = realloc(movies, (*movie_count + 1) * sizeof(Movie));

    printf("Movie removed successfully!\n");
  }
}