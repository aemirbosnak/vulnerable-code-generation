//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define NUM_CROSSINGS 4
#define RED_LIGHT_DURATION 10 // in seconds
#define GREEN_LIGHT_DURATION 5 // in seconds
#define YELLOW_LIGHT_DURATION 3 // in seconds

typedef struct {
    int id;
    char *name;
    pthread_t thread;
} Crossing;

void *run_crossing(void *arg) {
    Crossing *crossing = arg;
    int i;

    for (i = 0; i < NUM_CROSSINGS; i++) {
        if (i == crossing->id) {
            printf("Crossing %s is active\n", crossing->name);
        } else {
            printf("Crossing %s is inactive\n", crossing->name);
        }
    }

    return NULL;
}

int main() {
    int i;
    Crossing crossings[NUM_CROSSINGS];
    pthread_t threads[NUM_CROSSINGS];

    srand(time(NULL));

    for (i = 0; i < NUM_CROSSINGS; i++) {
        crossings[i].id = i;
        crossings[i].name = malloc(10 * sizeof(char));
        sprintf(crossings[i].name, "Crossing %d", i + 1);
        pthread_create(&threads[i], NULL, run_crossing, &crossings[i]);
    }

    for (i = 0; i < NUM_CROSSINGS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}