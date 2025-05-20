//Falcon-180B DATASET v1.0 Category: Movie Rating System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 100
#define MAX_RATINGS 5

struct movie {
    char title[100];
    int ratings[MAX_RATINGS];
    double average_rating;
};

struct user {
    char name[100];
    int num_ratings;
    int ratings[MAX_RATINGS];
    double average_rating;
};

int main() {
    int num_movies, num_users;
    scanf("%d %d", &num_movies, &num_users);

    struct movie movies[MAX_MOVIES];
    struct user users[num_users];

    for (int i = 0; i < num_movies; i++) {
        scanf("%s", movies[i].title);
        for (int j = 0; j < MAX_RATINGS; j++) {
            scanf("%d", &movies[i].ratings[j]);
        }
        movies[i].average_rating = (double)sum_array(movies[i].ratings, MAX_RATINGS) / MAX_RATINGS;
    }

    for (int i = 0; i < num_users; i++) {
        scanf("%s", users[i].name);
        for (int j = 0; j < MAX_RATINGS; j++) {
            scanf("%d", &users[i].ratings[j]);
        }
        users[i].average_rating = (double)sum_array(users[i].ratings, MAX_RATINGS) / MAX_RATINGS;
    }

    for (int i = 0; i < num_movies; i++) {
        printf("%s: %.2f\n", movies[i].title, movies[i].average_rating);
    }

    for (int i = 0; i < num_users; i++) {
        printf("%s: %.2f\n", users[i].name, users[i].average_rating);
    }

    return 0;
}

int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}