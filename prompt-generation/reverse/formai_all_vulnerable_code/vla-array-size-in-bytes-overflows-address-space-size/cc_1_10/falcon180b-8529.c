//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 20
#define MAX_REVIEW_LENGTH 500

typedef struct movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies;
    scanf("%d", &numMovies);

    Movie movies[numMovies];

    for (int i = 0; i < numMovies; i++) {
        printf("Enter the title of movie %d: ", i+1);
        scanf("%s", movies[i].title);
        printf("Enter the director of movie %d: ", i+1);
        scanf("%s", movies[i].director);
        printf("Enter the actors of movie %d (comma-separated): ", i+1);
        scanf("%s", movies[i].actors);
        printf("Enter the genre of movie %d: ", i+1);
        scanf("%s", movies[i].genre);
        printf("Enter the rating of movie %d (out of 10): ", i+1);
        scanf("%s", movies[i].rating);
        printf("Enter a brief review of movie %d: ", i+1);
        scanf("%s", movies[i].review);
    }

    printf("Movie Ratings:\n");
    for (int i = 0; i < numMovies; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %s\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }

    return 0;
}