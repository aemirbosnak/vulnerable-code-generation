//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
enum movie_rating {
    G,
    PG,
    PG13,
    R,
    NC17
};

// Define the movie struct
struct movie {
    char *title;
    enum movie_rating rating;
};

// Create a new movie
struct movie *create_movie(char *title, enum movie_rating rating) {
    struct movie *movie = malloc(sizeof(struct movie));
    movie->title = title;
    movie->rating = rating;
    return movie;
}

// Print the movie rating
void print_movie_rating(enum movie_rating rating) {
    switch (rating) {
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
}

// Main function
int main() {
    // Create some movies
    struct movie *movie1 = create_movie("The Shawshank Redemption", PG13);
    struct movie *movie2 = create_movie("The Godfather", R);
    struct movie *movie3 = create_movie("The Dark Knight", PG13);

    // Print the movie ratings
    printf("The Shawshank Redemption is rated ");
    print_movie_rating(movie1->rating);
    printf("\n");

    printf("The Godfather is rated ");
    print_movie_rating(movie2->rating);
    printf("\n");

    printf("The Dark Knight is rated ");
    print_movie_rating(movie3->rating);
    printf("\n");

    // Free the movies
    free(movie1);
    free(movie2);
    free(movie3);

    return 0;
}