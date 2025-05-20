//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int speed;
} Vehicle;

int main() {
    int numVehicles = 10;
    int maxSpeed = 100;
    int roadLength = 1000;
    int maxVehicles = 100;
    int crash = 0;

    srand(time(NULL));

    Vehicle* vehicles = (Vehicle*)malloc(numVehicles * sizeof(Vehicle));

    for (int i = 0; i < numVehicles; i++) {
        vehicles[i].x = rand() % roadLength;
        vehicles[i].y = rand() % roadLength;
        vehicles[i].speed = rand() % maxSpeed + 1;
    }

    while (crash < maxVehicles) {
        for (int i = 0; i < numVehicles; i++) {
            int x1 = vehicles[i].x;
            int y1 = vehicles[i].y;
            int speed1 = vehicles[i].speed;

            for (int j = i + 1; j < numVehicles; j++) {
                int x2 = vehicles[j].x;
                int y2 = vehicles[j].y;
                int speed2 = vehicles[j].speed;

                if (speed1 < speed2) {
                    int distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

                    if (distance > 0) {
                        int time = distance / speed1;
                        int time2 = distance / speed2;

                        if (time < time2) {
                            vehicles[i].x = x2;
                            vehicles[i].y = y2;
                            vehicles[i].speed = speed2;
                        }
                    }
                }
            }
        }

        crash++;
    }

    printf("Number of crashes: %d\n", crash);

    for (int i = 0; i < numVehicles; i++) {
        printf("Vehicle %d: (%d, %d), speed: %d\n", i, vehicles[i].x, vehicles[i].y, vehicles[i].speed);
    }

    free(vehicles);

    return 0;
}