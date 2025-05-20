//FormAI DATASET v1.0 Category: Movie Rating System ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[50];
    char genre[20];
    int year;
    float rating;
} Movie;

void printHeader() {
    printf("%-50s %-20s %-10s %-10s\n", "Title", "Genre", "Year", "Rating");
}

void printMovie(Movie movie) {
    printf("%-50s %-20s %-10d %-10.2f\n", movie.title, movie.genre, movie.year, movie.rating);
}

void printMenu() {
    printf("\n1. Add a movie to the database\n");
    printf("2. Display the entire database\n");
    printf("3. Display movies of a specific genre\n");
    printf("4. Display movies with a rating greater than a certain number\n");
    printf("5. Exit\n");
}

Movie* addMovie() {
    Movie* movie = (Movie*)malloc(sizeof(Movie));
    printf("Enter movie title: ");
    scanf("%s", movie->title);
    printf("Enter genre: ");
    scanf("%s", movie->genre);
    printf("Enter year: ");
    scanf("%d", &movie->year);
    printf("Enter rating (out of 10): ");
    scanf("%f", &movie->rating);
    return movie;
}

void displayAllMovies(Movie* movies, int numMovies) {
    printHeader();
    for (int i = 0; i < numMovies; i++) {
        printMovie(movies[i]);
    }
}

void displayMoviesByGenre(Movie* movies, int numMovies, char* genre) {
    printHeader();
    for (int i = 0; i < numMovies; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printMovie(movies[i]);
        }
    }
}

void displayMoviesByRating(Movie* movies, int numMovies, float rating) {
    printHeader();
    for (int i = 0; i < numMovies; i++) {
        if (movies[i].rating >= rating) {
            printMovie(movies[i]);
        }
    }
}

int main() {
    int numMovies = 0;
    int choice;
    char genre[20];
    float rating;
    Movie* movies = (Movie*)malloc(sizeof(Movie) * 10);

    do {
        printMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numMovies < 10) {
                    Movie* movie = addMovie();
                    movies[numMovies++] = *movie;
                    printf("Movie added to database.");
                }
                else {
                    printf("Database is full. Cannot add more movies.");
                }
                break;
            case 2:
                displayAllMovies(movies, numMovies);
                break;
            case 3:
                printf("Enter genre: ");
                scanf("%s", genre);
                displayMoviesByGenre(movies, numMovies, genre);
                break;
            case 4:
                printf("Enter minimum rating: ");
                scanf("%f", &rating);
                displayMoviesByRating(movies, numMovies, rating);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}