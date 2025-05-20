//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Structure to represent a traffic light
typedef struct {
    int id;
    int time_green;
    int time_yellow;
    int time_red;
    int current_time;
    int current_color; //0 - green, 1 - yellow, 2 - red
} TrafficLight;

//Function to initialize a traffic light object
TrafficLight* init_light(int id, int time_green, int time_yellow, int time_red) {
    TrafficLight* light = (TrafficLight*)malloc(sizeof(TrafficLight));
    light->id = id;
    light->time_green = time_green;
    light->time_yellow = time_yellow;
    light->time_red = time_red;
    light->current_time = 0;
    light->current_color = 0;
    return light;
}

//Function to update the current color of a traffic light
void update_light(TrafficLight *light) {
    if (light->current_color == 0) {
        if (light->current_time == light->time_green) {
            light->current_color = 1;
            light->current_time = 0;
        }
    }
    else if (light->current_color == 1) {
        if (light->current_time == light->time_yellow) {
            light->current_color = 2;
            light->current_time = 0;
        }
    }
    else {
        if (light->current_time == light->time_red) {
            light->current_color = 0;
            light->current_time = 0;
        }
    }
    light->current_time++;
}

//Function to print the current color of a traffic light
void print_light(TrafficLight* light) {
    printf("Traffic Light %d: ", light->id);
    if (light->current_color == 0) {
        printf("Green\n");
    }
    else if (light->current_color == 1) {
        printf("Yellow\n");
    }
    else {
        printf("Red\n");
    }
}

int main() {
    srand(time(NULL));
    int num_lights = 4;
    TrafficLight** lights = (TrafficLight**)malloc(num_lights*sizeof(TrafficLight*));
    
    //Initialize the traffic lights
    for (int i = 0; i < num_lights; i++) {
        lights[i] = init_light(i, rand()%10+1, rand()%5+1, rand()%10+1);
    }
    
    //Run the traffic light simulation for 20 time steps
    for (int i = 0; i < 20; i++) {
        printf("----- Time Step %d -----\n", i+1);
        for (int j = 0; j < num_lights; j++) {
            update_light(lights[j]);
            print_light(lights[j]);
        }
        printf("\n");
    }
    
    //Free memory allocated for traffic lights
    for (int i = 0; i < num_lights; i++) {
        free(lights[i]);
    }
    free(lights);
    
    return 0;
}