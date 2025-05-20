//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the movie rating system
#define RATING_G     0
#define RATING_PG    1
#define RATING_PG13  2
#define RATING_R     3
#define RATING_NC17  4

// Define the movie genre system
#define GENRE_ACTION    0
#define GENRE_COMEDY    1
#define GENRE_DRAMA     2
#define GENRE_HORROR    3
#define GENRE_ROMANCE   4
#define GENRE_SCI_FI    5
#define GENRE_THRILLER  6
#define GENRE_WESTERN   7

// Define the movie structure
typedef struct {
    char *title;
    int year;
    int rating;
    int genre;
} Movie;

// Create a new movie
Movie *createMovie(char *title, int year, int rating, int genre) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->year = year;
    movie->rating = rating;
    movie->genre = genre;
    return movie;
}

// Print the movie information
void printMovie(Movie *movie) {
    printf("%s (%d) - ", movie->title, movie->year);
    switch (movie->rating) {
        case RATING_G:
            printf("G");
            break;
        case RATING_PG:
            printf("PG");
            break;
        case RATING_PG13:
            printf("PG-13");
            break;
        case RATING_R:
            printf("R");
            break;
        case RATING_NC17:
            printf("NC-17");
            break;
    }
    printf(" - ");
    switch (movie->genre) {
        case GENRE_ACTION:
            printf("Action");
            break;
        case GENRE_COMEDY:
            printf("Comedy");
            break;
        case GENRE_DRAMA:
            printf("Drama");
            break;
        case GENRE_HORROR:
            printf("Horror");
            break;
        case GENRE_ROMANCE:
            printf("Romance");
            break;
        case GENRE_SCI_FI:
            printf("Sci-Fi");
            break;
        case GENRE_THRILLER:
            printf("Thriller");
            break;
        case GENRE_WESTERN:
            printf("Western");
            break;
    }
    printf("\n");
}

// Free the movie
void freeMovie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create some movies
    Movie *movies[] = {
        createMovie("The Shawshank Redemption", 1994, RATING_R, GENRE_DRAMA),
        createMovie("The Godfather", 1972, RATING_R, GENRE_DRAMA),
        createMovie("The Dark Knight", 2008, RATING_PG13, GENRE_ACTION),
        createMovie("12 Angry Men", 1957, RATING_PG, GENRE_DRAMA),
        createMovie("Schindler's List", 1993, RATING_R, GENRE_DRAMA)
    };

    // Print the movies
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
    }

    // Free the movies
    for (int i = 0; i < 5; i++) {
        freeMovie(movies[i]);
    }

    return 0;
}