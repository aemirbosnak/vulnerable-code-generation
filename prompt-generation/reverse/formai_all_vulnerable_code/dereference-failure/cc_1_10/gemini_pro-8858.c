//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the movie genre system
typedef enum {
    ACTION,
    ADVENTURE,
    COMEDY,
    DRAMA,
    HORROR,
    ROMANCE,
    SCI_FI,
    THRILLER
} Genre;

// Define the movie structure
typedef struct {
    char *title;
    Rating rating;
    Genre genre;
    int release_year;
} Movie;

// Create a new movie
Movie *new_movie(char *title, Rating rating, Genre genre, int release_year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    movie->genre = genre;
    movie->release_year = release_year;
    return movie;
}

// Free the memory allocated for a movie
void free_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Print the details of a movie
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Genre: %d\n", movie->genre);
    printf("Release year: %d\n", movie->release_year);
}

// Compare two movies by their titles
int compare_movies_by_title(const Movie *a, const Movie *b) {
    return strcmp(a->title, b->title);
}

// Compare two movies by their release years
int compare_movies_by_release_year(const Movie *a, const Movie *b) {
    return a->release_year - b->release_year;
}

// Sort an array of movies by their titles
void sort_movies_by_title(Movie **movies, int num_movies) {
    qsort(movies, num_movies, sizeof(Movie *), compare_movies_by_title);
}

// Sort an array of movies by their release years
void sort_movies_by_release_year(Movie **movies, int num_movies) {
    qsort(movies, num_movies, sizeof(Movie *), compare_movies_by_release_year);
}

// Print a list of movies
void print_movies(Movie **movies, int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
        printf("\n");
    }
}

int main() {
    // Create an array of movies
    Movie *movies[] = {
        new_movie("The Shawshank Redemption", PG13, DRAMA, 1994),
        new_movie("The Godfather", R, DRAMA, 1972),
        new_movie("The Dark Knight", PG13, ACTION, 2008),
        new_movie("12 Angry Men", PG, DRAMA, 1957),
        new_movie("Schindler's List", R, DRAMA, 1993)
    };

    // Sort the movies by their titles
    sort_movies_by_title(movies, 5);

    // Print the sorted movies
    printf("Movies sorted by title:\n");
    print_movies(movies, 5);

    // Sort the movies by their release years
    sort_movies_by_release_year(movies, 5);

    // Print the sorted movies
    printf("Movies sorted by release year:\n");
    print_movies(movies, 5);

    // Free the memory allocated for the movies
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}