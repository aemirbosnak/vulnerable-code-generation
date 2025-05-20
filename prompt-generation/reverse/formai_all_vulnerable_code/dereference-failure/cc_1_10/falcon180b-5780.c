//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct movie {
    char title[50];
    int ratings[MAX_RATINGS];
    int num_ratings;
    float avg_rating;
};

void add_rating(struct movie *movie, int rating) {
    if (movie->num_ratings < MAX_RATINGS) {
        movie->ratings[movie->num_ratings] = rating;
        movie->num_ratings++;
    } else {
        printf("Cannot add more ratings for this movie.\n");
    }
}

void print_movie(struct movie *movie) {
    printf("Title: %s\n", movie->title);
    printf("Number of ratings: %d\n", movie->num_ratings);
    printf("Average rating: %.2f\n", movie->avg_rating);
}

int main() {
    struct movie movies[MAX_MOVIES];
    int num_movies = 0;
    char choice;

    do {
        printf("Movie Rating System\n");
        printf("=====================\n");
        printf("1. Add a movie\n");
        printf("2. Add a rating\n");
        printf("3. Print ratings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                if (num_movies >= MAX_MOVIES) {
                    printf("Cannot add more movies.\n");
                } else {
                    printf("Enter the title of the movie: ");
                    scanf("%s", movies[num_movies].title);
                    num_movies++;
                }
                break;
            case '2':
                printf("Enter the title of the movie: ");
                scanf("%s", movies[num_movies-1].title);
                add_rating(&movies[num_movies-1], 0);
                break;
            case '3':
                printf("Movie Ratings\n");
                for (int i = 0; i < num_movies; i++) {
                    print_movie(&movies[i]);
                }
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');

    return 0;
}