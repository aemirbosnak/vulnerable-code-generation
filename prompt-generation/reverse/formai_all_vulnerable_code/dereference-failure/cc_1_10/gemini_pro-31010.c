//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

typedef struct car {
    int id;
    int speed;
    int position;
} car;

typedef struct lane {
    int length;
    int num_cars;
    car *cars;
} lane;

typedef struct road {
    int num_lanes;
    lane *lanes;
} road;

void init_road(road *r, int num_lanes, int lane_length) {
    r->num_lanes = num_lanes;
    r->lanes = malloc(sizeof(lane) * num_lanes);
    for (int i = 0; i < num_lanes; i++) {
        r->lanes[i].length = lane_length;
        r->lanes[i].num_cars = 0;
        r->lanes[i].cars = NULL;
    }
}

void add_car(road *r, int lane, int speed) {
    lane--;
    if (r->lanes[lane].num_cars == r->lanes[lane].length) {
        printf("Lane is full!\n");
        return;
    }
    r->lanes[lane].cars = realloc(r->lanes[lane].cars, sizeof(car) * (r->lanes[lane].num_cars + 1));
    r->lanes[lane].cars[r->lanes[lane].num_cars].id = rand() % 1000;
    r->lanes[lane].cars[r->lanes[lane].num_cars].speed = speed;
    r->lanes[lane].cars[r->lanes[lane].num_cars].position = 0;
    r->lanes[lane].num_cars++;
}

void remove_car(road *r, int lane, int car_id) {
    lane--;
    for (int i = 0; i < r->lanes[lane].num_cars; i++) {
        if (r->lanes[lane].cars[i].id == car_id) {
            for (int j = i + 1; j < r->lanes[lane].num_cars; j++) {
                r->lanes[lane].cars[j - 1] = r->lanes[lane].cars[j];
            }
            r->lanes[lane].num_cars--;
            r->lanes[lane].cars = realloc(r->lanes[lane].cars, sizeof(car) * r->lanes[lane].num_cars);
            return;
        }
    }
    printf("Car not found!\n");
}

void update_road(road *r) {
    for (int i = 0; i < r->num_lanes; i++) {
        for (int j = 0; j < r->lanes[i].num_cars; j++) {
            r->lanes[i].cars[j].position += r->lanes[i].cars[j].speed;
            if (r->lanes[i].cars[j].position >= r->lanes[i].length) {
                remove_car(r, i + 1, r->lanes[i].cars[j].id);
            }
        }
    }
}

void print_road(road *r) {
    for (int i = 0; i < r->num_lanes; i++) {
        printf("Lane %d: ", i + 1);
        for (int j = 0; j < r->lanes[i].num_cars; j++) {
            printf("%d ", r->lanes[i].cars[j].id);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    road r;
    init_road(&r, 3, 10);
    add_car(&r, 1, 5);
    add_car(&r, 2, 7);
    add_car(&r, 3, 3);
    add_car(&r, 1, 4);
    add_car(&r, 2, 6);
    add_car(&r, 3, 2);
    print_road(&r);
    update_road(&r);
    print_road(&r);
    remove_car(&r, 1, 5);
    print_road(&r);
    return 0;
}