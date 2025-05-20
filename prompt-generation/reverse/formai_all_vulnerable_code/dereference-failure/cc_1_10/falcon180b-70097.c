//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5

struct Movie {
    char title[100];
    int num_ratings;
    int ratings[MAX_RATINGS];
};

struct Movie* create_movie(char* title) {
    struct Movie* m = (struct Movie*)malloc(sizeof(struct Movie));
    strcpy(m->title, title);
    m->num_ratings = 0;
    for (int i = 0; i < MAX_RATINGS; i++) {
        m->ratings[i] = 0;
    }
    return m;
}

void add_rating(struct Movie* m, int rating) {
    if (m->num_ratings >= MAX_RATINGS) {
        printf("Error: Maximum number of ratings reached.\n");
        return;
    }
    m->ratings[m->num_ratings++] = rating;
}

double calculate_average_rating(struct Movie* m) {
    int total_rating = 0;
    for (int i = 0; i < m->num_ratings; i++) {
        total_rating += m->ratings[i];
    }
    return (double)total_rating / m->num_ratings;
}

int main() {
    struct Movie* movie1 = create_movie("The Shawshank Redemption");
    struct Movie* movie2 = create_movie("The Godfather");
    struct Movie* movie3 = create_movie("Pulp Fiction");

    add_rating(movie1, 5);
    add_rating(movie1, 4);
    add_rating(movie1, 4);
    add_rating(movie1, 5);
    add_rating(movie1, 4);

    add_rating(movie2, 5);
    add_rating(movie2, 5);
    add_rating(movie2, 5);
    add_rating(movie2, 5);
    add_rating(movie2, 5);

    add_rating(movie3, 4);
    add_rating(movie3, 5);
    add_rating(movie3, 4);
    add_rating(movie3, 4);
    add_rating(movie3, 5);

    printf("Average rating for The Shawshank Redemption: %.2f\n", calculate_average_rating(movie1));
    printf("Average rating for The Godfather: %.2f\n", calculate_average_rating(movie2));
    printf("Average rating for Pulp Fiction: %.2f\n", calculate_average_rating(movie3));

    return 0;
}