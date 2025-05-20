//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the traffic light structure
typedef struct TrafficLight {
    int current_state;
    int next_state;
    struct TrafficLight* next_light;
} TrafficLight;

// Define the traffic flow simulation function
void traffic_flow(TrafficLight* head) {
    // Iterate over the traffic lights and update their states
    TrafficLight* current_light = head;
    while (current_light) {
        switch (current_light->current_state) {
            case 0:
                current_light->current_state = 1;
                current_light->next_light->current_state = 2;
                break;
            case 1:
                current_light->current_state = 2;
                current_light->next_light->current_state = 0;
                break;
            case 2:
                current_light->current_state = 0;
                current_light->next_light->current_state = 1;
                break;
        }
        current_light = current_light->next_light;
    }

    // Print the traffic light states
    current_light = head;
    while (current_light) {
        switch (current_light->current_state) {
            case 0:
                printf("Red\n");
                break;
            case 1:
                printf("Yellow\n");
                break;
            case 2:
                printf("Green\n");
                break;
        }
        current_light = current_light->next_light;
    }
}

int main() {
    // Create a traffic light structure
    TrafficLight* head = malloc(sizeof(TrafficLight));
    head->current_state = 0;
    head->next_state = 1;
    head->next_light = malloc(sizeof(TrafficLight));
    head->next_light->current_state = 1;
    head->next_light->next_state = 2;
    head->next_light->next_light = malloc(sizeof(TrafficLight));
    head->next_light->next_light->current_state = 2;
    head->next_light->next_light->next_state = 0;

    // Simulate traffic flow
    traffic_flow(head);

    return 0;
}