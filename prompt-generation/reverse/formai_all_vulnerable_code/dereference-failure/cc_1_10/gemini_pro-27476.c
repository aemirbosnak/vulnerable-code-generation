//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: interoperable
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
    int year;
} Movie;

// Create a new movie
Movie *createMovie(char *title, MovieRating rating, int year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    movie->year = year;
    return movie;
}

// Print the movie information
void printMovie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Year: %d\n", movie->year);
}

// Get the movie rating as a string
char *getMovieRatingString(MovieRating rating) {
    switch (rating) {
        case G:
            return "G";
        case PG:
            return "PG";
        case PG13:
            return "PG13";
        case R:
            return "R";
        case NC17:
            return "NC17";
        default:
            return "Unknown";
    }
}

// Get the movie rating as an integer
int getMovieRatingInt(MovieRating rating) {
    switch (rating) {
        case G:
            return 0;
        case PG:
            return 1;
        case PG13:
            return 2;
        case R:
            return 3;
        case NC17:
            return 4;
        default:
            return -1;
    }
}

// Compare two movies by rating
int compareMoviesByRating(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;
    return getMovieRatingInt(movie1->rating) - getMovieRatingInt(movie2->rating);
}

// Main function
int main() {
    // Create an array of movies
    Movie *movies[] = {
        createMovie("The Shawshank Redemption", PG13, 1994),
        createMovie("The Godfather", R, 1972),
        createMovie("The Dark Knight", PG13, 2008),
        createMovie("12 Angry Men", PG, 1957),
        createMovie("Schindler's List", R, 1993),
    };

    // Print the original array of movies
    printf("Original array of movies:\n");
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
        printf("\n");
    }

    // Sort the array of movies by rating
    qsort(movies, 5, sizeof(Movie *), compareMoviesByRating);

    // Print the sorted array of movies
    printf("\nSorted array of movies by rating:\n");
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
        printf("\n");
    }

    return 0;
}