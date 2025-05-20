//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: interoperable
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

// Define the movie structure
typedef struct {
    char *title;
    int year;
    Rating rating;
} Movie;

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
    printf("%s (%d) - %s\n", movie->title, movie->year, movie->rating);
}

// Compare two movies by their titles
int compare_movies_by_title(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;
    return strcmp(movie1->title, movie2->title);
}

// Compare two movies by their years
int compare_movies_by_year(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;
    return movie1->year - movie2->year;
}

// Compare two movies by their ratings
int compare_movies_by_rating(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;
    return movie1->rating - movie2->rating;
}

// Get the user's input for a movie
Movie *get_user_input() {
    char title[100];
    int year;
    Rating rating;

    printf("Enter the movie title: ");
    scanf("%s", title);

    printf("Enter the movie year: ");
    scanf("%d", &year);

    printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
    scanf("%s", rating);

    return create_movie(title, year, rating);
}

// Main function
int main() {
    // Create an array of movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", 1994, PG13),
        create_movie("The Godfather", 1972, R),
        create_movie("The Dark Knight", 2008, PG13),
        create_movie("The Lord of the Rings: The Return of the King", 2003, PG13),
        create_movie("Pulp Fiction", 1994, R),
        create_movie("Fight Club", 1999, R),
        create_movie("The Matrix", 1999, R),
        create_movie("Star Wars: Episode IV - A New Hope", 1977, PG),
        create_movie("The Silence of the Lambs", 1991, R),
        create_movie("Schindler's List", 1993, R),
    };

    // Get the user's input for a movie
    Movie *movie = get_user_input();

    // Find the movie in the array
    Movie **found_movie = bsearch(movie, movies, sizeof(movies) / sizeof(Movie *), sizeof(Movie *), compare_movies_by_title);

    // Print the movie information
    if (found_movie) {
        printf("The movie \"%s\" was released in %d and is rated %s.\n", movie->title, movie->year, movie->rating);
    } else {
        printf("The movie \"%s\" was not found.\n", movie->title);
    }

    // Free the memory allocated for the movie
    free(movie);

    return 0;
}