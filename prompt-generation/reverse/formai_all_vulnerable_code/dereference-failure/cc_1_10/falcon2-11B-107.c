//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char title[100];
    int length;
    float rating;
} Movie;

Movie* createMovie(char* title, int length, float rating) {
    Movie* newMovie = (Movie*) malloc(sizeof(Movie));
    strcpy(newMovie->title, title);
    newMovie->length = length;
    newMovie->rating = rating;
    return newMovie;
}

float getRating(Movie* movie) {
    if (movie->rating >= 9.0) {
        return 5.0;
    } else if (movie->rating >= 8.0) {
        return 4.0;
    } else if (movie->rating >= 7.0) {
        return 3.0;
    } else if (movie->rating >= 6.0) {
        return 2.0;
    } else {
        return 1.0;
    }
}

int main() {
    Movie* movie1 = createMovie("The Godfather", 175, 9.2);
    Movie* movie2 = createMovie("The Shawshank Redemption", 142, 9.3);
    Movie* movie3 = createMovie("Pulp Fiction", 154, 8.9);

    printf("Movie 1: %s, Length: %d, Rating: %.2f\n", movie1->title, movie1->length, movie1->rating);
    printf("Movie 2: %s, Length: %d, Rating: %.2f\n", movie2->title, movie2->length, movie2->rating);
    printf("Movie 3: %s, Length: %d, Rating: %.2f\n", movie3->title, movie3->length, movie3->rating);

    printf("Rating: %.2f\n", getRating(movie1));
    printf("Rating: %.2f\n", getRating(movie2));
    printf("Rating: %.2f\n", getRating(movie3));

    free(movie1);
    free(movie2);
    free(movie3);

    return 0;
}