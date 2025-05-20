//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17,
    UNRATED
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int year;
} Movie;

// Create a new movie
Movie *createMovie(char *title, Rating rating, int year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    movie->year = year;
    return movie;
}

// Print the movie information
void printMovie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Year: %d\n", movie->year);
}

// Compare two movies by title
int compareMovies(const void *a, const void *b) {
    Movie *movieA = *(Movie **)a;
    Movie *movieB = *(Movie **)b;
    return strcmp(movieA->title, movieB->title);
}

// Get the movie rating from the user
Rating getRating() {
    int rating;
    printf("Enter the movie rating (0-5): ");
    scanf("%d", &rating);
    return rating;
}

// Get the movie year from the user
int getYear() {
    int year;
    printf("Enter the movie year: ");
    scanf("%d", &year);
    return year;
}

// Get the movie title from the user
char *getTitle() {
    char *title = malloc(100);
    printf("Enter the movie title: ");
    scanf("%s", title);
    return title;
}

// Main function
int main() {
    // Create an array of movies
    Movie *movies[] = {
        createMovie("The Shawshank Redemption", R, 1994),
        createMovie("The Godfather", R, 1972),
        createMovie("The Dark Knight", PG13, 2008),
        createMovie("12 Angry Men", PG, 1957),
        createMovie("Schindler's List", R, 1993)
    };

    // Sort the movies by title
    qsort(movies, 5, sizeof(Movie *), compareMovies);

    // Print the movies
    for (int i = 0; i < 5; i++) {
        printMovie(movies[i]);
        printf("\n");
    }

    // Get the user's rating and year
    Rating rating = getRating();
    int year = getYear();

    // Get the user's input if he wants to add a new movie to the array
    char *title = getTitle();
    Movie *newMovie = createMovie(title, rating, year);
    movies[5] = newMovie;

    // Sort the movies by title
    qsort(movies, 6, sizeof(Movie *), compareMovies);

    // Print the movies
    for (int i = 0; i < 6; i++) {
        printMovie(movies[i]);
        printf("\n");
    }

    return 0;
}