//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G_RATING = 0,  // General audience
    PG_RATING = 1, // Parental guidance suggested
    PG13_RATING = 2, // Parents strongly cautioned
    R_RATING = 3,  // Restricted
    NC17_RATING = 4 // No one under 17
} movie_rating;

// Define the movie structure
typedef struct {
    char *title;
    int year;
    movie_rating rating;
} movie;

// Create a new movie
movie *create_movie(char *title, int year, movie_rating rating) {
    movie *new_movie = malloc(sizeof(movie));
    if (new_movie == NULL) {
        return NULL;
    }

    new_movie->title = malloc(strlen(title) + 1);
    if (new_movie->title == NULL) {
        free(new_movie);
        return NULL;
    }
    strcpy(new_movie->title, title);

    new_movie->year = year;
    new_movie->rating = rating;

    return new_movie;
}

// Print the details of a movie
void print_movie(movie *m) {
    printf("Title: %s\n", m->title);
    printf("Year: %d\n", m->year);
    printf("Rating: ");
    switch (m->rating) {
        case G_RATING:
            printf("G (General audience)\n");
            break;
        case PG_RATING:
            printf("PG (Parental guidance suggested)\n");
            break;
        case PG13_RATING:
            printf("PG-13 (Parents strongly cautioned)\n");
            break;
        case R_RATING:
            printf("R (Restricted)\n");
            break;
        case NC17_RATING:
            printf("NC-17 (No one under 17)\n");
            break;
    }
}

// Free the memory allocated for a movie
void free_movie(movie *m) {
    free(m->title);
    free(m);
}

// Main function
int main() {
    // Create a few movies
    movie *m1 = create_movie("The Shawshank Redemption", 1994, R_RATING);
    movie *m2 = create_movie("The Godfather", 1972, R_RATING);
    movie *m3 = create_movie("The Dark Knight", 2008, PG13_RATING);
    movie *m4 = create_movie("E.T. the Extra-Terrestrial", 1982, PG_RATING);
    movie *m5 = create_movie("Schindler's List", 1993, R_RATING);

    // Print the details of each movie
    printf("Movies:\n");
    print_movie(m1);
    print_movie(m2);
    print_movie(m3);
    print_movie(m4);
    print_movie(m5);

    // Free the memory allocated for the movies
    free_movie(m1);
    free_movie(m2);
    free_movie(m3);
    free_movie(m4);
    free_movie(m5);

    return 0;
}