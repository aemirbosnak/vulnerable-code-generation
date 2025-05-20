//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int year;
    double ratings[MAX_RATINGS];
} Movie;

// Initialize a movie with the given title and year.
Movie *new_movie(char *title, int year) {
    Movie *movie = malloc(sizeof(Movie));
    strcpy(movie->title, title);
    movie->year = year;
    for (int i = 0; i < MAX_RATINGS; i++) {
        movie->ratings[i] = 0.0;
    }
    return movie;
}

// Add a rating to the given movie.
void add_rating(Movie *movie, double rating) {
    for (int i = 0; i < MAX_RATINGS; i++) {
        if (movie->ratings[i] == 0.0) {
            movie->ratings[i] = rating;
            break;
        }
    }
}

// Compute the average rating of the given movie.
double get_average_rating(Movie *movie) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < MAX_RATINGS; i++) {
        if (movie->ratings[i] != 0.0) {
            sum += movie->ratings[i];
            count++;
        }
    }
    return sum / count;
}

// Print the given movie to the console.
void print_movie(Movie *movie) {
    printf("%s (%d): %.2f\n", movie->title, movie->year, get_average_rating(movie));
}

// Free the memory allocated to the given movie.
void free_movie(Movie *movie) {
    free(movie);
}

int main() {
    // Create an array of movies.
    Movie *movies[MAX_MOVIES];

    // Add movies to the array.
    movies[0] = new_movie("The Shawshank Redemption", 1994);
    movies[1] = new_movie("The Godfather", 1972);
    movies[2] = new_movie("The Dark Knight", 2008);
    movies[3] = new_movie("12 Angry Men", 1957);
    movies[4] = new_movie("Schindler's List", 1993);

    // Add ratings to the movies.
    add_rating(movies[0], 4.5);
    add_rating(movies[0], 5.0);
    add_rating(movies[1], 5.0);
    add_rating(movies[1], 4.5);
    add_rating(movies[2], 5.0);
    add_rating(movies[2], 4.5);
    add_rating(movies[3], 4.5);
    add_rating(movies[3], 4.0);
    add_rating(movies[4], 5.0);
    add_rating(movies[4], 4.5);

    // Print the movies to the console.
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Free the memory allocated to the movies.
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}