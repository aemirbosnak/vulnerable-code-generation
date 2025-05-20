//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_GENRE_LEN 50
#define MAX_RATING 5
#define MAX_RATINGS 10
#define MAX_REVIEW_LEN 500

typedef struct {
    char name[MAX_NAME_LEN];
    char genre[MAX_GENRE_LEN];
    int rating;
    char review[MAX_REVIEW_LEN];
} Movie;

void print_movies(Movie movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("Name: %s\n", movies[i].name);
        printf("Genre: %s\n", movies[i].genre);
        printf("Rating: %d\n", movies[i].rating);
        printf("Review: %s\n\n", movies[i].review);
    }
}

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    Movie movies[num_movies];

    for (int i = 0; i < num_movies; i++) {
        printf("Enter the name of the movie: ");
        scanf("%s", movies[i].name);

        printf("Enter the genre of the movie: ");
        scanf("%s", movies[i].genre);

        printf("Enter the rating of the movie (1 to 5): ");
        scanf("%d", &movies[i].rating);

        printf("Enter the review of the movie: ");
        scanf("%s", movies[i].review);
    }

    print_movies(movies, num_movies);

    return 0;
}