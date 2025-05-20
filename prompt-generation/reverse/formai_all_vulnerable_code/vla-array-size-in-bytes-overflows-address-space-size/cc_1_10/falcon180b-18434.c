//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 10
#define MAX_NAME_LENGTH 50

// Movie struct
typedef struct {
    char name[MAX_NAME_LENGTH];
    int ratings[MAX_RATINGS];
    int num_ratings;
} Movie;

// Function prototypes
void read_movies(Movie* movies, int num_movies);
void read_ratings(Movie* movies, int num_movies);
void print_ratings(Movie* movie);
int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);
    Movie movies[num_movies];
    read_movies(movies, num_movies);
    read_ratings(movies, num_movies);
    printf("\nRatings:\n");
    for(int i=0; i<num_movies; i++) {
        printf("Movie %s:\n", movies[i].name);
        print_ratings(movies+i);
    }
    return 0;
}

void read_movies(Movie* movies, int num_movies) {
    for(int i=0; i<num_movies; i++) {
        printf("Enter movie name: ");
        scanf("%s", movies[i].name);
    }
}

void read_ratings(Movie* movies, int num_movies) {
    for(int i=0; i<num_movies; i++) {
        int rating;
        printf("Enter number of ratings for %s: ", movies[i].name);
        scanf("%d", &rating);
        movies[i].num_ratings = rating;
        for(int j=0; j<rating; j++) {
            printf("Enter rating %d for %s: ", j+1, movies[i].name);
            scanf("%d", &movies[i].ratings[j]);
        }
    }
}

void print_ratings(Movie* movie) {
    printf("Ratings:\n");
    for(int i=0; i<movie->num_ratings; i++) {
        printf("%d stars\n", movie->ratings[i]);
    }
}