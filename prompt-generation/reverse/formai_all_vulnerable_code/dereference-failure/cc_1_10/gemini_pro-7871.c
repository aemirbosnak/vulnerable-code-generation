//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_VEHICLES 100
#define MAX_ROAD_SEGMENTS 100

typedef struct {
    int id;
    int speed;
    int position;
    int destination;
} Vehicle;

typedef struct {
    int id;
    int length;
    int num_vehicles;
    Vehicle *vehicles;
} RoadSegment;

typedef struct {
    int num_vehicles;
    Vehicle *vehicles;
    int num_road_segments;
    RoadSegment *road_segments;
} TrafficSystem;

TrafficSystem *create_traffic_system(int num_vehicles, int num_road_segments) {
    TrafficSystem *system = malloc(sizeof(TrafficSystem));
    system->num_vehicles = num_vehicles;
    system->vehicles = malloc(sizeof(Vehicle) * num_vehicles);
    system->num_road_segments = num_road_segments;
    system->road_segments = malloc(sizeof(RoadSegment) * num_road_segments);
    return system;
}

void destroy_traffic_system(TrafficSystem *system) {
    free(system->vehicles);
    free(system->road_segments);
    free(system);
}

void initialize_vehicles(TrafficSystem *system) {
    for (int i = 0; i < system->num_vehicles; i++) {
        system->vehicles[i].id = i;
        system->vehicles[i].speed = rand() % 10 + 1;
        system->vehicles[i].position = 0;
        system->vehicles[i].destination = rand() % system->num_road_segments;
    }
}

void initialize_road_segments(TrafficSystem *system) {
    for (int i = 0; i < system->num_road_segments; i++) {
        system->road_segments[i].id = i;
        system->road_segments[i].length = rand() % 1000 + 1;
        system->road_segments[i].num_vehicles = 0;
        system->road_segments[i].vehicles = NULL;
    }
}

void update_traffic_system(TrafficSystem *system) {
    for (int i = 0; i < system->num_vehicles; i++) {
        Vehicle *vehicle = &system->vehicles[i];
        RoadSegment *segment = &system->road_segments[vehicle->destination];
        if (vehicle->position < segment->length) {
            vehicle->position += vehicle->speed;
            if (vehicle->position >= segment->length) {
                vehicle->position = segment->length;
                vehicle->destination++;
                if (vehicle->destination >= system->num_road_segments) {
                    vehicle->destination = 0;
                }
            }
        }
    }
}

void print_traffic_system(TrafficSystem *system) {
    for (int i = 0; i < system->num_road_segments; i++) {
        RoadSegment *segment = &system->road_segments[i];
        printf("Road Segment %d: ", segment->id);
        for (int j = 0; j < segment->num_vehicles; j++) {
            Vehicle *vehicle = &segment->vehicles[j];
            printf("%d ", vehicle->id);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int num_vehicles = 10;
    int num_road_segments = 5;

    TrafficSystem *system = create_traffic_system(num_vehicles, num_road_segments);
    initialize_vehicles(system);
    initialize_road_segments(system);

    for (int i = 0; i < 100; i++) {
        update_traffic_system(system);
        print_traffic_system(system);
        printf("\n");
    }

    destroy_traffic_system(system);

    return 0;
}