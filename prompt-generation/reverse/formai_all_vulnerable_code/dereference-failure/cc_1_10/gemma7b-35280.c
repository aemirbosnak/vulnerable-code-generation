//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STARS 5

typedef struct Movie {
    char title[256];
    int year;
    double rating;
    struct Movie* next;
} Movie;

void printMovieList(Movie* head) {
    Movie* current = head;
    while (current) {
        printf("%s (%d) - %.1f stars\n", current->title, current->year, current->rating);
        current = current->next;
    }
}

int main() {
    Movie* head = NULL;

    // Create a few movies
    Movie* newMovie1 = malloc(sizeof(Movie));
    strcpy(newMovie1->title, "The Shawshank Redemption");
    newMovie1->year = 1994;
    newMovie1->rating = 9.3;
    newMovie1->next = head;
    head = newMovie1;

    Movie* newMovie2 = malloc(sizeof(Movie));
    strcpy(newMovie2->title, "The Godfather");
    newMovie2->year = 1972;
    newMovie2->rating = 9.2;
    newMovie2->next = head;
    head = newMovie2;

    Movie* newMovie3 = malloc(sizeof(Movie));
    strcpy(newMovie3->title, "The Dark Knight Rises");
    newMovie3->year = 2008;
    newMovie3->rating = 8.8;
    newMovie3->next = head;
    head = newMovie3;

    // Print the movie list
    printMovieList(head);

    return 0;
}