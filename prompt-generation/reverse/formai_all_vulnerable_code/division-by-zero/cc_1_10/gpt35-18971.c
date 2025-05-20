//FormAI DATASET v1.0 Category: Movie Rating System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to hold movie data
typedef struct {
    char title[50];
    char director[50];
    int year;
    float rating;
} Movie;

// Declare functions
void addMovie();
void viewMovies();
int getAverageRating();
void quit();

// Declare variables
Movie movies[100];
int numMovies = 0;

int main() {
    int choice;

    // Display menu and get user input
    do {
        printf("\n-------------- Movie Rating System --------------\n\n");
        printf("1. Add a movie\n");
        printf("2. View all movies\n");
        printf("3. Get average rating\n");
        printf("4. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie();
                break;
            case 2:
                viewMovies();
                break;
            case 3:
                printf("\nThe average movie rating is %d\n", getAverageRating());
                break;
            case 4:
                quit();
                break;
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add a movie to the array
void addMovie() {
    printf("\nPlease enter the movie details:\n");
    printf("Title: ");
    scanf("%s", movies[numMovies].title);
    printf("Director: ");
    scanf("%s", movies[numMovies].director);
    printf("Release year: ");
    scanf("%d", &movies[numMovies].year);
    printf("Rating (out of 10): ");
    scanf("%f", &movies[numMovies].rating);

    numMovies++;

    printf("\nMovie added successfully!\n");
}

// Function to display all movies in the array
void viewMovies() {
    if (numMovies == 0) {
        printf("\nThere are no movies to view.\n");
    } else {
        printf("\n-------------- All Movies --------------\n\n");
        for (int i = 0; i < numMovies; i++) {
            printf("Title: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release year: %d\n", movies[i].year);
            printf("Rating: %.1f\n\n", movies[i].rating);
        }
    }
}

// Function to get the average movie rating
int getAverageRating() {
    int total = 0;
    for (int i = 0; i < numMovies; i++) {
        total += movies[i].rating;
    }
    return total / numMovies;
}

// Function to quit the program
void quit() {
    printf("\nGoodbye!\n");
    exit(0);
}