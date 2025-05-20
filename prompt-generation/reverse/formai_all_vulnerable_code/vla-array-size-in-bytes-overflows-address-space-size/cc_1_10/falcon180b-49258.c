//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RATINGS 5
#define MAX_MOVIES 100
#define MAX_USERS 50

typedef struct {
    char title[100];
    int year;
    int num_ratings;
    float avg_rating;
    int ratings[MAX_RATINGS];
} Movie;

typedef struct {
    char name[50];
    int num_ratings;
    float avg_rating;
    int ratings[MAX_RATINGS];
} User;

int main() {
    int num_movies, num_users;
    scanf("%d %d", &num_movies, &num_users);

    // Initialize movies
    Movie movies[num_movies];
    for (int i = 0; i < num_movies; i++) {
        movies[i].num_ratings = 0;
        movies[i].avg_rating = 0;
        for (int j = 0; j < MAX_RATINGS; j++) {
            movies[i].ratings[j] = 0;
        }
    }

    // Initialize users
    User users[num_users];
    for (int i = 0; i < num_users; i++) {
        users[i].num_ratings = 0;
        users[i].avg_rating = 0;
        for (int j = 0; j < MAX_RATINGS; j++) {
            users[i].ratings[j] = 0;
        }
    }

    // Read in movie and rating data
    char movie_title[100];
    int movie_year;
    int rating;
    for (int i = 0; i < num_movies; i++) {
        scanf("%s %d", movie_title, &movie_year);
        for (int j = 0; j < num_users; j++) {
            scanf("%d", &rating);
            movies[i].num_ratings++;
            movies[i].avg_rating += rating;
            movies[i].ratings[j] = rating;
            users[j].num_ratings++;
            users[j].avg_rating += rating;
            users[j].ratings[i] = rating;
        }
    }

    // Print movie ratings
    printf("Movie Ratings:\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%s (%d): %.2f\n", movies[i].title, movies[i].year, movies[i].avg_rating);
    }

    // Print user ratings
    printf("\nUser Ratings:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s: %.2f\n", users[i].name, users[i].avg_rating);
    }

    return 0;
}