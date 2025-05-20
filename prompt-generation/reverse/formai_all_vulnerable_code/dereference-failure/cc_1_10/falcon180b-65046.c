//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct {
    char *title;
    char *director;
    char *actors;
    char *genre;
    float rating;
} Movie;

typedef struct {
    Movie *movies;
    int num_movies;
    int max_movies;
} MovieDatabase;

MovieDatabase *movie_database_create(int max_movies) {
    MovieDatabase *db = malloc(sizeof(MovieDatabase));
    db->movies = malloc(max_movies * sizeof(Movie));
    db->num_movies = 0;
    db->max_movies = max_movies;
    return db;
}

void movie_database_destroy(MovieDatabase *db) {
    free(db->movies);
    free(db);
}

int movie_database_add_movie(MovieDatabase *db, const char *title, const char *director, const char *actors, const char *genre, float rating) {
    if (db->num_movies >= db->max_movies) {
        return -1;
    }
    db->movies[db->num_movies] = (Movie) {
       .title = strdup(title),
       .director = strdup(director),
       .actors = strdup(actors),
       .genre = strdup(genre),
       .rating = rating,
    };
    db->num_movies++;
    return 0;
}

int main() {
    MovieDatabase *db = movie_database_create(100);

    while (1) {
        printf("Enter movie title: ");
        char title[100];
        scanf("%s", title);

        printf("Enter movie director: ");
        char director[100];
        scanf("%s", director);

        printf("Enter movie actors: ");
        char actors[200];
        scanf("%s", actors);

        printf("Enter movie genre: ");
        char genre[50];
        scanf("%s", genre);

        printf("Enter movie rating: ");
        float rating;
        scanf("%f", &rating);

        int ret = movie_database_add_movie(db, title, director, actors, genre, rating);
        if (ret == -1) {
            printf("Movie database is full.\n");
        }
    }

    movie_database_destroy(db);
    return 0;
}