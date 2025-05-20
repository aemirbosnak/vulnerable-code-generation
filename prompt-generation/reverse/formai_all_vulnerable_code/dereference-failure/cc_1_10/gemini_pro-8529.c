//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,      // General audience
    PG,     // Parental guidance suggested
    PG13,   // Parents strongly cautioned
    R,      // Restricted
    NC17    // No one 17 and under admitted
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int runtime;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, int runtime) {
    Movie *movie = malloc(sizeof(Movie));  
    movie->title = title;
    movie->rating = rating;
    movie->runtime = runtime;
    return movie;
}

// Print the movie info
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G - General audience\n");
            break;
        case PG:
            printf("PG - Parental guidance suggested\n");
            break;
        case PG13:
            printf("PG-13 - Parents strongly cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC17:
            printf("NC-17 - No one 17 and under admitted\n");
            break;
    }
    printf("Runtime: %d minutes\n", movie->runtime);
}

// Get the user input
void get_user_input(Movie *movie) {
    char title[100];
    int rating;
    int runtime;

    printf("Enter the movie title: ");
    scanf("%s", title);

    printf("Enter the movie rating (1 for G, 2 for PG, 3 for PG-13, 4 for R, 5 for NC-17): ");
    scanf("%d", &rating);

    printf("Enter the movie runtime in minutes: ");
    scanf("%d", &runtime);

    movie->title = title;
    movie->rating = rating;
    movie->runtime = runtime;
}

// Main function
int main() {
    // Create a new movie
    Movie *movie = create_movie("The Shawshank Redemption", PG13, 142);

    // Print the movie info
    print_movie(movie);

    // Get the user input
    get_user_input(movie);

    // Print the movie info
    print_movie(movie);

    return 0;
}