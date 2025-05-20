//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
    int speed;
} Vehicle;

void print_vehicle(Vehicle *vehicle) {
    printf("(x=%d, y=%d, speed=%d)\n", vehicle->x, vehicle->y, vehicle->speed);
}

void move_vehicle(Vehicle *vehicle, int delta_time) {
    vehicle->x += vehicle->speed * delta_time;
    vehicle->y += vehicle->speed * delta_time;
}

int main() {
    srand(time(NULL));
    
    Vehicle *vehicles[100];
    int num_vehicles = 10;
    
    for (int i = 0; i < num_vehicles; i++) {
        vehicles[i] = (Vehicle *)malloc(sizeof(Vehicle));
        vehicles[i]->x = rand() % 1000;
        vehicles[i]->y = rand() % 1000;
        vehicles[i]->speed = (rand() % 100) + 10;
        printf("Added vehicle %d: (%d, %d, %d)\n", i+1, vehicles[i]->x, vehicles[i]->y, vehicles[i]->speed);
    }
    
    int delta_time = 0.1;
    int total_time = 60;
    
    for (int t = 0; t < total_time; t++) {
        for (int i = 0; i < num_vehicles; i++) {
            move_vehicle(vehicles[i], delta_time);
            
            for (int j = 0; j < num_vehicles; j++) {
                if (i!= j) {
                    int dx = vehicles[i]->x - vehicles[j]->x;
                    int dy = vehicles[i]->y - vehicles[j]->y;
                    double dist = sqrt(dx * dx + dy * dy);
                    
                    if (dist < 100) {
                        printf("Collision between vehicles %d and %d at (%d, %d)\n", i+1, j+1, vehicles[i]->x, vehicles[i]->y);
                    }
                }
            }
        }
        
        delta_time += 0.1;
    }
    
    return 0;
}