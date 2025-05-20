//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 60
#define MIN_SPEED 20
#define MAX_CARS 20
#define MAX_LANE_LENGTH 50

typedef struct {
    int speed;
    int position;
} Car;

void move_car(Car *car, int distance) {
    car->position += distance;
    if (car->position > MAX_LANE_LENGTH) {
        car->position = MAX_LANE_LENGTH;
        car->speed = 0;
    }
}

void print_lane(Car *lane[], int num_cars) {
    printf("Lane status:\n");
    for (int i=0; i<MAX_LANE_LENGTH+1; i++) {
        if (i == 0 || i == MAX_LANE_LENGTH) {
            printf("|");
        } else {
            printf("-");
        }
    }
    printf("\n");

    for (int i=0; i<num_cars; i++) {
        printf("%*s%d\n", lane[i]->position, "", i);
    }
}

int main() {
    srand(time(NULL));
    int num_cars = rand() % MAX_CARS + 1;
    Car *lane[num_cars];

    for (int i=0; i<num_cars; i++) {
        Car *car = malloc(sizeof(Car));
        car->speed = rand() % (MAX_SPEED-MIN_SPEED+1) + MIN_SPEED;
        car->position = i*3;

        lane[i] = car;
    }

    print_lane(lane, num_cars);

    while (1) {
        for (int i=0; i<num_cars; i++) {
            Car *car = lane[i];
            int next_car_pos = MAX_LANE_LENGTH+1;
            for (int j=0; j<num_cars; j++) {
                if (i == j) {
                    continue;
                }
                if (lane[j]->position > car->position) {
                    next_car_pos = lane[j]->position;
                    break;
                }
            }
            int distance = next_car_pos - car->position - 1;
            if (distance <= car->speed) {
                car->speed = distance;
            }
            move_car(car, car->speed);
        }
        print_lane(lane, num_cars);
        printf("\n");
        getchar();
    }
    return 0;
}