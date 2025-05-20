//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie structure
typedef struct {
    char *title;
    int year;
    Rating rating;
} Movie;

// Create a new movie
Movie *create_movie(char *title, int year, Rating rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->year = year;
    movie->rating = rating;
    return movie;
}

// Free a movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Print a movie
void print_movie(Movie *movie) {
    printf("%s (%d) - %s\n", movie->title, movie->year, movie->rating);
}

// Compare two movies
int compare_movies(const void *a, const void *b) {
    const Movie *movie1 = (const Movie *)a;
    const Movie *movie2 = (const Movie *)b;
    return strcmp(movie1->title, movie2->title);
}

// Main function
int main() {
    // Create an array of movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", 1994, R),
        create_movie("The Godfather", 1972, R),
        create_movie("The Dark Knight", 2008, PG13),
        create_movie("12 Angry Men", 1957, PG),
        create_movie("Schindler's List", 1993, R),
        create_movie("Pulp Fiction", 1994, R),
        create_movie("The Lord of the Rings: The Return of the King", 2003, PG13),
        create_movie("The Silence of the Lambs", 1991, R),
        create_movie("Forrest Gump", 1994, PG13),
        create_movie("Fight Club", 1999, R),
    };

    // Sort the array of movies
    qsort(movies, sizeof(movies) / sizeof(Movie *), sizeof(Movie *), compare_movies);

    // Print the sorted array of movies
    for (int i = 0; i < sizeof(movies) / sizeof(Movie *); i++) {
        print_movie(movies[i]);
    }

    // Free the array of movies
    for (int i = 0; i < sizeof(movies) / sizeof(Movie *); i++) {
        free_movie(movies[i]);
    }

    return 0;
}