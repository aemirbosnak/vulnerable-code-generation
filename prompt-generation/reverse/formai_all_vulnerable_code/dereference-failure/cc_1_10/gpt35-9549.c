//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: Sherlock Holmes
//The Case of the Traffic Light Controller
//By Sherlock Holmes

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED 0
#define YELLOW 1
#define GREEN 2

typedef struct light_s {
    int id;
    int time_interval;
    struct light_s *next;
} Light;

Light *head = NULL;
Light *tail = NULL;

int current_light = RED;

void add_light(int id, int time_interval) {
    Light *new_light = malloc(sizeof(Light));
    new_light->id = id;
    new_light->time_interval = time_interval;
    new_light->next = NULL;

    if(head == NULL) {
        head = tail = new_light;
    } else {
        tail->next = new_light;
        tail = new_light;
    }
}

void rotate_lights() {
    if(current_light == GREEN) {
        current_light = YELLOW;
        printf("YELLOW\n");
        sleep(head->time_interval);
        current_light = RED;
        printf("RED\n");
        sleep(head->next->time_interval);
        current_light = GREEN;
        printf("GREEN\n");
        sleep(head->next->next->time_interval);
    } else if(current_light == YELLOW) {
        current_light = RED;
        printf("RED\n");
        sleep(head->next->time_interval);
        current_light = GREEN;
        printf("GREEN\n");
        sleep(head->next->next->time_interval);
    } else {
        current_light = YELLOW;
        printf("YELLOW\n");
        sleep(head->time_interval);
        current_light = RED;
        printf("RED\n");
        sleep(head->next->time_interval);
    }
}

int main() {
    printf("The Case of the Traffic Light Controller\n\n");

    add_light(RED, 5);
    add_light(YELLOW, 2);
    add_light(GREEN, 5);

    printf("Starting the traffic light controller...\n");

    while(1) {
        rotate_lights();
    }

    return 0;
}