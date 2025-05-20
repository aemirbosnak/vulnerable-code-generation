//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_GENRES 100
#define MAX_ACTORS 100
#define MAX_DIRECTORS 100
#define MAX_TITLE_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_DIRECTOR_LENGTH 50

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char actors[MAX_ACTORS][MAX_ACTOR_LENGTH];
    char directors[MAX_DIRECTORS][MAX_DIRECTOR_LENGTH];
    int num_actors;
    int num_directors;
    int rating;
} Movie;

int main(void) {
    Movie movies[MAX_MOVIES];
    int num_movies = 0;
    char filename[100];
    FILE *fp;
    char line[1000];
    char *token;
    int i;

    printf("Enter the name of the file containing movie information: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (num_movies >= MAX_MOVIES) {
            printf("Error: Maximum number of movies reached.\n");
            exit(1);
        }

        token = strtok(line, ",");
        strcpy(movies[num_movies].title, token);

        token = strtok(NULL, ",");
        strcpy(movies[num_movies].genre, token);

        i = 0;
        while (i < MAX_ACTORS && token!= NULL) {
            strcpy(movies[num_movies].actors[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        movies[num_movies].num_actors = i;

        i = 0;
        while (i < MAX_DIRECTORS && token!= NULL) {
            strcpy(movies[num_movies].directors[i], token);
            i++;
            token = strtok(NULL, ",");
        }
        movies[num_movies].num_directors = i;

        movies[num_movies].rating = atoi(token);
        num_movies++;
    }

    fclose(fp);

    printf("Enter the name of the file to save the ratings to: ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    for (i = 0; i < num_movies; i++) {
        fprintf(fp, "%s,%s,%d,%d,%d\n", movies[i].title, movies[i].genre, movies[i].num_actors, movies[i].num_directors, movies[i].rating);
    }

    fclose(fp);

    return 0;
}