//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Movie struct
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
    printf("%s (%d) - %d\n", movie->title, movie->year, movie->rating);
}

// Get the rating of a movie
Rating get_rating(Movie *movie) {
    return movie->rating;
}

// Set the rating of a movie
void set_rating(Movie *movie, Rating rating) {
    movie->rating = rating;
}

// Main function
int main() {
    // Create some movies
    Movie *movie1 = create_movie("The Shawshank Redemption", 1994, PG13);
    Movie *movie2 = create_movie("The Godfather", 1972, R);
    Movie *movie3 = create_movie("The Dark Knight", 2008, PG13);
    Movie *movie4 = create_movie("Schindler's List", 1993, R);
    Movie *movie5 = create_movie("Pulp Fiction", 1994, R);

    // Print the movies
    printf("Movies:\n");
    print_movie(movie1);
    print_movie(movie2);
    print_movie(movie3);
    print_movie(movie4);
    print_movie(movie5);

    // Get the rating of a movie
    Rating rating = get_rating(movie1);
    printf("The rating of %s is %d\n", movie1->title, rating);

    // Set the rating of a movie
    set_rating(movie1, PG);
    printf("The rating of %s is now %d\n", movie1->title, get_rating(movie1));

    // Free the movies
    free_movie(movie1);
    free_movie(movie2);
    free_movie(movie3);
    free_movie(movie4);
    free_movie(movie5);

    return 0;
}