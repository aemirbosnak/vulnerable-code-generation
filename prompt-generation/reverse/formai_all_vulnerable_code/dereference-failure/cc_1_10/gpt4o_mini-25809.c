//GPT-4o-mini DATASET v1.0 Category: Traffic Light Controller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define RED_LIGHT_DURATION 5
#define YELLOW_LIGHT_DURATION 2
#define GREEN_LIGHT_DURATION 4

typedef struct {
    char *name;
    int red_duration;
    int yellow_duration;
    int green_duration;
} TrafficLight;

void *control_traffic_light(void *arg) {
    TrafficLight *light = (TrafficLight *)arg;

    while(1) {
        printf("%s: RED light is ON for %d seconds!\n", light->name, light->red_duration);
        sleep(light->red_duration);

        printf("%s: YELLOW light is ON for %d seconds!\n", light->name, light->yellow_duration);
        sleep(light->yellow_duration);

        printf("%s: GREEN light is ON for %d seconds!\n", light->name, light->green_duration);
        sleep(light->green_duration);
    }
    return NULL;
}

void create_traffic_light(char *name, int red_dur, int yellow_dur, int green_dur) {
    pthread_t thread_id;
    TrafficLight *light = (TrafficLight *)malloc(sizeof(TrafficLight));
    
    light->name = name;
    light->red_duration = red_dur;
    light->yellow_duration = yellow_dur;
    light->green_duration = green_dur;

    printf("Starting traffic light: %s\n", light->name);
    if (pthread_create(&thread_id, NULL, control_traffic_light, light) != 0) {
        perror("Failed to create thread");
        exit(EXIT_FAILURE);
    }
}

int main() {
    printf("Welcome to the Traffic Light Simulation!\n");
    
    // Create traffic lights for different intersections
    create_traffic_light("Main St", RED_LIGHT_DURATION, YELLOW_LIGHT_DURATION, GREEN_LIGHT_DURATION);
    create_traffic_light("1st Ave", RED_LIGHT_DURATION, YELLOW_LIGHT_DURATION, GREEN_LIGHT_DURATION);
    create_traffic_light("2nd Ave", RED_LIGHT_DURATION, YELLOW_LIGHT_DURATION, GREEN_LIGHT_DURATION);
    
    // Keep the main thread alive indefinitely
    while(1) {
        sleep(1);
    }
    
    return 0;
}