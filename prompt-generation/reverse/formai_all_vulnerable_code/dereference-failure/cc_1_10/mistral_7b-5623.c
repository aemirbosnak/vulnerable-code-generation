//MISTRAL-7B DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    int rating;
    struct movie *next;
} movie;

movie *head = NULL;

void addMovie(char *title, int rating) {
    movie *newMovie = (movie *) malloc(sizeof(movie));
    strcpy(newMovie->title, title);
    newMovie->rating = rating;
    newMovie->next = head;
    head = newMovie;
}

void printMovies() {
    movie *current = head;
    printf("Movie Ratings\n-----------------------\n");
    while (current != NULL) {
        printf("%s - %d\n", current->title, current->rating);
        current = current->next;
    }
}

void searchMovie(char *title) {
    movie *current = head;
    int found = 0;
    while (current != NULL && found == 0) {
        if (strcmp(current->title, title) == 0) {
            printf("%s - %d\n", current->title, current->rating);
            found = 1;
        } else {
            current = current->next;
        }
    }
    if (found == 0) {
        printf("Movie not found.\n");
    }
}

void updateRating(char *title, int newRating) {
    movie *current = head;
    movie *previous = NULL;
    int found = 0;
    while (current != NULL && found == 0) {
        if (strcmp(current->title, title) == 0) {
            found = 1;
            previous->rating = newRating;
        } else {
            previous = current;
            current = current->next;
        }
    }
    if (found == 0) {
        printf("Movie not found.\n");
    }
}

int main() {
    addMovie("Inception", 9);
    addMovie("The Dark Knight", 10);
    addMovie("The Shawshank Redemption", 9.3);
    addMovie("The Godfather", 9.2);
    addMovie("The Matrix", 8.7);

    printMovies();

    searchMovie("The Shawshank Redemption");

    updateRating("The Dark Knight", 11);

    printMovies();

    return 0;
}