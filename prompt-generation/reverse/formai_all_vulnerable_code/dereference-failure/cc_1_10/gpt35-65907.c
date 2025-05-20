//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 20
#define MAX_CARS 30

int main() {
    int num_cars, i;
    int *speeds;
    float sim_time = 0;
    float avg_speed = 0;

    // Get user input for number of cars
    printf("Enter the number of cars (up to %d): ", MAX_CARS);
    scanf("%d", &num_cars);

    if (num_cars < 1 || num_cars > MAX_CARS) {
        printf("Invalid number of cars.\n");
        return 1;
    }

    // Create array of car speeds
    speeds = (int *) malloc(num_cars * sizeof(int));

    srand(time(0));

    // Initialize car speeds to random values between MIN_SPEED and MAX_SPEED
    for (i = 0; i < num_cars; i++) {
        speeds[i] = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
        printf("Car %d speed: %d km/h\n", i + 1, speeds[i]);
    }

    // Simulate traffic flow for 1 hour (60 minutes)
    while (sim_time < 60) {
        float distance = 0;

        // Calculate distance travelled by each car in this time step
        for (i = 0; i < num_cars; i++) {
            distance += speeds[i] / 60;
        }

        // Calculate average speed of all cars in this time step
        avg_speed = distance * 60 / num_cars;

        // Update car speeds based on traffic rules
        for (i = 0; i < num_cars; i++) {
            if (speeds[i] > avg_speed) {
                speeds[i] -= 5;
            } else if (speeds[i] < avg_speed) {
                speeds[i] += 5;
            }
            printf("Car %d speed: %d km/h\n", i + 1, speeds[i]);
        }

        sim_time += 1;
    }

    // Free memory allocated for speeds array
    free(speeds);

    printf("Simulation complete. Average speed: %.2f km/h\n", avg_speed);

    return 0;
}