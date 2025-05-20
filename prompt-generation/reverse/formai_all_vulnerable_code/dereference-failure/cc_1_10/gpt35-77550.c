//FormAI DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// Define struct for movie
typedef struct {
    char title[50];
    float rating;
} movie;

// Function to rate a movie
void rateMovie(movie *m) {
    float newRating;
    printf("Enter your rating for %s (out of 10):\n", m->title);
    scanf("%f", &newRating);
    m->rating = (m->rating + newRating) / 2.0; // Average the new rating with the old rating
    printf("Thank you for rating %s. The new rating is %.1f.\n\n", m->title, m->rating);
}

// Function to display movie ratings
void displayRatings(movie *m, int numMovies) {
    printf("Movie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("%s: %.1f\n", m[i].title, m[i].rating);
    }
    printf("\n");
}

int main() {
    int numMovies;
    printf("Welcome to the Movie Rating System!\n\n");
    printf("How many movies would you like to rate? ");
    scanf("%d", &numMovies);

    // Allocate memory for array of movies
    movie *movies = (movie*) malloc(numMovies * sizeof(movie));

    // Prompt user to enter movie titles
    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d:\n", i+1);
        scanf("%s", movies[i].title);
        movies[i].rating = 0; // Set initial rating to 0
    }

    // Main loop
    int choice;
    do {
        printf("Main Menu:\n");
        printf("1) Rate a movie\n");
        printf("2) Display movie ratings\n");
        printf("3) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                // Prompt user to select movie to rate
                printf("Which movie would you like to rate?\n");
                for (int i = 0; i < numMovies; i++) {
                    printf("%d) %s\n", i+1, movies[i].title);
                }
                printf("Enter your choice: ");
                int movieChoice;
                scanf("%d", &movieChoice);
                printf("\n");

                rateMovie(&movies[movieChoice-1]); // Pass pointer to selected movie
                break;
            case 2:
                displayRatings(movies, numMovies);
                break;
            case 3:
                printf("Thank you for using the Movie Rating System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
                break;
        }
    } while (choice != 3);

    // Free dynamically allocated memory
    free(movies);
    return 0;
}