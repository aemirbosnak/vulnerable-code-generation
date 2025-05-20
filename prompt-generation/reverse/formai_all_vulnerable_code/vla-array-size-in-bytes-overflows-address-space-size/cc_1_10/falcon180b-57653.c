//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TITLE_LENGTH 256
#define MAX_DIRECTOR_LENGTH 256
#define MAX_ACTOR_LENGTH 256
#define MAX_GENRE_LENGTH 256
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 1024

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

void print_movie(Movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Director: %s\n", movie->director);
    printf("Actor: %s\n", movie->actor);
    printf("Genre: %s\n", movie->genre);
    printf("Rating: %d\n", movie->rating);
    printf("Review: %s\n", movie->review);
}

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        printf("Enter the details for movie %d:\n", i + 1);
        scanf(" %s", movies[i].title);
        scanf(" %s", movies[i].director);
        scanf(" %s", movies[i].actor);
        scanf(" %s", movies[i].genre);
        scanf(" %d", &movies[i].rating);
        scanf(" %s", movies[i].review);
    }

    printf("Movie Rating System\n");
    printf("===================\n");

    for (int i = 0; i < num_movies; i++) {
        print_movie(&movies[i]);
    }

    return 0;
}