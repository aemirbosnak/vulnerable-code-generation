//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,  // General audiences
    PG, // Parental guidance suggested
    PG13, // Parents strongly cautioned
    R,   // Restricted
    NC17 // No one 17 and under admitted
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, int year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    movie->year = year;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Year: %d\n", movie->year);
}

// Free the movie memory
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Get the movie rating from the user
Rating get_rating(void) {
    int rating;
    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%d", &rating);
    return rating;
}

// Get the movie year from the user
int get_year(void) {
    int year;
    printf("Enter the movie year: ");
    scanf("%d", &year);
    return year;
}

// Get the movie title from the user
char *get_title(void) {
    char *title = malloc(100);
    printf("Enter the movie title: ");
    scanf("%s", title);
    return title;
}

// Main function
int main(void) {
    // Create a new movie
    Movie *movie = create_movie("The Shawshank Redemption", R, 1994);

    // Print the movie information
    print_movie(movie);

    // Free the movie memory
    free_movie(movie);

    return 0;
}