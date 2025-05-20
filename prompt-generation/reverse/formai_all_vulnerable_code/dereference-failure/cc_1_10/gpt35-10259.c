//FormAI DATASET v1.0 Category: Movie Rating System ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SERVER_PORT 8080
#define MAX_RATINGS 10

typedef struct {
    char movie_title[256];
    int rating_count;
    int rating_sum;
    float rating_avg;
} movie_rating_t;

movie_rating_t *movie_ratings[MAX_RATINGS];

int num_ratings = 0;

void add_rating(char *title, int rating)
{
    // Check if movie already has rating
    int already_rated = 0;
    for (int i = 0; i < num_ratings; i++) {
        if (strcmp(movie_ratings[i]->movie_title, title) == 0) {
            movie_ratings[i]->rating_count += 1;
            movie_ratings[i]->rating_sum += rating;
            movie_ratings[i]->rating_avg = (float)movie_ratings[i]->rating_sum / movie_ratings[i]->rating_count;
            already_rated = 1;
            break;
        }
    }

    // Add movie and rating if no rating exists
    if (!already_rated) {
        movie_rating_t *new_rating = malloc(sizeof(movie_rating_t));
        strcpy(new_rating->movie_title, title);
        new_rating->rating_count = 1;
        new_rating->rating_sum = rating;
        new_rating->rating_avg = (float)rating;
        movie_ratings[num_ratings++] = new_rating;
    }
}

void print_ratings()
{
    for (int i = 0; i < num_ratings; i++) {
        printf("%s: %.2f\n", movie_ratings[i]->movie_title, movie_ratings[i]->rating_avg);
    }
}

int main()
{
    // Example ratings
    add_rating("The Shawshank Redemption", 9);
    add_rating("The Godfather", 10);
    add_rating("The Dark Knight", 8);
    add_rating("The Lord of the Rings: The Fellowship of the Ring", 9);
    add_rating("Pulp Fiction", 9);

    // Print all ratings
    print_ratings();

    return 0;
}