//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 20
#define MAX_RATING_LENGTH 10

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
} Movie;

int main() {
    int num_movies;
    Movie movies[100];
    char input[1000];
    char *token;
    int i;

    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    printf("Enter the movies:\n");
    for (i = 0; i < num_movies; i++) {
        fgets(input, sizeof(input), stdin);
        token = strtok(input, ",");
        strcpy(movies[i].title, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].director, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].actor, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].genre, token);
        token = strtok(NULL, ",");
        strcpy(movies[i].rating, token);
    }

    printf("The movies are:\n");
    for (i = 0; i < num_movies; i++) {
        printf("%s (%s) - %s, %s, %s - %s\n", movies[i].title, movies[i].rating, movies[i].director, movies[i].actor, movies[i].genre, movies[i].rating);
    }

    return 0;
}