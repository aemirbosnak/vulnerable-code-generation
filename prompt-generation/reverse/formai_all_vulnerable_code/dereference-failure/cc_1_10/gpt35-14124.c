//FormAI DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_MOVIES 10
#define NUM_USERS 5

int movie_ratings[NUM_MOVIES] = {0};
pthread_mutex_t mutex_lock;

void *user_thread(void *input)
{
    int *user_id = (int *)input;
    for(int i=0; i<NUM_MOVIES; i++)
    {
        int rating = rand() % 10 + 1; // random rating between 1 and 10
        pthread_mutex_lock(&mutex_lock);
        movie_ratings[i] += rating; // add user rating to movie rating
        pthread_mutex_unlock(&mutex_lock);
        printf("User %d rated movie %d: %d\n", *user_id, i+1, rating);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t users[NUM_USERS];
    pthread_mutex_init(&mutex_lock, NULL);

    // create user threads
    for(int i=0; i<NUM_USERS; i++)
    {
        int *user_id = (int *)malloc(sizeof(int));
        *user_id = i+1;
        pthread_create(&users[i], NULL, user_thread, (void *)user_id);
    }

    // wait for user threads to finish
    for(int i=0; i<NUM_USERS; i++)
    {
        pthread_join(users[i], NULL);
    }

    // print movie ratings
    printf("\nMovie Ratings:\n");
    for(int i=0; i<NUM_MOVIES; i++)
    {
        int average_rating = movie_ratings[i] / NUM_USERS;
        printf("Movie %d: %d\n", i+1, average_rating);
    }

    pthread_mutex_destroy(&mutex_lock);
    return 0;
}