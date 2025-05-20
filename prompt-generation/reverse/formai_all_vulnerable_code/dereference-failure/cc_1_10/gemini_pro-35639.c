//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _car {
    double pos;  // position (meters)
    double vel;  // velocity (meters per second)
    double acc;  // acceleration (meters per second squared)
} car;

typedef struct _road {
    int length;  // length of the road (meters)
    int num_cars;  // number of cars on the road
    car *cars;  // array of cars on the road
} road;

road create_road(int length, int num_cars) {
    road r;
    r.length = length;
    r.num_cars = num_cars;
    r.cars = malloc(sizeof(car) * num_cars);
    
    for (int i = 0; i < num_cars; i++) {
        r.cars[i].pos = (double)i * length / (num_cars - 1);
        r.cars[i].vel = 0.0;
        r.cars[i].acc = 0.0;
    }
    return r;
}

void destroy_road(road r) {
    free(r.cars);
}

void update_road(road *r, double dt) {
    for (int i = 0; i < r->num_cars; i++) {
        car *c = &r->cars[i];
        c->vel += c->acc * dt;
        c->pos += c->vel * dt;
        
        // check if the car has reached the end of the road
        if (c->pos >= r->length) {
            c->pos -= r->length;
        }
    }
}

void draw_road(road *r) {
    for (int i = 0; i < r->num_cars; i++) {
        car *c = &r->cars[i];
        printf("|");
        for (int j = 0; j < (int)(c->pos / 2); j++) {
            printf(" ");
        }
        printf("C");
        for (int j = 0; j < (int)((r->length - c->pos) / 2); j++) {
            printf(" ");
        }
    }
    printf("|\n");
}

int main() {
    // create a road with 100 cars and a length of 1000 meters
    road r = create_road(1000, 100);
    
    // run the simulation for 100 seconds
    for (int i = 0; i < 100; i++) {
        // update the road
        update_road(&r, 0.1);
        
        // draw the road
        draw_road(&r);
    }
    
    // destroy the road
    destroy_road(r);
    
    return 0;
}