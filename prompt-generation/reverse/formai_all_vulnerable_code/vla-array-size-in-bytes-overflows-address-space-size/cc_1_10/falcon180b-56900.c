//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITLE_LEN 100
#define MAX_DIRECTOR_LEN 50
#define MAX_ACTOR_LEN 50
#define MAX_ACTORS 10
#define MAX_RATING_VALUE 5
#define MAX_RATING_LENGTH 50
#define MAX_REVIEW_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LEN];
    char director[MAX_DIRECTOR_LEN];
    int num_actors;
    char actors[MAX_ACTORS][MAX_ACTOR_LEN];
    int rating_value;
    char rating[MAX_RATING_LENGTH];
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int num_movies;
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        movies[i].num_actors = 0;
        strcpy(movies[i].title, "");
        strcpy(movies[i].director, "");
        for (int j = 0; j < MAX_ACTORS; j++) {
            strcpy(movies[i].actors[j], "");
        }
        movies[i].rating_value = 0;
        strcpy(movies[i].rating, "");
        strcpy(movies[i].review, "");

        printf("Enter movie %d details:\n", i+1);
        printf("Title: ");
        scanf("%s", movies[i].title);
        printf("Director: ");
        scanf("%s", movies[i].director);
        printf("Number of actors: ");
        scanf("%d", &movies[i].num_actors);
        for (int j = 0; j < movies[i].num_actors; j++) {
            printf("Actor %d: ", j+1);
            scanf("%s", movies[i].actors[j]);
        }
        printf("Rating (1-5): ");
        scanf("%d", &movies[i].rating_value);
        printf("Rating (stars): ");
        scanf("%s", movies[i].rating);
        printf("Review: ");
        scanf("%[^\n]", movies[i].review);
    }

    return 0;
}