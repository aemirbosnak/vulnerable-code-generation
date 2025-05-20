//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

#define RED 1
#define YELLOW 2
#define GREEN 3

volatile bool running = true;

void signal_handler(int signum) {
    running = false;
}

void set_light(int color) {
    switch(color) {
        case RED:
            printf("RED light.\n");
            break;
        case YELLOW:
            printf("YELLOW light.\n");
            break;
        case GREEN:
            printf("GREEN light.\n");
            break;
        default:
            break;
    }
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: ./traffic_light_controller <time>\n");
        exit(0);
    }

    srand(time(0));
    signal(SIGTERM, signal_handler);

    int time = atoi(argv[1]);
    int current_color = RED;

    printf("Starting traffic light controller.\n");

    while(running) {
        set_light(current_color);

        int wait_time = time + (rand() % time);

        while(wait_time > 0 && running) {
            printf("Waiting %d seconds...\n", wait_time);
            sleep(1);
            wait_time--;
        }

        switch(current_color) {
            case RED:
                current_color = GREEN;
                break;
            case GREEN:
                current_color = YELLOW;
                break;
            case YELLOW:
                current_color = RED;
                break;
            default:
                break;
        }
    }

    printf("Shutting down traffic light controller.\n");

    return 0;
}