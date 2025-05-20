//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    GREEN,
    YELLOW,
    RED
} LightState;

typedef struct {
    LightState state;
    int count;
} TrafficLight;

TrafficLight* createTrafficLight(int count) {
    TrafficLight* light = (TrafficLight*) malloc(sizeof(TrafficLight));
    light->state = GREEN;
    light->count = count;
    return light;
}

void displayState(TrafficLight* light) {
    printf("Light State: %d\n", light->state);
}

void updateState(TrafficLight* light) {
    if (light->count > 0) {
        if (light->state == GREEN) {
            light->state = YELLOW;
            light->count--;
        } else if (light->state == YELLOW) {
            light->state = RED;
            light->count--;
        } else if (light->state == RED) {
            light->state = GREEN;
            light->count--;
        }
    }
}

void freeTrafficLight(TrafficLight* light) {
    free(light);
}

int main() {
    int count = 5;
    TrafficLight* trafficLight = createTrafficLight(count);
    displayState(trafficLight);
    updateState(trafficLight);
    printf("Count: %d\n", trafficLight->count);
    freeTrafficLight(trafficLight);
    return 0;
}