//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Movie {
    char title[100];
    int rating;
} Movie;

Movie* newMovie(const char* title, int rating) {
    Movie* movie = (Movie*)malloc(sizeof(Movie));
    strcpy(movie->title, title);
    movie->rating = rating;
    return movie;
}

void displayMovies(Movie* movies, int numMovies) {
    for (int i = 0; i < numMovies; i++) {
        printf("Title: %s\n", movies[i].title);
        printf("Rating: %d\n", movies[i].rating);
        printf("\n");
    }
}

int main() {
    Movie* movies = NULL;
    int numMovies = 0;

    while (1) {
        printf("Enter a movie title (or -1 to exit): ");
        char title[100];
        scanf("%s", title);

        if (strcmp(title, "-1") == 0) {
            break;
        }

        Movie* movie = newMovie(title, 0);
        movies = realloc(movies, (numMovies + 1) * sizeof(Movie));
        movies[numMovies] = *movie;

        printf("Enter a rating for the movie (or -1 to skip): ");
        int rating;
        scanf("%d", &rating);

        if (rating!= -1) {
            movie->rating = rating;
        }

        numMovies++;
    }

    displayMovies(movies, numMovies);

    free(movies);
    return 0;
}