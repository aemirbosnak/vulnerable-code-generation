//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: artistic
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

void rateMovie(Movie* movie) {
    char ratingStr[MAX_STARS + 1];
    int stars = movie->rating;

    switch (stars) {
        case 0:
            strcpy(ratingStr, "Flop!");
            break;
        case 1:
            strcpy(ratingStr, "Meh...");
            break;
        case 2:
            strcpy(ratingStr, "Not Bad");
            break;
        case 3:
            strcpy(ratingStr, "Good");
            break;
        case 4:
            strcpy(ratingStr, "Great!");
            break;
        case 5:
            strcpy(ratingStr, "Masterpiece!");
            break;
    }

    printf("%s (%d) - %s\n", movie->title, movie->year, ratingStr);
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
    movie3->rating = 4.2;
    movie3->next = head;
    head = movie3;

    // Rate the movies
    rateMovie(head);

    return 0;
}