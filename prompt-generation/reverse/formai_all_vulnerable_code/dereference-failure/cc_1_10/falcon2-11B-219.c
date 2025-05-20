//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int road_capacity;
    int speed_limit;
    int num_lanes;
    int num_intersections;
    int num_pedestrian_crossings;
} Road;

typedef struct {
    int start_time;
    int end_time;
    int num_cars;
} TrafficLight;

typedef struct {
    int start_time;
    int end_time;
    int num_cars;
} PedestrianCrossing;

typedef struct {
    Road* roads;
    TrafficLight* traffic_lights;
    PedestrianCrossing* pedestrian_crossings;
    int num_roads;
    int num_traffic_lights;
    int num_pedestrian_crossings;
} Simulation;

void initialize_simulation(Simulation* sim, int num_roads, int num_traffic_lights, int num_pedestrian_crossings) {
    sim->roads = malloc(num_roads * sizeof(Road));
    sim->traffic_lights = malloc(num_traffic_lights * sizeof(TrafficLight));
    sim->pedestrian_crossings = malloc(num_pedestrian_crossings * sizeof(PedestrianCrossing));
    srand(time(NULL));
    
    for (int i = 0; i < num_roads; i++) {
        Road* road = &sim->roads[i];
        road->road_capacity = rand() % 100 + 100;
        road->speed_limit = rand() % 100 + 100;
        road->num_lanes = rand() % 10 + 1;
        road->num_intersections = rand() % 5 + 1;
        road->num_pedestrian_crossings = rand() % 10 + 1;
    }
    
    for (int i = 0; i < num_traffic_lights; i++) {
        TrafficLight* traffic_light = &sim->traffic_lights[i];
        traffic_light->start_time = rand() % 100 + 1;
        traffic_light->end_time = rand() % 100 + 1;
        traffic_light->num_cars = rand() % 100 + 100;
    }
    
    for (int i = 0; i < num_pedestrian_crossings; i++) {
        PedestrianCrossing* pedestrian_crossing = &sim->pedestrian_crossings[i];
        pedestrian_crossing->start_time = rand() % 100 + 1;
        pedestrian_crossing->end_time = rand() % 100 + 1;
        pedestrian_crossing->num_cars = rand() % 100 + 100;
    }
}

void run_simulation(Simulation* sim) {
    for (int i = 0; i < sim->num_roads; i++) {
        Road* road = &sim->roads[i];
        int num_cars = 0;
        int car_speed = 0;
        
        while (num_cars < road->road_capacity) {
            int time = rand() % 100 + 1;
            int distance = rand() % 100 + 1;
            
            car_speed = (distance / time) * road->speed_limit;
            
            if (car_speed > 0) {
                printf("Car %d at position %d, speed %d\n", num_cars + 1, distance, car_speed);
                num_cars++;
            }
        }
    }
    
    for (int i = 0; i < sim->num_traffic_lights; i++) {
        TrafficLight* traffic_light = &sim->traffic_lights[i];
        int time = 0;
        
        while (time < traffic_light->end_time) {
            int num_cars = rand() % traffic_light->num_cars;
            
            if (num_cars > 0) {
                printf("Traffic light %d, %d cars waiting\n", i + 1, num_cars);
            }
            
            time++;
        }
    }
    
    for (int i = 0; i < sim->num_pedestrian_crossings; i++) {
        PedestrianCrossing* pedestrian_crossing = &sim->pedestrian_crossings[i];
        int time = 0;
        
        while (time < pedestrian_crossing->end_time) {
            int num_cars = rand() % pedestrian_crossing->num_cars;
            
            if (num_cars > 0) {
                printf("Pedestrian crossing %d, %d cars waiting\n", i + 1, num_cars);
            }
            
            time++;
        }
    }
}

int main() {
    int num_roads = 10;
    int num_traffic_lights = 5;
    int num_pedestrian_crossings = 10;
    
    Simulation sim;
    initialize_simulation(&sim, num_roads, num_traffic_lights, num_pedestrian_crossings);
    run_simulation(&sim);
    
    return 0;
}