//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_cars = 0;
    int num_lanes = 1;
    int max_speed = 60;

    printf("Welcome to the peaceful traffic simulator!\n");
    printf("The road has %d lane%s.\n", num_lanes, num_lanes == 1? "" : "s");
    printf("The maximum speed limit is %d mph.\n", max_speed);

    printf("Enter the number of cars to simulate: ");
    scanf("%d", &num_cars);

    int* cars = (int*)malloc(num_cars * sizeof(int));
    int* speeds = (int*)malloc(num_cars * sizeof(int));

    for (int i = 0; i < num_cars; i++) {
        printf("Enter the speed of car %d: ", i + 1);
        scanf("%d", &speeds[i]);
    }

    printf("Simulation started.\n");
    printf("Car 1 is now entering the road at %d mph.\n", speeds[0]);

    for (int i = 0; i < num_cars; i++) {
        if (i == 0) {
            printf("Car %d is now entering the road at %d mph.\n", i + 1, speeds[i]);
        } else {
            printf("Car %d is now driving at %d mph.\n", i + 1, speeds[i]);
        }

        // Simulate the traffic flow
        if (num_cars == i + 1) {
            printf("Car %d has reached its destination at %d mph.\n", i + 1, speeds[i]);
            num_cars--;
        } else {
            if (i < num_cars - 1) {
                int next_car_speed = speeds[i + 1];

                // Adjust the speed limit based on traffic density
                int traffic_density = num_cars / (num_lanes - 1);
                if (traffic_density > 0.5) {
                    next_car_speed -= max_speed * 0.5;
                    printf("Car %d's speed is adjusted to %d mph due to traffic.\n", i + 1, next_car_speed);
                }

                // Simulate the movement of cars
                int distance_to_move = next_car_speed / max_speed;
                int remaining_cars = num_cars - i;

                printf("Car %d is moving %d feet in %d seconds.\n", i + 1, distance_to_move, remaining_cars / distance_to_move);

                for (int j = 0; j < remaining_cars; j++) {
                    printf("Car %d is now driving at %d mph.\n", i + 1, speeds[i + 1]);
                }
            } else {
                printf("Car %d has reached its destination at %d mph.\n", i + 1, speeds[i]);
                break;
            }
        }
    }

    free(cars);
    free(speeds);

    printf("Simulation ended. Thank you for participating.\n");

    return 0;
}