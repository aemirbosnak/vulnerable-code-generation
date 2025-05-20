//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store movie data
typedef struct movie {
    char *title;
    int yearReleased;
    char *genre;
    int rating;
} Movie;

// Function to create a new movie
Movie *createMovie(char *title, int yearReleased, char *genre, int rating) {
    Movie *movie = (Movie *)malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->yearReleased = yearReleased;
    movie->genre = strdup(genre);
    movie->rating = rating;
    return movie;
}

// Function to print movie details
void printMovie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Year Released: %d\n", movie->yearReleased);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
}

// Function to compare two movies by rating
int compareMoviesByRating(const void *a, const void *b) {
    Movie *movie1 = (Movie *)a;
    Movie *movie2 = (Movie *)b;
    return movie1->rating - movie2->rating;
}

// Function to get the average rating of a list of movies
double getAverageRating(Movie *movies[], int numMovies) {
    int totalRating = 0;
    for (int i = 0; i < numMovies; i++) {
        totalRating += movies[i]->rating;
    }
    return (double)totalRating / numMovies;
}

// Function to print the top N movies with the highest ratings
void printTopNMovies(Movie *movies[], int numMovies, int n) {
    // Sort the movies by rating in descending order
    qsort(movies, numMovies, sizeof(Movie *), compareMoviesByRating);

    // Print the top N movies
    printf("Top %d Movies with the Highest Ratings:\n", n);
    for (int i = 0; i < n; i++) {
        printMovie(movies[i]);
        printf("\n");
    }
}

// Driver code
int main() {
    // Create a list of movies
    Movie *movies[] = {
        createMovie("The Shawshank Redemption", 1994, "Drama", 9.3),
        createMovie("The Godfather", 1972, "Crime", 9.2),
        createMovie("The Dark Knight", 2008, "Action", 9.0),
        createMovie("12 Angry Men", 1957, "Drama", 9.0),
        createMovie("Schindler's List", 1993, "Drama", 8.9),
        createMovie("The Lord of the Rings: The Return of the King", 2003, "Fantasy", 8.9),
        createMovie("Pulp Fiction", 1994, "Crime", 8.9),
        createMovie("The Matrix", 1999, "Sci-Fi", 8.7),
        createMovie("Star Wars: Episode V - The Empire Strikes Back", 1980, "Sci-Fi", 8.7),
        createMovie("The Silence of the Lambs", 1991, "Thriller", 8.6)
    };

    int numMovies = sizeof(movies) / sizeof(Movie *);

    // Print the list of movies
    printf("All Movies:\n");
    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
        printf("\n");
    }

    // Get the average rating of the movies
    double averageRating = getAverageRating(movies, numMovies);
    printf("Average Rating: %.2f\n", averageRating);

    // Print the top 5 movies with the highest ratings
    printTopNMovies(movies, numMovies, 5);

    // Free the memory allocated for the movies
    for (int i = 0; i < numMovies; i++) {
        free(movies[i]->title);
        free(movies[i]->genre);
        free(movies[i]);
    }

    return 0;
}