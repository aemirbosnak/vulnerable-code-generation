//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie rating system
enum rating { G, PG, PG13, R, NC17 };

// Movie struct
struct movie {
    char *title;
    enum rating rating;
    int year;
};

// Create a new movie
struct movie *create_movie(char *title, enum rating rating, int year) {
    struct movie *movie = malloc(sizeof(struct movie));
    movie->title = strdup(title);
    movie->rating = rating;
    movie->year = year;
    return movie;
}

// Free a movie
void free_movie(struct movie *movie) {
    free(movie->title);
    free(movie);
}

// Print a movie
void print_movie(struct movie *movie) {
    printf("%s (%d) - %d\n", movie->title, movie->rating, movie->year);
}

// Compare two movies by title
int compare_movies_by_title(const void *a, const void *b) {
    const struct movie *movie1 = a;
    const struct movie *movie2 = b;
    return strcmp(movie1->title, movie2->title);
}

// Compare two movies by year
int compare_movies_by_year(const void *a, const void *b) {
    const struct movie *movie1 = a;
    const struct movie *movie2 = b;
    return movie1->year - movie2->year;
}

// Compare two movies by rating
int compare_movies_by_rating(const void *a, const void *b) {
    const struct movie *movie1 = a;
    const struct movie *movie2 = b;
    return movie1->rating - movie2->rating;
}

// Main function
int main() {
    // Create an array of movies
    struct movie *movies[] = {
        create_movie("The Shawshank Redemption", R, 1994),
        create_movie("The Godfather", R, 1972),
        create_movie("The Dark Knight", PG13, 2008),
        create_movie("12 Angry Men", PG, 1957),
        create_movie("Schindler's List", R, 1993),
    };
    
    // Sort the movies by title
    qsort(movies, 5, sizeof(struct movie *), compare_movies_by_title);

    // Print the movies
    printf("Movies sorted by title:\n");
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Sort the movies by year
    qsort(movies, 5, sizeof(struct movie *), compare_movies_by_year);

    // Print the movies
    printf("\nMovies sorted by year:\n");
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Sort the movies by rating
    qsort(movies, 5, sizeof(struct movie *), compare_movies_by_rating);

    // Print the movies
    printf("\nMovies sorted by rating:\n");
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Free the movies
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}