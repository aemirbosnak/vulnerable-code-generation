//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MovieRating {
  char title[50];
  int year;
  float rating;
  char genre[50];
  struct MovieRating* next;
};

void addMovie(struct MovieRating** head) {
  struct MovieRating* newMovie = (struct MovieRating*)malloc(sizeof(struct MovieRating));
  printf("Enter movie title: ");
  scanf("%s", newMovie->title);
  printf("Enter movie year: ");
  scanf("%d", &newMovie->year);
  printf("Enter movie rating: ");
  scanf("%f", &newMovie->rating);
  printf("Enter movie genre: ");
  scanf("%s", newMovie->genre);
  newMovie->next = NULL;

  if (*head == NULL) {
    *head = newMovie;
  } else {
    (*head)->next = newMovie;
  }
}

void printMovies(struct MovieRating* head) {
  while (head) {
    printf("Title: %s\n", head->title);
    printf("Year: %d\n", head->year);
    printf("Rating: %.1f\n", head->rating);
    printf("Genre: %s\n", head->genre);
    printf("\n");
    head = head->next;
  }
}

int main() {
  struct MovieRating* head = NULL;
  int choice;

  while (1) {
    printf("Enter 1 to add a movie, 2 to print movies, or 3 to exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        addMovie(&head);
        break;
      case 2:
        printMovies(head);
        break;
      case 3:
        exit(0);
    }
  }

  return 0;
}