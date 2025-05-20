//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRAFFIC_LIGHT_TIME 5

// Define the traffic light structure
typedef struct TrafficLight {
    int current_state;
    int timer;
    int next_state;
} TrafficLight;

// Define the traffic flow structure
typedef struct TrafficFlow {
    TrafficLight **lights;
    int current_direction;
    int next_direction;
} TrafficFlow;

// Create a traffic flow object
TrafficFlow *create_traffic_flow() {
    TrafficFlow *flow = malloc(sizeof(TrafficFlow));

    flow->lights = malloc(sizeof(TrafficLight *) * 3);
    flow->lights[0] = malloc(sizeof(TrafficLight));
    flow->lights[1] = malloc(sizeof(TrafficLight));
    flow->lights[2] = malloc(sizeof(TrafficLight));

    flow->current_direction = 0;
    flow->next_direction = 1;

    return flow;
}

// Simulate traffic flow
void simulate_traffic_flow(TrafficFlow *flow) {
    for (int i = 0; i < MAX_TRAFFIC_LIGHT_TIME; i++) {
        switch (flow->lights[flow->current_direction]->current_state) {
            case 0:
                flow->lights[flow->current_direction]->current_state = 1;
                flow->lights[flow->next_direction]->current_state = 2;
                break;
            case 1:
                flow->lights[flow->current_direction]->current_state = 2;
                flow->lights[flow->next_direction]->current_state = 0;
                break;
            case 2:
                flow->lights[flow->current_direction]->current_state = 0;
                flow->lights[flow->next_direction]->current_state = 1;
                break;
        }

        flow->current_direction = flow->next_direction;
        flow->next_direction = (flow->next_direction + 1) % 3;

        printf("Current direction: %d, Current state: %d\n", flow->current_direction, flow->lights[flow->current_direction]->current_state);
    }
}

int main() {
    TrafficFlow *flow = create_traffic_flow();
    simulate_traffic_flow(flow);

    return 0;
}