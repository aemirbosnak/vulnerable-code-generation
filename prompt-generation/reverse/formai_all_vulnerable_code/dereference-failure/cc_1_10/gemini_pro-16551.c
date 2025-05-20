//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>

/* Declare the traffic light states. */
enum traffic_light_state {
    RED,
    YELLOW,
    GREEN
};

/* Declare the traffic light colors. */
enum traffic_light_color {
    RED_COLOR,
    YELLOW_COLOR,
    GREEN_COLOR
};

/* Declare the traffic light timing. */
struct traffic_light_timing {
    int red_time;
    int yellow_time;
    int green_time;
};

/* Declare the traffic light controller. */
struct traffic_light_controller {
    enum traffic_light_state state;
    enum traffic_light_color color;
    struct traffic_light_timing timing;
};

/* Create a new traffic light controller. */
struct traffic_light_controller *create_traffic_light_controller(struct traffic_light_timing timing) {
    struct traffic_light_controller *controller = malloc(sizeof(struct traffic_light_controller));
    controller->state = RED;
    controller->color = RED_COLOR;
    controller->timing = timing;
    return controller;
}

/* Destroy a traffic light controller. */
void destroy_traffic_light_controller(struct traffic_light_controller *controller) {
    free(controller);
}

/* Change the state of a traffic light controller. */
void change_traffic_light_state(struct traffic_light_controller *controller, enum traffic_light_state state) {
    controller->state = state;
    switch (state) {
        case RED:
            controller->color = RED_COLOR;
            break;
        case YELLOW:
            controller->color = YELLOW_COLOR;
            break;
        case GREEN:
            controller->color = GREEN_COLOR;
            break;
    }
}

/* Run a traffic light controller. */
void run_traffic_light_controller(struct traffic_light_controller *controller) {
    while (1) {
        switch (controller->state) {
            case RED:
                sleep(controller->timing.red_time);
                change_traffic_light_state(controller, YELLOW);
                break;
            case YELLOW:
                sleep(controller->timing.yellow_time);
                change_traffic_light_state(controller, GREEN);
                break;
            case GREEN:
                sleep(controller->timing.green_time);
                change_traffic_light_state(controller, RED);
                break;
        }
    }
}

/* Main function. */
int main(int argc, char **argv) {
    /* Create a traffic light timing. */
    struct traffic_light_timing timing = {
        .red_time = 10,
        .yellow_time = 5,
        .green_time = 15
    };

    /* Create a traffic light controller. */
    struct traffic_light_controller *controller = create_traffic_light_controller(timing);

    /* Run the traffic light controller. */
    run_traffic_light_controller(controller);

    /* Destroy the traffic light controller. */
    destroy_traffic_light_controller(controller);

    return 0;
}