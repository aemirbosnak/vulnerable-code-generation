//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_LENGTH_RATING 10
#define MAX_GENRE_LENGTH 30
#define MAX_SYNOPSIS_LENGTH 200

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char rating[MAX_LENGTH_RATING];
    char genre[MAX_GENRE_LENGTH];
    char synopsis[MAX_SYNOPSIS_LENGTH];
} Movie;

int main() {
    FILE *file;
    char line[1000];
    int num_movies = 0;
    Movie movies[100];

    file = fopen("movies.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_movies == 100) {
            printf("Error: Maximum number of movies reached.\n");
            break;
        }
        strcpy(movies[num_movies].title, strtok(line, ","));
        strcpy(movies[num_movies].director, strtok(NULL, ","));
        strcpy(movies[num_movies].actor, strtok(NULL, ","));
        strcpy(movies[num_movies].rating, strtok(NULL, ","));
        strcpy(movies[num_movies].genre, strtok(NULL, ","));
        strcpy(movies[num_movies].synopsis, strtok(NULL, ","));
        num_movies++;
    }

    fclose(file);

    printf("Number of movies: %d\n", num_movies);

    for (int i = 0; i < num_movies; i++) {
        printf("\nTitle: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actor(s): %s\n", movies[i].actor);
        printf("Rating: %s\n", movies[i].rating);
        printf("Genre: %s\n", movies[i].genre);
        printf("Synopsis: %s\n", movies[i].synopsis);
    }

    return 0;
}