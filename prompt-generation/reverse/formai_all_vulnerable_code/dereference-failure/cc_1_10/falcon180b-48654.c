//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5

typedef struct {
    char title[50];
    int ratings[MAX_RATINGS];
} Movie;

void addRating(Movie *movie, int rating) {
    int i;
    for (i = 0; i < movie->ratings[i]!= 0; i++) {
        if (movie->ratings[i] == rating) {
            movie->ratings[i]++;
            return;
        }
    }
    movie->ratings[i] = rating;
}

int getAverageRating(Movie *movie) {
    int sum = 0;
    int count = 0;
    int i;
    for (i = 0; i < MAX_RATINGS; i++) {
        if (movie->ratings[i]!= 0) {
            sum += movie->ratings[i];
            count++;
        }
    }
    return sum / count;
}

void printMovieRatings(Movie *movie) {
    int i;
    printf("Ratings for %s:\n", movie->title);
    for (i = 0; i < MAX_RATINGS; i++) {
        if (movie->ratings[i]!= 0) {
            printf("%d stars\n", movie->ratings[i]);
        }
    }
    printf("Average rating: %d stars\n", getAverageRating(movie));
}

int main() {
    Movie movie;
    strcpy(movie.title, "The Shawshank Redemption");
    addRating(&movie, 5);
    addRating(&movie, 5);
    addRating(&movie, 4);
    addRating(&movie, 3);
    addRating(&movie, 2);
    printMovieRatings(&movie);
    return 0;
}