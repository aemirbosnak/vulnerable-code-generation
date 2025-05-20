//FormAI DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct definition for movie rating
struct movieRating {
    char title[50];
    char director[50];
    int year;
    float rating;
};

// Function prototypes
void printMenu();
int addNewMovieRating(struct movieRating *movies, int count);
void viewAllMovieRatings(struct movieRating *movies, int count);
void viewTopRatedMovies(struct movieRating *movies, int count);
void viewMoviesByDirector(struct movieRating *movies, int count);

int main() {
    int menuChoice, movieCount = 0, maxMovies = 10;
    struct movieRating *movies = malloc(maxMovies * sizeof(struct movieRating));

    do {
        printMenu();
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                movieCount = addNewMovieRating(movies, movieCount);
                break;
            case 2:
                viewAllMovieRatings(movies, movieCount);
                break;
            case 3:
                viewTopRatedMovies(movies, movieCount);
                break;
            case 4:
                viewMoviesByDirector(movies, movieCount);
                break;
            case 5:
                printf("Exiting program..\n");
                break;
            default:
                printf("Invalid choice..\n");
                break;
        }
    } while (menuChoice != 5);

    free(movies);
    return 0;
}

// Function to print the menu options
void printMenu() {
    printf("\n--- C Movie Rating System ---\n");
    printf("1. Add new movie rating\n");
    printf("2. View all movie ratings\n");
    printf("3. View top rated movies\n");
    printf("4. View movies by director\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add new movie rating
int addNewMovieRating(struct movieRating *movies, int count) {
    if (count == 10) {
        printf("Max limit reached. Cannot add more movies.\n");
        return count;
    }

    int year;
    float rating;
    char buffer[50];

    printf("\nAdding new movie rating\n");
    printf("Enter movie title: ");
    scanf("%s", buffer);
    strcpy(movies[count].title, buffer);

    printf("Enter director name: ");
    scanf("%s", buffer);
    strcpy(movies[count].director, buffer);

    printf("Enter release year: ");
    scanf("%d", &year);
    movies[count].year = year;

    printf("Enter rating (out of 10): ");
    scanf("%f", &rating);
    movies[count].rating = rating;

    printf("Movie rating added successfully.\n");
    return count + 1;
}

// Function to view all movie ratings
void viewAllMovieRatings(struct movieRating *movies, int count) {
    if (count == 0) {
        printf("No movie ratings found.\n");
        return;
    }

    printf("\n--- All Movie Ratings ---\n");
    printf("Title\t\t\tDirector\tYear\tRating\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t\t%s\t\t%d\t%.2f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

// Function to view top rated movies
void viewTopRatedMovies(struct movieRating *movies, int count) {
    if (count == 0) {
        printf("No movie ratings found.\n");
        return;
    }

    printf("\n--- Top Rated Movies ---\n");
    printf("Title\t\t\tDirector\tYear\tRating\n");

    // Bubble sort to sort the movies based on rating
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (movies[j].rating < movies[j+1].rating) {
                struct movieRating temp = movies[j];
                movies[j] = movies[j+1];
                movies[j+1] = temp;
            }
        }
    }

    // Print the top 3 rated movies
    for (int i = 0; i < 3 && i < count; i++) {
        printf("%s\t\t\t%s\t\t%d\t%.2f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
    }
}

// Function to view movies by director
void viewMoviesByDirector(struct movieRating *movies, int count) {
    if (count == 0) {
        printf("No movie ratings found.\n");
        return;
    }

    char directorName[50];
    printf("\nEnter director name: ");
    scanf("%s", directorName);
    printf("Title\t\t\tDirector\tYear\tRating\n");
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].director, directorName) == 0) {
            printf("%s\t\t\t%s\t\t%d\t%.2f\n", movies[i].title, movies[i].director, movies[i].year, movies[i].rating);
        }
    }
}