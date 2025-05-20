//GEMINI-pro DATASET v1.0 Category: Traffic Flow Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Road segment data structure
typedef struct RoadSegment {
    int length;      // Length of the road segment in meters
    int speed_limit; // Speed limit in kilometers per hour
    int num_lanes;   // Number of lanes in the road segment
    int num_cars;    // Number of cars currently in the road segment
    int max_cars;    // Maximum number of cars that can fit in the road segment
    int arrival_rate; // Average number of cars arriving per minute
    int departure_rate; // Average number of cars departing per minute
} RoadSegment;

// Traffic light data structure
typedef struct TrafficLight {
    int state;       // Current state of the traffic light (0 = red, 1 = green, 2 = yellow)
    int change_time; // Time in seconds until the traffic light changes state
} TrafficLight;

// Create a new road segment
RoadSegment* create_road_segment(int length, int speed_limit, int num_lanes, int arrival_rate, int departure_rate) {
    RoadSegment* segment = (RoadSegment*)malloc(sizeof(RoadSegment));
    segment->length = length;
    segment->speed_limit = speed_limit;
    segment->num_lanes = num_lanes;
    segment->num_cars = 0;
    segment->max_cars = num_lanes * length / 10; // Assuming each car is 10 meters long
    segment->arrival_rate = arrival_rate;
    segment->departure_rate = departure_rate;
    return segment;
}

// Create a new traffic light
TrafficLight* create_traffic_light() {
    TrafficLight* light = (TrafficLight*)malloc(sizeof(TrafficLight));
    light->state = 0;
    light->change_time = 60; // Default to 60 seconds per cycle
    return light;
}

// Update the state of the traffic light
void update_traffic_light(TrafficLight* light) {
    light->change_time--;
    if (light->change_time <= 0) {
        light->state = (light->state + 1) % 3;
        light->change_time = 60;
    }
}

// Update the state of the road segment
void update_road_segment(RoadSegment* segment, TrafficLight* light) {
    // Update the number of cars in the segment
    segment->num_cars += segment->arrival_rate - segment->departure_rate;
    if (segment->num_cars > segment->max_cars) {
        segment->num_cars = segment->max_cars;
    }
    if (segment->num_cars < 0) {
        segment->num_cars = 0;
    }

    // Update the speed of the cars in the segment
    int speed = segment->speed_limit;
    if (light->state == 0) {
        speed = 0;
    } else if (light->state == 1) {
        if (segment->num_cars > segment->max_cars / 2) {
            speed /= 2;
        }
    }
    segment->speed_limit = speed;
}

// Print the state of the traffic simulation
void print_traffic_simulation(RoadSegment* segments, TrafficLight* lights, int num_segments) {
    printf("Traffic Simulation\n");
    for (int i = 0; i < num_segments; i++) {
        printf("Segment %d:\n", i);
        printf("    Length: %d meters\n", segments[i].length);
        printf("    Speed limit: %d km/h\n",
segments[i].speed_limit);
        printf("    Number of lanes: %d\n", segments[i].num_lanes);
        printf("    Number of cars: %d\n", segments[i].num_cars);
        printf("    Max number of cars: %d\n", segments[i].max_cars);
        printf("    Arrival rate: %d cars/minute\n", segments[i].arrival_rate);
        printf("    Departure rate: %d cars/minute\n", segments[i].departure_rate);
    }
    for (int i = 0; i < num_segments - 1; i++) {
        printf("Traffic Light %d:\n", i);
        printf("    State: %d\n", lights[i].state);
        printf("    Change time: %d seconds\n", lights[i].change_time);
    }
}

// Main function
int main() {
    // Create the road segments
    RoadSegment segments[3];
    segments[0] = *create_road_segment(1000, 60, 2, 10, 5);
    segments[1] = *create_road_segment(500, 50, 3, 15, 10);
    segments[2] = *create_road_segment(1500, 70, 4, 20, 15);

    // Create the traffic lights
    TrafficLight lights[2];
    lights[0] = *create_traffic_light();
    lights[1] = *create_traffic_light();

    // Run the simulation for 1000 seconds
    for (int i = 0; i < 1000; i++) {
        // Update the traffic lights
        for (int j = 0; j < 2; j++) {
            update_traffic_light(&lights[j]);
        }

        // Update the road segments
        for (int j = 0; j < 3; j++) {
            update_road_segment(&segments[j], &lights[j]);
        }

        // Print the state of the simulation
        print_traffic_simulation(segments, lights, 3);
    }

    return 0;
}