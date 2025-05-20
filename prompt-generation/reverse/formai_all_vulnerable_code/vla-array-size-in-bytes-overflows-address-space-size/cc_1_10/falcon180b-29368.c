//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_LENGTH 200
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void print_movie(Movie* movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actors: %s\n", movie->actors);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].genre);
        scanf("%d", &movies[i].rating);
        scanf("%s", movies[i].review);
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}