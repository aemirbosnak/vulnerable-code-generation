//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum rating {
    G, // General audiences
    PG, // Parental guidance suggested
    PG13, // Parents strongly cautioned
    R, // Restricted
    NC17 // No one 17 and under admitted
};

// Define the movie genres
enum genre {
    ACTION,
    ADVENTURE,
    COMEDY,
    DRAMA,
    FANTASY,
    HORROR,
    MYSTERY,
    ROMANCE,
    SCI_FI,
    THRILLER,
    WESTERN
};

// Define the movie struct
struct movie {
    char *title;
    enum rating rating;
    enum genre genre;
    int year;
};

// Create a new movie
struct movie *create_movie(char *title, enum rating rating, enum genre genre, int year) {
    struct movie *movie = malloc(sizeof(struct movie));
    movie->title = title;
    movie->rating = rating;
    movie->genre = genre;
    movie->year = year;
    return movie;
}

// Print the movie information
void print_movie(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Rating: %d\n", movie->rating);
    printf("Genre: %d\n", movie->genre);
    printf("Year: %d\n", movie->year);
}

// Free the movie
void free_movie(struct movie *movie) {
    free(movie->title);
    free(movie);
}

// Main function
int main() {
    // Create a new movie
    struct movie *movie = create_movie("The Shawshank Redemption", PG13, DRAMA, 1994);

    // Print the movie information
    print_movie(movie);

    // Free the movie
    free_movie(movie);

    return 0;
}