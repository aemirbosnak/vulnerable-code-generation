//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the states of the traffic light
typedef enum {
    RED,
    YELLOW,
    GREEN,
} State;

// define the transitions between states
typedef struct {
    State from;
    State to;
} Transition;

// define the traffic light controller
typedef struct {
    State state;
    Transition* transitions;
    int numTransitions;
} Controller;

// function to initialize the controller
void initController(Controller* controller) {
    controller->state = RED;

    controller->numTransitions = 5;
    controller->transitions = malloc(controller->numTransitions * sizeof(Transition));
    controller->transitions[0].from = RED;
    controller->transitions[0].to = GREEN;
    controller->transitions[1].from = GREEN;
    controller->transitions[1].to = YELLOW;
    controller->transitions[2].from = YELLOW;
    controller->transitions[2].to = RED;
    controller->transitions[3].from = YELLOW;
    controller->transitions[3].to = GREEN;
    controller->transitions[4].from = GREEN;
    controller->transitions[4].to = RED;
}

// function to update the controller state
void updateController(Controller* controller) {
    for (int i = 0; i < controller->numTransitions; i++) {
        if (controller->transitions[i].from == controller->state) {
            controller->state = controller->transitions[i].to;
            break;
        }
    }
}

// function to print the state of the traffic light
void printState(Controller* controller) {
    switch (controller->state) {
        case RED:
            printf("STOP\n");
            break;
        case YELLOW:
            printf("CAUTION\n");
            break;
        case GREEN:
            printf("GO\n");
            break;
    }
}

// main function
int main() {
    Controller controller;
    initController(&controller);

    printf("The traffic light controller narrates:\n");

    while (1) {
        printf("Romeo approaches the intersection...\n");
        printState(&controller);

        printf("Juliet approaches the intersection...\n");
        printState(&controller);

        updateController(&controller);
    }

    free(controller.transitions);

    return 0;
}