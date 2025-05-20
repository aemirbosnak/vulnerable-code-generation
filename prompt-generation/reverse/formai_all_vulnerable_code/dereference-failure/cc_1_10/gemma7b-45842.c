//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STARS 5

typedef struct Movie {
    char title[256];
    char genre[256];
    int year;
    int rating;
    struct Movie* next;
} Movie;

void rateMovie(Movie* movie, int rating) {
    movie->rating = rating;
}

void printMovie(Movie* movie) {
    printf("%s (%d) - %s, Rating: %d/5\n", movie->title, movie->year, movie->genre, movie->rating);
}

int main() {
    Movie* head = NULL;

    // Create a few movies
    Movie* movie1 = malloc(sizeof(Movie));
    strcpy(movie1->title, "The Shawshank Redemption");
    strcpy(movie1->genre, "Drama");
    movie1->year = 1994;
    movie1->rating = 4;
    movie1->next = head;
    head = movie1;

    Movie* movie2 = malloc(sizeof(Movie));
    strcpy(movie2->title, "The Godfather");
    strcpy(movie2->genre, "Crime");
    movie2->year = 1972;
    movie2->rating = 5;
    movie2->next = head;
    head = movie2;

    Movie* movie3 = malloc(sizeof(Movie));
    strcpy(movie3->title, "The Dark Knight Rises");
    strcpy(movie3->genre, "Action");
    movie3->year = 2008;
    movie3->rating = 3;
    movie3->next = head;
    head = movie3;

    // Print the movies
    printMovie(head);

    // Rate the first movie to 5 stars
    rateMovie(movie1, 5);

    // Print the movies again after rating the first movie
    printMovie(head);

    return 0;
}