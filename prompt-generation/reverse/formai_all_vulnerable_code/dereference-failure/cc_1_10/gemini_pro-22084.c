//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: interoperable
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
} movie;

// Create a new movie
movie *create_movie(char *title, rating rating) {
    movie *m = malloc(sizeof(movie));
    m->title = strdup(title);
    m->rating = rating;
    return m;
}

// Free a movie
void free_movie(movie *m) {
    free(m->title);
    free(m);
}

// Print a movie
void print_movie(movie *m) {
    printf("%s (%s)\n", m->title, m->rating);
}

// Compare two movies
int compare_movies(movie *m1, movie *m2) {
    return strcmp(m1->title, m2->title);
}

// Sort an array of movies
void sort_movies(movie **movies, int num_movies) {
    qsort(movies, num_movies, sizeof(movie *), compare_movies);
}

// Get the rating of a movie
rating get_rating(char *rating_str) {
    if (!strcmp(rating_str, "G")) {
        return G;
    } else if (!strcmp(rating_str, "PG")) {
        return PG;
    } else if (!strcmp(rating_str, "PG13")) {
        return PG13;
    } else if (!strcmp(rating_str, "R")) {
        return R;
    } else if (!strcmp(rating_str, "NC17")) {
        return NC17;
    } else {
        printf("Invalid rating: %s", rating_str);
        return -1;
    }
}

// Main function
int main() {
    // Create an array of movies
    movie *movies[] = {
        create_movie("The Shawshank Redemption", PG13),
        create_movie("The Godfather", R),
        create_movie("The Dark Knight", PG13),
        create_movie("12 Angry Men", PG),
        create_movie("Schindler's List", R)
    };

    // Sort the array of movies
    sort_movies(movies, 5);

    // Print the array of movies
    for (int i = 0; i < 5; i++) {
        print_movie(movies[i]);
    }

    // Free the array of movies
    for (int i = 0; i < 5; i++) {
        free_movie(movies[i]);
    }

    return 0;
}