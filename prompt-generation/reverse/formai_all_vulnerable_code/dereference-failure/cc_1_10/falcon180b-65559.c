//Falcon-180B DATASET v1.0 Category: Traffic Light Controller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define GREEN_TIME 10
#define YELLOW_TIME 3
#define RED_TIME 20
#define TOTAL_TIME (GREEN_TIME + YELLOW_TIME + RED_TIME)

void green_light(int duration) {
    printf("Green light on for %d seconds\n", duration);
    sleep(duration);
}

void yellow_light(int duration) {
    printf("Yellow light on for %d seconds\n", duration);
    sleep(duration);
}

void red_light(int duration) {
    printf("Red light on for %d seconds\n", duration);
    sleep(duration);
}

void traffic_light(int num_cycles) {
    for (int i = 0; i < num_cycles; i++) {
        green_light(GREEN_TIME);
        yellow_light(YELLOW_TIME);
        red_light(RED_TIME);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s num_cycles\n", argv[0]);
        return 1;
    }

    int num_cycles = atoi(argv[1]);
    srand(time(NULL));

    for (int i = 0; i < num_cycles; i++) {
        int green_duration = GREEN_TIME + rand() % (TOTAL_TIME - GREEN_TIME);
        int yellow_duration = YELLOW_TIME + rand() % (TOTAL_TIME - YELLOW_TIME);
        int red_duration = RED_TIME + rand() % (TOTAL_TIME - RED_TIME);

        printf("Cycle %d:\n", i+1);
        printf("Green light on for %d seconds\n", green_duration);
        green_light(green_duration);
        printf("Yellow light on for %d seconds\n", yellow_duration);
        yellow_light(yellow_duration);
        printf("Red light on for %d seconds\n", red_duration);
        red_light(red_duration);
        printf("\n");
    }

    return 0;
}