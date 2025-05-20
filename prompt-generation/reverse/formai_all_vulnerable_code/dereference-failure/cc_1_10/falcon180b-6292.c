//Falcon-180B DATASET v1.0 Category: Traffic Flow Simulation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROADS 100
#define MAX_CARS 100
#define MAX_WAITING_TIME 10

typedef struct {
    int id;
    int speed;
    int position;
    int waitingTime;
} Car;

typedef struct {
    int id;
    int length;
    int waitingCars;
} Road;

Car cars[MAX_CARS];
Road roads[MAX_ROADS];

void initCars() {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        cars[i].id = i;
        cars[i].speed = rand() % 10 + 1;
        cars[i].position = 0;
        cars[i].waitingTime = 0;
    }
}

void initRoads() {
    int i;
    for (i = 0; i < MAX_ROADS; i++) {
        roads[i].id = i;
        roads[i].length = rand() % 100 + 1;
        roads[i].waitingCars = 0;
    }
}

void moveCars() {
    int i;
    for (i = 0; i < MAX_CARS; i++) {
        if (cars[i].position < roads[cars[i].id].length) {
            if (roads[cars[i].id].waitingCars == 0) {
                cars[i].position++;
            } else {
                cars[i].waitingTime++;
                if (cars[i].waitingTime >= MAX_WAITING_TIME) {
                    cars[i].position = 0;
                    cars[i].waitingTime = 0;
                }
            }
        } else {
            cars[i].position = 0;
        }
    }
}

void simulateTraffic(int duration) {
    int i;
    srand(time(NULL));
    initCars();
    initRoads();

    printf("Simulating traffic for %d seconds...\n", duration);

    while (duration-- > 0) {
        moveCars();
        printf("\r");
        for (i = 0; i < MAX_ROADS; i++) {
            int j;
            for (j = 0; j < roads[i].length; j++) {
                if (cars[i].position == j) {
                    printf("C");
                } else {
                    printf(".");
                }
            }
            printf(" ");
        }
        fflush(stdout);
        usleep(100000);
    }

    printf("\n");
}

int main(int argc, char *argv[]) {
    int duration;

    if (argc < 2) {
        duration = 10;
    } else {
        duration = atoi(argv[1]);
    }

    simulateTraffic(duration);

    return 0;
}