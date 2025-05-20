//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED_LIGHT_DURATION 10
#define YELLOW_LIGHT_DURATION 5
#define GREEN_LIGHT_DURATION 15

void traffic_light_controller(int duration) {
    printf("Traffic light controller started.\n");
    int current_duration = duration;

    while (current_duration > 0) {
        switch (current_duration) {
            case GREEN_LIGHT_DURATION:
                printf("Green light is on.\n");
                break;
            case YELLOW_LIGHT_DURATION:
                printf("Yellow light is on.\n");
                break;
            case RED_LIGHT_DURATION:
                printf("Red light is on.\n");
                break;
            default:
                printf("Invalid duration: %d\n", current_duration);
        }

        current_duration--;
        sleep(1);
    }

    printf("Traffic light controller stopped.\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <duration>\n", argv[0]);
        return 1;
    }

    int duration = atoi(argv[1]);
    if (duration <= 0) {
        printf("Invalid duration: %d\n", duration);
        return 1;
    }

    traffic_light_controller(duration);

    return 0;
}