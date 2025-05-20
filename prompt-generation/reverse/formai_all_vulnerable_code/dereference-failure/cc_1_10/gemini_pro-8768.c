//GEMINI-pro DATASET v1.0 Category: Movie Rating System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct Movie {
    char *title;
    int year;
    int rating;
};

struct MovieRatingSystem {
    int numMovies;
    struct Movie *movies;
};

struct MovieRatingSystem *createMovieRatingSystem() {
    struct MovieRatingSystem *mrs = malloc(sizeof(struct MovieRatingSystem));
    mrs->numMovies = 0;
    mrs->movies = NULL;
    return mrs;
}

void addMovie(struct MovieRatingSystem *mrs, char *title, int year, int rating) {
    mrs->numMovies++;
    mrs->movies = realloc(mrs->movies, mrs->numMovies * sizeof(struct Movie));
    struct Movie *movie = &mrs->movies[mrs->numMovies - 1];
    movie->title = title;
    movie->year = year;
    movie->rating = rating;
}

void printMovieRatingSystem(struct MovieRatingSystem *mrs) {
    for (int i = 0; i < mrs->numMovies; i++) {
        struct Movie *movie = &mrs->movies[i];
        printf("%s (%d) - %d\n", movie->title, movie->year, movie->rating);
    }
}

void freeMovieRatingSystem(struct MovieRatingSystem *mrs) {
    for (int i = 0; i < mrs->numMovies; i++) {
        free(mrs->movies[i].title);
    }
    free(mrs->movies);
    free(mrs);
}

int main() {
    struct MovieRatingSystem *mrs = createMovieRatingSystem();
    addMovie(mrs, "The Shawshank Redemption", 1994, 9);
    addMovie(mrs, "The Godfather", 1972, 9);
    addMovie(mrs, "The Dark Knight", 2008, 9);
    addMovie(mrs, "12 Angry Men", 1957, 8);
    addMovie(mrs, "Schindler's List", 1993, 9);
    printMovieRatingSystem(mrs);
    freeMovieRatingSystem(mrs);
    return 0;
}