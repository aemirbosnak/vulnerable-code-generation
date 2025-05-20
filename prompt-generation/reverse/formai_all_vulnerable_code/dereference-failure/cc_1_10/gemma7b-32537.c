//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STARS 5

typedef struct Movie {
    char title[256];
    int year;
    float rating;
    struct Movie* next;
} Movie;

void rateMovie(Movie* movie, int stars) {
    if (stars < 1 || stars > MAX_STARS) {
        return;
    }
    movie->rating = stars;
}

void printMovie(Movie* movie) {
    printf("%s (%d) - %.1f stars\n", movie->title, movie->year, movie->rating);
}

int main() {
    Movie* head = NULL;

    // Create a few movies
    Movie* movie1 = malloc(sizeof(Movie));
    strcpy(movie1->title, "The Shawshank Redemption");
    movie1->year = 1994;
    movie1->rating = 4.8;
    movie1->next = head;
    head = movie1;

    Movie* movie2 = malloc(sizeof(Movie));
    strcpy(movie2->title, "The Godfather");
    movie2->year = 1972;
    movie2->rating = 4.9;
    movie2->next = head;
    head = movie2;

    Movie* movie3 = malloc(sizeof(Movie));
    strcpy(movie3->title, "The Dark Knight Rises");
    movie3->year = 2008;
    movie3->rating = 4.6;
    movie3->next = head;
    head = movie3;

    // Rate the movies
    rateMovie(movie1, 5);
    rateMovie(movie2, 4);
    rateMovie(movie3, 3);

    // Print the movies
    printMovie(head);

    return 0;
}