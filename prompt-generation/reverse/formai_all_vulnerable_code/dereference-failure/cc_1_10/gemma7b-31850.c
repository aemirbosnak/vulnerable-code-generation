//Gemma-7B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5

typedef struct Rating {
    char movie_name[256];
    int rating;
    struct Rating* next;
} Rating;

Rating* create_rating(char* movie_name, int rating) {
    Rating* new_rating = (Rating*)malloc(sizeof(Rating));
    strcpy(new_rating->movie_name, movie_name);
    new_rating->rating = rating;
    new_rating->next = NULL;
    return new_rating;
}

void add_rating(Rating* ratings, char* movie_name, int rating) {
    Rating* new_rating = create_rating(movie_name, rating);
    if (ratings) {
        ratings->next = new_rating;
    } else {
        ratings = new_rating;
    }
}

int get_rating(Rating* ratings, char* movie_name) {
    for (Rating* current_rating = ratings; current_rating; current_rating = current_rating->next) {
        if (strcmp(current_rating->movie_name, movie_name) == 0) {
            return current_rating->rating;
        }
    }
    return -1;
}

int main() {
    Rating* ratings = NULL;
    add_rating(ratings, "The Shawshank Redemption", 9);
    add_rating(ratings, "The Godfather", 8);
    add_rating(ratings, "The Dark Knight", 7);
    add_rating(ratings, "The Matrix Reloaded", 6);

    int rating = get_rating(ratings, "The Shawshank Redemption");
    if (rating != -1) {
        printf("Rating for The Shawshank Redemption: %d\n", rating);
    } else {
        printf("Movie not found: The Shawshank Redemption\n");
    }

    return 0;
}