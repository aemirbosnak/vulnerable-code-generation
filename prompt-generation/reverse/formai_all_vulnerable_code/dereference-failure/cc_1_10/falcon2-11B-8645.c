//Falcon2-11B DATASET v1.0 Category: Traffic Light Controller ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GREEN_LIGHT 0
#define RED_LIGHT 1
#define YELLOW_LIGHT 2

#define MAX_LIGHT_STATE 3

typedef struct {
    int state;
    int light;
    int duration;
    int time_remaining;
} LightState;

void update_light(LightState *light_state, int duration) {
    switch (light_state->state) {
        case GREEN_LIGHT:
            light_state->light = RED_LIGHT;
            light_state->time_remaining = duration;
            break;
        case RED_LIGHT:
            light_state->light = GREEN_LIGHT;
            light_state->time_remaining = duration;
            break;
        case YELLOW_LIGHT:
            light_state->light = RED_LIGHT;
            light_state->time_remaining = duration;
            break;
        default:
            break;
    }
}

void print_light_state(LightState *light_state) {
    printf("State: %d, Light: %d, Time Remaining: %d\n", light_state->state, light_state->light, light_state->time_remaining);
}

int main() {
    LightState light_state[MAX_LIGHT_STATE];
    int duration = 5;
    int i;

    srand(time(NULL));

    for (i = 0; i < MAX_LIGHT_STATE; i++) {
        light_state[i].state = GREEN_LIGHT;
        light_state[i].light = GREEN_LIGHT;
        light_state[i].duration = duration;
        light_state[i].time_remaining = duration;
    }

    while (1) {
        int light_index = rand() % MAX_LIGHT_STATE;
        LightState *light_state = &light_state[light_index];

        update_light(light_state, duration);

        if (light_state->time_remaining <= 0) {
            light_state->time_remaining = duration;
            update_light(light_state, duration);
        }

        print_light_state(light_state);

        usleep(duration * 1000);
    }

    return 0;
}