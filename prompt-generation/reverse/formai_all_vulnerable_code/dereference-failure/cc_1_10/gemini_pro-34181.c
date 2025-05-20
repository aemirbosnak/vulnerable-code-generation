//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the rating system
enum rating { G, PG, PG13, R, NC17 };

// Define the movie struct
struct movie {
    char *title;
    enum rating rating;
};

// Create a new movie
struct movie *new_movie(char *title, enum rating rating) {
    struct movie *movie = malloc(sizeof(struct movie));
    movie->title = strdup(title);
    movie->rating = rating;
    return movie;
}

// Free a movie
void free_movie(struct movie *movie) {
    free(movie->title);
    free(movie);
}

// Print a movie
void print_movie(struct movie *movie) {
    printf("%s (%s)\n", movie->title, movie->rating);
}

// Compare two movies
int compare_movies(const void *a, const void *b) {
    const struct movie *movie1 = a;
    const struct movie *movie2 = b;
    return strcmp(movie1->title, movie2->title);
}

// Get the rating of a movie
enum rating get_rating(struct movie *movie) {
    return movie->rating;
}

// Set the rating of a movie
void set_rating(struct movie *movie, enum rating rating) {
    movie->rating = rating;
}

// Main function
int main() {
    // Create a list of movies
    struct movie *movies[] = {
        new_movie("The Shawshank Redemption", PG13),
        new_movie("The Godfather", R),
        new_movie("The Dark Knight", PG13),
        new_movie("12 Angry Men", PG),
        new_movie("Schindler's List", R),
    };

    // Sort the movies by title
    qsort(movies, sizeof(movies) / sizeof(movies[0]), sizeof(movies[0]), compare_movies);

    // Print the movies
    for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++) {
        print_movie(movies[i]);
    }

    // Get the rating of a movie
    enum rating rating = get_rating(movies[0]);
    printf("The rating of %s is %s\n", movies[0]->title, rating);

    // Set the rating of a movie
    set_rating(movies[0], G);
    printf("The rating of %s is now %s\n", movies[0]->title, get_rating(movies[0]));

    // Free the movies
    for (int i = 0; i < sizeof(movies) / sizeof(movies[0]); i++) {
        free_movie(movies[i]);
    }

    return 0;
}