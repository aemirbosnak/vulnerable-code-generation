//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie rating system structure
typedef struct {
    char title[100];
    int year;
    double rating;
} Movie;

// Initialize a movie rating system
Movie* initRatingSystem() {
    Movie* ratingSystem = malloc(sizeof(Movie) * 100);
    if (ratingSystem == NULL) {
        return NULL;
    }
    for (int i = 0; i < 100; i++) {
        strcpy(ratingSystem[i].title, "");
        ratingSystem[i].year = 0;
        ratingSystem[i].rating = 0.0;
    }
    return ratingSystem;
}

// Add a movie to the rating system
void addMovie(Movie* ratingSystem, char* title, int year, double rating) {
    int i = 0;
    while (i < 100 && strcmp(ratingSystem[i].title, "") != 0) {
        i++;
    }
    if (i < 100) {
        strcpy(ratingSystem[i].title, title);
        ratingSystem[i].year = year;
        ratingSystem[i].rating = rating;
    }
}

// Get the average rating of the movies in the rating system
double getAverageRating(Movie* ratingSystem) {
    int i = 0;
    double sum = 0.0;
    while (i < 100 && strcmp(ratingSystem[i].title, "") != 0) {
        sum += ratingSystem[i].rating;
        i++;
    }
    return sum / i;
}

// Print the movies in the rating system
void printMovies(Movie* ratingSystem) {
    int i = 0;
    while (i < 100 && strcmp(ratingSystem[i].title, "") != 0) {
        printf("%s (%d) - %.1f\n", ratingSystem[i].title, ratingSystem[i].year, ratingSystem[i].rating);
        i++;
    }
}

// Main function
int main() {
    // Initialize the rating system
    Movie* ratingSystem = initRatingSystem();

    // Add some movies to the rating system
    addMovie(ratingSystem, "The Shawshank Redemption", 1994, 9.3);
    addMovie(ratingSystem, "The Godfather", 1972, 9.2);
    addMovie(ratingSystem, "The Dark Knight", 2008, 9.0);
    addMovie(ratingSystem, "12 Angry Men", 1957, 9.0);
    addMovie(ratingSystem, "Schindler's List", 1993, 8.9);

    // Get the average rating of the movies in the rating system
    double averageRating = getAverageRating(ratingSystem);

    // Print the movies in the rating system
    printMovies(ratingSystem);

    // Print the average rating of the movies in the rating system
    printf("Average rating: %.1f\n", averageRating);

    return 0;
}