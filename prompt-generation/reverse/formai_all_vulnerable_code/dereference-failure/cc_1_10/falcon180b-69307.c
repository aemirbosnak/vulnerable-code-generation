//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 50
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 100
#define MAX_RATING_VALUE 10
#define MAX_RATING_LENGTH 3

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

void print_movie_info(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Rating: %s\n", movie->rating);
}

int main() {
    int num_movies;
    Movie *movies = NULL;

    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    movies = (Movie *)malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d info:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Actors: ");
        scanf("%s", movies[i].actors);
        printf("Rating: ");
        scanf("%s", movies[i].rating);
    }

    printf("Movie info:\n");
    for (int i = 0; i < num_movies; i++) {
        print_movie_info(&movies[i]);
    }

    return 0;
}