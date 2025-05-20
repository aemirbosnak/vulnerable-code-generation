//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    RATED_G,
    RATED_PG,
    RATED_PG13,
    RATED_R,
    RATED_NC17,
    RATED_UNRATED
} rating_t;

// Define the movie struct
typedef struct {
    char *title;
    int year;
    rating_t rating;
} movie_t;

// Create a new movie
movie_t *create_movie(char *title, int year, rating_t rating) {
    movie_t *movie = malloc(sizeof(movie_t));
    if (movie == NULL) {
        return NULL;
    }

    movie->title = strdup(title);
    movie->year = year;
    movie->rating = rating;

    return movie;
}

// Destroy a movie
void destroy_movie(movie_t *movie) {
    free(movie->title);
    free(movie);
}

// Print a movie
void print_movie(movie_t *movie) {
    printf("%s (%d) - %d\n", movie->title, movie->year, movie->rating);
}

// Main function
int main() {
    // Create some movies
    movie_t *movies[] = {
        create_movie("The Shawshank Redemption", 1994, RATED_R),
        create_movie("The Godfather", 1972, RATED_R),
        create_movie("The Dark Knight", 2008, RATED_PG13),
        create_movie("Inception", 2010, RATED_PG13),
        create_movie("Interstellar", 2014, RATED_PG13),
        create_movie("The Martian", 2015, RATED_PG13),
        create_movie("Arrival", 2016, RATED_PG13),
        create_movie("Blade Runner 2049", 2017, RATED_R),
        create_movie("Dunkirk", 2017, RATED_PG13),
        create_movie("Bohemian Rhapsody", 2018, RATED_PG13),
    };

    // Print the movies
    for (int i = 0; i < 10; i++) {
        print_movie(movies[i]);
    }

    // Destroy the movies
    for (int i = 0; i < 10; i++) {
        destroy_movie(movies[i]);
    }

    return 0;
}