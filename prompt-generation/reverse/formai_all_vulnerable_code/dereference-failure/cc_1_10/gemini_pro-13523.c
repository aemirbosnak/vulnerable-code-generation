//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
enum Rating {
    G,
    PG,
    PG_13,
    R,
    NC_17
};

// Define the movie struct
struct Movie {
    char *title;
    enum Rating rating;
    int year_released;
};

// Create a new movie
struct Movie *create_movie(char *title, enum Rating rating, int year_released) {
    struct Movie *movie = (struct Movie *) malloc(sizeof(struct Movie));
    if (movie == NULL) {
        return NULL;
    }
    movie->title = strdup(title);
    movie->rating = rating;
    movie->year_released = year_released;
    return movie;
}

// Print the movie information
void print_movie(struct Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG_13:
            printf("PG-13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC_17:
            printf("NC-17\n");
            break;
    }
    printf("Year released: %d\n", movie->year_released);
}

// Free the movie memory
void free_movie(struct Movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create a few movies
    struct Movie *movies[] = {
        create_movie("The Shawshank Redemption", R, 1994),
        create_movie("The Godfather", R, 1972),
        create_movie("The Dark Knight", PG_13, 2008),
        create_movie("The Lord of the Rings: The Return of the King", PG_13, 2003),
        create_movie("Pulp Fiction", R, 1994)
    };

    // Print the movie information
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
        printf("\n");
    }

    // Free the movie memory
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}