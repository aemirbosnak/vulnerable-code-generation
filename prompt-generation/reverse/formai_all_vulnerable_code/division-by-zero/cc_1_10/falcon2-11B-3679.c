//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10

int ratings[MAX_MOVIES];
int num_movies = 0;

void add_movie(const char* title, int rating) {
    if (num_movies < MAX_MOVIES) {
        ratings[num_movies] = rating;
        num_movies++;
        printf("Movie '%s' added.\n", title);
    } else {
        printf("Cannot add more movies.\n");
    }
}

int get_average_rating() {
    int sum = 0;
    for (int i = 0; i < num_movies; i++) {
        sum += ratings[i];
    }
    return (sum / num_movies);
}

int main() {
    int choice, movie_rating;
    printf("Welcome to the Movie Rating System!\n");
    do {
        printf("1. Add Movie\n");
        printf("2. View Average Rating\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title of the movie: ");
                scanf("%s", ratings[num_movies]);
                printf("Enter the rating of the movie: ");
                scanf("%d", &movie_rating);
                add_movie(ratings[num_movies], movie_rating);
                break;
            case 2:
                printf("Average rating: %d\n", get_average_rating());
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}