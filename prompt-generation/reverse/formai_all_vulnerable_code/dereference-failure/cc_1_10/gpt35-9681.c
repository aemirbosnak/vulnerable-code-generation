//FormAI DATASET v1.0 Category: Movie Rating System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100

typedef struct {
    char title[50];
    char year[5];
    char director[50];
    float rating;
} Movie;

void add_movie(Movie movies[], int *count);
void display_movies(Movie movies[], int count);
void rate_movie(Movie movies[], int count);
void save_movies(Movie movies[], int count);
void load_movies(Movie movies[], int *count);

int main() {
    Movie movies[MAX_MOVIES];
    int count = 0;
    int choice;

    load_movies(movies, &count);

    while (1) {
        printf("\n1) Add a movie\n");
        printf("2) Display all movies\n");
        printf("3) Rate a movie\n");
        printf("4) Save movies\n");
        printf("5) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_movie(movies, &count);
                break;
            case 2:
                display_movies(movies, count);
                break;
            case 3:
                rate_movie(movies, count);
                break;
            case 4:
                save_movies(movies, count);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_movie(Movie movies[], int *count) {
    Movie new_movie;

    printf("\nEnter movie title: ");
    scanf(" %[^\n]", new_movie.title);
    printf("Enter movie year: ");
    scanf(" %4s", new_movie.year);
    printf("Enter movie director: ");
    scanf(" %[^\n]", new_movie.director);
    new_movie.rating = 0.0;

    movies[*count] = new_movie;
    (*count)++;
}

void display_movies(Movie movies[], int count) {
    printf("\n%-30s%-10s%-30s%s\n", "Title", "Year", "Director", "Rating");

    for (int i = 0; i < count; i++) {
        printf("%-30s%-10s%-30s%.1f\n", movies[i].title, movies[i].year, movies[i].director, movies[i].rating);
    }
}

void rate_movie(Movie movies[], int count) {
    char movie_title[50];
    float new_rating;

    printf("\nEnter movie title to rate: ");
    scanf(" %[^\n]", movie_title);

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].title, movie_title) == 0) {
            printf("Enter new rating (0.0-10.0): ");
            scanf("%f", &new_rating);
            movies[i].rating = new_rating;
            printf("Thank you for rating %s.\n", movies[i].title);
            return;
        }
    }

    printf("Movie not found. Please try again.\n");
}

void save_movies(Movie movies[], int count) {
    FILE *fp = fopen("movies.txt", "w");

    if (fp == NULL) {
        printf("Error opening file. Please try again.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s;%s;%s;%.1f\n", movies[i].title, movies[i].year, movies[i].director, movies[i].rating);
    }

    fclose(fp);
    printf("Movies saved successfully.\n");
}

void load_movies(Movie movies[], int *count) {
    FILE *fp = fopen("movies.txt", "r");

    if (fp == NULL) {
        printf("Error opening file. Creating new file.\n");
        return;
    }

    char line[200];
    char *token;

    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ";");
        strcpy(movies[*count].title, token);

        token = strtok(NULL, ";");
        strcpy(movies[*count].year, token);

        token = strtok(NULL, ";");
        strcpy(movies[*count].director, token);

        token = strtok(NULL, ";");
        movies[*count].rating = atof(token);

        (*count)++;
    }

    fclose(fp);
    printf("%d movie(s) loaded successfully.\n", *count);
}