//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ROADS 10
#define MAX_CYCLES 5
#define GREEN_TIME 30
#define YELLOW_TIME 5
#define RED_TIME 30
#define TOTAL_CYCLE_TIME (GREEN_TIME + YELLOW_TIME + RED_TIME)

typedef struct {
    int roadId;
    int cycleCount;
    int greenTime;
    int yellowTime;
    int redTime;
    int currentTime;
} Road;

void initRoads(Road* roads, int numRoads) {
    for (int i = 0; i < numRoads; i++) {
        roads[i].roadId = i + 1;
        roads[i].cycleCount = 0;
        roads[i].greenTime = GREEN_TIME;
        roads[i].yellowTime = YELLOW_TIME;
        roads[i].redTime = RED_TIME;
        roads[i].currentTime = 0;
    }
}

void updateRoads(Road* roads, int numRoads) {
    for (int i = 0; i < numRoads; i++) {
        roads[i].currentTime++;
        if (roads[i].currentTime >= roads[i].greenTime) {
            roads[i].currentTime = 0;
            roads[i].cycleCount++;
        }
        if (roads[i].cycleCount >= MAX_CYCLES) {
            roads[i].cycleCount = 0;
        }
    }
}

void printRoads(Road* roads, int numRoads) {
    for (int i = 0; i < numRoads; i++) {
        printf("Road %d: Green %d, Yellow %d, Red %d\n", roads[i].roadId, roads[i].greenTime, roads[i].yellowTime, roads[i].redTime);
        printf("Current time: %d, Cycle count: %d\n\n", roads[i].currentTime, roads[i].cycleCount);
    }
}

int main() {
    int numRoads;
    printf("Enter the number of roads: ");
    scanf("%d", &numRoads);

    Road* roads = malloc(sizeof(Road) * numRoads);
    initRoads(roads, numRoads);

    int numCycles;
    printf("Enter the number of cycles: ");
    scanf("%d", &numCycles);

    for (int i = 0; i < numCycles; i++) {
        updateRoads(roads, numRoads);
        printRoads(roads, numRoads);
        sleep(TOTAL_CYCLE_TIME);
    }

    free(roads);
    return 0;
}