//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 30
#define YELLOW_LIGHT_DURATION 10
#define GREEN_LIGHT_DURATION 40
#define TOTAL_LIGHT_DURATION (RED_LIGHT_DURATION + YELLOW_LIGHT_DURATION + GREEN_LIGHT_DURATION)

enum traffic_light_state {
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT
};

void initialize_traffic_light(enum traffic_light_state initial_state) {
    enum traffic_light_state current_state = initial_state;
    time_t start_time = time(NULL);
    while (1) {
        switch (current_state) {
            case RED_LIGHT:
                printf("The traffic light is red.\n");
                break;
            case YELLOW_LIGHT:
                printf("The traffic light is yellow.\n");
                break;
            case GREEN_LIGHT:
                printf("The traffic light is green.\n");
                break;
            default:
                break;
        }
        time_t current_time = time(NULL);
        if (current_time - start_time >= TOTAL_LIGHT_DURATION) {
            start_time = current_time;
            current_state = (current_state + 1) % 3;
        }
        sleep(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <initial_state>\n", argv[0]);
        return 1;
    }
    enum traffic_light_state initial_state = atoi(argv[1]);
    initialize_traffic_light(initial_state);
    return 0;
}