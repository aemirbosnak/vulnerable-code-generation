//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_TRAFFIC_LIGHTS 3
#define RED_LIGHT_DURATION 5
#define YELLOW_LIGHT_DURATION 2
#define GREEN_LIGHT_DURATION 10

// Semaphores to control access to the traffic lights
sem_t traffic_lights[NUM_TRAFFIC_LIGHTS];

// Function to simulate a traffic light
void *traffic_light(void *arg)
{
    int traffic_light_index = *(int *)arg;

    while (1)
    {
        // Wait for the green light
        sem_wait(&traffic_lights[traffic_light_index]);

        // Display the green light
        printf("Traffic light %d: Green light on\n", traffic_light_index);
        sleep(GREEN_LIGHT_DURATION);

        // Display the yellow light
        printf("Traffic light %d: Yellow light on\n", traffic_light_index);
        sleep(YELLOW_LIGHT_DURATION);

        // Display the red light
        printf("Traffic light %d: Red light on\n", traffic_light_index);
        sleep(RED_LIGHT_DURATION);

        // Release the lock on the traffic light
        sem_post(&traffic_lights[traffic_light_index]);
    }

    return NULL;
}

int main()
{
    // Initialize the semaphores
    for (int i = 0; i < NUM_TRAFFIC_LIGHTS; i++)
    {
        sem_init(&traffic_lights[i], 0, 0);
    }

    // Create the traffic light threads
    pthread_t traffic_light_threads[NUM_TRAFFIC_LIGHTS];
    for (int i = 0; i < NUM_TRAFFIC_LIGHTS; i++)
    {
        int *traffic_light_index = malloc(sizeof(int));
        *traffic_light_index = i;
        pthread_create(&traffic_light_threads[i], NULL, traffic_light, traffic_light_index);
    }

    // Join the traffic light threads
    for (int i = 0; i < NUM_TRAFFIC_LIGHTS; i++)
    {
        pthread_join(traffic_light_threads[i], NULL);
    }

    // Destroy the semaphores
    for (int i = 0; i < NUM_TRAFFIC_LIGHTS; i++)
    {
        sem_destroy(&traffic_lights[i]);
    }

    return 0;
}