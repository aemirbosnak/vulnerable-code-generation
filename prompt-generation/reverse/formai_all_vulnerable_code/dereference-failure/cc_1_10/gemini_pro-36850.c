//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,  // General audiences
    PG, // Parental guidance suggested
    PG13, // Parents strongly cautioned
    R,   // Restricted
    NC17 // No one 17 and under admitted
} MovieRating;

// Define the movie struct
typedef struct {
    char *title;
    MovieRating rating;
    int year;
} Movie;

// Create a new movie
Movie *createMovie(char *title, MovieRating rating, int year) {
    Movie *movie = malloc(sizeof(Movie));
    if (movie == NULL) {
        return NULL;
    }

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

// Get the movie rating
MovieRating getMovieRating(int rating) {
    switch (rating) {
        case 0:
            return G;
        case 1:
            return PG;
        case 2:
            return PG13;
        case 3:
            return R;
        case 4:
            return NC17;
        default:
            return -1;
    }
}

// Get the movie rating as a string
char *getMovieRatingString(MovieRating rating) {
    switch (rating) {
        case G:
            return "G";
        case PG:
            return "PG";
        case PG13:
            return "PG-13";
        case R:
            return "R";
        case NC17:
            return "NC-17";
        default:
            return "Unknown";
    }
}

// Get the movie year as a string
char *getMovieYearString(int year) {
    char *yearString = malloc(5);
    sprintf(yearString, "%d", year);
    return yearString;
}

// Get the movie as a JSON string
char *getMovieJSONString(Movie *movie) {
    char *jsonString = malloc(1024);
    sprintf(jsonString, "{\"title\": \"%s\", \"rating\": %d, \"year\": %d}", movie->title, movie->rating, movie->year);
    return jsonString;
}

// Free the movie
void freeMovie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create a new movie
    Movie *movie = createMovie("The Shawshank Redemption", R, 1994);

    // Print the movie information
    printMovie(movie);

    // Get the movie rating
    MovieRating rating = getMovieRating(movie->rating);

    // Get the movie rating as a string
    char *ratingString = getMovieRatingString(rating);

    // Get the movie year as a string
    char *yearString = getMovieYearString(movie->year);

    // Get the movie as a JSON string
    char *jsonString = getMovieJSONString(movie);

    // Print the movie rating and year
    printf("Rating: %s\n", ratingString);
    printf("Year: %s\n", yearString);

    // Print the movie as a JSON string
    printf("JSON: %s\n", jsonString);

    // Free the movie
    freeMovie(movie);

    return 0;
}