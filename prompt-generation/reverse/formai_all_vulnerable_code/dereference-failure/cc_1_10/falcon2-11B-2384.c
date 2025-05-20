//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    int speed;
} Car;

int main() {
    // Initialize cars
    Car* cars = malloc(10 * sizeof(Car));
    for (int i = 0; i < 10; i++) {
        cars[i].x = rand() % 1000;
        cars[i].y = rand() % 1000;
        cars[i].speed = rand() % 100;
    }

    // Simulate traffic flow
    int time = 0;
    while (time < 10000) {
        // Update car positions
        for (int i = 0; i < 10; i++) {
            int dx = (cars[i].speed * 10) % 1000;
            int dy = (cars[i].speed * 10) % 1000;
            cars[i].x += dx;
            cars[i].y += dy;
        }

        // Check for collisions
        for (int i = 0; i < 10; i++) {
            for (int j = i + 1; j < 10; j++) {
                if (abs(cars[i].x - cars[j].x) < 5 && abs(cars[i].y - cars[j].y) < 5) {
                    printf("Collision at (%d, %d)\n", cars[i].x, cars[i].y);
                    break;
                }
            }
        }

        // Update time
        time++;
    }

    // Free memory
    free(cars);

    return 0;
}