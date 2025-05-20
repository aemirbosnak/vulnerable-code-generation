//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

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
    movie->title = title;
    movie->year = year;
    movie->rating = rating;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Year: %d\n", movie->year);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG13:
            printf("PG-13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC-17\n");
            break;
    }
}

// Free the memory allocated for the movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create a few movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", 1994, PG13),
        create_movie("The Godfather", 1972, R),
        create_movie("The Dark Knight", 2008, PG13),
        create_movie("Pulp Fiction", 1994, R),
        create_movie("Schindler's List", 1993, R)
    };

    // Print the movie information
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
        printf("\n");
    }

    // Free the memory allocated for the movies
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}