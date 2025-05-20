//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Define the movie struct
struct movie {
    char *title;
    enum rating rating;
};

// Create a new movie
struct movie *create_movie(char *title, enum rating rating) {
    struct movie *new_movie = malloc(sizeof(struct movie));
    new_movie->title = title;
    new_movie->rating = rating;
    return new_movie;
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
        default:
            printf("Invalid rating\n");
            break;
    }
}

// Free the movie memory
void free_movie(struct movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create a few movies
    struct movie *movie1 = create_movie("The Shawshank Redemption", R);
    struct movie *movie2 = create_movie("The Godfather", R);
    struct movie *movie3 = create_movie("The Dark Knight", PG13);
    struct movie *movie4 = create_movie("The Lord of the Rings: The Return of the King", PG13);
    struct movie *movie5 = create_movie("Pulp Fiction", R);

    // Print the movie information
    print_movie(movie1);
    print_movie(movie2);
    print_movie(movie3);
    print_movie(movie4);
    print_movie(movie5);

    // Free the movie memory
    free_movie(movie1);
    free_movie(movie2);
    free_movie(movie3);
    free_movie(movie4);
    free_movie(movie5);

    return 0;
}