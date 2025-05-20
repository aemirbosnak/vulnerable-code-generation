//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: protected
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

// Declare the movie struct
typedef struct {
    char title[128];
    Rating rating;
    int year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, int year) {
    Movie *movie = malloc(sizeof(Movie));
    if (movie == NULL) {
        return NULL;
    }

    strcpy(movie->title, title);
    movie->rating = rating;
    movie->year = year;

    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G");
            break;
        case PG:
            printf("PG");
            break;
        case PG13:
            printf("PG-13");
            break;
        case R:
            printf("R");
            break;
        case NC17:
            printf("NC-17");
            break;
    }
    printf("\n");
    printf("Year: %d\n", movie->year);
}

// Get the movie rating
Rating get_movie_rating(Movie *movie) {
    return movie->rating;
}

// Set the movie rating
void set_movie_rating(Movie *movie, Rating rating) {
    movie->rating = rating;
}

// Main function
int main() {
    // Create a few movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", R, 1994),
        create_movie("The Godfather", R, 1972),
        create_movie("The Dark Knight", PG13, 2008),
        create_movie("The Lord of the Rings: The Return of the King", PG13, 2003),
        create_movie("Pulp Fiction", R, 1994)
    };

    // Print the movies
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
        printf("\n");
    }

    // Change the rating of one of the movies
    set_movie_rating(movies[2], PG);

    // Print the movie again
    print_movie(movies[2]);

    // Free the movies
    for (int i = 0; i < 5; i++) {
        free(movies[i]);
    }

    return 0;
}