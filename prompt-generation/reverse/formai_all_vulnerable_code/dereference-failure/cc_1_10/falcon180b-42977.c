//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_GENRE_LENGTH 20
#define MAX_RATING 5
#define MAX_REVIEW_LENGTH 500

typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    int rating;
    char review[MAX_REVIEW_LENGTH];
} Movie;

int main() {
    int numMovies;
    Movie movies[100];
    FILE *moviesFile;
    char filename[50];
    int i, j;
    char line[1024];
    char *token;
    int rating;
    char review[MAX_REVIEW_LENGTH];

    printf("Enter the name of the file containing movie data:\n");
    scanf("%s", filename);

    moviesFile = fopen(filename, "r");
    if (moviesFile == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    numMovies = 0;
    while (fgets(line, sizeof(line), moviesFile)!= NULL) {
        if (numMovies >= 100) {
            printf("Error: maximum number of movies reached.\n");
            exit(1);
        }
        token = strtok(line, ",");
        strcpy(movies[numMovies].title, token);
        token = strtok(NULL, ",");
        strcpy(movies[numMovies].director, token);
        token = strtok(NULL, ",");
        strcpy(movies[numMovies].actor, token);
        token = strtok(NULL, ",");
        strcpy(movies[numMovies].genre, token);
        rating = atoi(strtok(NULL, ","));
        movies[numMovies].rating = rating;
        strcpy(movies[numMovies].review, "");
        numMovies++;
    }
    fclose(moviesFile);

    printf("Enter the name of the file to save the movie ratings:\n");
    scanf("%s", filename);

    moviesFile = fopen(filename, "w");
    if (moviesFile == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    for (i = 0; i < numMovies; i++) {
        printf("Enter your rating for %s:\n", movies[i].title);
        scanf("%d", &movies[i].rating);
        printf("Enter your review for %s:\n", movies[i].title);
        fgets(movies[i].review, sizeof(movies[i].review), stdin);
        fprintf(moviesFile, "%s,%d,%s\n", movies[i].title, movies[i].rating, movies[i].review);
    }

    fclose(moviesFile);
    printf("Movie ratings saved to file.\n");

    return 0;
}