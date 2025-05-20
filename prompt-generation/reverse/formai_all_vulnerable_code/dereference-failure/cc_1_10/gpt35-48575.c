//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARS 20
#define MAX_SPEED 10
#define MAX_DISTANCE 100
#define MIN_SPEED 1 

typedef struct Car {
    char name[10];
    int speed;
    int distance;
    int ID;
} Car;

typedef struct Road {
    int length;
    Car* cars[100];
} Road;

int RandInt(int max) {
    return (rand() % max);
}

void PrintRoad(Road* r) {
    for (int i = 0; i < r->length; i++) {
        if (r->cars[i] != NULL) {
            printf("%s  ", r->cars[i]->name);
        } else {
            printf("-  ");
        }
    }
    printf("\n");
}

void MoveCar(Road* r, int index) {
    Car* car = r->cars[index];
    int new_dis = car->distance + car->speed;
    if (new_dis >= r->length) {
        r->cars[index] = NULL;
        free(car);
    } else {
        r->cars[index] = NULL;
        r->cars[new_dis] = car;
        car->distance = new_dis;
    }
}

int CanMove(Road* r, int index) {
    if (r->cars[index]->distance + r->cars[index]->speed >= r->length) {
        return 1;
    }
    for (int i = r->cars[index]->distance + 1; i < r->cars[index]->distance + r->cars[index]->speed + 1; i++) {
        if (r->cars[i] != NULL) {
            return 0;
        }
    }
    return 1;
}

void Simulate(Road* r) {
    for (int i = 0; i < r->length; i++) {
        if (r->cars[i] != NULL && CanMove(r, i)) {
            MoveCar(r, i);
        } else if (r->cars[i] == NULL && RandInt(10) > 7) {
            Car* c = (Car*)malloc(sizeof(Car));
            sprintf(c->name, "Car%d", c->ID + 1);
            c->speed = RandInt(MAX_SPEED) + MIN_SPEED;
            c->distance = i;
            c->ID++;
            r->cars[i] = c;
        }
    }
}

int main() {
    srand(time(NULL));
    Road* r = (Road*)malloc(sizeof(Road));
    r->length = MAX_DISTANCE;
    for (int i = 0; i < r->length; i++) {
        r->cars[i] = NULL;
    }
    int steps = 0;
    while (1) {
        system("cls");
        Simulate(r);
        PrintRoad(r);
        steps++;
        printf("Steps: %d\n", steps);
        getchar();
    }
    return 0;
}