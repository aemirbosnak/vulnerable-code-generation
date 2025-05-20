//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_MOVIE_COUNT 100

typedef struct {
    char title[50];
    char director[50];
    char actors[100];
    char genre[20];
    int year;
    int rating;
} Movie;

int main() {
    Movie movies[MAX_MOVIE_COUNT];
    int movie_count = 0;
    FILE *fp;
    char filename[50];
    char line[100];
    char delimiter = ',';
    int i = 0, j = 0;

    printf("Enter the name of the CSV file containing the movie data: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (movie_count >= MAX_MOVIE_COUNT) {
            printf("Maximum number of movies reached\n");
            break;
        }

        char *token = strtok(line, &delimiter);
        strcpy(movies[movie_count].title, token);

        token = strtok(NULL, &delimiter);
        strcpy(movies[movie_count].director, token);

        token = strtok(NULL, &delimiter);
        strcpy(movies[movie_count].actors, token);

        token = strtok(NULL, &delimiter);
        strcpy(movies[movie_count].genre, token);

        token = strtok(NULL, &delimiter);
        movies[movie_count].year = atoi(token);

        token = strtok(NULL, &delimiter);
        movies[movie_count].rating = atoi(token);

        movie_count++;
    }

    fclose(fp);

    printf("List of movies:\n");

    for (i = 0; i < movie_count; i++) {
        printf("Movie %d:\n", i+1);
        printf("Title: %s\n", movies[i].title);
        printf("Director: %s\n", movies[i].director);
        printf("Actors: %s\n", movies[i].actors);
        printf("Genre: %s\n", movies[i].genre);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %d\n\n", movies[i].rating);
    }

    return 0;
}