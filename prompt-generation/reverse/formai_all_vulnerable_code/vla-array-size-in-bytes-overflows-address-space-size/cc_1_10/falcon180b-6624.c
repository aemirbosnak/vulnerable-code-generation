//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: automated
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

struct movie {
    char title[MAX_LENGTH];
    int rating;
    int num_reviews;
};

void read_movies(struct movie movies[], int num_movies);
void read_reviews(struct movie *movie);
void print_movies(struct movie movies[], int num_movies);

int main() {
    int num_movies;
    printf("Enter the number of movies: ");
    scanf("%d", &num_movies);

    struct movie movies[num_movies];
    read_movies(movies, num_movies);

    printf("\nMovie Ratings:\n");
    print_movies(movies, num_movies);

    return 0;
}

void read_movies(struct movie movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("Enter movie %d:\n", i + 1);
        scanf("%s", movies[i].title);
        movies[i].rating = 0;
        movies[i].num_reviews = 0;
    }
}

void read_reviews(struct movie *movie) {
    char review[MAX_LENGTH];
    int rating;

    printf("Enter reviews for %s:\n", movie->title);
    while (scanf("%s", review)!= EOF) {
        for (int i = 0; i < strlen(review); i++) {
            if (!isalpha(review[i])) {
                printf("Invalid review: %s\n", review);
                return;
            }
        }
        rating = atoi(review);
        movie->rating += rating;
        movie->num_reviews++;
    }
}

void print_movies(struct movie movies[], int num_movies) {
    for (int i = 0; i < num_movies; i++) {
        printf("%s: %.1f\n", movies[i].title, (float)movies[i].rating / movies[i].num_reviews);
    }
}