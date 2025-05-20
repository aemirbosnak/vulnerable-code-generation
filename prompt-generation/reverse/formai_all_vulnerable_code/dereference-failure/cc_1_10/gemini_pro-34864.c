//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

// Define the movie rating system
typedef enum {
    G,
    PG,
    PG13,
    R,
    NC17
} Rating;

// Define the age rating system
typedef enum {
    ALL_AGES,
    CHILDREN,
    TEENS,
    ADULTS,
    NO_ONE
} AgeRating;

// Define the movie struct
typedef struct {
    char *title;
    Rating rating;
    AgeRating age_rating;
    int release_year;
} Movie;

// Create a new movie
Movie *create_movie(char *title, Rating rating, AgeRating age_rating, int release_year) {
    Movie *movie = malloc(sizeof(Movie));
    movie->title = title;
    movie->rating = rating;
    movie->age_rating = age_rating;
    movie->release_year = release_year;
    return movie;
}

// Print the movie information
void print_movie(Movie *movie) {
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
    }
    printf("Age Rating: ");
    switch (movie->age_rating) {
        case ALL_AGES:
            printf("All Ages\n");
            break;
        case CHILDREN:
            printf("Children\n");
            break;
        case TEENS:
            printf("Teens\n");
            break;
        case ADULTS:
            printf("Adults\n");
            break;
        case NO_ONE:
            printf("No One\n");
            break;
    }
    printf("Release Year: %d\n", movie->release_year);
}

// Get the movie rating
Rating get_movie_rating(Movie *movie) {
    return movie->rating;
}

// Get the movie age rating
AgeRating get_movie_age_rating(Movie *movie) {
    return movie->age_rating;
}

// Main function
int main() {
    // Create some movies
    Movie *movies[] = {
        create_movie("The Shawshank Redemption", PG13, TEENS, 1994),
        create_movie("The Godfather", R, ADULTS, 1972),
        create_movie("The Dark Knight", PG13, TEENS, 2008),
        create_movie("Pulp Fiction", R, ADULTS, 1994),
        create_movie("The Lord of the Rings: The Return of the King", PG13, TEENS, 2003),
    };

    // Print the movie information
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
        printf("\n");
    }

    // Get the movie rating
    Rating rating = get_movie_rating(movies[0]);
    printf("The rating of the movie '%s' is %s\n", movies[0]->title, rating == G ? "G" : rating == PG ? "PG" : rating == PG13 ? "PG-13" : rating == R ? "R" : "NC-17");

    // Get the movie age rating
    AgeRating age_rating = get_movie_age_rating(movies[0]);
    printf("The age rating of the movie '%s' is %s\n", movies[0]->title, age_rating == ALL_AGES ? "All Ages" : age_rating == CHILDREN ? "Children" : age_rating == TEENS ? "Teens" : age_rating == ADULTS ? "Adults" : "No One");

    return 0;
}