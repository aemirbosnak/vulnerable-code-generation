//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

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

Movie* createMovie(char* title, int year, float rating) {
    Movie* movie = malloc(sizeof(Movie));

    strcpy(movie->title, title);
    movie->year = year;
    movie->rating = rating;
    movie->next = NULL;

    return movie;
}

int main() {
    Movie* head = NULL;

    // Create a few movies
    Movie* movie1 = createMovie("The Matrix", 1999, 4.8);
    Movie* movie2 = createMovie("The Lord of the Rings: The Fellowship of the Ring", 2001, 4.9);
    Movie* movie3 = createMovie("The Dark Knight", 2008, 4.5);

    // Rate the movies
    rateMovie(movie1, 5);
    rateMovie(movie2, 4);
    rateMovie(movie3, 4);

    // Print the ratings
    for (movie1 = head; movie1; movie1 = movie1->next) {
        printf("%s (%d) - Rating: %.1f stars\n", movie1->title, movie1->year, movie1->rating);
    }

    return 0;
}