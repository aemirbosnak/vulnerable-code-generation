//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_lanes = 3;
    int num_cars = 5;
    int current_lane = 0;
    int target_lane = 0;
    int speed = 0;
    int i;

    // Create a 2D array to store the positions of the cars
    int **positions = (int **)malloc(num_cars * sizeof(int *));
    for (i = 0; i < num_cars; i++)
    {
        positions[i] = (int *)malloc(num_lanes * sizeof(int));
    }

    // Initialize the positions of the cars
    for (i = 0; i < num_cars; i++)
    {
        positions[i][current_lane] = 1;
    }

    // Simulate traffic flow
    for (i = 0; i < 100; i++)
    {
        // Update the target lane for each car
        for (i = 0; i < num_cars; i++)
        {
            target_lane = rand() % num_lanes;
        }

        // Move the cars to their target lanes
        for (i = 0; i < num_cars; i++)
        {
            if (positions[i][current_lane] == 1)
            {
                speed = rand() % 5 + 1;
                current_lane = target_lane;
                positions[i][current_lane] = 1;
            }
        }

        // Print the positions of the cars
        for (i = 0; i < num_cars; i++)
        {
            for (int j = 0; j < num_lanes; j++)
            {
                printf("%d ", positions[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}