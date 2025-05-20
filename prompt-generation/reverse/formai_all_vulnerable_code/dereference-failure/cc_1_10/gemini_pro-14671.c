//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} MovieRating;

// Define the movie struct
typedef struct {
    char *title;
    MovieRating rating;
    int releaseYear;
} Movie;

// Create a new movie
Movie *createMovie(char *title, MovieRating rating, int releaseYear) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    movie->releaseYear = releaseYear;
    return movie;
}

// Print the movie information
void printMovie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Release year: %d\n", movie->releaseYear);
}

// Get the movie rating as a string
char *getMovieRatingString(MovieRating rating) {
    switch (rating) {
        case G:
            return "G";
        case PG:
            return "PG";
        case PG13:
            return "PG-13";
        case R:
            return "R";
        case NC17:
            return "NC-17";
        default:
            return "Unknown";
    }
}

// Main function
int main() {
    // Create some movies
    Movie *movies[] = {
        createMovie("The Shawshank Redemption", PG13, 1994),
        createMovie("The Godfather", R, 1972),
        createMovie("The Dark Knight", PG13, 2008),
        createMovie("12 Years a Slave", R, 2013),
        createMovie("Schindler's List", R, 1993)
    };

    // Print the movie information
    for (int i = 0; i < 5; i++) {
        printf("Movie %d:\n", i + 1);
        printMovie(movies[i]);
        printf("\n");
    }

    // Free the movies
    for (int i = 0; i < 5; i++) {
        free(movies[i]->title);
        free(movies[i]);
    }

    return 0;
}