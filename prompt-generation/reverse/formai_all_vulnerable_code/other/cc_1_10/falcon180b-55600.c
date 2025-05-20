//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_LANES 4
#define GREEN_LIGHT 1
#define YELLOW_LIGHT 2
#define RED_LIGHT 3
#define LANE_WAIT_TIME 5 // seconds
#define PEDESTRIAN_WAIT_TIME 10 // seconds
#define PEDESTRIAN_GREEN_TIME 15 // seconds

// semaphores for each lane
sem_t lane_sem[NUM_LANES];
// mutex for pedestrian crossing
pthread_mutex_t pedestrian_mutex = PTHREAD_MUTEX_INITIALIZER;

void *traffic_light(void *arg) {
    int lane = *((int *) arg);
    while(1) {
        sem_wait(&lane_sem[lane]);
        printf("Lane %d turns green\n", lane);
        sleep(LANE_WAIT_TIME);
        printf("Lane %d turns yellow\n", lane);
        sleep(1);
        printf("Lane %d turns red\n", lane);
        sem_post(&lane_sem[lane]);
        sleep(1);
    }
    return NULL;
}

void *pedestrian_light(void *arg) {
    while(1) {
        pthread_mutex_lock(&pedestrian_mutex);
        printf("Pedestrians can cross\n");
        sleep(PEDESTRIAN_GREEN_TIME);
        printf("Pedestrians must wait\n");
        sleep(PEDESTRIAN_WAIT_TIME);
        pthread_mutex_unlock(&pedestrian_mutex);
        sleep(1);
    }
    return NULL;
}

int main() {
    int i;
    pthread_t thread_id[NUM_LANES + 1];

    for(i = 0; i < NUM_LANES; i++) {
        sem_init(&lane_sem[i], 0, 0);
        pthread_create(&thread_id[i], NULL, traffic_light, (void *)&i);
        printf("Lane %d initialized\n", i);
    }

    pthread_create(&thread_id[NUM_LANES], NULL, pedestrian_light, NULL);

    for(i = 0; i < NUM_LANES; i++) {
        pthread_join(thread_id[i], NULL);
        printf("Lane %d terminated\n", i);
    }

    return 0;
}