//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>

// Define the maximum and minimum temperature values
#define MAX_TEMP 120
#define MIN_TEMP 0

// Define the temperature sensor resolution
#define TEMP_RES 0.1

// Define the temperature alarm threshold
#define TEMP_ALARM_THRESH 90

// Define the temperature display format
#define TEMP_DISPLAY_FORMAT "%.1f"

// Create a temperature sensor data structure
typedef struct {
    float temperature;
    bool alarm_state;
} temp_sensor_t;

// Create a temperature monitor data structure
typedef struct {
    temp_sensor_t sensor;
    time_t last_update_time;
    bool alarm_on;
} temp_monitor_t;

// Create a new temperature sensor
temp_sensor_t* create_temp_sensor() {
    temp_sensor_t* sensor = malloc(sizeof(temp_sensor_t));
    if (sensor == NULL) {
        return NULL;
    }
    sensor->temperature = 0.0;
    sensor->alarm_state = false;
    return sensor;
}

// Create a new temperature monitor
temp_monitor_t* create_temp_monitor() {
    temp_monitor_t* monitor = malloc(sizeof(temp_monitor_t));
    if (monitor == NULL) {
        return NULL;
    }
    monitor->sensor = *create_temp_sensor();
    monitor->last_update_time = time(NULL);
    monitor->alarm_on = false;
    return monitor;
}

// Destroy a temperature sensor
void destroy_temp_sensor(temp_sensor_t* sensor) {
    free(sensor);
}

// Destroy a temperature monitor
void destroy_temp_monitor(temp_monitor_t* monitor) {
    destroy_temp_sensor(&monitor->sensor);
    free(monitor);
}

// Update the temperature sensor data
void update_temp_sensor(temp_sensor_t* sensor) {
    // Simulate a temperature reading
    float temp = (float)rand() / (float)RAND_MAX * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
    sensor->temperature = temp;

    // Check if the temperature has exceeded the alarm threshold
    sensor->alarm_state = (temp >= TEMP_ALARM_THRESH);
}

// Update the temperature monitor data
void update_temp_monitor(temp_monitor_t* monitor) {
    // Update the temperature sensor data
    update_temp_sensor(&monitor->sensor);

    // Update the last update time
    monitor->last_update_time = time(NULL);

    // Check if the alarm has been triggered
    if (monitor->sensor.alarm_state && !monitor->alarm_on) {
        monitor->alarm_on = true;
        printf("Temperature alarm triggered at %.1f degrees Celsius!\n", monitor->sensor.temperature);
    }
}

// Display the temperature monitor data
void display_temp_monitor(temp_monitor_t* monitor) {
    // Get the current time
    time_t now = time(NULL);

    // Calculate the time since the last update
    int elapsed_time = (int)difftime(now, monitor->last_update_time);

    // Display the temperature and alarm status
    printf("Temperature: %s degrees Celsius\n", TEMP_DISPLAY_FORMAT, monitor->sensor.temperature);
    printf("Alarm status: %s\n", monitor->sensor.alarm_state ? "Triggered" : "Normal");
    printf("Time since last update: %d seconds\n", elapsed_time);
}

// Main program
int main() {
    // Create a temperature monitor
    temp_monitor_t* monitor = create_temp_monitor();

    // Continuously update and display the temperature monitor data
    while (true) {
        update_temp_monitor(monitor);
        display_temp_monitor(monitor);

        // Sleep for 1 second
        sleep(1);
    }

    // Destroy the temperature monitor
    destroy_temp_monitor(monitor);

    return 0;
}