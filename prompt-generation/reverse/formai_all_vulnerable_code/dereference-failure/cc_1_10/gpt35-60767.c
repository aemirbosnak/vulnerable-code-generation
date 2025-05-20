//FormAI DATASET v1.0 Category: Movie Rating System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to represent a movie
typedef struct {
    char *title;
    int year;
    float rating;
} Movie;

// Define a function to create a new movie
Movie* create_movie(char *title, int year, float rating) {
    Movie *new_movie = (Movie*) malloc(sizeof(Movie));
    new_movie->title = title;
    new_movie->year = year;
    new_movie->rating = rating;
    return new_movie;
}

// Define a function to print a movie
void print_movie(Movie *movie) {
    printf("%s (%d) - %0.1f/10\n", movie->title, movie->year, movie->rating);
}

// Define the main program
int main() {
    // Initialize an array of 5 movies
    Movie *movies[5];
    movies[0] = create_movie("The Shawshank Redemption", 1994, 9.3);
    movies[1] = create_movie("The Godfather", 1972, 9.2);
    movies[2] = create_movie("The Godfather: Part II", 1974, 9.0);
    movies[3] = create_movie("The Dark Knight", 2008, 9.0);
    movies[4] = create_movie("12 Angry Men", 1957, 8.9);

    // Print out the list of movies
    printf("Top 5 Movies of All Time:\n");
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Prompt the user for a new movie
    char title_buff[100];
    printf("Enter the title of a new movie: ");
    fgets(title_buff, 100, stdin);
    title_buff[strcspn(title_buff, "\n")] = 0; // Remove newline character
    int year = 0;
    float rating = 0.0;
    bool valid_input = false;
    while (!valid_input) {
        printf("Enter the year of the movie: ");
        if (scanf("%d", &year) != 1 || year < 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            while(getchar() != '\n'); // Clear input buffer
        } else {
            valid_input = true;
        }
    }
    valid_input = false;
    while (!valid_input) {
        printf("Enter the rating of the movie (out of 10): ");
        if (scanf("%f", &rating) != 1 || rating < 0 || rating > 10) {
            printf("Invalid input. Please enter a number between 0 and 10 inclusive.\n");
            while(getchar() != '\n'); // Clear input buffer
        } else {
            valid_input = true;
        }
    }
    Movie *new_movie = create_movie(title_buff, year, rating);
    printf("\n");
    print_movie(new_movie);

    // Free memory allocated for movies
    for (int i = 0; i < 5; i++) {
        free(movies[i]);
    }
    free(new_movie);

    return 0;
}