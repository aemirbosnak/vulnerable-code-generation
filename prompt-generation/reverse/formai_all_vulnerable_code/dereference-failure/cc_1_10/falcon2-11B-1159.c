//Falcon2-11B DATASET v1.0 Category: Movie Rating System ; Style: multi-threaded
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_RATING 5

int num_users;
int ratings[MAX_RATING];

void *user_thread(void *arg) {
    int user_id = *((int*)arg);
    int i;
    for (i = 0; i < MAX_RATING; i++) {
        ratings[i] = 0;
    }
    while (1) {
        printf("User %d, enter your rating (1-5): ", user_id);
        int rating;
        scanf("%d", &rating);
        if (rating < 1 || rating > 5) {
            printf("Invalid rating, please try again.\n");
            continue;
        }
        ratings[rating - 1]++;
        printf("Thank you for your rating.\n");
    }
}

int main() {
    int i, total_ratings = 0;
    int sum_ratings = 0;
    pthread_t threads[MAX_RATING];
    int *ids = (int*)malloc(sizeof(int) * MAX_RATING);
    for (i = 0; i < MAX_RATING; i++) {
        ids[i] = i;
    }

    num_users = MAX_RATING;
    for (i = 0; i < num_users; i++) {
        pthread_create(&threads[i], NULL, user_thread, &ids[i]);
    }

    for (i = 0; i < num_users; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < MAX_RATING; i++) {
        total_ratings += ratings[i];
        sum_ratings += (i + 1) * ratings[i];
    }

    printf("Average rating: %.2f\n", (float)sum_ratings / total_ratings);

    free(ids);
    return 0;
}