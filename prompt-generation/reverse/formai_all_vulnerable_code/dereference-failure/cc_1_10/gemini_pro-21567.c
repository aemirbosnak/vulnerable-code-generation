//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the movie struct
typedef struct Movie {
    char *title;
    int rating;
} Movie;

// Create a new movie
Movie *newMovie(char *title, int rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    return movie;
}

// Print a movie
void printMovie(Movie *movie) {
    printf("%s: %d\n", movie->title, movie->rating);
}

// Compare two movies
int compareMovies(Movie *a, Movie *b) {
    return strcmp(a->title, b->title);
}

// Sort an array of movies
void sortMovies(Movie **movies, int numMovies) {
    qsort(movies, numMovies, sizeof(Movie *), (int (*)(const void *, const void *))compareMovies);
}

// Get the average rating of an array of movies
double getAverageRating(Movie **movies, int numMovies) {
    double totalRating = 0;
    for (int i = 0; i < numMovies; i++) {
        totalRating += movies[i]->rating;
    }
    return totalRating / numMovies;
}

// Get the highest rated movie from an array of movies
Movie *getHighestRatedMovie(Movie **movies, int numMovies) {
    Movie *highestRatedMovie = NULL;
    int highestRating = -1;
    for (int i = 0; i < numMovies; i++) {
        if (movies[i]->rating > highestRating) {
            highestRating = movies[i]->rating;
            highestRatedMovie = movies[i];
        }
    }
    return highestRatedMovie;
}

// Get the lowest rated movie from an array of movies
Movie *getLowestRatedMovie(Movie **movies, int numMovies) {
    Movie *lowestRatedMovie = NULL;
    int lowestRating = 10;
    for (int i = 0; i < numMovies; i++) {
        if (movies[i]->rating < lowestRating) {
            lowestRating = movies[i]->rating;
            lowestRatedMovie = movies[i];
        }
    }
    return lowestRatedMovie;
}

// Main function
int main() {
    // Create an array of movies
    Movie *movies[] = {
        newMovie("The Shawshank Redemption", 9),
        newMovie("The Godfather", 9),
        newMovie("The Dark Knight", 9),
        newMovie("12 Angry Men", 9),
        newMovie("Schindler's List", 9),
        newMovie("The Lord of the Rings: The Return of the King", 9),
        newMovie("Pulp Fiction", 9),
        newMovie("The Good, the Bad and the Ugly", 9),
        newMovie("The Matrix", 8),
        newMovie("Star Wars: Episode V - The Empire Strikes Back", 8),
    };

    // Sort the movies by title
    sortMovies(movies, 10);

    // Print the sorted movies
    printf("Sorted movies:\n");
    for (int i = 0; i < 10; i++) {
        printMovie(movies[i]);
    }

    // Get the average rating of the movies
    double averageRating = getAverageRating(movies, 10);
    printf("Average rating: %.1f\n", averageRating);

    // Get the highest rated movie
    Movie *highestRatedMovie = getHighestRatedMovie(movies, 10);
    printf("Highest rated movie: %s\n", highestRatedMovie->title);

    // Get the lowest rated movie
    Movie *lowestRatedMovie = getLowestRatedMovie(movies, 10);
    printf("Lowest rated movie: %s\n", lowestRatedMovie->title);

    return 0;
}