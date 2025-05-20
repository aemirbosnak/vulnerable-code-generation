//FormAI DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define struct for movie
typedef struct {
    char title[100];
    char director[50];
    int year;
    float rating;
} Movie;

// function to recursively get user input for movie rating
void rateMovie(Movie *movie) {
    // prompt user for rating for current movie
    printf("Please rate the movie %s, directed by %s in %d (Out of 10): ", movie->title, movie->director, movie->year);
    // get input from user
    char input[10];
    fgets(input, 10, stdin);
    // convert user input to float
    float rating = atof(input);
    // check if input is within range
    if (rating < 0 || rating > 10) {
        printf("Invalid input\n");
        // recursively call function until valid input is received
        rateMovie(movie);
    } else {
        // if input is valid, set rating in movie struct
        movie->rating = rating;
    }
}

// function to recursively prompt user to add movie information
void addMovie(Movie *movie) {
    printf("Please enter the movie information:\n");
    // prompt user for title
    printf("Title: ");
    fgets(movie->title, 100, stdin);
    // prompt user for director
    printf("Director: ");
    fgets(movie->director, 50, stdin);
    // prompt user for year
    printf("Year: ");
    char input[10];
    fgets(input, 10, stdin);
    // convert user input to int
    int year = atoi(input);
    // check if input is within range
    if (year < 1900 || year > 2021) {
        printf("Invalid input\n");
        // recursively call function until valid input is received
        addMovie(movie);
    } else {
        // if input is valid, set year in movie struct and call rateMovie function
        movie->year = year;
        rateMovie(movie);
    }
}

// function to display movie information
void displayMovie(Movie *movie) {
    printf("\nMovie: %s\n", movie->title);
    printf("Directed by: %s\n", movie->director);
    printf("Released in: %d\n", movie->year);
    printf("Rating: %.1f\n", movie->rating);
}

int main() {
    // allocate memory for array of movies (up to 10)
    Movie *movies = malloc(10 * sizeof(Movie));
    // initialize count variable
    int count = 0;
    // loop through and prompt user to add movies until maximum is reached or user chooses to stop
    while (count < 10) {
        printf("\nDo you want to rate a movie? (Y/N): ");
        char input[2];
        fgets(input, 2, stdin);
        // check if user wants to stop adding movies
        if (strcmp(input, "N") == 0 || strcmp(input, "n") == 0) {
            break;
        } else if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
            // if user wants to rate a movie, allocate memory for current movie and call addMovie function
            Movie *currentMovie = malloc(sizeof(Movie));
            addMovie(currentMovie);
            // add current movie to array and increment count
            movies[count++] = *currentMovie;
            free(currentMovie);
        } else {
            // if input is invalid, prompt user again
            printf("Invalid input\n");
        }
    }
    // display all added movies
    printf("\nMovies:\n");
    for (int i = 0; i < count; i++) {
        displayMovie(&movies[i]);
    }
    // free allocated memory
    free(movies);
    return 0;
}