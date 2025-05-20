//FormAI DATASET v1.0 Category: Movie Rating System ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Structure to hold movie information
typedef struct Movie {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Function to get movie information from user
void getMovieInfo(Movie *movie) {
    printf("Enter movie title: ");
    fgets(movie->title, 50, stdin);
    printf("Enter movie director: ");
    fgets(movie->director, 50, stdin);
    printf("Enter movie release year: ");
    scanf("%d", &movie->year);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie->rating);
    // Consume newline character left in input buffer
    getchar();
}

// Function to display movie information
void displayMovieInfo(Movie movie) {
    printf("Title: %sDirector: %sYear: %dRating: %.1f\n\n", 
        movie.title, movie.director, movie.year, movie.rating);
}

int main() {
    int numMovies, i;
    float totalRating = 0.0, avgRating;
    Movie *movies;

    printf("Welcome to the Unique C Movie Rating System!\n\n");

    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);
    // Consume newline character left in input buffer
    getchar();

    // Allocate memory for movie array
    movies = (Movie*) malloc(numMovies * sizeof(Movie));

    // Get movie information from user for each movie
    for (i = 0; i < numMovies; i++) {
        printf("\nEnter information for movie #%d:\n", i+1);
        getMovieInfo(&movies[i]);
        totalRating += movies[i].rating;
    }

    // Calculate average rating
    avgRating = totalRating / numMovies;

    // Display movie information and rating
    printf("\n\nHere are the movies you have rated along with their information:\n\n");
    for (i = 0; i < numMovies; i++) {
        displayMovieInfo(movies[i]);
    }
    printf("The average movie rating is: %.1f\n\n", avgRating);

    // Free memory allocated for movie array
    free(movies);

    return 0;
}