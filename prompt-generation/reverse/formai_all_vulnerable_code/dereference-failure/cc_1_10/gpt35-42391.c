//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 60 // Maximum car speed in mph
#define LANE_LENGTH 1000 // Length of one lane in feet
#define MAX_CARS 100 // Maximum number of cars on one lane
#define LIGHT_INTERVAL 60 // Traffic light interval in seconds
#define SIM_TIME 3600 // Length of simulation in seconds

typedef struct car_t
{
    int id;
    int lane;
    float speed;
    float position;
} Car;

void move_car(Car* car, int time_diff);
void print_cars(Car* lanes[]);
void add_car(Car* lanes[]);
void simulate_traffic(Car* lanes[]);

int main()
{
    srand(time(NULL));
    Car* lanes[3];
    for (int i = 0; i < 3; i++)
    {
        lanes[i] = malloc(MAX_CARS * sizeof(Car));
        for (int j = 0; j < MAX_CARS; j++)
        {
            lanes[i][j].id = -1;
        }
    }
    simulate_traffic(lanes);
    return 0;
}

void simulate_traffic(Car* lanes[])
{
    int time_diff;
    int current_time = 0;
    int light_timer = 0;
    while (current_time < SIM_TIME)
    {
        time_diff = rand() % 10 + 1; // Generate random time difference between 1 and 10 (in seconds)
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < MAX_CARS; j++)
            {
                if (lanes[i][j].id != -1)
                {
                    move_car(&lanes[i][j], time_diff);
                }
            }
        }
        light_timer += time_diff;
        if (light_timer >= LIGHT_INTERVAL)
        {
            // Switch traffic light
            printf("\nTraffic light switched.\n");
            light_timer = 0;
        }
        print_cars(lanes);
        add_car(lanes);
        current_time += time_diff;
    }
}

void add_car(Car* lanes[])
{
    // Add car to random lane, if there is space
    int lane_index = rand() % 3;
    for (int i = 0; i < MAX_CARS; i++)
    {
        if (lanes[lane_index][i].id == -1)
        {
            Car car;
            car.id = rand() % 10000;
            car.lane = lane_index;
            car.speed = (float)(rand() % MAX_SPEED + 1);
            car.position = (float)(i * 10);
            lanes[lane_index][i] = car;
            break;
        }
    }
}

void move_car(Car* car, int time_diff)
{
    if (car->position + time_diff * car->speed / 60.0f > LANE_LENGTH)
    {
        car->id = -1; // Car has left the lane
    }
    else
    {
        car->position += time_diff * car->speed / 60.0f;
    }
}

void print_cars(Car* lanes[])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Lane %d: ", i);
        for (int j = 0; j < MAX_CARS; j++)
        {
            if (lanes[i][j].id != -1)
            {
                printf("%.2f ", lanes[i][j].position);
            }
        }
        printf("\n");
    }
}