//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
enum rating {G, PG, PG13, R, NC17, X};

// Define the movie struct
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

// Print the movie information
void print_movie(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: ");
    switch (movie->rating) {
        case G:
            printf("G\n");
            break;
        case PG:
            printf("PG\n");
            break;
        case PG13:
            printf("PG-13\n");
            break;
        case R:
            printf("R\n");
            break;
        case NC17:
            printf("NC-17\n");
            break;
        case X:
            printf("X\n");
            break;
    }
    printf("Year: %d\n", movie->year);
}

// Free the movie
void free_movie(struct movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create some movies
    struct movie *movies[] = {
        create_movie("The Shawshank Redemption", R, 1994),
        create_movie("The Godfather", R, 1972),
        create_movie("The Dark Knight", PG13, 2008),
        create_movie("The Lord of the Rings: The Return of the King", PG13, 2003),
        create_movie("Schindler's List", R, 1993),
    };

    // Print the movies
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
        printf("\n");
    }

    // Free the movies
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}