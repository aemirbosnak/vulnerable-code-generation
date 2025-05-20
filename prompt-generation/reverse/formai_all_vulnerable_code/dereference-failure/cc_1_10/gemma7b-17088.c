//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store movie ratings
typedef struct Movie {
    char name[50];
    int rating;
    struct Movie* next;
} Movie;

// Function to add a movie to the rating system
void addMovie(Movie* head, char* name, int rating) {
    Movie* newMovie = (Movie*)malloc(sizeof(Movie));
    strcpy(newMovie->name, name);
    newMovie->rating = rating;
    newMovie->next = NULL;

    if (head == NULL) {
        head = newMovie;
    } else {
        head->next = newMovie;
    }
    head = newMovie;
}

// Function to display the average rating of a movie
void displayAverageRating(Movie* head, char* name) {
    Movie* currentMovie = head;
    int totalRating = 0;
    int numRatings = 0;

    while (currentMovie) {
        if (strcmp(currentMovie->name, name) == 0) {
            totalRating += currentMovie->rating;
            numRatings++;
        }
        currentMovie = currentMovie->next;
    }

    if (numRatings > 0) {
        printf("The average rating for %s is %f.\n", name, (float)totalRating / numRatings);
    } else {
        printf("There are no ratings for %s.\n", name);
    }
}

// Function to update the average rating of a movie
void updateAverageRating(Movie* head, char* name, int newRating) {
    Movie* currentMovie = head;
    int totalRating = 0;
    int numRatings = 0;

    while (currentMovie) {
        if (strcmp(currentMovie->name, name) == 0) {
            totalRating += newRating;
            numRatings++;
        }
        currentMovie = currentMovie->next;
    }

    if (numRatings > 0) {
        currentMovie->rating = newRating;
        printf("The average rating for %s has been updated to %f.\n", name, (float)totalRating / numRatings);
    } else {
        printf("There are no ratings for %s.\n", name);
    }
}

int main() {
    Movie* head = NULL;

    // Add some movies to the rating system
    addMovie(head, "The Shawshank Redemption", 5);
    addMovie(head, "The Godfather", 4);
    addMovie(head, "The Dark Knight", 3);

    // Display the average rating of a movie
    displayAverageRating(head, "The Shawshank Redemption");

    // Update the average rating of a movie
    updateAverageRating(head, "The Godfather", 5);

    // Display the updated average rating of a movie
    displayAverageRating(head, "The Godfather");

    return 0;
}