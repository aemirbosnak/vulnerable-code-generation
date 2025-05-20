//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTORS_LENGTH 200
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 20
#define MAX_REVIEW_LENGTH 1000

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actors[MAX_ACTORS_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].title);
        scanf("%s", movies[i].director);
        scanf("%s", movies[i].genre);
        scanf("%s", movies[i].rating);
        scanf("%s", movies[i].review);
    }

    // Sort by rating
    for (int i = 0; i < num_movies - 1; i++) {
        for (int j = i + 1; j < num_movies; j++) {
            if (strcmp(movies[i].rating, movies[j].rating) > 0) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }

    // Print sorted list
    for (int i = 0; i < num_movies; i++) {
        printf("%s\n", movies[i].title);
    }

    return 0;
}