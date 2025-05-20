//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the movie rating system
typedef enum {
    G = 0, // General Audiences
    PG = 1, // Parental Guidance Suggested
    PG_13 = 2, // Parents Strongly Cautioned
    R = 3, // Restricted
    NC_17 = 4 // No One 17 and Under Admitted
} MovieRating;

// Define the movie struct
typedef struct {
    char* title;
    char* director;
    char* cast;
    int runtime;
    MovieRating rating;
} Movie;

// Function to initialize a movie struct
Movie* createMovie(char* title, char* director, char* cast, int runtime, MovieRating rating) {
    Movie* movie = (Movie*)malloc(sizeof(Movie));
    movie->title = title;
    movie->director = director;
    movie->cast = cast;
    movie->runtime = runtime;
    movie->rating = rating;
    return movie;
}

// Function to print a movie's details
void printMovieDetails(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Cast: %s\n", movie->cast);
    printf("Runtime: %d minutes\n", movie->runtime);
    printf("Rating: ");
    switch(movie->rating) {
        case G:
            printf("G - General Audiences\n");
            break;
        case PG:
            printf("PG - Parental Guidance Suggested\n");
            break;
        case PG_13:
            printf("PG-13 - Parents Strongly Cautioned\n");
            break;
        case R:
            printf("R - Restricted\n");
            break;
        case NC_17:
            printf("NC-17 - No One 17 and Under Admitted\n");
            break;
    }
}

// Function to free a movie struct
void freeMovie(Movie* movie) {
    free(movie->title);
    free(movie->director);
    free(movie->cast);
    free(movie);
}

// Main function
int main() {
    // Initialize movies
    Movie* movie1 = createMovie("The Shawshank Redemption", "Frank Darabont", "Tim Robbins, Morgan Freeman", 142, R);
    Movie* movie2 = createMovie("The Godfather", "Francis Ford Coppola", "Marlon Brando, Al Pacino", 175, R);
    Movie* movie3 = createMovie("The Dark Knight", "Christopher Nolan", "Christian Bale, Heath Ledger", 152, PG_13);

    // Print movie details
    printMovieDetails(movie1);
    printMovieDetails(movie2);
    printMovieDetails(movie3);

    // Free movies
    freeMovie(movie1);
    freeMovie(movie2);
    freeMovie(movie3);

    return 0;
}