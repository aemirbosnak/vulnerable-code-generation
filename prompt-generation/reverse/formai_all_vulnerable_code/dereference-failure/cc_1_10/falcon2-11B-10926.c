//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int speed;
    int direction;
    int car_type;
} car;

typedef struct {
    int num_cars;
    car *cars;
} road;

void initialize_road(road *road_ptr, int num_cars, int car_type) {
    road_ptr->num_cars = num_cars;
    road_ptr->cars = (car *)malloc(num_cars * sizeof(car));
    
    int i;
    for (i = 0; i < num_cars; i++) {
        road_ptr->cars[i].name = (char *)malloc(20);
        road_ptr->cars[i].speed = 0;
        road_ptr->cars[i].direction = 0;
        road_ptr->cars[i].car_type = car_type;
    }
}

void update_car_speed(road *road_ptr, int car_idx) {
    car *car_ptr = &road_ptr->cars[car_idx];
    
    if (car_ptr->direction == 1) {
        car_ptr->speed += 10;
    } else {
        car_ptr->speed -= 10;
    }
    
    if (car_ptr->speed < 0) {
        car_ptr->speed = 0;
    }
}

void print_road(road *road_ptr) {
    int i;
    printf("Road: %d cars\n", road_ptr->num_cars);
    
    for (i = 0; i < road_ptr->num_cars; i++) {
        car *car_ptr = &road_ptr->cars[i];
        printf("Car %d: %s, Speed: %d, Direction: %d, Type: %d\n", i, car_ptr->name, car_ptr->speed, car_ptr->direction, car_ptr->car_type);
    }
}

int main() {
    road r;
    initialize_road(&r, 4, 1);
    
    char *names[] = {"Romeo", "Juliet", "Mercutio", "Tybalt"};
    int speeds[] = {0, 0, 0, 0};
    int directions[] = {1, 1, 1, 1};
    int car_types[] = {1, 1, 1, 1};
    
    int i;
    for (i = 0; i < 4; i++) {
        car *car_ptr = &r.cars[i];
        car_ptr->name = (char *)malloc(20);
        strcpy(car_ptr->name, names[i]);
        car_ptr->speed = speeds[i];
        car_ptr->direction = directions[i];
        car_ptr->car_type = car_types[i];
    }
    
    print_road(&r);
    
    while (1) {
        int i;
        for (i = 0; i < 4; i++) {
            update_car_speed(&r, i);
        }
        
        print_road(&r);
    }
    
    return 0;
}