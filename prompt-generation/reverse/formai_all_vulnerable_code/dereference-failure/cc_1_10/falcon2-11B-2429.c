//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_MOVIES 10
#define NUM_USERS 5

float movie_ratings[NUM_MOVIES];
int num_ratings[NUM_MOVIES];

void *user_thread(void *arg) {
    int user_id = *((int *)arg);
    int num_ratings[NUM_MOVIES];

    for (int i = 0; i < NUM_MOVIES; i++) {
        movie_ratings[i] = rand() % 10 + 1;
        num_ratings[i] = 0;
    }

    for (int i = 0; i < NUM_USERS; i++) {
        movie_ratings[i % NUM_MOVIES] = (movie_ratings[i % NUM_MOVIES] + (rand() % 2 - 1)) / 2;
        num_ratings[i % NUM_MOVIES]++;
    }

    pthread_exit(NULL);
}

void *rating_system_thread(void *arg) {
    int num_ratings[NUM_MOVIES];

    for (int i = 0; i < NUM_MOVIES; i++) {
        num_ratings[i] = 0;
    }

    for (int i = 0; i < NUM_USERS; i++) {
        movie_ratings[i % NUM_MOVIES] = (movie_ratings[i % NUM_MOVIES] + (rand() % 2 - 1)) / 2;
        num_ratings[i % NUM_MOVIES]++;
    }

    for (int i = 0; i < NUM_MOVIES; i++) {
        printf("%d: %d/%d = %.2f\n", i, num_ratings[i], NUM_USERS, movie_ratings[i] / num_ratings[i]);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t user_thread;
    pthread_t rating_system_thread;
    int user_ids[NUM_USERS];

    for (int i = 0; i < NUM_USERS; i++) {
        user_ids[i] = i;
    }

    pthread_create(&user_thread, NULL, user_thread, &user_ids[0]);
    pthread_create(&rating_system_thread, NULL, rating_system_thread, NULL);

    pthread_join(user_thread, NULL);
    pthread_join(rating_system_thread, NULL);

    return 0;
}