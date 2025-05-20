//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RATING_MAX 5
#define RATING_MIN 1

struct movie {
    char title[50];
    char director[50];
    char cast[100];
    int year;
    int rating;
};

struct movie create_movie(char* title, char* director, char* cast, int year, int rating) {
    struct movie movie = {
       .title = title,
       .director = director,
       .cast = cast,
       .year = year,
       .rating = rating
    };
    return movie;
}

void print_movie(struct movie movie) {
    printf("Title: %s\n", movie.title);
    printf("Director: %s\n", movie.director);
    printf("Cast: %s\n", movie.cast);
    printf("Year: %d\n", movie.year);
    printf("Rating: %d\n", movie.rating);
    printf("\n");
}

int main() {
    srand(time(0));

    int num_movies = rand() % 10 + 1;
    struct movie* movies = malloc(num_movies * sizeof(struct movie));

    for (int i = 0; i < num_movies; i++) {
        char title[50] = {0};
        char director[50] = {0};
        char cast[100] = {0};
        int year = rand() % 100 + 1900;
        int rating = rand() % (RATING_MAX - RATING_MIN + 1) + RATING_MIN;

        sprintf(title, "Movie %d", i+1);
        sprintf(director, "Director %d", i+1);
        sprintf(cast, "Actor 1, Actor 2, Actor 3");

        movies[i] = create_movie(title, director, cast, year, rating);
    }

    for (int i = 0; i < num_movies; i++) {
        print_movie(movies[i]);
    }

    free(movies);
    return 0;
}