//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: multivariable
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

// Define the movie categories
typedef enum {
    ACTION,
    ADVENTURE,
    COMEDY,
    DRAMA,
    HORROR,
    ROMANCE,
    SCI_FI,
    THRILLER
} Category;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    Category category;
    int year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, Category category, int year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    movie->category = category;
    movie->year = year;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("%s (%d) - %s - %d\n", movie->title, movie->rating, movie->category, movie->year);
}

// Get the movie rating
Rating get_movie_rating(Movie *movie) {
    return movie->rating;
}

// Get the movie category
Category get_movie_category(Movie *movie) {
    return movie->category;
}

// Get the movie year
int get_movie_year(Movie *movie) {
    return movie->year;
}

// Main function
int main() {
    // Create a few movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", R, DRAMA, 1994),
        create_movie("The Godfather", R, DRAMA, 1972),
        create_movie("The Dark Knight", PG13, ACTION, 2008),
        create_movie("Inception", PG13, SCI_FI, 2010),
        create_movie("The Lord of the Rings: The Return of the King", PG13, ADVENTURE, 2003)
    };

    // Print the movie information
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Get the movie rating
    Rating rating = get_movie_rating(movies[0]);
    printf("The movie '%s' has a rating of %d.\n", movies[0]->title, rating);

    // Get the movie category
    Category category = get_movie_category(movies[0]);
    printf("The movie '%s' is in the %s category.\n", movies[0]->title, category);

    // Get the movie year
    int year = get_movie_year(movies[0]);
    printf("The movie '%s' was released in %d.\n", movies[0]->title, year);

    // Free the movies
    for (int i = 0; i < 5; i++) {
        free(movies[i]);
    }

    return 0;
}