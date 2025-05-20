//Gemma-7B DATASET v1.0 Category: Traffic Light Controller ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the traffic light controller structure
typedef struct TrafficLightController {
    int current_state;
    int next_state;
    int timer;
} TrafficLightController;

// Create a traffic light controller
TrafficLightController* create_traffic_light_controller() {
    TrafficLightController* controller = (TrafficLightController*)malloc(sizeof(TrafficLightController));
    controller->current_state = 0;
    controller->next_state = 1;
    controller->timer = 0;
    return controller;
}

// Update the traffic light controller
void update_traffic_light_controller(TrafficLightController* controller) {
    controller->timer++;
    if (controller->timer >= controller->next_state) {
        controller->current_state = controller->next_state;
        controller->next_state++;
        controller->timer = 0;
    }
}

// Get the current state of the traffic light controller
int get_current_state(TrafficLightController* controller) {
    return controller->current_state;
}

int main() {
    TrafficLightController* controller = create_traffic_light_controller();

    // Simulate traffic light controller for 10 iterations
    for (int i = 0; i < 10; i++) {
        update_traffic_light_controller(controller);
        switch (get_current_state(controller)) {
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
    }

    return 0;
}