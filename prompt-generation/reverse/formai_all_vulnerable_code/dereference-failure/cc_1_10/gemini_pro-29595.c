//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ephemeral movie rating system

// Movie struct
typedef struct Movie {
    char *title;
    int rating;
} Movie;

// Create a new movie
Movie *new_movie(char *title, int rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = malloc(strlen(title) + 1);
    strcpy(movie->title, title);
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
    printf("%s: %d\n", movie->title, movie->rating);
}

// Compare two movies
int compare_movies(const void *a, const void *b) {
    Movie *movie1 = *(Movie **)a;
    Movie *movie2 = *(Movie **)b;
    return movie1->rating - movie2->rating;
}

// Main function
int main() {
    // Create a list of movies
    Movie *movies[] = {
        new_movie("The Shawshank Redemption", 9),
        new_movie("The Godfather", 9),
        new_movie("The Dark Knight", 8),
        new_movie("12 Angry Men", 8),
        new_movie("Schindler's List", 9),
    };

    // Sort the movies by rating
    qsort(movies, sizeof(movies) / sizeof(Movie *), sizeof(Movie *), compare_movies);

    // Print the movies
    for (int i = 0; i < sizeof(movies) / sizeof(Movie *); i++) {
        print_movie(movies[i]);
    }

    // Free the movies
    for (int i = 0; i < sizeof(movies) / sizeof(Movie *); i++) {
        free_movie(movies[i]);
    }

    return 0;
}