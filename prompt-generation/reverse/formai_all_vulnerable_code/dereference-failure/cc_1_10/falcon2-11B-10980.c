//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_CARS 100

typedef struct {
    int id;
    int current_lane;
    int current_speed;
} Car;

typedef struct {
    Car* cars;
    int num_cars;
} Queue;

Queue createQueue() {
    Queue q;
    q.cars = malloc(MAX_NUM_CARS * sizeof(Car));
    q.num_cars = 0;
    return q;
}

void enqueue(Queue* q, Car c) {
    q->cars[q->num_cars++] = c;
}

Car dequeue(Queue* q) {
    if (q->num_cars == 0) {
        return *q->cars;
    }
    Car c = q->cars[0];
    q->cars[0] = q->cars[--q->num_cars];
    return c;
}

int main() {
    srand(time(NULL));

    Queue q = createQueue();

    Car car;
    int num_lanes = 4;
    int num_cars_per_lane = 25;

    for (int i = 0; i < num_lanes; i++) {
        car.id = i;
        car.current_lane = i;
        car.current_speed = rand() % num_cars_per_lane + 1;
        enqueue(&q, car);
    }

    printf("Initial traffic flow: ");
    for (int i = 0; i < q.num_cars; i++) {
        printf("%d ", q.cars[i].id);
    }
    printf("\n");

    for (int i = 0; i < 100; i++) {
        Car car = dequeue(&q);
        printf("Car %d moving to lane %d with speed %d\n", car.id, car.current_lane + 1, car.current_speed);
        car.current_lane = (car.current_lane + 1) % num_lanes;
        car.current_speed = rand() % num_cars_per_lane + 1;
        enqueue(&q, car);
    }

    printf("Final traffic flow: ");
    for (int i = 0; i < q.num_cars; i++) {
        printf("%d ", q.cars[i].id);
    }
    printf("\n");

    return 0;
}