//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    RATING_TERRIBLE = 1,
    RATING_BAD,
    RATING_OK,
    RATING_GOOD,
    RATING_EXCELLENT
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("%s: ", movie->title);
    switch (movie->rating) {
        case RATING_TERRIBLE:
            printf("Terrible\n");
            break;
        case RATING_BAD:
            printf("Bad\n");
            break;
        case RATING_OK:
            printf("Ok\n");
            break;
        case RATING_GOOD:
            printf("Good\n");
            break;
        case RATING_EXCELLENT:
            printf("Excellent\n");
            break;
    }
}

// Free the movie memory
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create some movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", RATING_EXCELLENT),
        create_movie("The Godfather", RATING_EXCELLENT),
        create_movie("The Dark Knight", RATING_EXCELLENT),
        create_movie("12 Angry Men", RATING_EXCELLENT),
        create_movie("Schindler's List", RATING_EXCELLENT),
        create_movie("The Lord of the Rings: The Return of the King", RATING_EXCELLENT),
        create_movie("Pulp Fiction", RATING_EXCELLENT),
        create_movie("Forrest Gump", RATING_EXCELLENT),
        create_movie("The Matrix", RATING_EXCELLENT),
        create_movie("Good Will Hunting", RATING_EXCELLENT),
    };

    // Print the movies
    for (int i = 0; i < 10; i++) {
        print_movie(movies[i]);
    }

    // Free the movies
    for (int i = 0; i < 10; i++) {
        free_movie(movies[i]);
    }

    return 0;
}