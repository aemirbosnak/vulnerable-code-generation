//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: portable
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
    int releaseYear;
    Rating rating;
} Movie;

// Create a new movie
Movie *createMovie(char *title, int releaseYear, Rating rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->releaseYear = releaseYear;
    movie->rating = rating;
    return movie;
}

// Print the movie information
void printMovie(Movie *movie) {
    printf("%s (%d) - %s\n", movie->title, movie->releaseYear,
           movie->rating == G ? "G" : movie->rating == PG ? "PG"
           : movie->rating == PG13 ? "PG-13" : movie->rating == R ? "R"
           : "NC-17");
}

// Compare two movies by their release year
int compareMoviesByReleaseYear(const void *a, const void *b) {
    Movie *movie1 = *(Movie **)a;
    Movie *movie2 = *(Movie **)b;
    return movie1->releaseYear - movie2->releaseYear;
}

// Compare two movies by their rating
int compareMoviesByRating(const void *a, const void *b) {
    Movie *movie1 = *(Movie **)a;
    Movie *movie2 = *(Movie **)b;
    return movie1->rating - movie2->rating;
}

// Get the user's input
void getInput(char *prompt, char *buffer, size_t size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    strtok(buffer, "\n");
}

// Main function
int main() {
    // Create an array of movies
    Movie *movies[] = {
        createMovie("The Shawshank Redemption", 1994, PG13),
        createMovie("The Godfather", 1972, R),
        createMovie("The Dark Knight", 2008, PG13),
        createMovie("12 Angry Men", 1957, PG),
        createMovie("Schindler's List", 1993, R),
        createMovie("The Lord of the Rings: The Return of the King", 2003, PG13),
        createMovie("Pulp Fiction", 1994, R),
        createMovie("Forrest Gump", 1994, PG13),
        createMovie("The Matrix", 1999, R),
        createMovie("Good Will Hunting", 1997, R),
    };

    // Get the number of movies
    int numMovies = sizeof(movies) / sizeof(movies[0]);

    // Sort the movies by release year
    qsort(movies, numMovies, sizeof(Movie *), compareMoviesByReleaseYear);

    // Print the movies by release year
    printf("Movies sorted by release year:\n");
    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }

    // Sort the movies by rating
    qsort(movies, numMovies, sizeof(Movie *), compareMoviesByRating);

    // Print the movies by rating
    printf("\nMovies sorted by rating:\n");
    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }

    // Get the user's input
    char input[100];
    getInput("Enter a movie title: ", input, sizeof(input));

    // Find the movie by title
    Movie *movie = NULL;
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(input, movies[i]->title) == 0) {
            movie = movies[i];
            break;
        }
    }

    // Print the movie information
    if (movie != NULL) {
        printf("\nMovie information:\n");
        printMovie(movie);
    } else {
        printf("Movie not found.\n");
    }

    // Free the memory allocated for the movies
    for (int i = 0; i < numMovies; i++) {
        free(movies[i]->title);
        free(movies[i]);
    }

    return 0;
}