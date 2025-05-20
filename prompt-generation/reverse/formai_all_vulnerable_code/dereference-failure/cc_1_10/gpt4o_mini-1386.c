//GPT-4o-mini DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <time.h>

#define TEMPERATURE_SENSOR_COUNT 3

volatile bool running = true;

void* temperature_sensor(void* arg) {
    int sensor_id = *((int*)arg);
    free(arg);
    
    while (running) {
        // Simulate reading temperature
        float temperature = (float)(rand() % 100); // Random temperature between 0°C and 99°C
        
        // Print the temperature reading with a timestamp
        time_t now = time(NULL);
        struct tm *t = localtime(&now);
        printf("Sensor %d: Temp = %.2f°C at %02d:%02d:%02d\n", 
                sensor_id, temperature, t->tm_hour, t->tm_min, t->tm_sec);
        
        // Sleep for a second before the next reading
        sleep(1);
    }
    return NULL;
}

void signal_handler(int signo) {
    if (signo == SIGINT) {
        printf("\nTerminating program...\n");
        running = false;
    }
}

int main() {
    srand(time(NULL));
    signal(SIGINT, signal_handler);
    
    pthread_t sensors[TEMPERATURE_SENSOR_COUNT];

    // Start the temperature sensor threads
    for (int i = 0; i < TEMPERATURE_SENSOR_COUNT; i++) {
        int* sensor_id = malloc(sizeof(int));
        *sensor_id = i + 1;
        if (pthread_create(&sensors[i], NULL, temperature_sensor, sensor_id) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    // Main loop to handle user commands
    char command[10];
    while (running) {
        printf("Enter a command (read, exit): ");
        fgets(command, sizeof(command), stdin);

        if (strncmp(command, "read", 4) == 0) {
            // Read command entered
            printf("You have requested to read temperatures (view logs).\n");
            // Assume logs could be maintained here if implemented
        } else if (strncmp(command, "exit", 4) == 0) {
            printf("Exit command received. Terminating...\n");
            running = false;
        } else {
            printf("Unknown command: %s", command);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < TEMPERATURE_SENSOR_COUNT; i++) {
        pthread_cancel(sensors[i]);
        pthread_join(sensors[i], NULL);
    }

    printf("All sensors terminated. Exiting.\n");
    return EXIT_SUCCESS;
}