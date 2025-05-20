//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    int year;
} Movie;

// Define the comparator for the movie struct
int compare_movies(const void *a, const void *b) {
    const Movie *movie1 = (const Movie *)a;
    const Movie *movie2 = (const Movie *)b;

    // Compare the titles of the movies
    int result = strcmp(movie1->title, movie2->title);
    if (result != 0) {
        return result;
    }

    // Compare the ratings of the movies
    result = movie1->rating - movie2->rating;
    if (result != 0) {
        return result;
    }

    // Compare the years of the movies
    return movie1->year - movie2->year;
}

// Print the movie rating system
void print_rating_system() {
    printf("Movie Rating System:\n");
    printf("G: General audiences\n");
    printf("PG: Parental guidance suggested\n");
    printf("PG13: Parents strongly cautioned\n");
    printf("R: Restricted\n");
    printf("NC17: No one 17 and under admitted\n");
}

// Get the movie rating from the user
Rating get_rating() {
    char rating_input[10];
    Rating rating;

    while (1) {
        printf("Enter the movie rating (G, PG, PG13, R, NC17): ");
        scanf("%s", rating_input);

        if (strcmp(rating_input, "G") == 0) {
            rating = G;
            break;
        } else if (strcmp(rating_input, "PG") == 0) {
            rating = PG;
            break;
        } else if (strcmp(rating_input, "PG13") == 0) {
            rating = PG13;
            break;
        } else if (strcmp(rating_input, "R") == 0) {
            rating = R;
            break;
        } else if (strcmp(rating_input, "NC17") == 0) {
            rating = NC17;
            break;
        } else {
            printf("Invalid rating. Please enter a valid rating.\n");
        }
    }

    return rating;
}

// Create a new movie
Movie *create_movie() {
    Movie *movie = malloc(sizeof(Movie));

    // Get the movie title from the user
    char title[100];
    printf("Enter the movie title: ");
    scanf("%s", title);

    // Allocate memory for the movie title
    movie->title = malloc(strlen(title) + 1);
    strcpy(movie->title, title);

    // Get the movie rating from the user
    movie->rating = get_rating();

    // Get the movie year from the user
    printf("Enter the movie year: ");
    scanf("%d", &movie->year);

    return movie;
}

// Print the movie
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G");
            break;
        case PG:
            printf("PG");
            break;
        case PG13:
            printf("PG13");
            break;
        case R:
            printf("R");
            break;
        case NC17:
            printf("NC17");
            break;
    }
    printf("\n");
    printf("Year: %d\n", movie->year);
}

// Main function
int main() {
    // Print the movie rating system
    print_rating_system();

    // Create an array of movies
    Movie *movies[10];

    // Get the number of movies from the user
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    // Create the movies
    for (int i = 0; i < num_movies; i++) {
        movies[i] = create_movie();
    }

    // Sort the movies
    qsort(movies, num_movies, sizeof(Movie *), compare_movies);

    // Print the movies
    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
        printf("\n");
    }

    // Free the memory allocated for the movies
    for (int i = 0; i < num_movies; i++) {
        free(movies[i]->title);
        free(movies[i]);
    }

    return 0;
}