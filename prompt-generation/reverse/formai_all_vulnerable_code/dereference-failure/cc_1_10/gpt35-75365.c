//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_TIME 100

pthread_mutex_t lock;
int time_travel = 0;

void *travel(void *arg)
{
    int *year = (int *) arg;
    int i;

    for (i = 1; i <= MAX_TIME; i++) {
        pthread_mutex_lock(&lock);
        time_travel = i;
        printf("Traveling to year %d...\n", *year);
        sleep(1);
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    int year1, year2, rc;

    if (argc != 3) {
        printf("Usage: %s <year1> <year2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    year1 = atoi(argv[1]);
    year2 = atoi(argv[2]);

    printf("Starting time travel simulator...\n");

    pthread_mutex_init(&lock, NULL);

    rc = pthread_create(&thread1, NULL, travel, (void *) &year1);
    if (rc) {
        printf("Error: failed to create thread1: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&thread2, NULL, travel, (void *) &year2);
    if (rc) {
        printf("Error: failed to create thread2: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    while (time_travel < MAX_TIME) {
        printf("Current year: %d\n", time_travel);
        sleep(1);
    }

    rc = pthread_join(thread1, NULL);
    if (rc) {
        printf("Error: thread1 join failed: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    rc = pthread_join(thread2, NULL);
    if (rc) {
        printf("Error: thread2 join failed: %d\n", rc);
        exit(EXIT_FAILURE);
    }

    pthread_mutex_destroy(&lock);

    printf("Time travel simulation complete.\n");

    return 0;
}