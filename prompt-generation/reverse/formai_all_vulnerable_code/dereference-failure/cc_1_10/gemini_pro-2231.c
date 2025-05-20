//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: real-life
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

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int year;
} Movie;

// Create a function to print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General audiences\n");
    printf("PG: Parental guidance suggested\n");
    printf("PG13: Parents strongly cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No one 17 and under admitted\n");
}

// Create a function to get the movie rating from the user
Rating get_movie_rating() {
    char rating_str[10];
    Rating rating;

    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%s", rating_str);

    if (strcmp(rating_str, "G") == 0) {
        rating = G;
    } else if (strcmp(rating_str, "PG") == 0) {
        rating = PG;
    } else if (strcmp(rating_str, "PG13") == 0) {
        rating = PG13;
    } else if (strcmp(rating_str, "R") == 0) {
        rating = R;
    } else if (strcmp(rating_str, "NC17") == 0) {
        rating = NC17;
    } else {
        printf("Invalid rating. Please enter a valid rating.\n");
        rating = get_movie_rating();
    }

    return rating;
}

// Create a function to create a new movie
Movie *create_movie() {
    Movie *movie = malloc(sizeof(Movie));

    printf("Enter the movie title: ");
    scanf("%s", movie->title);

    movie->rating = get_movie_rating();

    printf("Enter the movie year: ");
    scanf("%d", &movie->year);

    return movie;
}

// Create a function to print the movie details
void print_movie(Movie *movie) {
    printf("Movie Title: %s\n", movie->title);
    printf("Movie Rating: %d\n", movie->rating);
    printf("Movie Year: %d\n", movie->year);
}

// Create a function to free the memory allocated to the movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Print the movie rating system
    print_rating_system();

    // Create a new movie
    Movie *movie = create_movie();

    // Print the movie details
    print_movie(movie);

    // Free the memory allocated to the movie
    free_movie(movie);

    return 0;
}