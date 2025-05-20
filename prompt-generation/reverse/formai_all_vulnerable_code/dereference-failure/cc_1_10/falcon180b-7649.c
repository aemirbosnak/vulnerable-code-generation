//Falcon-180B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 1000
#define MAX_PLANES 10
#define MAX_BAGGAGES 50

typedef struct {
    int plane_id;
    int num_baggage;
    int *baggage_id;
} Plane;

typedef struct {
    int id;
    int destination;
} Baggage;

Baggage *baggage_pool;
Plane *plane_pool;

void init() {
    srand(time(NULL));
    baggage_pool = (Baggage *)malloc(MAX_BAGS * sizeof(Baggage));
    for (int i = 0; i < MAX_BAGS; i++) {
        baggage_pool[i].id = i;
        baggage_pool[i].destination = rand() % 10;
    }
    plane_pool = (Plane *)malloc(MAX_PLANES * sizeof(Plane));
    for (int i = 0; i < MAX_PLANES; i++) {
        plane_pool[i].plane_id = i;
        plane_pool[i].num_baggage = 0;
        plane_pool[i].baggage_id = (int *)malloc(MAX_BAGGAGES * sizeof(int));
    }
}

void deinit() {
    free(baggage_pool);
    free(plane_pool);
}

int main() {
    init();
    int num_planes = 5;
    for (int i = 0; i < num_planes; i++) {
        int plane_id = rand() % MAX_PLANES;
        Plane *plane = &plane_pool[plane_id];
        plane->plane_id = plane_id;
        int num_baggage = rand() % MAX_BAGGAGES;
        plane->num_baggage = num_baggage;
        for (int j = 0; j < num_baggage; j++) {
            int baggage_id = rand() % MAX_BAGS;
            Baggage *baggage = &baggage_pool[baggage_id];
            plane->baggage_id[j] = baggage_id;
            baggage->destination = rand() % 10;
        }
    }
    for (int i = 0; i < num_planes; i++) {
        Plane *plane = &plane_pool[i];
        printf("Plane %d has %d baggages:\n", plane->plane_id, plane->num_baggage);
        for (int j = 0; j < plane->num_baggage; j++) {
            int baggage_id = plane->baggage_id[j];
            Baggage *baggage = &baggage_pool[baggage_id];
            printf("Baggage %d is going to %d\n", baggage_id, baggage->destination);
        }
    }
    deinit();
    return 0;
}