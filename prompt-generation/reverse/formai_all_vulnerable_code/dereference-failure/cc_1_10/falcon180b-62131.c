//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: all-encompassing
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 100
#define MAX_ACTOR_LENGTH 100
#define MAX_GENRE_LENGTH 50
#define MAX_RATING_LENGTH 10

struct Movie {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_LENGTH];
    char genre[MAX_GENRE_LENGTH];
    char rating[MAX_RATING_LENGTH];
};

struct Movie* createMovie() {
    struct Movie* movie = (struct Movie*)malloc(sizeof(struct Movie));
    strcpy(movie->title, "");
    strcpy(movie->director, "");
    strcpy(movie->actor, "");
    strcpy(movie->genre, "");
    strcpy(movie->rating, "");
    return movie;
}

void setTitle(struct Movie* movie, char* title) {
    strcpy(movie->title, title);
}

void setDirector(struct Movie* movie, char* director) {
    strcpy(movie->director, director);
}

void setActor(struct Movie* movie, char* actor) {
    strcpy(movie->actor, actor);
}

void setGenre(struct Movie* movie, char* genre) {
    strcpy(movie->genre, genre);
}

void setRating(struct Movie* movie, char* rating) {
    strcpy(movie->rating, rating);
}

char* getTitle(struct Movie* movie) {
    return movie->title;
}

char* getDirector(struct Movie* movie) {
    return movie->director;
}

char* getActor(struct Movie* movie) {
    return movie->actor;
}

char* getGenre(struct Movie* movie) {
    return movie->genre;
}

char* getRating(struct Movie* movie) {
    return movie->rating;
}

int main() {
    struct Movie* movie = createMovie();
    setTitle(movie, "The Shawshank Redemption");
    setDirector(movie, "Frank Darabont");
    setActor(movie, "Tim Robbins");
    setGenre(movie, "Drama");
    setRating(movie, "9.3/10");

    printf("Title: %s\n", getTitle(movie));
    printf("Director: %s\n", getDirector(movie));
    printf("Actor: %s\n", getActor(movie));
    printf("Genre: %s\n", getGenre(movie));
    printf("Rating: %s\n", getRating(movie));

    return 0;
}