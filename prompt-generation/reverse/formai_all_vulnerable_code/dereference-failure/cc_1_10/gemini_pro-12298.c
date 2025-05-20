//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: peaceful
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

// Define the movie struct
typedef struct {
    char *title;
    int year;
    Rating rating;
} Movie;

// Print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General audiences\n");
    printf("PG: Parental guidance suggested\n");
    printf("PG13: Parents strongly cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No one 17 and under admitted\n");
}

// Get the movie rating from the user
Rating get_rating() {
    int rating;
    printf("Enter the movie rating (G, PG, PG13, R, or NC17): ");
    scanf("%d", &rating);
    return rating;
}

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
            printf("PG13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC17\n");
            break;
    }
}

// Free the movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Print the movie rating system
    print_rating_system();

    // Get the movie rating from the user
    Rating rating = get_rating();

    // Create a new movie
    Movie *movie = create_movie("The Shawshank Redemption", 1994, rating);

    // Print the movie information
    print_movie(movie);

    // Free the movie
    free_movie(movie);

    return 0;
}