//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: happy
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
} rating;

// Define the movie struct
typedef struct {
    char *title;
    rating rating;
    int year;
} movie;

// Create a new movie
movie *create_movie(char *title, rating rating, int year) {
    movie *m = malloc(sizeof(movie));
    m->title = strdup(title);
    m->rating = rating;
    m->year = year;
    return m;
}

// Print a movie
void print_movie(movie *m) {
    printf("%s (%d) - ", m->title, m->year);
    switch (m->rating) {
        case G:
            printf("G");
            break;
        case PG:
            printf("PG");
            break;
        case PG13:
            printf("PG-13");
            break;
        case R:
            printf("R");
            break;
        case NC17:
            printf("NC-17");
            break;
    }
    printf("\n");
}

// Get the rating of a movie
rating get_rating(movie *m) {
    return m->rating;
}

// Set the rating of a movie
void set_rating(movie *m, rating rating) {
    m->rating = rating;
}

// Get the year of a movie
int get_year(movie *m) {
    return m->year;
}

// Set the year of a movie
void set_year(movie *m, int year) {
    m->year = year;
}

// Compare two movies by title
int compare_movies_by_title(const void *a, const void *b) {
    movie *m1 = *(movie **)a;
    movie *m2 = *(movie **)b;
    return strcmp(m1->title, m2->title);
}

// Compare two movies by rating
int compare_movies_by_rating(const void *a, const void *b) {
    movie *m1 = *(movie **)a;
    movie *m2 = *(movie **)b;
    return m1->rating - m2->rating;
}

// Compare two movies by year
int compare_movies_by_year(const void *a, const void *b) {
    movie *m1 = *(movie **)a;
    movie *m2 = *(movie **)b;
    return m1->year - m2->year;
}

// Main function
int main() {
    // Create some movies
    movie *movies[] = {
        create_movie("The Shawshank Redemption", R, 1994),
        create_movie("The Godfather", R, 1972),
        create_movie("The Godfather Part II", R, 1974),
        create_movie("The Dark Knight", PG13, 2008),
        create_movie("12 Angry Men", PG, 1957),
        create_movie("Schindler's List", R, 1993),
        create_movie("Pulp Fiction", R, 1994),
        create_movie("Fight Club", R, 1999),
        create_movie("The Lord of the Rings: The Return of the King", PG13, 2003),
        create_movie("The Matrix", R, 1999),
    };

    // Print the movies in the order they were created
    printf("Movies in the order they were created:\n");
    for (int i = 0; i < 10; i++) {
        print_movie(movies[i]);
    }

    // Sort the movies by title
    qsort(movies, 10, sizeof(movie *), compare_movies_by_title);

    // Print the movies sorted by title
    printf("\nMovies sorted by title:\n");
    for (int i = 0; i < 10; i++) {
        print_movie(movies[i]);
    }

    // Sort the movies by rating
    qsort(movies, 10, sizeof(movie *), compare_movies_by_rating);

    // Print the movies sorted by rating
    printf("\nMovies sorted by rating:\n");
    for (int i = 0; i < 10; i++) {
        print_movie(movies[i]);
    }

    // Sort the movies by year
    qsort(movies, 10, sizeof(movie *), compare_movies_by_year);

    // Print the movies sorted by year
    printf("\nMovies sorted by year:\n");
    for (int i = 0; i < 10; i++) {
        print_movie(movies[i]);
    }

    // Free the movies
    for (int i = 0; i < 10; i++) {
        free(movies[i]->title);
        free(movies[i]);
    }

    return 0;
}