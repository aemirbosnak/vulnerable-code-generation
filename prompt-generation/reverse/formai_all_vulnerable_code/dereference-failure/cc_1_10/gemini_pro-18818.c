//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    int year;
    Rating rating;
} Movie;

// Create a new movie
Movie *new_movie(char *title, int year, Rating rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->year = year;
    movie->rating = rating;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("%s (%d) - %s\n", movie->title, movie->year, movie->rating);
}

// Get the movie rating from the user
Rating get_rating(void) {
    char rating;
    printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");
    scanf(" %c", &rating);
    rating = toupper(rating);
    switch (rating) {
        case 'G':
            return G;
        case 'P':
            return PG;
        case 'T':
            return PG13;
        case 'R':
            return R;
        case 'N':
            return NC17;
        default:
            printf("Invalid rating. Please enter a valid rating.\n");
            return get_rating();
    }
}

// Get the movie title from the user
char *get_title(void) {
    char *title;
    printf("Enter the movie title: ");
    scanf(" %[^\n]s", &title);
    return title;
}

// Get the movie year from the user
int get_year(void) {
    int year;
    printf("Enter the movie year: ");
    scanf(" %d", &year);
    return year;
}

// Main function
int main(void) {
    // Create a new movie
    Movie *movie = new_movie(get_title(), get_year(), get_rating());

    // Print the movie information
    print_movie(movie);

    // Free the movie
    free(movie);

    return 0;
}