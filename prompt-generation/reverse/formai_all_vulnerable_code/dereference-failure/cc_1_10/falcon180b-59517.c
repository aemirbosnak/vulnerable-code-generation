//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DIRECTOR_LENGTH 50
#define MAX_ACTOR_LENGTH 50
#define MAX_ACTOR_NUM 10
#define MAX_GENRE_LENGTH 20

// structure for movie data
typedef struct {
    char title[MAX_TITLE_LENGTH];
    char director[MAX_DIRECTOR_LENGTH];
    char actor[MAX_ACTOR_NUM][MAX_ACTOR_LENGTH];
    int num_actors;
    char genre[MAX_GENRE_LENGTH];
    int rating;
} Movie;

// function to read and store movie data
void read_movie_data(Movie* movie) {
    printf("Enter movie title: ");
    scanf("%s", movie->title);

    printf("Enter movie director: ");
    scanf("%s", movie->director);

    printf("Enter number of actors: ");
    scanf("%d", &movie->num_actors);

    for (int i = 0; i < movie->num_actors; i++) {
        printf("Enter actor %d name: ", i+1);
        scanf("%s", movie->actor[i]);
    }

    printf("Enter movie genre: ");
    scanf("%s", movie->genre);

    printf("Enter movie rating: ");
    scanf("%d", &movie->rating);
}

// function to display movie data
void display_movie_data(Movie* movie) {
    printf("Movie Title: %s\n", movie->title);
    printf("Movie Director: %s\n", movie->director);

    printf("Movie Actors:\n");
    for (int i = 0; i < movie->num_actors; i++) {
        printf("\t%s\n", movie->actor[i]);
    }

    printf("Movie Genre: %s\n", movie->genre);
    printf("Movie Rating: %d\n", movie->rating);
}

// function to search for movie by title
Movie* search_movie_by_title(Movie* movies, int num_movies, char* title) {
    for (int i = 0; i < num_movies; i++) {
        if (strcmp(movies[i].title, title) == 0) {
            return &movies[i];
        }
    }
    return NULL;
}

// function to sort movies by rating
void sort_movies_by_rating(Movie* movies, int num_movies) {
    for (int i = 0; i < num_movies-1; i++) {
        for (int j = i+1; j < num_movies; j++) {
            if (movies[j].rating < movies[i].rating) {
                Movie temp = movies[i];
                movies[i] = movies[j];
                movies[j] = temp;
            }
        }
    }
}

// function to display all movies
void display_all_movies(Movie* movies, int num_movies) {
    printf("List of all movies:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("\nMovie %d:\n", i+1);
        display_movie_data(&movies[i]);
    }
}

// main function
int main() {
    int num_movies;
    printf("Enter number of movies: ");
    scanf("%d", &num_movies);

    Movie* movies = (Movie*) malloc(num_movies * sizeof(Movie));

    for (int i = 0; i < num_movies; i++) {
        read_movie_data(&movies[i]);
    }

    sort_movies_by_rating(movies, num_movies);

    display_all_movies(movies, num_movies);

    return 0;
}