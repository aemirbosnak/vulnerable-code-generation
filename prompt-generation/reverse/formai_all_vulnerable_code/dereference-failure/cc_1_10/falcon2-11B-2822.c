//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: decentralized
// A unique C Movie Rating System example program in a decentralized style
#include <stdio.h>
#include <stdlib.h>

// Structure to store the movie information
struct Movie {
    char title[100];
    float rating;
};

// Structure to store the rating information
struct Rating {
    struct Movie movie;
    struct Rating *next;
};

// Function to create a new rating
struct Rating* create_rating(struct Movie movie) {
    struct Rating* rating = (struct Rating*) malloc(sizeof(struct Rating));
    rating->movie = movie;
    rating->next = NULL;
    return rating;
}

// Function to add a new rating
void add_rating(struct Rating* ratings, struct Movie movie) {
    struct Rating* new_rating = create_rating(movie);
    struct Rating* current = ratings;
    while (current->next!= NULL) {
        current = current->next;
    }
    current->next = new_rating;
}

// Function to print all ratings
void print_ratings(struct Rating* ratings) {
    struct Rating* current = ratings;
    while (current!= NULL) {
        printf("%s - %.2f\n", current->movie.title, current->movie.rating);
        current = current->next;
    }
}

int main() {
    // Create a new movie
    struct Movie movie1 = {"The Shawshank Redemption", 9.3};

    // Create a new rating for the movie
    struct Rating* rating1 = create_rating(movie1);

    // Add the rating to the rating list
    struct Rating* ratings = NULL;
    add_rating(ratings, movie1);

    // Print all ratings
    print_ratings(ratings);

    // Free the memory
    free(rating1);
    free(ratings);

    return 0;
}