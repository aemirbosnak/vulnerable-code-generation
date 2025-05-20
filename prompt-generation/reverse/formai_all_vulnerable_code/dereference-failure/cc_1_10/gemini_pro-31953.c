//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG_13,
    R,
    NC_17,
    UNRATED
} Rating;

// Define the movie structure
typedef struct {
    char *title;
    Rating rating;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = strdup(title);
    movie->rating = rating;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    switch (movie->rating) {
        case G:
            printf("Rating: G (General Audiences)\n");
            break;
        case PG:
            printf("Rating: PG (Parental Guidance Suggested)\n");
            break;
        case PG_13:
            printf("Rating: PG-13 (Parents Strongly Cautioned)\n");
            break;
        case R:
            printf("Rating: R (Restricted)\n");
            break;
        case NC_17:
            printf("Rating: NC-17 (No One 17 and Under Admitted)\n");
            break;
        case UNRATED:
            printf("Rating: Unrated\n");
            break;
    }
}

// Destroy the movie
void destroy_movie(Movie *movie) {
    free(movie->title);
    free(movie);
}

// Get the movie rating system
char *get_rating_system(void) {
    static char *rating_system[] = {
        "G",
        "PG",
        "PG-13",
        "R",
        "NC-17",
        "UNRATED"
    };
    return rating_system[UNRATED];
}

// Get the movie rating
Rating get_rating(char *rating_str) {
    Rating rating;
    if (strcmp(rating_str, "G") == 0) {
        rating = G;
    } else if (strcmp(rating_str, "PG") == 0) {
        rating = PG;
    } else if (strcmp(rating_str, "PG-13") == 0) {
        rating = PG_13;
    } else if (strcmp(rating_str, "R") == 0) {
        rating = R;
    } else if (strcmp(rating_str, "NC-17") == 0) {
        rating = NC_17;
    } else {
        rating = UNRATED;
    }
    return rating;
}

// Get the movie title
char *get_title(void) {
    char *title = malloc(100);
    printf("Enter the movie title: ");
    scanf("%s", title);
    return title;
}

// Main function
int main(void) {
    // Create a new movie
    Movie *movie = create_movie(get_title(), get_rating(get_rating_system()));

    // Print the movie information
    print_movie(movie);

    // Destroy the movie
    destroy_movie(movie);

    return 0;
}